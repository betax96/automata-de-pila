#ifndef TRANSICION_H
#define TRANSICION_H

#include <QObject>

class Transition : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QChar evalChar READ getEvalChar WRITE setEvalChar)
    Q_PROPERTY(QChar stackOut READ getStackOut WRITE setStackOut)
    Q_PROPERTY(QChar stackIn READ getStackIn WRITE setStackIn)
    Q_PROPERTY(QObject* targetState READ getTargetState WRITE setTargetState)
public:
    explicit Transition(QObject *parent = 0);

    Transition(QChar evalChar, QChar stackOut, QChar stackIn,QObject* targetState,QObject *parent = 0);

    QChar getEvalChar() const;
    void setEvalChar(const QChar &value);

    QChar getStackOut() const;
    void setStackOut(const QChar &value);

    QChar getStackIn() const;
    void setStackIn(const QChar &value);

    QObject* getTargetState() const;
    void setTargetState(QObject* &state);

signals:

public slots:

private:
    QChar evalChar;
    QChar stackOut;
    QChar stackIn;
    QObject* targetState;

};

#endif // TRANSICION_H
