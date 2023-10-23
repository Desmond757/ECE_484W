#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QFileDialog>
#include <QPixmap>
#include <QLabel>
#include <QPainter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString fileImage = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images (*.png, *.jpg *.jpeg *.bmp)")); // gets existing file selected by user, null if cancel is selected



    if(QString::compare(fileImage, QString()) != 0) {   // checks for null

        bool valid = image1.load(fileImage);           // loads image from file name

        if(valid){                                      // checks if image is valid

                ui->image_label->setPixmap(QPixmap::fromImage(image1)); // displays image to window

        }

    }
}


void MainWindow::on_pushButton_2_clicked()
{
    QString fileImage = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images (*.png, *.jpg *.jpeg *.bmp)")); // gets existing file selected by user, null if cancel is selected



    if(QString::compare(fileImage, QString()) != 0) {   // checks for null

        bool valid = image2.load(fileImage);           // loads image from file name

        if(valid){                                      // checks if image is valid

                ui->image_label_2->setPixmap(QPixmap::fromImage(image2)); // displays image to window

        }

    }
}


void MainWindow::on_pushButton_3_clicked()
{
    QPixmap base = QPixmap::fromImage(image1);         // creates pixmap from loaded image

    QPixmap overlay = QPixmap::fromImage(image2.scaled(200, 200)); // creates pixmap from loaded image scaled to fixed size

    QPixmap result((base.width()-150), (base.height()-150));      // creates pixmap with lenght and height from base image

    result.fill(Qt::transparent); // force alpha channel

    {

        QPainter painter(&result);                            // creates a painter object

        painter.drawPixmap(0, 0, base);                       // draws base image onto the result pixmap

        painter.drawPixmap(0, 0, overlay);                    // draws overlay image onto the result pixmap

    }

    ui->image_label_3->setPixmap(QPixmap(result));            // displays image to window
}


