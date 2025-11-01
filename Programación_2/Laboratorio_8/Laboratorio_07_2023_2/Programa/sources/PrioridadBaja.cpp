//
// Created by User on 31/10/2025.
//

#include "PrioridadBaja.hpp"

PrioridadBaja::PrioridadBaja() {
    nueva_fecha_entrega = 0;
}

void PrioridadBaja::imprime(ofstream &arch) {
    arch<<left<<setw(15)<<" BAJA";

    Pedido::imprime(arch);
    arch<<right<<setw(10)<<nueva_fecha_entrega%100<<"/"<<
        nueva_fecha_entrega%10000/100<<"/"<<nueva_fecha_entrega/10000
    <<endl;
}

void PrioridadBaja::actualiza() {
    int fecha=Pedido::get_fecha();
    int dd=fecha%100,mm=fecha%10000/100,aa=fecha/10000;
    dd+=dias_espera;
    if (mm==1 or mm==3 or mm==5 or mm==7 or mm==8 or mm==10 or mm==12) {
        if (dd>31) {
            dd-=31;
            mm++;
        }
        if (mm>=13) {
            mm=1;
            aa++;
        }
    }else if (mm==2) {
        if (dd>28) {
            dd-=28;
            mm++;
        }
    }else {
        if (dd>30) {
            dd-=30;
            mm++;
        }
    }
   this->nueva_fecha_entrega=aa*10000+mm*100+dd;
}

void PrioridadBaja::leer(ifstream &arch) {
    Pedido::leer(arch);
    arch>>dias_espera;
}

int PrioridadBaja::get_dias_espera() const {
    return dias_espera;
}

void PrioridadBaja::set_dias_espera(int dias_espera) {
    this->dias_espera = dias_espera;
}

int PrioridadBaja::get_nueva_fecha_entrega() const {
    return nueva_fecha_entrega;
}

void PrioridadBaja::set_nueva_fecha_entrega(int nueva_fecha_entrega) {
    this->nueva_fecha_entrega = nueva_fecha_entrega;
}
