//
// Created by User on 2/11/2025.
//

#include "Libro.hpp"

Libro::Libro() {
    codigo=nullptr;
    nombre=nullptr;
    colocado=false;
}

Libro::~Libro() {
    if (codigo)delete codigo;
    if (nombre)delete nombre;
}

void Libro::leer(ifstream &arch) {
    char aux[100];
    arch.getline(aux, 100,',');
    set_codigo(aux);
    arch.getline(aux, 100,',');
    set_nombre(aux);
    arch>>ancho;
    arch.get();
    arch>>alto;
    arch.get();

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

double Libro::get_peso() const {
    return peso;
}

void Libro::set_peso(double peso) {
    this->peso = peso;
}

bool Libro::is_colocado() const {
    return colocado;
}

void Libro::set_colocado(bool colocado) {
    this->colocado = colocado;
}
