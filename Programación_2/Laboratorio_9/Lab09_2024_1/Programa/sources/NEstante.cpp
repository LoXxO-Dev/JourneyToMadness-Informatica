//
// Created by User on 23/11/2025.
//

#include "NEstante.hpp"

void NEstante::imprimir(ofstream &arch) {
    arch << "Estante: " << id << endl;
    arch << "Capacidad: " << left << setw(10) << capacidad <<
            "Disponibilidad " << right << setw(5) << disponible << endl;
    imprimir_linea(arch,TAM_LINEA, '=');
    for (auto &x: vlibros) {
        x.imprimir(arch);
        arch << endl;
    }
}

int NEstante::get_id() const {
    return id;
}

void NEstante::set_id(int id) {
    this->id = id;
}

double NEstante::get_capacidad() const {
    return capacidad;
}

void NEstante::set_capacidad(double capacidad) {
    this->capacidad = capacidad;
}

double NEstante::get_disponible() const {
    return disponible;
}

void NEstante::set_disponible(double disponible) {
    this->disponible = disponible;
}

NEstante::NEstante() {
    izq = nullptr;
    der = nullptr;
}

void NEstante::leer(ifstream &arch, int id, ifstream &arch2) {
    this->id = id;
    arch.get();
    arch >> capacidad;
    disponible = capacidad;
    class NLibro libr;
    for (int i = 0; i < 10; i++) {
        libr.leer(arch2, disponible);
        vlibros.push_back(libr);
    }
}
