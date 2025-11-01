//
// Created by User on 31/10/2025.
//

#include "Pedido.hpp"

Pedido::Pedido() {
    codigo = nullptr;
    estado = nullptr;
    total = 0;
}

Pedido::~Pedido() {
    if (codigo != nullptr)delete this->codigo;
    if (estado != nullptr)delete this->estado;
}

void Pedido::imprime(ofstream &arch) {
    char aux[100];
    get_codigo(aux);
    arch << setw(10) << left << aux << right << setw(10) << dni_cliente << setw(10) << subtotal << setw(10) << fecha %
            100 <<
            "/" << fecha / 100 % 100 << "/" << fecha / 10000<<setw(6)<<" ";
    if (estado==nullptr) {
        arch << left << setw(10) << "Nulo";
    } else {
        char aux[100];
        get_estado(aux);
        arch << left << setw(10) << aux;

    }
        arch << setw(10) << right << total;
}


void Pedido::get_codigo(char *codigo) const {
    if (this->codigo == nullptr)codigo[0] = 0;
    else strcpy(codigo, this->codigo);
}

void Pedido::leer(ifstream &arch) {
    //   M,AWB-345,13245501,67.6,2023-12-18,1
    int dd, mm, aa;
    char car;
    char aux[100];
    arch.getline(aux, 100, ',');
    set_codigo(aux);
    arch >> dni_cliente;
    arch.get();
    arch >> subtotal;
    arch.get();
    arch >> aa >> car >> mm >> car >> dd >> car;
    fecha = aa * 10000 + mm * 100 + dd;
    total = subtotal;
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

double Pedido::get_subtotal() const {
    return subtotal;
}

void Pedido::set_subtotal(double subtotal) {
    this->subtotal = subtotal;
}

int Pedido::get_fecha() const {
    return fecha;
}

void Pedido::set_fecha(int fecha) {
    this->fecha = fecha;
}

void Pedido::get_estado(char *estado) const {
    if (this->estado == nullptr)estado[0] = 0;
    else strcpy(estado, this->estado);
}

void Pedido::set_estado(const char *estado) {
    if (this->estado != nullptr)delete this->estado;
    this->estado = new char[strlen(estado) + 1];
    strcpy(this->estado, estado);
}

double Pedido::get_total() const {
    return total;
}

void Pedido::set_total(double total) {
    this->total = total;
}
