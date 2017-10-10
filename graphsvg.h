#ifndef GRAPHSVG_H
#define GRAPHSVG_H



#include <ogdf/basic/Graph.h>
#include <ogdf/basic/GraphAttributes.h>
#include <ogdf/planarity/PlanarizationLayout.h>
#include <ogdf/fileformats/GraphIO.h>
#include <QSize>
#include "state.h"
#include "transition.h"
#include "pdautomaton.h"
#include <ogdf/planarity/PlanarizationLayout.h>

using namespace ogdf;
class GraphSvg : public QObject
{
    Q_OBJECT
public:
     explicit GraphSvg(QObject *parent);
    GraphSvg(QSize defaultSize, Color defaultEdgeColor,Color defaultNodeColor, QObject *parent = 0);

    node addNode(State *state, QSize size, Color nodeColor);
    void addEdge(node source, node target, Color edgeColor);
    void drawAuto(PDAutomaton *automata, Color init, Color acept);
    bool saveSvg(QString name);
    bool haveEdge(node source, node target);
signals:

public slots:

private:
    Graph graph;
    GraphAttributes graphAttr;
    QSize defaultSize;
    Color defaultNodeColor;
    Color defaultEdgeColor;
    QVector<node> *nodeList;
    QVector<edge> *edgeList;
};

#endif // GRAPHSVG_H
