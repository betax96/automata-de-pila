#include "transicion.h"

Transicion::Transicion(QObject *parent) : QObject(parent)
{

}

Transicion::Transicion(int id, QChar letraEval, QChar salePila, QChar entraPila, QObject* estadoOrigen,
                       QObject* estadoDestino, QObject *parent) : QObject(parent)
{
    this->letraEval = letraEval;
    this->salePila = salePila;
    this->entraPila = entraPila;
    this->estadoOrigen = estadoOrigen;
    this->estadoDestino = estadoDestino;
    this->id = id;

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

QObject *Transicion::getEstadoOrigen() const
{
    return estadoOrigen;
}

void Transicion::setEstadoOrigen(QObject *value)
{
    estadoOrigen = value;
}

int Transicion::getId() const
{
    return id;
}

void Transicion::setId(int value)
{
    id = value;
}
