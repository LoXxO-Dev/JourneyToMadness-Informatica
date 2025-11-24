//
// Created by User on 23/11/2025.
//

#include "Revista.hpp"

void Revista::leer(ifstream &arch) {
    Libro::leer(arch);
    arch>>ISSN;
    arch.get();
    arch>>anho;
    arch.get();
    arch>>numero;
}

void Revista::imprimir(ofstream &arch) {
    Libro::imprimir(arch);
    arch<<"ISSN: "<<left<<setw(10)<<ISSN<<
        "Año: "<<setw(10)<<anho
    <<"Número: "<<numero<<endl;
}

int Revista::get_issn() const {
    return ISSN;
}

void Revista::set_issn(int issn) {
    ISSN = issn;
}

int Revista::get_anho() const {
    return anho;
}

void Revista::set_anho(int anho) {
    this->anho = anho;
}

int Revista::get_numero() const {
    return numero;
}

void Revista::set_numero(int numero) {
    this->numero = numero;
}
