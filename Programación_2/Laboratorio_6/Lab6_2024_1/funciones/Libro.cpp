//
// Created by User on 6/10/2025.
//

#include "Libro.hpp"

Libro::Libro() {
    iniciliza();
}

Libro::Libro(const Libro &copia) {
    iniciliza();

    *this = copia;
}

void Libro::operator =(const Libro &copia) {
    char codigo[10], nombre[50];
    copia.get_codigo(codigo);
    copia.get_nombre(nombre);
    set_codigo(codigo);
    set_nombre(nombre);

    set_ancho(copia.get_ancho());
    set_alto(copia.get_alto());
    set_colocado(copia.is_colocado());
}

void Libro::iniciliza() {
    this->nombre = nullptr;
    this->codigo = nullptr;
}

void Libro::leerLibro(ifstream &archivo) {
    //CCC123, El libro perdido, 11, 5
    char codigo[10], nombre[50], car;

    archivo.getline(codigo, 10, ',');
    if (archivo.eof())return;
    archivo.getline(nombre, 50, ',');
    archivo >> ancho >> car >> alto;
    archivo.get();
    set_codigo(codigo);
    set_nombre(nombre);
    colocado = false;
}

void Libro::imprime(ofstream &archivo) {
    char codigo[10], nombre[50];
    get_nombre(nombre);
    get_codigo(codigo);
    if (colocado)
        archivo << left << setw(10) << codigo << setw(30) << nombre << right
                << setw(5) << ancho << setw(5) << alto << right << endl;
    else
        archivo << left << setw(10) << codigo << setw(30) << "NO SE PUDO COLOCAR" << right
                << setw(5) << ancho << setw(5) << alto << right << endl;
}

void Libro::get_codigo(char *codigo) const {
    if (this->codigo == nullptr)codigo[0] = 0;
    else strcpy(codigo, this->codigo);
}

void Libro::set_codigo(const char *codigo) {
    if (this->codigo != nullptr)delete this->codigo;
    this->codigo = new char[strlen(codigo) + 1];
    strcpy(this->codigo, codigo);
}

void Libro::get_nombre(char *nombre) const {
    if (this->nombre == nullptr)nombre[0] = 0;
    else strcpy(nombre, this->nombre);
}

void Libro::set_nombre(const char *nombre) {
    if (this->nombre != nullptr)delete this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

int Libro::get_ancho() const {
    return ancho;
}

void Libro::set_ancho(int ancho) {
    this->ancho = ancho;
}

int Libro::get_alto() const {
    return alto;
}

void Libro::set_alto(int alto) {
    this->alto = alto;
}

bool Libro::is_colocado() const {
    return colocado;
}

void Libro::set_colocado(bool colocado) {
    this->colocado = colocado;
}

void operator>>(ifstream &arch, class Libro &lib) {
    lib.leerLibro(arch);

}

void operator <<(ofstream &arch, class Libro lib) {
    lib.imprime(arch);
}
