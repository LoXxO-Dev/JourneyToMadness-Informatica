//
// Created by User on 25/11/2025.
//

#include "Metrica.hpp"
//ENGAGEMENT,320975,121,Maratón de chat,2025-10-17,2025-10-31,1535,553,54

void Metrica::leer(ifstream &arch) {
    int ide_streamer, dd, mm, aa;
    char car;
    arch >> ide_streamer;
    arch.get();
    arch >> id;
    arch.get();
    getline(arch, descripcion, ',');
    arch >> aa >> car >> mm >> car >> dd >> car;
    fecha_calculo = aa * 10000 + mm * 100 + dd;
    arch >> aa >> car >> mm >> car >> dd >> car;
    fecha_expiracion = aa * 10000 + mm * 100 + dd;
    if (FECHA_ACTUAL > fecha_expiracion)
        estado = false;
    else estado = true;
}

void Metrica::imprimir(ofstream &arch) {
    arch << setw(4) << setfill('0') << id <<
            setfill(' ') << setw(5) << " " << left <<
            setw(30) << descripcion <<
                setw(10)<<right<<fecha_calculo<<
                    setw(15)<<fecha_expiracion<<setw(5)<<" "<<left;
    if (estado)
        arch<<setw(10)<<"ACTIVA";
    else arch<<setw(10)<<"NO ACTIVA";
    arch<<right;

}

int Metrica::get_id() const {
    return id;
}


void Metrica::set_id(int id) {
    this->id = id;
}

bool Metrica::operator<(const class Metrica &metrica2) const {
    int tipo1 = obtener_tipo();
    int tipo2 = metrica2.obtener_tipo();
    if (tipo1 < tipo2)
        return true;
    else if (tipo1 > tipo2)
        return false;
    else if (tipo1 == tipo2) {
        return descripcion < metrica2.descripcion;
    }
}

string Metrica::get_descripcion() const {
    return descripcion;
}

void Metrica::set_descripcion(const string &descripcion) {
    this->descripcion = descripcion;
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
