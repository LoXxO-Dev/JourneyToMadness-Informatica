//
// Created by User on 11/11/2025.
//

#include "Libro.hpp"

Libro::Libro() {
    nombre=nullptr;
}

Libro::~Libro() {
    if (nombre)delete  nombre;
}

void Libro::leer(ifstream &arch) {
    char aux[100];
    arch.getline(aux,100,',');
    set_nombre(aux);
    arch>>paginas;
    arch.get();
    arch>>peso;
    arch.get();
}

void Libro::imprime(ofstream &arch) {
    char  aux[100];
    get_nombre(aux);
    arch<<"Titulo: "<<nombre<<endl;
    arch<<"Peso: "<<peso<<endl;

}

void  Libro::get_nombre(char *nombre) const {

    if (this->nombre==nullptr)nombre[0]=0;
    else strcpy(nombre,this->nombre);
}

void Libro::set_nombre(const char *nombre) {
    if (this->nombre)delete [] this->nombre;
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

int Libro::get_paginas() const {
    return paginas;
}

void Libro::set_paginas(int paginas) {
    this->paginas = paginas;
}

double Libro::get_peso() const {
    return peso;
}

void Libro::set_peso(double peso) {
    this->peso = peso;
}
