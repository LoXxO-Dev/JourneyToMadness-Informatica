//
// Created by User on 23/11/2025.
//

#include "Libro.hpp"

void Libro::leer(ifstream &arch) {
    getline(arch,nombre,',');
    arch>>paginas;
    arch.get();
    arch>>peso;
    arch.get();
}

void Libro::imprimir(ofstream &arch) {
    arch<<"Titulo:"<<nombre<<endl;
    arch<<"Peso:"<<peso<<endl;
}

string Libro::get_nombre() const {
    return nombre;
}

void Libro::set_nombre(const string &nombre) {
    this->nombre = nombre;
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
