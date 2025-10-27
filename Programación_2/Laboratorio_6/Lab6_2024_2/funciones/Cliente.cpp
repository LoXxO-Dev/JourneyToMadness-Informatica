//
// Created by User on 5/10/2025.
//

#include "Cliente.hpp"

Cliente::Cliente() {
    nombre = nullptr;
    distrito = nullptr;
    totalPagado = 0;
}

Cliente::Cliente(const Cliente &copia) {
    nombre = nullptr;
    distrito = nullptr;
    totalPagado = 0;
    *this = copia;
}

Cliente::~Cliente() {
    if (nombre != nullptr)delete nombre;
    if (distrito != nullptr)delete distrito;
}

void Cliente::operator =(const class Cliente &copia) {
    char nombre[100], distrito[20];
    dni = copia.get_dni();
    copia.get_nombre(nombre);
    set_nombre(nombre);
    copia.get_distrito(distrito);
    set_distrito(distrito);
    descuento = copia.get_descuento();
    totalPagado = copia.get_total_pagado();
    dni = copia.get_dni();
}

void operator >>(ifstream &arch, class Cliente &cli) {
    cli.leerCliente(arch);
}

void operator<<(ofstream &arch, class Cliente cli) {
    cli.imprimir(arch);
}

void Cliente::imprimir(ofstream &arch) {
    char nombre[100], distrito[20];
    get_nombre(nombre);
    get_distrito(distrito);
    arch<<right<<setw(10)<<dni<<setw(5)<<" "<<left<<setw(50)<<nombre<<setw(30)<<distrito<<
    right<<setw(10)<<descuento<<"%"<<setw(15)<<totalPagado<<endl;
}


void Cliente::leerCliente(ifstream &arch) {
    int dni;
    char nombre[100], distrito[30], car;
    arch >> dni;
    if (arch.eof())return;
    set_dni(dni);
    arch.get();
    arch.getline(nombre, 100, ',');
    arch.getline(distrito, 30, ',');
    set_nombre(nombre);
    set_distrito(distrito);
    car = arch.get();
    if (car == 'S') {
        arch.get();
        arch >> descuento;
        arch.get();
    }
}
void Cliente::agregarSubTotal(int cantidad, double descuentoPlato,double precioPlato) {
    double sub=cantidad*(100-descuentoPlato)/100*precioPlato*(100-this->descuento)/100;

    this->totalPagado+=sub;
}

bool Cliente::posCliente(int dni) {
    if (this->dni == dni)
        return true;
    else return false;
}

int Cliente::get_dni() const {
    return dni;
}

void Cliente::set_dni(int dni) {
    this->dni = dni;
}

void Cliente::get_nombre(char *nombre) const {
    if (this->nombre == nullptr)nombre[0] = 0;
    else strcpy(nombre, this->nombre);
}

void Cliente::set_nombre(const char *nombre) {
    if (this->nombre != nullptr)delete this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

void Cliente::get_distrito(char *distrito) const {
    if (this->distrito == nullptr)distrito[0] = 0;
    else strcpy(distrito, this->distrito);
}

void Cliente::set_distrito(const char *distrito) {
    if (this->distrito != nullptr)delete this->distrito;
    this->distrito = new char[strlen(distrito) + 1];
    strcpy(this->distrito, distrito);
}

double Cliente::get_descuento() const {
    return descuento;
}

void Cliente::set_descuento(double descuento) {
    this->descuento = descuento;
}

double Cliente::get_total_pagado() const {
    return totalPagado;
}

void Cliente::set_total_pagado(double total_pagado) {
    totalPagado = total_pagado;
}
