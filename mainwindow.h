#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <pdautomaton.h>
#include <QTreeWidgetItem>
#include <qdebug.h>
#include <QSvgWidget>
#include <QDir>
#include "graphsvg.h"

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
    void addState();
    void addRule();
    void removeState();
    void evaluateExp();
    void refresh();
private:
    Ui::MainWindow *ui;
    PDAutomaton *pdAutomaton;
    bool haveInitState;
    GraphSvg *graph;
};

#endif // MAINWINDOW_H
