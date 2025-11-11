//
// Created by User on 11/11/2025.
//

#include "Revista.hpp"

void Revista::leer(ifstream &arch) {
    Libro::leer(arch);
    arch >> ISSN;
    arch.get();
    arch >> anho;
    arch.get();
    arch >> numero;
}

void Revista::imprime(ofstream &arch) {
    Libro::imprime(arch);
    arch << left << "ISSN:" << setw(15) << ISSN << "Año:"
            << setw(15) << anho << "Numero:" << setw(15) << numero
            << "Vigencia:" << vigencia << endl << endl;
}

void Revista::actualiza() {
    if (anho <= 2020)vigencia = 0;
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

int Revista::get_vigencia() const {
    return vigencia;
}

void Revista::set_vigencia(int vigencia) {
    this->vigencia = vigencia;
}
