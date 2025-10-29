//
// Created by User on 7/10/2025.
//

#include "Cliente.hpp"

#include "Pedido.hpp"

Cliente::Cliente() {
    this->nombre = nullptr;
    cantidad_productos_entregados = 0;
    monto_total = 0;
}

Cliente::Cliente(const Cliente &copia) {
    this->nombre = nullptr;
    cantidad_productos_entregados = 0;
    monto_total = 0;
    *this = copia;
}

Cliente::~Cliente() {
    if (this->nombre != nullptr)delete this->nombre;
}

void Cliente::operator=(const Cliente &copia) {
    char nomb[100];
    copia.get_nombre(nomb);
    set_nombre(nomb);
    dni = copia.get_dni();
    telefono = copia.get_telefono();
    cantidad_productos_entregados = copia.get_cantidad_productos_entregados();
    monto_total = copia.get_monto_total();
}

void Cliente::operator +=(class Pedido &ped) {
    this->productos_entregados[cantidad_productos_entregados]=ped;
    cantidad_productos_entregados++;
    monto_total+=ped.get_precio_producto();
}


bool Cliente::leer_cliente(ifstream &arch) {
    char nomb[50];
    arch >> dni;
    if (arch.eof())return false;
    arch.get();
    arch.getline(nomb, 50, ',');
    set_nombre(nomb);
    arch >> telefono;
    cantidad_productos_entregados = 0;
    monto_total = 0;
    return true;
}

void Cliente::imprimir(ofstream &arch) {
    char nomb[50];
    get_nombre(nombre);
    arch << left << setw(10) << dni << setw(40) << nombre <<
            right << setw(10) << telefono << right << setw(15) << monto_total;
    if (cantidad_productos_entregados > 0) {
        arch << setw(10) << " " << left << setw(25) << "Productos entregados: ";
        char cod[10];
        for (int i = 0; i < cantidad_productos_entregados; i++) {
            this->productos_entregados[i].get_codigo(cod);
            arch << setw(10) << cod;
        }
        arch << endl;
    } else arch << setw(10) << " " << left << setw(20) << "NO SE LE ENTREGARON PRODUCTOS:" << endl;;
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

int Cliente::get_telefono() const {
    return telefono;
}

void Cliente::set_telefono(int telefono) {
    this->telefono = telefono;
}

int Cliente::get_cantidad_productos_entregados() const {
    return cantidad_productos_entregados;
}

void Cliente::set_cantidad_productos_entregados(int cantidad_productos_entregados) {
    this->cantidad_productos_entregados = cantidad_productos_entregados;
}

double Cliente::get_monto_total() const {
    return monto_total;
}

void Cliente::set_monto_total(double monto_total) {
    this->monto_total = monto_total;
}

bool operator >>(ifstream &arch, Cliente &clie) {
    return clie.leer_cliente(arch);
}

void operator <<(ofstream &arch, Cliente &clie) {
    clie.imprimir(arch);
}
