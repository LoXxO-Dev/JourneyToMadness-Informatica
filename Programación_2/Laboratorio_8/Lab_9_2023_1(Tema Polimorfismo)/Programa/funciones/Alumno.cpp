//
// Created by User on 29/10/2025.
//
#include "Alumno.hpp"

Alumno::Alumno() {
    nombre = nullptr;
    total = 0;
}

Alumno::~Alumno() {
    if (this->nombre != nullptr)delete [] this->nombre;
}

void Alumno::lee(ifstream &arch) {
    char aux[100];
    arch >> codigo;
    arch.get();
    arch.getline(aux, 100, ',');
    set_nombre(aux);
    arch >> escala;
    arch.get();
    arch >> creditos;
    arch.get();
}

void Alumno::imprime(ofstream &arch) {
    char aux[100];
    get_nombre(aux);
    arch<<left<<setw(20)<<codigo<<setw(50)<<aux<<right<<setw(5)<<
        escala<<setw(10)<<creditos;
}
int Alumno::buscarEscala(Escala *arreEscala,int escala) {
    for (int i=0;i<5;i++)
        if (arreEscala[i].get_codigo()==escala)
            return i;
    return -1;
}

int Alumno::get_codigo() const {
    return codigo;
}

void Alumno::set_codigo(int codigo) {
    this->codigo = codigo;
}

void Alumno::get_nombre(char *nombre) const {
    if (this->nombre == nullptr)nombre[0] = 0;
    else strcpy(nombre, this->nombre);
}

void Alumno::set_nombre(const char *nombre) {
    if (this->nombre != nullptr)delete [] this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

int Alumno::get_escala() const {
    return escala;
}

void Alumno::set_escala(int escala) {
    this->escala = escala;
}

double Alumno::get_creditos() const {
    return creditos;
}

void Alumno::set_creditos(double creditos) {
    this->creditos = creditos;
}

double Alumno::get_total() const {
    return total;
}

void Alumno::set_total(double total) {
    this->total = total;
}
