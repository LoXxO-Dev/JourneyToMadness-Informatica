//
// Created by User on 11/11/2025.
//

#include "Estante.hpp"

Estante::Estante() {
}

double Estante::obtenerPeso() {
    return llibros.obtenerTotal();
}

void Estante::inserta(class Libro *aux) {
    llibros.insertar(aux);
}

void Estante::actualiza() {
    llibros.actualiza();
}

void Estante::imprimir(ofstream &arch) {
    arch<<"Id: "<<id<<endl<<"Tipo: ";
    if (clase == 'H') arch<<" Horizontal"<<endl;
    else if (clase == 'V') arch<<" Vertical"<<endl;
    arch<<"Capacidad : "<<capacidad<<endl;
    arch<<"Libros Contenidos:"<<endl;
    imprimirLinea(arch,TAM_LINEA,'=');
    llibros.imprimir(arch);
}

void Estante::leer(ifstream &arch) {
    char cla;
    arch >> cla;
    if (arch.eof()) return;
    clase=cla;
    arch.get();
    arch>>id;
    arch.get();
    arch>>capacidad;
}

char Estante::get_clase() const {
    return clase;
}

void Estante::set_clase(char clase) {
    this->clase = clase;
}

int Estante::get_id() const {
    return id;
}

void Estante::set_id(int id) {
    this->id = id;
}

double Estante::get_capacidad() const {
    return capacidad;
}

void Estante::set_capacidad(double capacidad) {
    this->capacidad = capacidad;
}
