//
// Created by User on 20/11/2025.
//

#include "Pedido.hpp"

void Pedido::lee(ifstream &arch) {
    getline(arch,nombre,',');
    arch>>cantidad;
    arch.get();
    arch>>total;
    arch.get();
    arch>>dni;
    arch.get();
    int dd,aa,mm;
    char car;
    arch>>dd>>car>>mm>>car>>aa;
    fecha=aa*10000+mm*100+dd;
}

void Pedido::imprimir(ofstream &arch) {
    int dd=fecha%100;
    int mm=fecha/100%100;
    int aa=fecha/10000;
    arch<<setfill('0');
    arch<<right<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<setw(4)<<aa<<
        setfill(' ')<<endl;
    arch<<left<<setw(15)<<codigo<<nombre<<endl;
    arch<<left<<setw(20)<<"DNI:"<<dni<<endl;
    arch<<left<<setw(20)<<"Monto Total:"<<total<<endl;

}

int Pedido::get_codigo() const {
    return codigo;
}

void Pedido::set_codigo(int codigo) {
    this->codigo = codigo;
}

string Pedido::get_nombre() const {
    return nombre;
}

void Pedido::set_nombre(const string &nombre) {
    this->nombre = nombre;
}

int Pedido::get_cantidad() const {
    return cantidad;
}

void Pedido::set_cantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::get_dni() const {
    return dni;
}

void Pedido::set_dni(int dni) {
    this->dni = dni;
}

int Pedido::get_fecha() const {
    return fecha;
}

void Pedido::set_fecha(int fecha) {
    this->fecha = fecha;
}

double Pedido::get_total() const {
    return total;
}

void Pedido::set_total(double total) {
    this->total = total;
}
