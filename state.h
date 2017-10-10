#ifndef ESTADO_H
#define ESTADO_H

#include <QObject>
#include "transition.h"
#include <QDebug>

class State : public QObject
{
    Q_OBJECT
     Q_PROPERTY(QString name READ getName WRITE setName)
     Q_PROPERTY(int type READ getType WRITE setType)
public:
    static const int TYPE_NORMAL = 0;
    static const int TYPE_ACCEPT = 2;
    static const int TYPE_INIT = 1;
    explicit State(QObject *parent = 0);
    State(QString name, int type, QObject *parent = 0);

    QString getName() const;
    void setName(const QString &name);

    int getType() const;
    void setType(const int &type);

    void addRule(Transition *rule);
    void removeRule(int index);
    void printDebug();
    int ruleCount();
    Transition* getRule(int index);

signals:

public slots:

private:
    QString name;
    int type;
    QList<Transition*> *rules ;

};

#endif // ESTADO_H
