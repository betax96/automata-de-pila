#include "automatapila.h"

AutomataPila::AutomataPila(QObject *parent) : QObject(parent)
{
    estados = new QList<Estado*>();
    pila = new QStack<QChar>();
}

void AutomataPila::entraPila(QChar c)
{
    pila->push(c);
}

QChar AutomataPila::salePila()
{
    return pila->pop();
}


bool AutomataPila::pilaVacia()
{
    return pila->isEmpty();
}


void AutomataPila::agregarEstado(Estado *e)
{
    estados->append(e);
    emit modificacion();
}

void AutomataPila::removerEstado(int k)
{
    estados->removeAt(k);

    emit modificacion();
}

Estado *AutomataPila::obtenerEstado(int i)
{
    return estados->at(i);
}


void AutomataPila::printDebug()
{
    for(int i=0;i<estados->count();i++){
        obtenerEstado(i)->printDebug();
    }
    qDebug()<<"------";
}

Estado *AutomataPila::estadoInicial()
{
    Estado *e = NULL;
    for(int i=0;i<estados->count();i++){
        if(obtenerEstado(i)->getTipo()==Estado::TIPO_INICIAL){
            e = obtenerEstado(i);
        }
    }
    return e;
}

int AutomataPila::estadosCount()
{
    return estados->count();
}

int AutomataPila::evaluarExpresion(QString exp)
{
    if(estadoInicial()==NULL){
        return -1;

    }
    return recEval(exp,"",estadoInicial());

}



bool AutomataPila::recEval(QString exp, QString pila, Estado *e)
{
    if(exp.count()==0&&e->getTipo()==Estado::TIPO_ACEPTACION){
        return true;
    }
    if(exp.count()==0||e==NULL){
        return false;
    }
    int acp = false;
    QChar c = exp.at(0);
    for(int i=0;i<e->reglasCount();i++){
        Transicion *r = e->getRegla(i);
        QString tPila = pila;
        if(r->getLetraEval()=='*'){
            if(r->getSalePila()=='*'){

                if(r->getEntraPila()!='*'){
                     tPila=tPila.prepend(r->getEntraPila());
                }
                acp=acp||recEval(exp,tPila,qobject_cast<Estado*>(r->getEstadoDestino()));
            }else if(r->getSalePila()=='#'&&tPila.count()==0){
                if(r->getEntraPila()!='*'){
                     tPila=tPila.prepend(r->getEntraPila());
                }
                acp=acp||recEval(exp,tPila,qobject_cast<Estado*>(r->getEstadoDestino()));
            }else if(pila.count()>0&&r->getSalePila()==pila.at(0)){
                tPila=tPila.remove(0,1);
                if(r->getEntraPila()!='*'){
                     tPila=tPila.prepend(r->getEntraPila());
                }
                acp=acp||recEval(exp,tPila,qobject_cast<Estado*>(r->getEstadoDestino()));
            }
        }else{
            if(r->getLetraEval()==c){
                if(r->getSalePila()=='*'){

                    if(r->getEntraPila()!='*'){
                         tPila=tPila.prepend(r->getEntraPila());
                    }
                    acp=acp||recEval(exp.remove(0,1),tPila,qobject_cast<Estado*>(r->getEstadoDestino()));
                }else if(r->getSalePila()=='#'&&tPila.count()==0){
                    if(r->getEntraPila()!='*'){
                         tPila=tPila.prepend(r->getEntraPila());
                    }
                    acp=acp||recEval(exp,tPila,qobject_cast<Estado*>(r->getEstadoDestino()));
                }else if(pila.count()>0&&r->getSalePila()==pila.at(0)){
                    tPila=tPila.remove(0,1);
                    if(r->getEntraPila()!='*'){
                         tPila=tPila.prepend(r->getEntraPila());
                    }
                    acp=acp||recEval(exp.remove(0,1),tPila,qobject_cast<Estado*>(r->getEstadoDestino()));
                }
            }
        }
    }
    return acp;
}
