#ifndef ESTADO_H
#define ESTADO_H

#include <QObject>
#include "transicion.h"

class Estado : public QObject
{
    Q_OBJECT
     Q_PROPERTY(QString nombre READ getNombre WRITE setNombre)
     Q_PROPERTY(qint32 tipo READ getTipo WRITE setTipo)

public:
    const qint32 TIPO_NORMAL = 0;
    const qint32 TIPO_ACEPTACION = 2;
    const qint32 TIPO_INICIAL = 1;
    explicit Estado(QObject *parent = 0);
    Estado(QString nombre, qint32 tipo, QObject *parent = 0);

    QString getNombre() const;
    void setNombre(const QString &value);

    qint32 getTipo() const;
    void setTipo(const qint32 &value);

    void agregarRegla(Transicion regla);
    void removerRegla(Transicion regla);
    Transicion getRegla(qint32 pos);

signals:

public slots:

private:
    QString nombre;
    qint32 tipo;
    QList<Transicion>* reglas ;

};

#endif // ESTADO_H
