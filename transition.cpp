#include "transition.h"

Transition::Transition(QObject *parent) : QObject(parent)
{

}

Transition::Transition(QString evalChar, QString stackOut, QString stackIn, QObject* targetState, QObject *parent) : QObject(parent)
{
    this->evalChar = evalChar;
    this->stackOut = stackOut;
    this->stackIn = stackIn;
    this->targetState = targetState;

}

QString Transition::getEvalChar() const
{
    return evalChar;
}

void Transition::setEvalChar(const QString &value)
{
    evalChar = value;
}

QString Transition::getStackOut() const
{
    return stackOut;
}

void Transition::setStackOut(const QString &value)
{
    stackOut = value;
}

QString Transition::getStackIn() const
{
    return stackIn;
}

void Transition::setStackIn(const QString &value)
{
    stackIn = value;
}

QObject* Transition::getTargetState() const
{
    return targetState;
}

void Transition::setTargetState(QObject* &state)
{
    targetState = state;
}

