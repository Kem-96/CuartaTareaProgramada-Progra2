#ifndef FORMTIENDA_H
#define FORMTIENDA_H

#include <QDialog>

namespace Ui {
class FormTienda;
}

class FormTienda : public QDialog
{
    Q_OBJECT

public:
    explicit FormTienda(QWidget *parent = nullptr);
    ~FormTienda();

    void CargarInformacion(std::string nombre, std::string direccionInternet, std::string direccionFisica, int telefono);

    std::string ObtenerNombre();
    std::string ObtenerDireccionInternet();
    std::string ObtenerDireccionFisica();
    std::string ObtenerTelefono();

private slots:
    void on_buttonBox_Tienda_accepted();

private:
    Ui::FormTienda *ui;
};

#endif // FORMTIENDA_H


