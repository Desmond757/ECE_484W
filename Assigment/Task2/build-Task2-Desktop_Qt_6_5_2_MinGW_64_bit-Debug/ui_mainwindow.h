/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_6;
    QFormLayout *formLayout_2;
    QSlider *vertical_slider_contrast;
    QLabel *label_picture2;
    QLabel *label_picture1;
    QGroupBox *groupBox_7;
    QPushButton *reset_button;
    QPushButton *save_button;
    QPushButton *pushButton_1;
    QGroupBox *groupBox_3;
    QFormLayout *formLayout;
    QSlider *vertical_slider_brightness;
    QSlider *verticalSlider;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(943, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(780, 210, 90, 116));
        formLayout_2 = new QFormLayout(groupBox_6);
        formLayout_2->setObjectName("formLayout_2");
        vertical_slider_contrast = new QSlider(groupBox_6);
        vertical_slider_contrast->setObjectName("vertical_slider_contrast");
        vertical_slider_contrast->setMinimum(-100);
        vertical_slider_contrast->setMaximum(100);
        vertical_slider_contrast->setPageStep(1);
        vertical_slider_contrast->setValue(0);
        vertical_slider_contrast->setSliderPosition(0);
        vertical_slider_contrast->setOrientation(Qt::Vertical);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, vertical_slider_contrast);

        label_picture2 = new QLabel(centralwidget);
        label_picture2->setObjectName("label_picture2");
        label_picture2->setGeometry(QRect(430, 60, 302, 306));
        label_picture1 = new QLabel(centralwidget);
        label_picture1->setObjectName("label_picture1");
        label_picture1->setEnabled(true);
        label_picture1->setGeometry(QRect(70, 50, 303, 306));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_picture1->sizePolicy().hasHeightForWidth());
        label_picture1->setSizePolicy(sizePolicy);
        groupBox_7 = new QGroupBox(centralwidget);
        groupBox_7->setObjectName("groupBox_7");
        groupBox_7->setGeometry(QRect(270, 430, 251, 71));
        reset_button = new QPushButton(groupBox_7);
        reset_button->setObjectName("reset_button");
        reset_button->setGeometry(QRect(20, 40, 80, 18));
        save_button = new QPushButton(groupBox_7);
        save_button->setObjectName("save_button");
        save_button->setGeometry(QRect(120, 40, 80, 18));
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setGeometry(QRect(20, 10, 297, 24));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(780, 60, 84, 117));
        formLayout = new QFormLayout(groupBox_3);
        formLayout->setObjectName("formLayout");
        vertical_slider_brightness = new QSlider(groupBox_3);
        vertical_slider_brightness->setObjectName("vertical_slider_brightness");
        vertical_slider_brightness->setMinimum(-100);
        vertical_slider_brightness->setMaximum(100);
        vertical_slider_brightness->setSingleStep(1);
        vertical_slider_brightness->setPageStep(1);
        vertical_slider_brightness->setValue(0);
        vertical_slider_brightness->setOrientation(Qt::Vertical);

        formLayout->setWidget(0, QFormLayout::LabelRole, vertical_slider_brightness);

        verticalSlider = new QSlider(centralwidget);
        verticalSlider->setObjectName("verticalSlider");
        verticalSlider->setGeometry(QRect(780, 360, 16, 160));
        verticalSlider->setOrientation(Qt::Vertical);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 943, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "Contrast", nullptr));
        label_picture2->setText(QString());
        label_picture1->setText(QString());
        groupBox_7->setTitle(QString());
        reset_button->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        save_button->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "Choose Image", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Brightness", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
