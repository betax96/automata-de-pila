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

int Estado::getTipo() const
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

void Estado::printDebug()
{
    qDebug()<<getNombre()+" "+QString::number(tipo);
    for(int i=0;i<reglas->count();i++){
        Estado* estadoDestino = qobject_cast<Estado*>(getRegla(i)->getEstadoDestino());
        qDebug()<<estadoDestino->getNombre()<<" : "
               <<getRegla(i)->getLetraEval()<<"/"<<getRegla(i)->getSalePila()<<"/"<<getRegla(i)->getEntraPila();
    }
    qDebug()<<"---";
}

int Estado::reglasCount()
{
    return reglas->count();
}


