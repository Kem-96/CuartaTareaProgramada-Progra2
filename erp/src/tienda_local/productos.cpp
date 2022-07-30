#include "productos.h"
#include <iostream>
#include <cstring>

Productos::Productos(int id, string nombre, int existencias)
{
    this->idProducto = id;
    strcpy(this->nombreProducto, nombre.c_str());
    this->existenciasEnTienda = existencias;
}

Productos::Productos()
{

}

string Productos::getProducto(){
    string resultado;
    resultado += this->idProducto + this->nombreProducto + this->existenciasEnTienda;
    return resultado;
}

ostream& operator << (ostream &o, const Productos *producto)
{
    o << "[" << producto->idProducto << "] - " << producto->nombreProducto << " " << producto->existenciasEnTienda;
    return o;
}
