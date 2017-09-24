#include "estado.h"

Estado::Estado(QObject *parent) : QObject(parent)
{

}

Estado::Estado(QString nombre, int tipo, QObject *parent) : QObject(parent)
{
    this->nombre = nombre;
    this->tipo = tipo;
    this->reglas = new QList<Transicion*>();
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

void Estado::setTipo(const int &value)
{
    tipo = value;
}


void Estado::agregarRegla(Transicion *regla)
{
    reglas->append(regla);
}

void Estado::removerRegla(int i)
{
    reglas->removeAt(i);
}

Transicion* Estado::getRegla(int i)
{
    return reglas->at(i);
}

