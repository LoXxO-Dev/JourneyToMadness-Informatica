//
// Created by User on 11/11/2025.
//

#include "Bebida.hpp"

Bebida::Bebida() {
    tamano=nullptr;
}

Bebida::~Bebida() {
    if (tamano)delete [] this->tamano;
}

void Bebida::leer(ifstream &archivo) {
    Producto::leer(archivo);
    char aux[100];
    archivo.get(aux,100,'\n');
    set_tamano(aux);
}

void Bebida::imprimir(ofstream &archivo) {
    Producto::imprimir(archivo);
char aux[100];
    get_tamano(aux);
    archivo<<"Tamano: "<<aux;
}

bool Bebida::verificar(int num) {
    return false;
}

void  Bebida::get_tamano(char *tamano) const {
    if (this->tamano==nullptr)tamano[0]=0;
    else strcpy(tamano,this->tamano);

}

void Bebida::set_tamano(const char *tamano) {

    if (this->tamano)delete [] this->tamano;
    this->tamano = new char[strlen(tamano)+1];
    strcpy(this->tamano,tamano);
}
