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
