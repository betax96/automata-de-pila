#ifndef AUTOMATAPILA_H
#define AUTOMATAPILA_H

#include <QObject>
#include "state.h"
#include "simulationroute.h"

class PDAutomaton : public QObject
{
    Q_OBJECT
public:
    explicit PDAutomaton(QObject *parent = 0);

    void addState(State *state);
    void removeState(int index);
    State* getState(int index);
    void printDebug();
    int evaluateExp(QString exp);
    State* initState();
    int stateCount();
    int getIndex(State *state);
    QString reverse(QString str);
    SimulationRoute* getSimRoute();
    QString stringSimData(int index);

public slots:

private:
    bool recEval(SimulationRoute *route, int stepNum, QString exp, QString stack, State *e);
    QList<State*> *states;
    SimulationRoute *simulation;
};

#endif // AUTOMATAPILA_H
