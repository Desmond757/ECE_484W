#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QImage adjust_Brightness(QImage &picture, int factor);
    QImage adjust_Contrast(QImage &picture, int factor);

private slots:

    void on_pushButton_1_clicked();

    void on_reset_button_clicked();

    void on_save_button_clicked();

    void on_vertical_slider_brightness_valueChanged(int value);

    void on_vertical_slider_contrast_valueChanged(int value);

private:
    Ui::MainWindow *ui;   
    void sendtoUDP(const QByteArray &data);
    QUdpSocket *udpSocket, *udpSocket_send;
    QImage image1, image2;
};
#endif // MAINWINDOW_H
