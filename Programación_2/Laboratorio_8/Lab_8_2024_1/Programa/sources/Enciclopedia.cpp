//
// Created by User on 11/11/2025.
//

#include "Enciclopedia.hpp"

void Enciclopedia::leer(ifstream &arch) {
    Libro::leer(arch);
     arch>>sku;
    arch.get();
    arch>>anho;
}

void Enciclopedia::actualiza() {
    if (anho<=2020)vigencia=0;

}

void Enciclopedia::imprime(ofstream &arch) {
    Libro::imprime(arch);
    arch<<left<<"Sku:"<<setw(15)<<sku<<"Año:"
        <<setw(15)<<anho<<"Vigencia:"<<setw(15)<<vigencia<<endl<<endl;
}

int Enciclopedia::get_sku() const {
    return sku;
}

void Enciclopedia::set_sku(int sku) {
    this->sku = sku;
}

int Enciclopedia::get_anho() const {
    return anho;
}

void Enciclopedia::set_anho(int anho) {
    this->anho = anho;
}

int Enciclopedia::get_vigencia() const {
    return vigencia;
}

void Enciclopedia::set_vigencia(int vigencia) {
    this->vigencia = vigencia;
}
