//
// Created by User on 27/10/2025.
//

#include "Empresa.hpp"

Empresa::Empresa() {
    this->nombre = nullptr;
    for (int i = 0; i < 10; i++)
        placas[i] = nullptr;
    numPlacas = 0;
    numMultas = 0;
}

Empresa::~Empresa() {
    if (this->nombre != nullptr)delete this->nombre;
    for (int i = 0; i < 10; i++) {
        if (placas[i] != nullptr)delete placas[i];
    }
}

void Empresa::operator=(class Empresa &orig) {
    char bufeer[100];
    dni = orig.dni;
    orig.get_nombre(bufeer);
    set_nombre(bufeer);
    numPlacas = orig.numPlacas;
    numMultas = orig.numMultas;
    for (int i = 0; i < numPlacas; i++) {
        orig.getPlacaI(bufeer, i);
        setPlacaI(bufeer, i);
    }
}


void Empresa::leer(ifstream &arch) {
    char buffer[100], placa[9];
    // 13219606,Rodriguez Moreno Blanca Ofelia,P201-291,M312-270,M312-270
    arch >> dni;
    if (arch.eof()) return;
    arch.get();
    arch.getline(buffer, 100, ',');
    set_nombre(buffer);
    while (true) {
        arch >> placa;
        setPlacaI(placa, numPlacas);
        numPlacas++;
        if (arch.get() == '\n')break;
    }
}
void Empresa::imprimir(ofstream &arch) {
    char buffer[100], placa[9];
    get_nombre(buffer);
    arch<<setw(5)<< left<<setw(10) << dni<<setw(40)<<
        buffer;
    for (int i = 0; i < numPlacas; i++) {
        getPlacaI(placa, i);
        arch<<setw(15)<< left<<setw(10) << placa;
    }
    arch<<endl<<setw(10)<<" "<<setw(15)<<"Placa"<<setw(30)<<"Fecha de infraccion"<<setw(30)<<
        "Código de infraccion"<<setw(20)<<"Multa"<<"Fecha de pago"<<endl;
    for (int i = 0; i < numMultas; i++) {
        arch<<multas[i];
    }
}

void Empresa::operator +=(const class Multa &multa) {
    this->multas[numMultas]=multa;
    numMultas++;
}

void Empresa::setPlacaI(const char *placa, int i) {
    if (this->placas[i] != nullptr)delete this->placas[i];
    this->placas[i] = new char[strlen(placa) + 1];
    strcpy(this->placas[i], placa);
}

void Empresa::getPlacaI(char *placa, int i) {
    if (this->placas[i] == nullptr)placa[0] = 0;
    else strcpy(placa, this->placas[i]);
}

int Empresa::get_dni() const {
    return dni;
}

void Empresa::set_dni(int dni) {
    this->dni = dni;
}

void Empresa::get_nombre(char *nombre) const {
    if (this->nombre == nullptr)nombre[0] = 0;
    else strcpy(nombre, this->nombre);
}

void Empresa::set_nombre(const char *nombre) {
    if (this->nombre != nullptr)delete this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

int Empresa::get_num_placas() const {
    return numPlacas;
}

void Empresa::set_num_placas(int num_placas) {
    numPlacas = num_placas;
}

int Empresa::get_num_multas() const {
    return numMultas;
}

void Empresa::set_num_multas(int num_multas) {
    numMultas = num_multas;
}

void operator >>(ifstream &arch, class Empresa &empre) {
    empre.leer(arch);
}
void operator <<(ofstream &arch,class Empresa &empre) {
    empre.imprimir(arch);
}
