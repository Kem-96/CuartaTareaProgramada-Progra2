#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qlistwidget.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_Consultar_clicked();

    void on_listaEditable_Consulta_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);


    void on_pushButton_agregarProducto_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
