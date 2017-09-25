#ifndef ESTADO_H
#define ESTADO_H

#include <QObject>
#include "transicion.h"
#include <QDebug>

class Estado : public QObject
{
    Q_OBJECT
     Q_PROPERTY(QString nombre READ getNombre WRITE setNombre)
     Q_PROPERTY(int tipo READ getTipo WRITE setTipo)

public:
    static const int TIPO_NORMAL = 0;
    static const int TIPO_ACEPTACION = 2;
    static const int TIPO_INICIAL = 1;
    explicit Estado(QObject *parent = 0);
    Estado(QString nombre, int tipo, QObject *parent = 0);

    QString getNombre() const;
    void setNombre(const QString &value);

    int getTipo() const;
    void setTipo(const int &value);

    void agregarRegla(Transicion *regla);
    void removerRegla(int i);
    void printDebug();
    int reglasCount();
    Transicion* getRegla(int i);

signals:

public slots:

private:
    QString nombre;
    int tipo;
    QList<Transicion*> *reglas ;

};

#endif // ESTADO_H
