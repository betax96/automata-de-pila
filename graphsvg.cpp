#include "graphsvg.h"

GraphSvg::GraphSvg(QObject *parent) : QObject(parent)
{

}

GraphSvg::GraphSvg(QSize defaultSize, Color defaultEdgeColor, Color defaultNodeColor, QObject *parent)
{
    this->defaultSize = defaultSize;
    this->defaultEdgeColor = defaultEdgeColor;
    this->defaultNodeColor = defaultNodeColor;

    graph = Graph();
    graphAttr = GraphAttributes( graph, GraphAttributes::nodeGraphics |
        GraphAttributes::edgeGraphics |
        GraphAttributes::nodeLabel |
        GraphAttributes::nodeStyle |
        GraphAttributes::nodeType |
        GraphAttributes::edgeType |
        GraphAttributes::edgeArrow |
        GraphAttributes::edgeStyle );
    nodeList = new QVector<node>();
    edgeList = new QVector<edge>();
}

node GraphSvg::addNode(State *state, QSize size , Color nodeColor)
{
    node newNode = graph.newNode();
    graphAttr.width(newNode) = size.width();
    graphAttr.height(newNode) = size.height();
    graphAttr.shape(newNode) = ogdf::Shape::Ellipse;
    graphAttr.fillColor(newNode) = nodeColor;
    graphAttr.label(newNode) = state->getName().toStdString();
    graphAttr.x(newNode) = 50;
    graphAttr.y(newNode) = 50;
    nodeList->push_back(newNode);
    return newNode;
}

void GraphSvg::addEdge(node source, node target, Color edgeColor)
{
    edge newEdge = graph.newEdge(source, target);
    graphAttr.arrowType(newEdge) = ogdf::EdgeArrow::Last;
    graphAttr.strokeColor(newEdge) = edgeColor;
    edgeList->push_back(newEdge);
}

bool GraphSvg::haveEdge(node source, node target)
{
    bool haveEdge = false;
    for(int k=0; k<edgeList->count();k++){
        if(edgeList->at(k)->source()== source&&edgeList->at(k)->target()== target){
            haveEdge = true;
        }
    }

    return haveEdge;
}


void GraphSvg::drawAuto(PDAutomaton *automata, Color init, Color acept)
{
    for(int i=0; i<automata->stateCount();i++){
        State *e = automata->getState(i);
        int sType = e->getType();
        switch(sType){
            case State::TYPE_INIT:
                addNode(e,defaultSize,init);
            break;
            case State::TYPE_NORMAL:
                addNode(e,defaultSize,defaultNodeColor);
            break;
            case State::TYPE_ACCEPT:
                 addNode(e,defaultSize,acept);
            break;
        }

    }

    for(int i=0; i<automata->stateCount();i++){
        State *e = automata->getState(i);
        for(int j=0; j<e->ruleCount();j++){

            int di = automata->getIndex(qobject_cast<State*>(e->getRule(j)->getTargetState()));

            if(di!=-1&&!haveEdge(nodeList->at(i),nodeList->at(di))){
                addEdge(nodeList->at(i),nodeList->at(di),defaultEdgeColor);
            }

        }
    }

}

bool GraphSvg::saveSvg(QString name)
{
    PlanarizationLayout pl;
    pl.call(graphAttr);

    GraphIO::drawSVG( graphAttr, name.toStdString() );
}

