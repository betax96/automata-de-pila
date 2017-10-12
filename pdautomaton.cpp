#include "pdautomaton.h"

PDAutomaton::PDAutomaton(QObject *parent) : QObject(parent)
{
    states = new QList<State*>();
    simulation = NULL;
}

void PDAutomaton::addState(State *state)
{
    states->append(state);
}

void PDAutomaton::removeState(int index)
{
    states->removeAt(index);

}

State *PDAutomaton::getState(int index)
{
    return states->at(index);
}


void PDAutomaton::printDebug()
{
    for(int i=0;i<states->count();i++){
        getState(i)->printDebug();
    }
    qDebug()<<"------";
}

State *PDAutomaton::initState()
{
    State *e = NULL;
    for(int i=0;i<states->count();i++){
        if(getState(i)->getType()==State::TYPE_INIT){
            e = getState(i);
        }
    }
    return e;
}

int PDAutomaton::stateCount()
{
    return states->count();
}

int PDAutomaton::getIndex(State *state)
{
    return states->indexOf(state);
}





QString PDAutomaton::reverse(QString str)
{
    QString reverseStr = "";
    for(int i=0;i<str.count();i++){
        reverseStr.prepend(str.at(i));
    }
    return reverseStr;
}

SimulationRoute *PDAutomaton::getSimRoute()
{
    return simulation;
}

QString PDAutomaton::stringSimData(int index)
{

    SimulationData *sd = simulation->getSimData(index);

     QString out = "Paso "+QString::number(sd->getStepNum())+":-------------------------\n"+
                   "Estado :"+sd->getState()+"\n"+
                   "Expresion :"+sd->getExpresion()+"\n"+
                   "Pila :"+sd->getStack()+"\n"+
                   "Regla :"+sd->getRule()+"\n"+
                   "--------------------------------";
     return out;
}

int PDAutomaton::evaluateExp(QString exp)
{
    if(initState()==NULL){
        return -1;

    }
    SimulationRoute *sr = new SimulationRoute();

    bool acceptance = recEval(sr,1 , exp,"",initState());
    simulation = sr;

    return acceptance;
}


bool PDAutomaton::recEval(SimulationRoute *sr, int stepNum, QString exp, QString stack, State *state){



    if(state==NULL){
        return false;
    }
    if(exp.count()==0&&state->getType()==State::TYPE_ACCEPT){
        sr->setAcceptance(true);
        return true;
    }

    int acp = false;
    int ruleIn = false;

    for(int i=0;i<state->ruleCount();i++){
        Transition *r = state->getRule(i);
        QString tStack = stack;
        QString tExp = exp;
        if(r->getEvalChar()=="*"){
            if(r->getStackOut()=="*"){

                if(r->getStackIn()!="*"&&r->getStackIn()!="#"){
                     tStack=tStack.prepend(reverse(r->getStackIn()));
                }
                SimulationData *sd = new SimulationData(stepNum,state->getName(),exp,stack,"");

                sd->setRule(r->getEvalChar()+","+r->getStackOut()+"/"+r->getStackIn()
                            +" -> "+qobject_cast<State*>(r->getTargetState())->getName());
                sr->addSimData(sd);
                ruleIn = true;
                acp=acp||recEval(sr,stepNum+1,tExp,tStack,qobject_cast<State*>(r->getTargetState()));
            }else if(r->getStackOut()=="#"&&tStack.count()==0){
                if(r->getStackIn()!="*"&&r->getStackIn()!="#"){
                     tStack=tStack.prepend(reverse(r->getStackIn()));
                }
                SimulationData *sd = new SimulationData(stepNum,state->getName(),exp,stack,"");
                sd->setRule(r->getEvalChar()+","+r->getStackOut()+"/"+r->getStackIn()
                            +" -> "+qobject_cast<State*>(r->getTargetState())->getName());
                sr->addSimData(sd);
                ruleIn = true;
                acp=acp||recEval(sr,stepNum+1,tExp,tStack,qobject_cast<State*>(r->getTargetState()));
            }else if(stack.count()>0&&r->getStackOut()==stack.at(0)){
                tStack=tStack.remove(0,1);
                if(r->getStackIn()!="*"&&r->getStackIn()!="#"){
                     tStack=tStack.prepend(reverse(r->getStackIn()));
                }
                SimulationData *sd = new SimulationData(stepNum,state->getName(),exp,stack,"");
                sd->setRule(r->getEvalChar()+","+r->getStackOut()+"/"+r->getStackIn()
                            +" -> "+qobject_cast<State*>(r->getTargetState())->getName());
                sr->addSimData(sd);
                ruleIn = true;
                acp=acp||recEval(sr,stepNum+1,tExp,tStack,qobject_cast<State*>(r->getTargetState()));
            }
        }else{
            if(exp.count()>0&&r->getEvalChar()==tExp.at(0)){
                if(r->getStackOut()=="*"){

                    if(r->getStackIn()!="*"&&r->getStackIn()!="#"){
                         tStack=tStack.prepend(reverse(r->getStackIn()));
                    }
                    SimulationData *sd = new SimulationData(stepNum,state->getName(),exp,stack,"");
                    sd->setRule(r->getEvalChar()+","+r->getStackOut()+"/"+r->getStackIn()
                                 +" -> "+qobject_cast<State*>(r->getTargetState())->getName());
                    sr->addSimData(sd);
                    ruleIn = true;
                    acp=acp||recEval(sr,stepNum+1,tExp.remove(0,1),tStack,qobject_cast<State*>(r->getTargetState()));
                }else if(r->getStackOut()=="#"&&tStack.count()==0){
                    if(r->getStackIn()!="*"&&r->getStackIn()!="#"){
                         tStack=tStack.prepend(reverse(r->getStackIn()));
                    }
                    SimulationData *sd = new SimulationData(stepNum,state->getName(),exp,stack,"");
                    sd->setRule(r->getEvalChar()+","+r->getStackOut()+"/"+r->getStackIn()
                                 +" -> "+qobject_cast<State*>(r->getTargetState())->getName());
                    sr->addSimData(sd);
                    ruleIn = true;
                    acp=acp||recEval(sr,stepNum+1,tExp.remove(0,1),tStack,qobject_cast<State*>(r->getTargetState()));
                }else if(stack.count()>0&&r->getStackOut()==stack.at(0)){
                    tStack=tStack.remove(0,1);
                    if(r->getStackIn()!="*"&&r->getStackIn()!="#"){
                         tStack=tStack.prepend(reverse(r->getStackIn()));
                    }
                    SimulationData *sd = new SimulationData(stepNum,state->getName(),exp,stack,"");
                    sd->setRule(r->getEvalChar()+","+r->getStackOut()+"/"+r->getStackIn()
                                +" -> "+qobject_cast<State*>(r->getTargetState())->getName());
                    sr->addSimData(sd);
                    ruleIn = true;
                    acp=acp||recEval(sr,stepNum+1,tExp.remove(0,1),tStack,qobject_cast<State*>(r->getTargetState()));
                }
            }
        }
        if(acp){
            break;
        }
    }
    if(!ruleIn){
        SimulationData *sd = new SimulationData(stepNum,state->getName(),exp,stack,"Sin regla");
        sr->addSimData(sd);
    }

    return acp;
}


