//
// Created by User on 7/10/2025.
//

#include "ProductoEntregado.hpp"

#include "Pedido.hpp"

ProductoEntregado::ProductoEntregado() {
    this->codigo = nullptr;
}

void ProductoEntregado::operator =(class Pedido &ped) {
    char cod[10];
    ped.get_codigo(cod);
    set_codigo(cod);
    precio=ped.get_precio_producto();
}

void ProductoEntregado::get_codigo(char *codigo) const {
    if (this->codigo == nullptr)codigo[0] = 0;
    else strcpy(codigo, this->codigo);
}

void ProductoEntregado::set_codigo(const char *codigo) {
    if (this->codigo != nullptr)delete this->codigo;
    this->codigo = new char[strlen(codigo) + 1];
    strcpy(this->codigo, codigo);
}

double ProductoEntregado::get_precio() const {
    return precio;
}

void ProductoEntregado::set_precio(double precio) {
    this->precio = precio;
}
