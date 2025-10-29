//
// Created by User on 28/10/2025.
//

#include "Cliente.hpp"

Cliente::Cliente() {
    this->nombre=nullptr;
    this->distrito=nullptr;
    totalPagado=0;
}
Cliente:: ~Cliente() {
    if (this->nombre!=nullptr)delete this->nombre;
    if (this->distrito!=nullptr)delete this->distrito;

}
Cliente::Cliente(const class Cliente &orig) {
    this->nombre=nullptr;
    this->distrito=nullptr;
    *this=orig;

}
void Cliente:: operator=(const class Cliente &orig) {
    char aux[100];
    orig.get_nombre(aux);
    set_nombre(aux);
    orig.get_distrito(aux);
    set_distrito(aux);
    totalPagado=orig.get_total_pagado();
    dni=orig.get_dni();
    descuento=orig.get_descuento();

}
void Cliente::leer(ifstream &archivo) {
    char car,buffer[100];
    archivo>>dni;
    if (archivo.eof()) return;
    archivo>>car;
    archivo.getline(buffer,100,',');
    set_nombre(buffer);
    archivo.getline(buffer,100,',');
    set_distrito(buffer);
    descuento=0;
    if (archivo.get()=='S') {
        archivo.get();
        archivo>>descuento;
        archivo.get();
    }

}
void Cliente::imprimir(ofstream &arch) {
    char nombre[100],dist[100];
    get_nombre(nombre);
    get_distrito(dist);
    arch<<setw(15)<<dni<<setw(5)<<" "<<left<<setw(40)<<nombre<<setw(40)<<dist<<
        right<<setw(5)<<descuento<<"%"<<setw(20)<<totalPagado<<endl;

}

int Cliente::get_dni() const {
    return dni;
}

void Cliente::set_dni(int dni) {
    this->dni = dni;
}

void  Cliente::get_nombre(char *nombre) const {
    if (this->nombre==nullptr)nombre[0]=0;
    else strcpy(nombre,this->nombre);
}

void Cliente::set_nombre(const char *nombre) {
    if (this->nombre!=nullptr)delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

void Cliente::get_distrito(char *distrito) const {
    if (this->distrito==nullptr)distrito[0]=0;
    else strcpy(distrito,this->distrito);
}

void Cliente::set_distrito(const char *distrito) {
    if (this->distrito!=nullptr)delete this->distrito;
    this->distrito = new char[strlen(distrito)+1];
    strcpy(this->distrito,distrito);
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
void operator >>(ifstream &arch,class Cliente &clie) {
    clie.leer(arch);
}
void operator <<(ofstream &arch,class Cliente &clie) {
    clie.imprimir(arch);
}