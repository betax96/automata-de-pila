#ifndef TRANSICION_H
#define TRANSICION_H

#include <QObject>

class Transicion : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QChar letraEval READ getLetraEval WRITE setLetraEval)
    Q_PROPERTY(QChar salePila READ getSalePila WRITE setSalePila)
    Q_PROPERTY(QChar entraPila READ getEntraPila WRITE setEntraPila)
    Q_PROPERTY(QObject* estadoDestino READ getEstadoDestino WRITE setEstadoDestino)
    Q_PROPERTY(QObject* estadoOrigen READ getEstadoDestino WRITE setEstadoOrigen)
    Q_PROPERTY(int id READ getId WRITE setId)
public:
    explicit Transicion(QObject *parent = 0);

    Transicion(int id, QChar letraEval, QChar salePila, QChar entraPila, QObject* estadoOrigen, QObject* estadoDestino,QObject *parent = 0);

    QChar getLetraEval() const;
    void setLetraEval(const QChar &value);

    QChar getSalePila() const;
    void setSalePila(const QChar &value);

    QChar getEntraPila() const;
    void setEntraPila(const QChar &value);

    QObject* getEstadoDestino() const;
    void setEstadoDestino(QObject* &value);

    QObject *getEstadoOrigen() const;
    void setEstadoOrigen(QObject *value);

    int getId() const;
    void setId(int value);


signals:

public slots:

private:
    QObject* estadoOrigen;
    QChar letraEval;
    QChar salePila;
    QChar entraPila;
    QObject* estadoDestino;
    int id;

};

#endif // TRANSICION_H
