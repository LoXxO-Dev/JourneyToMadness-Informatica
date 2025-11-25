//
// Created by User on 25/11/2025.
//

#include "MetricaBasica.hpp"

MetricaBasica::MetricaBasica() {
}

MetricaBasica::~MetricaBasica() {
}

int MetricaBasica::obtener_tipo()const  {
    return BASICA;
}

//ENGAGEMENT,320975,121,Maratón de chat,2025-10-17,2025-10-31,1535,553,54

void MetricaBasica::leer(ifstream &arch) {
    Metrica::leer(arch);
    arch>>horas_transmitidas;
    arch.get();
    arch>>espectadores_promedio;
    arch.get();
}

void MetricaBasica::imprimir(ofstream &arch) {
    arch<<setw(5)<<" "<<"MB-"<<right;
    Metrica::imprimir(arch);
    arch<<setw(15)<<horas_transmitidas<<setw(15)<<espectadores_promedio<<endl;
}

double MetricaBasica::get_horas_transmitidas() const {
    return horas_transmitidas;
}

void MetricaBasica::set_horas_transmitidas(double horas_transmitidas) {
    this->horas_transmitidas = horas_transmitidas;
}

int MetricaBasica::get_espectadores_promedio() const {
    return espectadores_promedio;
}

void MetricaBasica::set_espectadores_promedio(int espectadores_promedio) {
    this->espectadores_promedio = espectadores_promedio;
}
