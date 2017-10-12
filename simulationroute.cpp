#include "simulationroute.h"

SimulationRoute::SimulationRoute(QObject *parent) : QObject(parent)
{
    route = new QList<SimulationData*>();
    acceptance = false;
}

bool SimulationRoute::getAcceptance() const
{
    return acceptance;
}

void SimulationRoute::setAcceptance(bool value)
{
    acceptance = value;
}

void SimulationRoute::addSimData(SimulationData *sd)
{
    route->append(sd);
}

void SimulationRoute::removeSimData(int index)
{
    route->removeAt(index);
}

SimulationData *SimulationRoute::getSimData(int index)
{
    return route->at(index);
}

int SimulationRoute::simDataCount()
{
    return route->count();
}

void SimulationRoute::addSimData(int index, SimulationData *sd)
{
    route->replace(index,sd);
}

void SimulationRoute::removeLastSimData()
{
    route->removeLast();
}
