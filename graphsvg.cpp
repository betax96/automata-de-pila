#include "graphsvg.h"

GraphSvg::GraphSvg(QObject *parent) : QObject(parent)
{

}

GraphSvg::GraphSvg(QSize defaultSize, Color defaultEdgeColor, Color defaultNodeColor, QObject *parent)
{
    this->defaultSize = defaultSize;
    this->defaultEdgeColor = defaultEdgeColor;
    this->defaultNodeColor = defaultNodeColor;

    graph = new Graph();

        graphAttr = GraphAttributes( *graph, GraphAttributes::nodeGraphics |
            GraphAttributes::edgeGraphics |
            GraphAttributes::nodeLabel |
            GraphAttributes::nodeStyle |
            GraphAttributes::edgeType |
            GraphAttributes::edgeArrow |
            GraphAttributes::edgeStyle );
        nodeList = new QVector<node>();
        edgeList = new QVector<edge>();
}

node GraphSvg::addNode(Estado *state, QSize size , Color nodeColor)
{
    node newNode = graph ->newNode();
    graphAttr.width(newNode) = size.width();
    graphAttr.height(newNode) = size.height();
    graphAttr.shape(newNode) = ogdf::Shape::shEllipse;
    graphAttr.fillColor(newNode) = nodeColor;
    graphAttr.label(newNode) = state->getNombre().toStdString();
    nodeList->push_back(newNode);
    return newNode;
}

void GraphSvg::addEdge(node source, node target, Color edgeColor)
{
    edge newEdge = graph->newEdge(source, target);
    graphAttr.arrowType(newEdge) = ogdf::EdgeArrow::eaLast;
    graphAttr.strokeColor(newEdge) = edgeColor;

   graphAttr.bends(newEdge);
    edgeList->push_back(newEdge);
}

void GraphSvg::drawAuto(AutomataPila *automata)
{
    for(int i=0; i<automata->estadosCount();i++){
        Estado *e = automata->obtenerEstado(i);
        int sType = e->getTipo();
        switch(sType){
            case Estado::TIPO_INICIAL:
                addNode(e,defaultSize,Color("#A9F5A9"));
            break;
            case Estado::TIPO_NORMAL:
                addNode(e,defaultSize,defaultNodeColor);
            break;
            case Estado::TIPO_ACEPTACION:
                 addNode(e,defaultSize,Color("#F3F781"));
            break;
        }

    }

    for(int i=0; i<automata->estadosCount();i++){
        Estado *e = automata->obtenerEstado(i);
        for(int j=0; j<e->reglasCount();j++){
            int di = automata->getIndex(qobject_cast<Estado*>(e->getRegla(j)->getEstadoDestino()));
            addEdge(nodeList->at(i),nodeList->at(di),defaultEdgeColor);
        }
    }

}

bool GraphSvg::saveSvg(QString name)
{
    PlanarizationLayout pl;
    pl.call(graphAttr);
    GraphIO::drawSVG( graphAttr, name.toStdString() );
}

