#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QFileDialog>
#include <QPixmap>
#include <QLabel>
#include <QPainter>
#include <QUdpSocket>
#include <QHostAddress>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    udpSocket = new QUdpSocket(this);
   /* udpSocket_send = new QUdpSocket(this);
    udpSocket -> bind(QHostAddress("127.0.0.1"), 115200, QUdpSocket::ShareAddress);*/

    connect(ui -> vertical_slider_brightness, SIGNAL(valueChanged(int)), this, SLOT(on_vertical_slider_brightness_valueChanged(int)));
    connect(ui -> vertical_slider_contrast, SIGNAL(valueChanged(int)), this, SLOT(on_vertical_slider_contrast_valueChanged(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sendtoUDP(const QByteArray &data){
    QHostAddress targetAddress("12.0.0.1"); // IP address
    quint16 targetPort = 0x00000100;
    udpSocket ->writeDatagram(data, targetAddress, targetPort);
}
void MainWindow::on_pushButton_1_clicked()
{
    {

        QString filename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images (*.bmp)"));

        if(QString::compare(filename, QString()) != 0) {

            bool valid = image2.load(filename);

            if(valid){

                ui->label_picture1->setPixmap(QPixmap::fromImage(image2));

                ui->label_picture2->setPixmap(QPixmap::fromImage(image2));
            }
        }
    }
}

QImage MainWindow::adjust_Brightness(QImage &picture, int factor)
{
    double red, green, blue;
    int pixels;
    unsigned int *data;
    pixels = picture.width() * picture.height();
    data = (unsigned int *)picture.bits();
    for (int i = 0; i < pixels; ++i)
    {
        red= qRed(data[i])+ factor;
        red = (red < 0x00) ? 0x00 : (red > 0xff) ? 0xff : red;
        green= qGreen(data[i])+factor;
        green = (green < 0x00) ? 0x00 : (green > 0xff) ? 0xff : green;
        blue= qBlue(data[i])+factor;
        blue =  (blue  < 0x00) ? 0x00 : (blue  > 0xff) ? 0xff : blue ;
        data[i] = qRgba(red, green, blue, qAlpha(data[i]));
    }
    return picture;
}



QImage MainWindow::adjust_Contrast(QImage &picture, int factor)
{
    double contrast;
    double red, green, blue;
    int pixels;
    unsigned int *data;
    contrast = (100.0+factor)/100.0;
    pixels = picture.width()*picture.height();
    data = (unsigned int *)picture.bits();

    //contrast -> newColor = 128 + contrast *(oldColor - 128)
    for (int i = 0; i < pixels; ++i)
    {
        red= 128+ contrast*(qRed(data[i])-128);
        red = (red < 0x00) ? 0x00 : (red > 0xff) ? 0xff : red;
        green= 128+ contrast*(qGreen(data[i])-128);
        green = (green < 0x00) ? 0x00 : (green > 0xff) ? 0xff : green;
        blue= 128+ contrast*(qBlue(data[i])-128);
        blue =  (blue  < 0x00) ? 0x00 : (blue  > 0xff) ? 0xff : blue ;
        data[i] = qRgba(red, green, blue, qAlpha(data[i]));
    }
    return picture;
}
/*void MainWindow::on_groupBox_3_toggled(bool arg1)
{

}*/


void MainWindow::on_reset_button_clicked()
{
    QImage picture;
    QPixmap picturePixmap;
    picture=ui->label_picture1->pixmap().toImage();
    picturePixmap=QPixmap::fromImage(picture);
    ui->label_picture2->setPixmap(picturePixmap);
    ui->vertical_slider_brightness->setValue(0);
    ui->vertical_slider_contrast->setValue(0);
}


void MainWindow::on_save_button_clicked()
{
    QString fullName;

    fullName = QFileDialog::getSaveFileName(this, "Save", "modified_picture.jpg", "*.*");
    if (fullName=="")
    {  return;  }
    ui->label_picture2->pixmap().save(fullName);

}


void MainWindow::on_vertical_slider_brightness_valueChanged(int value)
{
    QImage picture;
    QPixmap picturePixmap;

    picture=ui->label_picture1->pixmap().toImage();
    picture=adjust_Brightness(picture, value);
    picturePixmap=QPixmap::fromImage(picture);
    ui->label_picture2->setPixmap(picturePixmap);
}


void MainWindow::on_vertical_slider_contrast_valueChanged(int value)
{
    QImage picture;
    QPixmap picturePixmap;

    picture=ui->label_picture1->pixmap().toImage();
    picture=adjust_Contrast(picture, value);
    picturePixmap=QPixmap::fromImage(picture);
    ui->label_picture2->setPixmap(picturePixmap);
}

