#ifndef SIMULATIONDATA_H
#define SIMULATIONDATA_H

#include <QObject>

class SimulationData : public QObject
{
    Q_OBJECT
public:
    explicit SimulationData(QObject *parent = 0);
    SimulationData(int stepNum, QString state, QString expresion, QString stack, QString rule, QObject *parent = 0);

    QString getState() const;
    void setState(const QString &value);

    QString getExpresion() const;
    void setExpresion(const QString &value);

    QString getStack() const;
    void setStack(const QString &value);

    QString getRule() const;
    void setRule(const QString &value);

    int getStepNum() const;
    void setStepNum(int value);

signals:

public slots:

private:
    int stepNum;
    QString state;
    QString expresion;
    QString stack;
    QString rule;
};

#endif // SIMULATIONDATA_H
