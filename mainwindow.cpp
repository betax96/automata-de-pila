#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    automata = new AutomataPila();
    estadoInicial = false;
    connect(ui->bAgregarEstado,SIGNAL(clicked()),this,SLOT(agregarEstado()));
    connect(ui->bAgregarRegla,SIGNAL(clicked()),this,SLOT(agregarRegla()));
    connect(ui->bEliminar,SIGNAL(clicked()),this,SLOT(eliminarEstado()));
    connect(ui->bEvaluar,SIGNAL(clicked()),this,SLOT(evaluarExpresion()));
    /*automata->agregarEstado(new Estado("e1",Estado::TIPO_INICIAL));
    automata->agregarEstado(new Estado("e2",Estado::TIPO_ACEPTACION));
    automata->obtenerEstado(0)->agregarRegla(new Transicion('*','#','a',automata->obtenerEstado(0)));
    automata->obtenerEstado(0)->agregarRegla(new Transicion('a','a','b',automata->obtenerEstado(1)));
    automata->obtenerEstado(1)->agregarRegla(new Transicion('b','b','a',automata->obtenerEstado(0)));
    automata->obtenerEstado(1)->agregarRegla(new Transicion('b','a','a',automata->obtenerEstado(1)));

    ui->lExpresion->setText("ababa");*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::agregarEstado()
{
    if(ui->lineEdit->text().length()>0){
        QString nombre = ui->lineEdit->text();
        int tipo = Estado::TIPO_NORMAL;
        if(!estadoInicial){
            tipo = Estado::TIPO_INICIAL;
            estadoInicial = true;
        }else{
            if(ui->rAceptacion->isChecked()){
                tipo = Estado::TIPO_ACEPTACION;
            }
        }
        automata->agregarEstado(new Estado(nombre,tipo));
        ui->lEstados1->addItem(nombre);
        ui->lEstados2->addItem(nombre);
        QTreeWidgetItem* item = new QTreeWidgetItem();
        item->setText(0,nombre);
        ui->treeWidget->addTopLevelItem(item);
    }
     automata->printDebug();

}

void MainWindow::eliminarEstado(){

    if(ui->treeWidget->topLevelItemCount()>0){
        int itemRow = ui->treeWidget->currentIndex().row();
        if(ui->treeWidget->selectedItems().at(0)->parent()==NULL){

            delete ui->lEstados1->item(itemRow);
            delete ui->lEstados2->item(itemRow);
            delete ui->treeWidget->selectedItems().at(0);
            automata->removerEstado(itemRow);
            if(automata->estadosCount()==0){
                estadoInicial = false;
            }
        }else{

            int topRow = ui->treeWidget->indexOfTopLevelItem(ui->treeWidget->selectedItems().at(0)->parent());
            automata->obtenerEstado(topRow)->removerRegla(itemRow);
            delete ui->treeWidget->selectedItems().at(0);
        }

    }

}

void MainWindow::agregarRegla()
{
    if(ui->lEstados1->count()>0&&ui->lEval->text().length()>0&&
            ui->lSale->text().length()>0&&ui->lEntra->text().length()>0){

        int estado1 = ui->lEstados1->currentRow();
        int estado2 = ui->lEstados2->currentRow();

        QChar eval = ui->lEval->text().at(0);
        QChar sale = ui->lSale->text().at(0);
        QChar entra = ui->lEntra->text().at(0);

        automata->obtenerEstado(estado1)->agregarRegla(new Transicion(eval,sale,entra,automata->obtenerEstado(estado2)));
        QTreeWidgetItem* item = new QTreeWidgetItem();
        item->setText(0,ui->lEstados2->currentItem()->text());
        QString text2 = ui->lEval->text()+"/"+ui->lSale->text()+"/"+ui->lEntra->text();
        item->setText(1,text2);
        ui->treeWidget->topLevelItem(estado1)->addChild(item);
    }

}

void MainWindow::evaluarExpresion(){
    QString exp = ui->lExpresion->text();
    int result = automata->evaluarExpresion(exp);
    switch(result){
    case 0:
        ui->lEvalResult->setText("Expresion no valida");
        break;
    case 1:
        ui->lEvalResult->setText("Expresion aceptada");
        break;
    default:
        ui->lEvalResult->setText("Error");
    }
}

void MainWindow::actualizarVistas()
{

}



