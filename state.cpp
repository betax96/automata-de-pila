#include "state.h"

State::State(QObject *parent) : QObject(parent)
{

}

State::State(QString name, int type, QObject *parent) : QObject(parent)
{
    this->name = name;
    this->type = type;
    this->rules = new QList<Transition*>();

}

QString State::getName() const
{
    return name;
}

void State::setName(const QString &name)
{
    this->name = name;
}

int State::getType() const
{
    return type;
}

void State::setType(const int &type)
{
    this->type = type;
}


void State::addRule(Transition *rule)
{
    rules->append(rule);
}

void State::removeRule(int index)
{
    rules->removeAt(index);
}

Transition* State::getRule(int index)
{
    return rules->at(index);
}

void State::printDebug()
{
    qDebug()<<getName()+" "+QString::number(type);
    for(int i=0;i<rules->count();i++){
        State* estadoDestino = qobject_cast<State*>(getRule(i)->getTargetState());
        qDebug()<<estadoDestino->getName()<<" : "
               <<getRule(i)->getEvalChar()<<"/"<<getRule(i)->getStackOut()<<"/"<<getRule(i)->getStackIn();
    }
    qDebug()<<"---";
}

int State::ruleCount()
{
    return rules->count();
}


