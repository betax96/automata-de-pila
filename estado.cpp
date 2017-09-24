#include "estado.h"

Estado::Estado(QObject *parent) : QObject(parent)
{

}

Estado::Estado(QString nombre, qint32 tipo, QObject *parent) : QObject(parent)
{
    this->nombre = nombre;
    this->tipo = tipo;
    this->reglas = new QList<Transicion>();
}

QString Estado::getNombre() const
{
    return nombre;
}

void Estado::setNombre(const QString &value)
{
    nombre = value;
}

qint32 Estado::getTipo() const
{
    return tipo;
}

void Estado::setTipo(const qint32 &value)
{
    tipo = value;
}


void Estado::agregarRegla(Transicion regla)
{

}

void Estado::removerRegla(Transicion regla)
{

}

Transicion Estado::getRegla(qint32 pos)
{

}


