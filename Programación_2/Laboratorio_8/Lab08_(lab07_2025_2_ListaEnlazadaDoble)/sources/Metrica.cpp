//
// Created by User on 20/11/2025.
//

#include "Metrica.hpp"

void Metrica::leer(ifstream &archivo) {
    archivo >> id;
    archivo.get();
    getline(archivo, descripcion, ',');
    int dd, mm, aa;
    char car;
    archivo >> aa >> car >> mm >> car >> dd >> car;
    fecha_calculo = aa * 10000 + mm * 100 + dd;
    archivo >> aa >> car >> mm >> car >> dd >> car;
    fecha_expiracion = aa * 10000 + mm * 100 + dd;
    if (20251120 > fecha_expiracion) estado = false;
    else estado = true;
}

void Metrica::imprimir(ofstream &arch) {
    arch<<setw(10)<<left<<id<<right<<setw(10)<<fecha_calculo
    <<setw(10)<<fecha_expiracion<<setw(10)<<" "<<left<<setw(15);
    if (estado)
        arch<<"ACTIVA";
    else arch<<"EXPIRADA";
}

int Metrica::get_id() const {
    return id;
}

void Metrica::set_id(int id) {
    this->id = id;
}

string Metrica::get_descripcion() const {
    return descripcion;
}

void Metrica::set_descripcion(const string &descripcion) {
    this->descripcion = descripcion;
}

int Metrica::get_fecha_calculo() const {
    return fecha_calculo;
}

void Metrica::set_fecha_calculo(int fecha_calculo) {
    this->fecha_calculo = fecha_calculo;
}

int Metrica::get_fecha_expiracion() const {
    return fecha_expiracion;
}

void Metrica::set_fecha_expiracion(int fecha_expiracion) {
    this->fecha_expiracion = fecha_expiracion;
}

bool Metrica::is_estado() const {
    return estado;
}

void Metrica::set_estado(bool estado) {
    this->estado = estado;
}
