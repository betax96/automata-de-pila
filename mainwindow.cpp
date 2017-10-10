#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pdAutomaton = new PDAutomaton();
    haveInitState = false;
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);
    connect(ui->addStateButton,SIGNAL(clicked()),this,SLOT(addState()));
    connect(ui->addRuleButton,SIGNAL(clicked()),this,SLOT(addRule()));
    connect(ui->removeButton,SIGNAL(clicked()),this,SLOT(removeState()));
    connect(ui->evaluateButton,SIGNAL(clicked()),this,SLOT(evaluateExp()));
    ui->scrollArea->setWidget(ui->svgView);

    QString a = "*";

    if(a != "*"){
        qDebug()<<"asd";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addState()
{
    if(ui->addStateText->text().length()>0){
        QString name = ui->addStateText->text();
        int type = State::TYPE_NORMAL;
        if(ui->radioTypeInit->isChecked()){
            type= State::TYPE_INIT;
            haveInitState = true;
            ui->radioTypeNormal->setChecked(true);
        }else if(ui->radioTypeAccept->isChecked()){
            type= State::TYPE_ACCEPT;
        }
        pdAutomaton->addState(new State(name,type));
        ui->stateList1->addItem(name);
        ui->stateList2->addItem(name);
        QTreeWidgetItem* item = new QTreeWidgetItem();
        item->setText(0,name);
        ui->treeWidget->addTopLevelItem(item);
        refresh();


    }
     pdAutomaton->printDebug();

}

void MainWindow::removeState(){

    if(ui->treeWidget->topLevelItemCount()>0&&ui->treeWidget->selectedItems().count()>0){
        int itemRow = ui->treeWidget->currentIndex().row();
        if(ui->treeWidget->selectedItems().at(0)->parent()==NULL){

            delete ui->stateList1->item(itemRow);
            delete ui->stateList2->item(itemRow);
            delete ui->treeWidget->selectedItems().at(0);
            int tipo = pdAutomaton->getState(itemRow)->getType();
            pdAutomaton->removeState(itemRow);
            if(pdAutomaton->stateCount()==0||tipo == State::TYPE_INIT){
                haveInitState = false;
                ui->radioTypeInit->setDisabled(false);
            }
        }else{

            int topRow = ui->treeWidget->indexOfTopLevelItem(ui->treeWidget->selectedItems().at(0)->parent());
            pdAutomaton->getState(topRow)->removeRule(itemRow);
            delete ui->treeWidget->selectedItems().at(0);
        }
        refresh();

    }

}

void MainWindow::addRule()
{
    if(ui->stateList1->count()>0&&ui->evalCharText->text().length()>0&&
            ui->stackOutText->text().length()>0&&ui->stackInText->text().length()>0&&
            ui->stateList1->selectedItems().count()>0&&
            ui->stateList2->selectedItems().count()>0){

        int state1 = ui->stateList1->currentRow();
        int state2 = ui->stateList2->currentRow();

        QString evalChar = ui->evalCharText->text();
        QString stackOut = ui->stackOutText->text();
        QString stackIn = ui->stackInText->text();
        pdAutomaton->getState(state1)->addRule(new Transition(evalChar,stackOut,stackIn,pdAutomaton->getState(state2)));
        QTreeWidgetItem* item = new QTreeWidgetItem();
        item->setText(0,ui->stateList2->currentItem()->text());
        QString text2 = ui->evalCharText->text()+"/"+ui->stackOutText->text()+"/"+ui->stackInText->text();
        item->setText(1,text2);
        ui->treeWidget->topLevelItem(state1)->addChild(item);
        refresh();

    }

}

void MainWindow::evaluateExp(){
    QString exp = ui->evaluateExpText->text();
    int result = pdAutomaton->evaluateExp(exp);
    switch(result){
    case 0:
        ui->evaluateResultLabel->setText("Expresion no valida");
        break;
    case 1:
        ui->evaluateResultLabel->setText("Expresion aceptada");
        break;
    default:
        ui->evaluateResultLabel->setText("Error");
    }
}

void MainWindow::refresh()
{
    graph = new GraphSvg(QSize(30,30),Color("#000000"),Color("#ffffff"));
    graph->drawAuto(pdAutomaton, Color("#A9F5A9"), Color("#F3F781"));
    graph->saveSvg("graph.i");
    ui->svgView->load(QDir::currentPath()+"/graph.i");
    ui->svgView->adjustSize();
    if(haveInitState){
        ui->radioTypeInit->setDisabled(true);
    }
}



