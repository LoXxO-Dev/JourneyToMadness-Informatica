//
// Created by User on 7/10/2025.
//

#include "Pedido.hpp"

Pedido::Pedido() {
    this->codigo = nullptr;
}

Pedido::~Pedido() {
    if (codigo != nullptr)delete this->codigo;
}

bool Pedido::leerPedido(ifstream &arch) {
    //OQI-373,78757121
    char cod[10];
    arch.getline(cod, 10, ',');

    if (arch.eof()) return false;
    arch >> dni_cliente;
    arch.get();
    set_codigo(cod);


    return true;
}

void Pedido::get_codigo(char *codigo) const {
    if (this->codigo == nullptr)codigo[0] = 0;
    else strcpy(codigo, this->codigo);
}

void Pedido::set_codigo(const char *codigo) {
    if (this->codigo != nullptr)delete this->codigo;
    this->codigo = new char[strlen(codigo) + 1];
    strcpy(this->codigo, codigo);
}

int Pedido::get_dni_cliente() const {
    return dni_cliente;
}

void Pedido::set_dni_cliente(int dni_cliente) {
    this->dni_cliente = dni_cliente;
}

double Pedido::get_precio_producto() const {
    return precio_producto;
}

void Pedido::set_precio_producto(double precio_producto) {
    this->precio_producto = precio_producto;
}

bool operator >>(ifstream &arch, class Pedido &ped) {
    return ped.leerPedido(arch);
}
