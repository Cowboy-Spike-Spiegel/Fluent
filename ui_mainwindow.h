/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_select;
    QPushButton *pushButton_start;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_folder;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_select = new QPushButton(centralwidget);
        pushButton_select->setObjectName(QString::fromUtf8("pushButton_select"));
        pushButton_select->setGeometry(QRect(10, 520, 150, 40));
        pushButton_start = new QPushButton(centralwidget);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setGeometry(QRect(490, 520, 150, 40));
        pushButton_stop = new QPushButton(centralwidget);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(640, 520, 150, 40));
        pushButton_folder = new QPushButton(centralwidget);
        pushButton_folder->setObjectName(QString::fromUtf8("pushButton_folder"));
        pushButton_folder->setGeometry(QRect(160, 520, 150, 40));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 741, 471));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_select->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\347\233\256\346\240\207\346\226\207\344\273\266", nullptr));
        pushButton_start->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
        pushButton_folder->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\345\233\276\347\211\207\346\226\207\344\273\266\345\244\271", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
