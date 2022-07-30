#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <string>
#include <fstream>
#include <sstream>
#include "./../Tienda_local/tienda.h"
#include "./../Tienda_local/productos.h"
#include "formProducto.h"
#include "formtienda.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_agregarProducto, SIGNAL(clicked()), this, SLOT(on_pushButton_agregarProducto_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_listaEditable_Consulta_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{

    std::ifstream archivoEntrada;
    archivoEntrada.open("archivo_test.dat", std::ios::in|std::ios::binary);

    if (!archivoEntrada.is_open())
    {
        // QMessageBox *msgbox = new QMessageBox(this);
        // msgbox->setWindowTitle("Título del diálogo");
        // msgbox->setText("No se pudo abrir archivo archivo_test.dat para escribir los datos");
        // msgbox->open();
    }

    Tienda *tiendaLeida = new Tienda();
    tiendaLeida->CargarDesdeStreamBinario(&archivoEntrada);


    int id = this->ui->listaEditable_Consulta->count();
    QString opcion = QString::fromStdString(tiendaLeida->Consultar());
    QListWidgetItem *itemNuevo = new QListWidgetItem(opcion);


    this->ui->listaEditable_Consulta->addItem(itemNuevo);



    itemNuevo->setData(id, opcion);

    this->ui->listaEditable_Consulta->addItem(itemNuevo);
}





void MainWindow::on_pushButton_agregarProducto_clicked()
{
    formProducto w(this);
         int t = w.exec();

          if (t == QDialog::Accepted){
               //aquí va código en caso de que la ventana siguiente
               //se haya cerrado al hacer clic en Aceptar (si lo tiene)

                //here goes code in case you clicked accept

            }
}

