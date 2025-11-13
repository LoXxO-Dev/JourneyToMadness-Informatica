//
// Created by User on 11/11/2025.
//

#include "Metrica.hpp"

Metrica::Metrica() {
    descripcion=nullptr;
}

Metrica::~Metrica() {
    if (descripcion)delete descripcion;
}

void Metrica::leer(ifstream &arch) {
    char auxx[100];
    int dd,mm,aa;
    char car;
    arch>>id;
    arch.get();
    arch.getline(auxx,100,',');
    set_descripcion(auxx);
    arch>>aa>>car>>mm>>car>>dd>>car;
    fecha_calculo=aa*10000+mm*100+dd;
    arch>>aa>>car>>mm>>car>>dd>>car;
    fecha_expiracion=aa*10000+mm*100+dd;
    if (fecha_expiracion<20251111)  estado=false;
    else estado=true;

}

void Metrica::imprimir(ofstream &arch) {
    arch<<setw(10)<<id<<right<<setw(10)<<fecha_calculo
    <<setw(10)<<fecha_expiracion<<setw(10)<<" "<<left<<setw(15);
    if (estado)
        arch<<"ACTIVA";
    else arch<<"EXPIRADA";
}

int Metrica::get_id() const {
    return id;
}

void Metrica::set_id(int id) {
    this->id = id;
}

void  Metrica::get_descripcion(char *descripcion) const {
    if (this->descripcion==nullptr)descripcion[0]=0;
    else strcpy(descripcion,this->descripcion);
}

void Metrica::set_descripcion(const char *descripcion) {
    if (this->descripcion)delete [] this->descripcion;
    this->descripcion = new char[strlen(descripcion)+1];
    strcpy(this->descripcion,descripcion);
}

int Metrica::get_fecha_calculo() const {
    return fecha_calculo;
}

void Metrica::set_fecha_calculo(int fecha_calculo) {
    this->fecha_calculo = fecha_calculo;
}

int Metrica::get_fecha_expiracion() const {
    return fecha_expiracion;
}

void Metrica::set_fecha_expiracion(int fecha_expiracion) {
    this->fecha_expiracion = fecha_expiracion;
}

bool Metrica::is_estado() const {
    return estado;
}

void Metrica::set_estado(bool estado) {
    this->estado = estado;
}
