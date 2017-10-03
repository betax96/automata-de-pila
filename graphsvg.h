#ifndef GRAPHSVG_H
#define GRAPHSVG_H



#include <ogdf/basic/Graph.h>
#include <ogdf/basic/GraphAttributes.h>
#include <ogdf/planarity/PlanarizationLayout.h>
#include <ogdf/fileformats/GraphIO.h>
#include <QSize>
#include "estado.h"
#include "transicion.h"
#include "automatapila.h"


using namespace ogdf;
class GraphSvg : public QObject
{
    Q_OBJECT
public:
     explicit GraphSvg(QObject *parent);
    GraphSvg(QSize defaultSize, Color defaultEdgeColor,Color defaultNodeColor, QObject *parent = 0);

    node addNode(Estado *state, QSize size, Color nodeColor);
    void addEdge(node source, node target, Color edgeColor);
    void drawAuto(AutomataPila *automata);
    bool saveSvg(QString name);
signals:

public slots:

private:
    Graph* graph;
    GraphAttributes graphAttr;
    QSize defaultSize;
    Color defaultNodeColor;
    Color defaultEdgeColor;
    QVector<node> *nodeList;
    QVector<edge> *edgeList;
};

#endif // GRAPHSVG_H
