//
// Created by User on 31/10/2025.
//

#include "PrioridadMedia.hpp"

PrioridadMedia::PrioridadMedia() {
    descripcion = nullptr;
}

void PrioridadMedia::imprime(ofstream &arch) {
    arch << left << setw(15) << " MEDIA";

    Pedido::imprime(arch);
    char aux[100];
    get_descripcion(aux);
    arch << right << setw(10) <<nueva_fecha_entrega%100<<"/"<<
        nueva_fecha_entrega%10000/100<<"/"<<nueva_fecha_entrega/10000 << endl;
}

PrioridadMedia::~PrioridadMedia() {
    if (descripcion != nullptr)delete descripcion;
}

void PrioridadMedia::leer(ifstream &arch) {
    Pedido::leer(arch);
    char aux[100];
    arch>>this->nueva_fecha_entrega;
}

void PrioridadMedia::actualiza() {
    char *aux;
    aux=new char[100];
    if (nueva_fecha_entrega == 0) {
        strcpy(aux, "Inactivo");
    } else if (nueva_fecha_entrega == 1) {
        strcpy(aux, "Activo");
    }
    Pedido::set_estado(aux);

    int fecha=Pedido::get_fecha();
    int dd=fecha%100,mm=fecha%10000/100,aa=fecha/10000;
    dd++;
    if (mm==1 or mm==3 or mm==5 or mm==7 or mm==8 or mm==10 or mm==12) {
        if (dd>31) {
            dd=1;
            mm++;
        }
        if (mm>=13) {
            mm=1;
            aa++;
        }
    }else if (mm==2) {
        if (dd>28) {
            dd=1;
            mm++;
        }
    }else {
        if (dd>30) {
            dd=1;
            mm++;
        }
    }
    set_nueva_fecha_entrega(aa*10000+mm*100+dd);
}

void PrioridadMedia::get_descripcion(char *descripcion) const {
    if (this->descripcion == nullptr)descripcion[0] = 0;
    else strcpy(descripcion, this->descripcion);
}

void PrioridadMedia::set_descripcion(const char *descripcion) {
    if (this->descripcion != nullptr)delete this->descripcion;
    this->descripcion = new char[strlen(descripcion) + 1];
    strcpy(this->descripcion, descripcion);
}

int PrioridadMedia::get_nueva_fecha_entrega() const {
    return nueva_fecha_entrega;
}

void PrioridadMedia::set_nueva_fecha_entrega(int nueva_fecha_entrega) {
    this->nueva_fecha_entrega = nueva_fecha_entrega;
}
