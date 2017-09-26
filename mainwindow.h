#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <automatapila.h>
#include <QTreeWidgetItem>
#include <qdebug.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void agregarEstado();
    void actualizarVistas();
    void agregarRegla();
    void eliminarEstado();
    void evaluarExpresion();
private:
    Ui::MainWindow *ui;
    AutomataPila *automata;
    bool estadoInicial;
};

#endif // MAINWINDOW_H
