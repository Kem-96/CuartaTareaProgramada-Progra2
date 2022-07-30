#include "formProducto.h"
#include "ui_formProducto.h"

#include "./../tienda_local/tienda_local.h""
#include <QMessageBox>
#include <QFileDialog>
#include "formProducto.h"
#include <sstream>
#include <fstream>

formProducto::formProducto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formProducto)
{
    ui->setupUi(this);
}

formProducto::~formProducto()
{
    delete ui;
}

void formProducto::CargarInformacion(int id, std::string nombre, int existencias)
{
    QString stringID = QString::number(id);
    this->ui->lineEdit_ID_Producto->setText(stringID);
    this->ui->lineEdit_ID_Producto->setReadOnly(true);

    QString stringNombre = QString::fromStdString(nombre);
    this->ui->lineEdit_Nombre_Producto->setText(stringNombre);

    QString stringExistencias = QString::number(existencias);
    this->ui->lineEdit_Existencias_Producto->setText(stringExistencias);
    this->ui->lineEdit_Existencias_Producto->setReadOnly(true);
}

int formProducto::ObtenerID()
{
    QString stringID = this->ui->lineEdit_ID_Producto->text();
    int id = stringID.toInt();
    return id;
}

std::string formProducto::ObtenerNombre()
{
    QString stringNombre = this->ui->lineEdit_Nombre_Producto->text();
    std::string nombre = stringNombre.toStdString();
    return nombre;
}

int formProducto::ObtenerExistencias()
{
    QString stringExistencias = this->ui->lineEdit_Existencias_Producto->text();
    int existencias = stringExistencias.toInt();

    return existencias;
}


void formProducto::on_buttonBox_producto_accepted()
{
    formProducto formProducto {this};
    int result = formProducto.exec();

    if (result == QDialog::Accepted) {

        int id = formProducto.ObtenerID();
        std::string nombre = formProducto.ObtenerNombre();
        int existencias = formProducto.ObtenerExistencias();

        // Acá llamamos a la biblioteca
        /*try {
            Tienda *tienda = new Tienda();
            Productos *producto1 = new Productos(id, nombre, existencias);
            tienda->AgregarProducto(producto1);
        }
        catch (ExcepcionDatosInvalidosProducto &e) {
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Título del diálogo");
            msgbox->setText("Datos de producto inválido");
            msgbox->open();
        }*/
         // comenmtar
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Título del diálogo");
        msgbox->setText(QString::fromStdString(nombre));
        msgbox->open();
    }

}
