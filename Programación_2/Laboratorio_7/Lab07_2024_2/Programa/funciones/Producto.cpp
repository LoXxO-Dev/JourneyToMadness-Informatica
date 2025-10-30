//
// Created by User on 29/10/2025.
//

#include "Producto.hpp"

Producto::Producto() {
    nombre=nullptr;
}

Producto::~Producto() {
    if (this->nombre!=nullptr)delete this->nombre;
}

void Producto::get_nombre(char *nombre) const {
    if (this->nombre==nullptr)nombre[0]=0;
    else strcpy(nombre,this->nombre);
}

void Producto::set_nombre(const char *nombre) {
    if (this->nombre!=nullptr)delete this->nombre;
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

double Producto::get_precio() const {
    return precio;
}

void Producto::set_precio(double precio) {
    this->precio = precio;
}

void Producto::leer(ifstream &arch) {
    char aux[100];
    arch.getline(aux,100,',');
    this->set_nombre(aux);
    arch>>precio;
    arch.get();

}

void Producto::imprimir(ofstream &arch) {
    char aux[100];
    get_nombre(aux);
    arch<<setw(10)<<" "<<left<<setw(30)<<aux<<right <<setw(5)<<precio;
}
void Producto::imprimir_linea(ofstream &arch, int cant, char car) {
    for (int i=0;i<cant;i++)
        arch.put(car);
    arch<<endl;
}
