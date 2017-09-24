#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <automatapila.h>

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


private:
    Ui::MainWindow *ui;
    AutomataPila *automata;
    bool estadoInicial;
};

#endif // MAINWINDOW_H
