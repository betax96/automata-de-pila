#include "simulationdata.h"

SimulationData::SimulationData(QObject *parent) : QObject(parent)
{

}

SimulationData::SimulationData(int stepNum, QString state, QString expresion, QString stack, QString rule, QObject *parent)
: QObject(parent)
{
    this->stepNum = stepNum;
    this->state = state;
    this->expresion = expresion;
    this->stack = stack;
    this->rule = rule;
}

QString SimulationData::getState() const
{
    return state;
}

void SimulationData::setState(const QString &value)
{
    state = value;
}

QString SimulationData::getExpresion() const
{
    return expresion;
}

void SimulationData::setExpresion(const QString &value)
{
    expresion = value;
}

QString SimulationData::getStack() const
{
    return stack;
}

void SimulationData::setStack(const QString &value)
{
    stack = value;
}

QString SimulationData::getRule() const
{
    return rule;
}

void SimulationData::setRule(const QString &value)
{
    rule = value;
}

int SimulationData::getStepNum() const
{
    return stepNum;
}

void SimulationData::setStepNum(int value)
{
    stepNum = value;
}
