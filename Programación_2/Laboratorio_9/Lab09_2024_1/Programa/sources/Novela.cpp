//
// Created by User on 23/11/2025.
//

#include "Novela.hpp"

void Novela::leer(ifstream &arch) {
    Libro::leer(arch);
    getline(arch,autor,'\n');
}

void Novela::imprimir(ofstream &arch) {
    Libro::imprimir(arch);
    arch<<"Autor: "<<autor<<endl;
}

string Novela::get_autor() const {
    return autor;
}

void Novela::set_autor(const string &autor) {
    this->autor = autor;
}
