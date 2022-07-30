#ifndef TIENDA_LOCAL_H
#define TIENDA_LOCAL_H

#include "productos.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Tienda_local
{

    protected:

    vector<Productos *> productos;
    char nombreTienda[15]; //15 caracteres
    char direccionInternet[24]; //24 caracteres
    char direccionFisica[24]; // 24 caracteres
    char telefono[8];    //8 caracteres
    public:
        Tienda_local();
        Tienda_local(string nombre, string direccionInternet, string direccionFisica, string telef);
        //~Tienda();
        void Guardar(ostream *streamSalida);
        string Consultar();
        //void GuardarEnStreamBinario(ostream *streamSalida);
        void CargarDesdeStreamBinario(istream *streamEntrada);
        void CargarPorPosicionDesdeStreamBinario(istream *streamEntrada, int posicion);
        void AgregarProducto(Productos *nuevoProducto);

        friend ostream& operator << (ostream &o, const Tienda_local *tienda);
        friend istream& operator >> (istream &o, Tienda_local *tienda);
};

#endif // TIENDA_LOCAL_H

