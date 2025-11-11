//
// Created by User on 11/11/2025.
//

#include "DetalleComanda.hpp"

#include "Bebida.hpp"
#include "Nodo.hpp"
#include "PlatoFondo.hpp"
#include "Entrada.hpp"
#include "Bebida.hpp"

void DetalleComanda::leer(ifstream &archivo, int id) {
    char car;
    set_id(id);
    archivo.get();
    archivo >> car;
    archivo.get();
    if (car == 'B')
        pedido = new class Bebida();
    else if (car == 'E')
        pedido = new class Entrada();
    else if (car == 'P')
        pedido = new class PlatoFondo();
    pedido->leer(archivo);
}

void DetalleComanda::imprimir(ofstream &arch) {
    arch << "Codigo de comanda:" << id << endl;
    pedido->imprimir(arch);
    arch << endl << endl;
}

DetalleComanda::~DetalleComanda() {
    pedido = nullptr;
}

int DetalleComanda::get_id() const {
    return id;
}

void DetalleComanda::operator =(class DetalleComanda &orig) {
    id = orig.id;
    this->pedido = orig.pedido;
}

void DetalleComanda::set_id(int id) {
    this->id = id;
}

bool DetalleComanda::verifica(int num) {
    return pedido->verificar(num);
}
