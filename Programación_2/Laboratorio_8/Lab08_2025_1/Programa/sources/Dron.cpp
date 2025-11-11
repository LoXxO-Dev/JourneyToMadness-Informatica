//
// Created by User on 7/11/2025.
//

#include "Dron.hpp"


Dron::Dron() {
    id=nullptr;
    ubicacion=nullptr;
}

Dron::~Dron() {
    if (id)delete id;
}

void Dron::leer(ifstream &arch) {
    // Estacionamiento,DE467,Avenida C,15,false
    char aux[100];
    arch.getline(aux,100,',');
    set_id(aux);
    arch.getline(aux,100,',');
    set_ubicacion(aux);
    arch>>capacidad;
    arch.get();

}

bool Dron::operator>(const class Dron *dron) const {
    char aux[100],aux2[100];
    get_id(aux);
    dron->get_id(aux2);
    return strcmp(aux,aux2)>0;
}



void Dron::imprimir(ofstream &arch) {
    char aux[100],ubi[100];
    get_id(aux);
    get_ubicacion(ubi);
    arch<<setw(10)<<" "<<left<<setw(10)<<aux<<setw(15)<<
        ubi<<right<<setw(5)<<capacidad;
}

void Dron::get_id(char *id) const {
    if (this->id==nullptr)id[0]=0;
    else strcpy(id,this->id);
}

void Dron::set_id(const char *id) {
if (this->id)delete this->id;
    this->id=new char[strlen(id)+1];
    strcpy(this->id,id);
}

void  Dron::get_ubicacion(char *ubicacion) const {
    if (this->ubicacion==nullptr)ubicacion[0]=0;
    else strcpy(ubicacion,this->ubicacion);
}

void Dron::set_ubicacion(const char* ubicacion) {
    if (this->ubicacion)delete this->ubicacion;
    this->ubicacion=new char[strlen(ubicacion)+1];
    strcpy(this->ubicacion,ubicacion);
}

int Dron::get_capacidad() const {
    return capacidad;
}

void Dron::set_capacidad(int capacidad) {
    this->capacidad = capacidad;
}
