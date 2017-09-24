#include "transicion.h"

Transicion::Transicion(QObject *parent) : QObject(parent)
{

}

Transicion::Transicion(QChar letraEval, QChar salePila, QChar entraPila, QObject* estadoDestino, QObject *parent) : QObject(parent)
{
    this->letraEval = letraEval;
    this->salePila = salePila;
    this->entraPila = entraPila;
    this->estadoDestino = estadoDestino;

}

QChar Transicion::getLetraEval() const
{
    return letraEval;
}

void Transicion::setLetraEval(const QChar &value)
{
    letraEval = value;
}

QChar Transicion::getSalePila() const
{
    return salePila;
}

void Transicion::setSalePila(const QChar &value)
{
    salePila = value;
}

QChar Transicion::getEntraPila() const
{
    return entraPila;
}

void Transicion::setEntraPila(const QChar &value)
{
    entraPila = value;
}

QObject* Transicion::getEstadoDestino() const
{
    return estadoDestino;
}

void Transicion::setEstadoDestino(QObject* &value)
{
    estadoDestino = value;
}
