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

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::agregarEstado()
{
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

void MainWindow::agregarRegla()
{
    if(ui->lEstados1->count()>0&&ui->lEval->text().length()>0&&
            ui->lSale->text().length()>0&&ui->lEntra->text().length()>0){

        int estado1 = ui->lEstados1->currentRow();
        int estado2 = ui->lEstados2->currentRow();

        QChar eval = ui->lEval->text().at(0);
        QChar sale = ui->lSale->text().at(0);
        QChar entra = ui->lEntra->text().at(0);

        automata->obtenerEstado(1)->agregarRegla(new Transicion(eval,sale,entra,automata->obtenerEstado(estado2)));
        QTreeWidgetItem* item = new QTreeWidgetItem();
        item->setText(0,ui->lEstados2->currentItem()->text());
        item->setText(1,eval);
        item->setText(2,entra);
        item->setText(3,sale);
        ui->treeWidget->topLevelItem(estado1)->addChild(item);
    }
}

void MainWindow::actualizarVistas()
{

}



