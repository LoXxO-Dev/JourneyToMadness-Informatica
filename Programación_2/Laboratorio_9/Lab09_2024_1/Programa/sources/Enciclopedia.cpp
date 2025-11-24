//
// Created by User on 23/11/2025.
//

#include "Enciclopedia.hpp"

void Enciclopedia::leer(ifstream &arch) {
    Libro::leer(arch);
    arch>>sku;
    arch.get();
    arch>>anho;

}

void Enciclopedia::imprimir(ofstream &arch) {
    Libro::imprimir(arch);
    arch<<"SKU: "<<left<<setw(10)<<sku<<
        "Año: "<<anho<<endl;

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
