#ifndef AUTOMATAPILA_H
#define AUTOMATAPILA_H

#include <QObject>
#include "state.h"

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

public slots:

private:
    bool recEval(QString exp, QString stack, State *e);

    QList<State*> *states;
};

#endif // AUTOMATAPILA_H
