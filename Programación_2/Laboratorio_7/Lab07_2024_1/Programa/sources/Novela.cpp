//
// Created by User on 2/11/2025.
//

#include "Novela.hpp"

Novela::Novela() {
    tipo=nullptr;

}

Novela::~Novela() {
    if (tipo)delete tipo;
}

Novela::Novela(const Novela &nove) {
    tipo=nullptr;
    *this=nove;
}

void Novela::imprimir(ofstream &arch) {
    char aux[100],nombre[100];
    get_codigo(aux);
    get_nombre(nombre);
    arch<<left<<setw(20)<<aux<<setw(30)<<nombre<<right<<setw(10)<<get_ancho()<<setw(10)<<get_alto()<<setw(10)<<peso<<endl;
}

void Novela::operator=(const class Novela &nove) {
    char aux[100];
    nove.get_tipo(aux);
    set_tipo(aux);
    this->peso=nove.get_peso();
    nove.get_nombre(aux);
    set_nombre(aux);
    set_ancho(nove.get_ancho());
    set_alto(nove.get_alto());
    nove.get_codigo(aux);
    set_codigo(aux);

}

void Novela::leer(ifstream &arch) {
    Libro::leer(arch);
    char aux[100];
    arch.getline(aux,100,',');
    set_tipo(aux);
    arch>>peso;
}

void  Novela::get_tipo(char *tipo) const {
    if (this->tipo ==nullptr)tipo[0]=0;
    else strcpy(tipo,this->tipo);
}

void Novela::set_tipo(const char *tipo) {
    if (this->tipo !=nullptr)this->tipo=nullptr;
    this->tipo=new char[strlen(tipo)+1];
    strcpy(this->tipo,tipo);
}

double Novela::get_peso() const {
    return peso;
}

void Novela::set_peso(double peso) {
    this->peso = peso;
}

void operator>>(ifstream &arch, Novela &nove) {
    nove.leer(arch);
}
