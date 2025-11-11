//
// Created by User on 11/11/2025.
//

#include "Producto.hpp"

void  Producto::get_nombre(char *nombre) const {
    if (this->nombre==nullptr)nombre[0]=0;
    else strcpy(nombre,this->nombre);
}

void Producto::set_nombre(const char *nombre) {
    if (this->nombre)delete [] this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

Producto::Producto() {
    nombre=nullptr;
}

Producto::~Producto() {
    if (nombre)delete nombre;
}

void Producto::leer(ifstream &archivo) {
char aux[100];
    archivo.getline(aux,100,',');
    set_nombre(aux);
    archivo>>precio;
    archivo.get();
}

void Producto::imprimir(ofstream &archivo) {
    char aux[100];
    get_nombre(aux);
    archivo<<"Nombre :"<<aux<<endl;
    archivo<<"Precio :"<<precio<<endl;
}

double Producto::get_precio() const {
    return precio;
}

void Producto::set_precio(double precio) {
    this->precio = precio;
}
