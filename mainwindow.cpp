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
    ui->listWidget->addItem(nombre);
    ui->listWidget_2->addItem(nombre);
}

void MainWindow::actualizarVistas()
{

}


