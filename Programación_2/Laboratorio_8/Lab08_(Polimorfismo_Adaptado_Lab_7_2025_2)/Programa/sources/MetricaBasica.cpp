//
// Created by User on 11/11/2025.
//

#include "MetricaBasica.hpp"

void MetricaBasica::leer(ifstream &arch) {
    Metrica::leer(arch);
    arch >> horas_transmitidas;
    arch.get();
    arch >> espectadores_promedio;
    arch.get();
}

void MetricaBasica::imprimir(ofstream &arch) {
    arch<<setw(5)<<" "<<"MB-";
    Metrica::imprimir(arch);
    char aux[100];
    get_descripcion(aux);
    arch<<setw(10)<<right<<horas_transmitidas<<setw(10)<<
        espectadores_promedio<<left<<"m"<<setw(24)<<" "
    <<aux<<endl;
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
