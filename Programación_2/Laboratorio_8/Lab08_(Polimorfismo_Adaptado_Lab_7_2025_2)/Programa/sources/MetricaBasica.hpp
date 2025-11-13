//
// Created by User on 11/11/2025.
//

#ifndef METRICABASICA_HPP
#define METRICABASICA_HPP

#include "Metrica.hpp"
#include "utils.hpp"

class MetricaBasica :public  Metrica{
private:
    double horas_transmitidas;
    int espectadores_promedio;

public:
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
    double get_horas_transmitidas() const;

    void set_horas_transmitidas(double horas_transmitidas);

    int get_espectadores_promedio() const;

    void set_espectadores_promedio(int espectadores_promedio);
};



#endif //METRICABASICA_HPP
