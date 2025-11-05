//
// Created by User on 5/11/2025.
//

#include "Categoria.hpp"

Categoria::Categoria() {
    codigo = nullptr;
    nombre = nullptr;
}

void Categoria::leer(ifstream &arch) {
    char aux[100];
    arch>>aux;
    if (arch.eof())return;
    set_codigo(aux);
    arch>>aux;
    set_nombre(aux);
}

Categoria::~Categoria() {
    if (codigo != nullptr)delete this->codigo;
    if (nombre != nullptr)delete this->nombre;
}

Categoria::Categoria(const Categoria &cate) {
    codigo = nullptr;
    nombre = nullptr;
    *this=cate;
}

void Categoria::operator=(const Categoria &cate) {
    char aux[100];
    cate.get_nombre(aux);
    set_nombre(aux);
    cate.get_codigo(aux);
    set_codigo(aux);
}

void Categoria::get_codigo(char *codigo) const {
    if (this->codigo ==nullptr)codigo[0]=0;
    else strcpy(codigo,this->codigo);
}

void Categoria::set_codigo(const char *codigo) {
    if (this->codigo !=nullptr)delete this->codigo;
    this->codigo = new char[strlen(codigo)+1];
    strcpy(this->codigo,codigo);
}

void  Categoria::get_nombre(char *nombre) const {
    if (this->nombre ==nullptr)nombre[0]=0;
    else strcpy(nombre,this->nombre);
}

void Categoria::set_nombre(const char *nombre) {
    if (this->nombre !=nullptr)delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

void operator>>(ifstream &arch, Categoria &cate) {
    cate.leer(arch);
}
