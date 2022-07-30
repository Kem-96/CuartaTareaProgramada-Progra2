#include "tienda_local.h"

#include <iostream>
#include <cstring>
Tienda_local::Tienda_local(string nombre, string direccionInternet, string direccionFisica, string telef)
{
    strcpy(this->nombreTienda, nombre.c_str());
    strcpy(this->direccionInternet, direccionInternet.c_str());
    strcpy(this->direccionFisica, direccionFisica.c_str());
    strcpy(this->telefono, telef.c_str());

}

Tienda_local::Tienda_local()
{

}



void Tienda_local::AgregarProducto(Productos *nuevoProducto)
{
    this->productos.push_back(nuevoProducto);
}

void Tienda_local::Guardar(ostream *streamSalida)
{
    for (Productos *producto : this->productos)
    {
        streamSalida->write((char *)producto, sizeof(Productos));
    }
}

void Tienda_local::CargarPorPosicionDesdeStreamBinario(istream *streamEntrada, int posicion)
{
    streamEntrada->seekg(sizeof(productos) * posicion);

    Productos *producto = new Productos();
    streamEntrada->read((char *)producto, sizeof(Productos));

    this->AgregarProducto(producto);
}

void Tienda_local::CargarDesdeStreamBinario(istream *streamEntrada)
{
    // Calcule cantidad de registros
    streamEntrada->seekg( 0, std::ios::end );
    int cantidadBytesEnArchivo = streamEntrada->tellg();
    int cantidadProductos = cantidadBytesEnArchivo / sizeof(Productos);

    // Leer cada empleado
    streamEntrada->seekg( 0, std::ios::beg ); // Empezar desde el principio del archivo
    for (int indice = 0; indice < cantidadProductos; indice++)
    {
        Productos *producto = new Productos();
        streamEntrada->read((char *)producto, sizeof(Productos)); // variable para guardar y cuántos bytes leo

        this->AgregarProducto(producto);
    }

}

string Tienda_local::Consultar(){
    string resultado;
    for(Productos* producto : productos){
        resultado += producto->getProducto();
        resultado += "\n";;
    }
}

ostream& operator << (ostream &o, const Tienda_local *tienda)
{
    o << "Tienda: " << std::endl;

    for (Productos *producto : tienda->productos)
    {
        o << producto << endl;
    }

    return o;

}
