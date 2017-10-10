#include "transition.h"

Transition::Transition(QObject *parent) : QObject(parent)
{

}

Transition::Transition(QChar evalChar, QChar stackOut, QChar stackIn, QObject* targetState, QObject *parent) : QObject(parent)
{
    this->evalChar = evalChar;
    this->stackOut = stackOut;
    this->stackIn = stackIn;
    this->targetState = targetState;

}

QChar Transition::getEvalChar() const
{
    return evalChar;
}

void Transition::setEvalChar(const QChar &value)
{
    evalChar = value;
}

QChar Transition::getStackOut() const
{
    return stackOut;
}

void Transition::setStackOut(const QChar &value)
{
    stackOut = value;
}

QChar Transition::getStackIn() const
{
    return stackIn;
}

void Transition::setStackIn(const QChar &value)
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

