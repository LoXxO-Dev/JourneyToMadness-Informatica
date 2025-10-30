//
// Created by User on 29/10/2025.
//

#include "Bebida.hpp"

Bebida::Bebida() {
    tamano = nullptr;
}

Bebida::~Bebida() {
    if (this->tamano != nullptr)delete this->tamano;
}

void Bebida::get_tamano(char *tamano) const {
    if (this->tamano == nullptr)tamano[0] = 0;
    else strcpy(tamano, this->tamano);
}

void Bebida::set_tamano(const char *tamano) {
    if (this->tamano != nullptr)delete this->tamano;
    this->tamano = new char[strlen(tamano) + 1];
    strcpy(this->tamano, tamano);
}

void Bebida::leer(ifstream &arch) {
    Producto::leer(arch);
    char aux[100];
    arch.getline(aux,100,'\n');
    set_tamano(aux);

}

void Bebida::imprimir(ofstream &arch) {
    Producto::imprimir(arch);
    char aux[100];
    get_tamano(aux);
    arch<<setw(10)<<" "<<left<<setw(20)<<aux<<endl;
}

void operator<<(ofstream &arch, class Bebida &bed) {
    bed.imprimir(arch);
}
