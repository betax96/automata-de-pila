#ifndef AUTOMATAPILA_H
#define AUTOMATAPILA_H

#include <QObject>
#include "estado.h"
#include <QStack>

class AutomataPila : public QObject
{
    Q_OBJECT
public:
    explicit AutomataPila(QObject *parent = 0);

    void entraPila(QChar c);
    QChar salePila();
    void agregarEstado(Estado *e);
    void removerEstado(int i);
    Estado* obtenerEstado(int i);
    bool pilaVacia();
    void printDebug();
signals:
    void modificacion();
public slots:

private:
    QList<Estado*> *estados;
    QStack<QChar> *pila;
};

#endif // AUTOMATAPILA_H
