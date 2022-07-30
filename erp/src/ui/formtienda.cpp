#include "formtienda.h"
#include "ui_formtienda.h"


#include "./../Tienda_local/tienda.h"
#include <QMessageBox>
#include <QFileDialog>
#include <sstream>
#include <fstream>

FormTienda::FormTienda(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormTienda)
{
    ui->setupUi(this);
}

FormTienda::~FormTienda()
{
    delete ui;
}


void FormTienda::CargarInformacion(std::string nombre, std::string direccionInternet, std::string direccionFisica, int telefono)
{

    QString stringNombre = QString::fromStdString(nombre);
    this->ui->lineEdit_Nombre_tienda->setText(stringNombre);

    QString stringDireccionInternet = QString::fromStdString(direccionInternet);
    this->ui->lineEdit_Direccion_internet_tienda->setText(stringDireccionInternet);

    QString stringDireccionFisica = QString::fromStdString(direccionFisica);
    this->ui->lineEdit_Direccion_Fisica_tienda->setText(stringDireccionFisica);

    QString stringTelefono = QString::number(telefono);
    this->ui->lineEdit_Telefono_tienda->setText(stringTelefono);
    this->ui->lineEdit_Telefono_tienda->setReadOnly(true);
}


std::string FormTienda::ObtenerNombre()
{
    QString stringNombre = this->ui->lineEdit_Nombre_tienda->text();
    std::string nombre = stringNombre.toStdString();
    return nombre;
}

std::string FormTienda::ObtenerDireccionInternet()
{
    QString stringDireccionInternet = this->ui->lineEdit_Direccion_internet_tienda->text();
    std::string direccionInternet = stringDireccionInternet.toStdString();

    return direccionInternet;
}

std::string FormTienda::ObtenerDireccionFisica()
{
    QString stringDireccionFisica = this->ui->lineEdit_Direccion_Fisica_tienda->text();
    std::string direccionFisica = stringDireccionFisica.toStdString();

    return direccionFisica;
}

std::string FormTienda::ObtenerTelefono()
{
    QString stringTelefono = this->ui->lineEdit_Telefono_tienda->text();
    std::string telefono = stringTelefono.toStdString();
    return telefono;
}

void FormTienda::on_buttonBox_Tienda_accepted()
{
    FormTienda FormTienda {this};
    int result = FormTienda.exec();

    if (result == QDialog::Accepted) {

        std::string nombre = FormTienda.ObtenerNombre();
        std::string direccionInternet = FormTienda.ObtenerDireccionInternet();
        std::string direccionFisica = FormTienda.ObtenerDireccionFisica();
        std::string telefono = FormTienda.ObtenerTelefono();

        // Acá llamamos a la biblioteca
        //try {
            Tienda *tienda = new Tienda(nombre, direccionInternet, direccionFisica, telefono);

        //}
        //catch ( Exception &e) {
           // QMessageBox *msgbox = new QMessageBox(this);
           // msgbox->setWindowTitle("Título del diálogo");
           // msgbox->setText("Datos de producto inválido");
           // msgbox->open();
        //}
         // comenmtar
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Título del diálogo");
        msgbox->setText(QString::fromStdString(nombre));
        msgbox->open();
    }
}

