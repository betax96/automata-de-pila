#ifndef SIMULATIONROUTE_H
#define SIMULATIONROUTE_H

#include <QObject>
#include <QList>
#include <simulationdata.h>

class SimulationRoute : public QObject
{
    Q_OBJECT
public:
    explicit SimulationRoute(QObject *parent = 0);
    bool getAcceptance() const;
    void setAcceptance(bool value);
    void addSimData(SimulationData *sd);
    void removeSimData(int index);
    SimulationData* getSimData(int index);
    int simDataCount();
    void addSimData(int index, SimulationData *sd);
    void removeLastSimData();

signals:

public slots:

private:
    QList<SimulationData*> *route;
    bool acceptance;
};

#endif // SIMULATIONROUTE_H
