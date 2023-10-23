#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

}

MainWindow::~MainWindow()
{

    delete ui;
}
