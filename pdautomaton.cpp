#include "pdautomaton.h"

PDAutomaton::PDAutomaton(QObject *parent) : QObject(parent)
{
    states = new QList<State*>();
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

int PDAutomaton::evaluateExp(QString exp)
{
    if(initState()==NULL){
        return -1;

    }
    return recEval(exp,"",initState());

}



bool PDAutomaton::recEval(QString exp, QString stack, State *state){

    if(state==NULL){
        return false;
    }
    if(exp.count()==0&&state->getType()==State::TYPE_ACCEPT){
        return true;
    }

    int acp = false;

    for(int i=0;i<state->ruleCount();i++){
        Transition *r = state->getRule(i);
        QString tStack = stack;
        QString tExp = exp;
        if(r->getEvalChar()=="*"){
            if(r->getStackOut()=="*"){

                if(r->getStackIn()!="*"&&r->getStackIn()!="#"){
                     tStack=tStack.prepend(reverse(r->getStackIn()));
                }
                acp=acp||recEval(tExp,tStack,qobject_cast<State*>(r->getTargetState()));
            }else if(r->getStackOut()=="#"&&tStack.count()==0){
                if(r->getStackIn()!="*"&&r->getStackIn()!="#"){
                     tStack=tStack.prepend(reverse(r->getStackIn()));
                }
                acp=acp||recEval(tExp,tStack,qobject_cast<State*>(r->getTargetState()));
            }else if(stack.count()>0&&r->getStackOut()==stack.at(0)){
                tStack=tStack.remove(0,1);
                if(r->getStackIn()!="*"&&r->getStackIn()!="#"){
                     tStack=tStack.prepend(reverse(r->getStackIn()));
                }
                acp=acp||recEval(tExp,tStack,qobject_cast<State*>(r->getTargetState()));
            }
        }else{
            if(exp.count()>0&&r->getEvalChar()==tExp.at(0)){
                if(r->getStackOut()=="*"){

                    if(r->getStackIn()!="*"&&r->getStackIn()!="#"){
                         tStack=tStack.prepend(reverse(r->getStackIn()));
                    }
                    acp=acp||recEval(tExp.remove(0,1),tStack,qobject_cast<State*>(r->getTargetState()));
                }else if(r->getStackOut()=="#"&&tStack.count()==0){
                    if(r->getStackIn()!="*"&&r->getStackIn()!="#"){
                         tStack=tStack.prepend(reverse(r->getStackIn()));
                    }
                    acp=acp||recEval(tExp.remove(0,1),tStack,qobject_cast<State*>(r->getTargetState()));
                }else if(stack.count()>0&&r->getStackOut()==stack.at(0)){
                    tStack=tStack.remove(0,1);
                    if(r->getStackIn()!="*"&&r->getStackIn()!="#"){
                         tStack=tStack.prepend(reverse(r->getStackIn()));
                    }
                    acp=acp||recEval(tExp.remove(0,1),tStack,qobject_cast<State*>(r->getTargetState()));
                }
            }
        }
        if(acp){
            break;
        }
    }
    return acp;
}



