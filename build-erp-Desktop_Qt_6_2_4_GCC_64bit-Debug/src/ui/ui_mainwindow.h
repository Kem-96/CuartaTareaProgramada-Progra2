/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_agregarProducto;
    QPushButton *pushButton_AgregarTienda;
    QPushButton *pushButton_Guardar;
    QPushButton *pushButton_Consultar;
    QListWidget *listaEditable_Consulta;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_agregarProducto = new QPushButton(centralwidget);
        pushButton_agregarProducto->setObjectName(QString::fromUtf8("pushButton_agregarProducto"));
        pushButton_agregarProducto->setGeometry(QRect(300, 60, 141, 31));
        pushButton_AgregarTienda = new QPushButton(centralwidget);
        pushButton_AgregarTienda->setObjectName(QString::fromUtf8("pushButton_AgregarTienda"));
        pushButton_AgregarTienda->setGeometry(QRect(300, 100, 121, 25));
        pushButton_Guardar = new QPushButton(centralwidget);
        pushButton_Guardar->setObjectName(QString::fromUtf8("pushButton_Guardar"));
        pushButton_Guardar->setGeometry(QRect(300, 140, 151, 25));
        pushButton_Consultar = new QPushButton(centralwidget);
        pushButton_Consultar->setObjectName(QString::fromUtf8("pushButton_Consultar"));
        pushButton_Consultar->setGeometry(QRect(50, 20, 161, 25));
        listaEditable_Consulta = new QListWidget(centralwidget);
        listaEditable_Consulta->setObjectName(QString::fromUtf8("listaEditable_Consulta"));
        listaEditable_Consulta->setGeometry(QRect(20, 60, 251, 201));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_agregarProducto->setText(QCoreApplication::translate("MainWindow", "Agregar Producto", nullptr));
        pushButton_AgregarTienda->setText(QCoreApplication::translate("MainWindow", "Agregar Tienda", nullptr));
        pushButton_Guardar->setText(QCoreApplication::translate("MainWindow", "Guardar Informacion", nullptr));
        pushButton_Consultar->setText(QCoreApplication::translate("MainWindow", "Consultar Informacion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
