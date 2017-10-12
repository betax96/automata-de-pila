#ifndef TRANSICION_H
#define TRANSICION_H

#include <QObject>

class Transition : public QObject
{
    Q_OBJECT
public:
    explicit Transition(QObject *parent = 0);

    Transition(QString evalChar, QString stackOut, QString stackIn,QObject* targetState,QObject *parent = 0);

    QString getEvalChar() const;
    void setEvalChar(const QString &value);

    QString getStackOut() const;
    void setStackOut(const QString &value);

    QString getStackIn() const;
    void setStackIn(const QString &value);

    QObject* getTargetState() const;
    void setTargetState(QObject* &state);

signals:

public slots:

private:
    QString evalChar;
    QString stackOut;
    QString stackIn;
    QObject* targetState;

};

#endif // TRANSICION_H
