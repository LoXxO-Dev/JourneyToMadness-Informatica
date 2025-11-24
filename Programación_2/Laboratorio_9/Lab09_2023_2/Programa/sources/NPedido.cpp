//
// Created by User on 24/11/2025.
//

#include "NPedido.hpp"

void NPedido::leer(ifstream &arch) {
    getline(arch,this->codigo,',');
    arch >>cantidad;
    arch.get();
    arch >>peso;
}

void NPedido::imprimir(ofstream &arch) {
    arch<<setw(5)<<" "<<left<<setw(15)<<codigo<<setw(10)<<cantidad<<
    setw(10)<<right<<peso<<endl;


}

NPedido::NPedido() {
}

NPedido::NPedido(const NPedido &orig) {
    *this=orig;
}

void NPedido::operator=(const NPedido &ped) {
    codigo = ped.codigo;
    cantidad = ped.cantidad;
    peso = ped.peso;
}

string NPedido::get_codigo() const {
    return codigo;
}

void NPedido::set_codigo(const string &codigo) {
    this->codigo = codigo;
}

int NPedido::get_cantidad() const {
    return cantidad;
}

void NPedido::set_cantidad(int cantidad) {
    this->cantidad = cantidad;
}

double NPedido::get_peso() const {
    return peso;
}

void NPedido::set_peso(double peso) {
    this->peso = peso;
}
