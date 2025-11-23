//
// Created by User on 18/11/2025.
//

#include "Multa.hpp"

Multa::Multa() {
    fechaDePago=0;
}

Multa::Multa(const Multa &orig) {
    *this = orig;
}

void Multa::operator=(const Multa &orig) {
    fecha=orig.fecha;
    placa=orig.placa;
    codMulta=orig.codMulta;
    multa=orig.multa;
    pagada=orig.pagada;
    fechaDePago=orig.fechaDePago;

}

bool Multa::operator<(const class Multa &mult) const {
    return fecha<mult.fecha;
}

void Multa::leer(ifstream &arch) {
    int dd,aa,mm;
    char car;

    arch >> dd;
    if (arch.eof()) return;;
    arch >> car >> mm >> car >> aa >> car;
    fecha=aa*10000+mm*100+dd;

    getline(arch, placa, ',');
    getline(arch, codMulta, ',');
    arch>>car;
    if (car=='P') {
        arch.get();
        pagada=true;
        arch>>dd>>car>>mm>>car>>aa;
        fechaDePago=aa*10000+mm*100+dd;
    }else {
        pagada=false;
    }
}



void Multa::imprimir(ofstream &arch) {
    int dd,mm,aa;
    dd=fecha%100;
    aa=fecha/10000;
    mm=fecha%10000/100;
    string aux=codMulta;
    aux.erase(0,1);
    arch<<left<<setw(15)<<placa<<right<<setw(10 )<<" "<<
        setfill('0')<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<
            setw(4)<<aa<<setfill(' ')<<setw(15)<<aux<<
                setw(20)<<multa;
    if (pagada) {
        arch<<setw(15)<<"SI";
        dd=fechaDePago%100;
        aa=fechaDePago/10000;
        mm=fechaDePago%10000/100;
        arch<<right<<setw(10)<<" "<<setfill('0')<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"
        <<setw(4)<<aa<<endl<<setfill(' ');
    }else arch<<setw(15)<<"NO"<<endl;

}

int Multa::get_fecha() const {
    return fecha;
}

void Multa::set_fecha(int fecha) {
    this->fecha = fecha;
}

string Multa::get_placa() const {
    return placa;
}

void Multa::set_placa(const string &placa) {
    this->placa = placa;
}

string Multa::get_cod_multa() const {
    return codMulta;
}

void Multa::set_cod_multa(const string &cod_multa) {
    codMulta = cod_multa;
}

double Multa::get_multa() const {
    return multa;
}

void Multa::set_multa(double multa) {
    this->multa = multa;
}

bool Multa::is_pagada() const {
    return pagada;
}

void Multa::set_pagada(bool pagada) {
    this->pagada = pagada;
}

int Multa::get_fecha_de_pago() const {
    return fechaDePago;
}

void Multa::set_fecha_de_pago(int fecha_de_pago) {
    fechaDePago = fecha_de_pago;
}

void operator>>(ifstream &arch, Multa &mult) {
    mult.leer(arch);
}

void operator<<(ofstream &arch, Multa multa) {
    multa.imprimir(arch);
}
