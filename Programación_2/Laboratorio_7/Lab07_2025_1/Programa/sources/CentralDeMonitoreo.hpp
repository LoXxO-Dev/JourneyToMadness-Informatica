//
// Created by User on 4/11/2025.
//

#ifndef CENTRALDEMONITOREO_HPP
#define CENTRALDEMONITOREO_HPP


#include "Flota.hpp"
#include "utils.hpp"
class CentralDeMonitoreo {
private:
    Flota flota;
    int cantidad_multas_registradas;
    double total_multas_acumuladas;

public:
    CentralDeMonitoreo();
    void leer(ifstream &arch,char *tipo_dron);
    void cargar_infracciones(ifstream& arch);
    int get_cantidad_multas_registradas() const;
    void imprimir( ofstream &arch);
    void set_cantidad_multas_registradas(int cantidad_multas_registradas);

    double get_total_multas_acumuladas() const;

    void set_total_multas_acumuladas(double total_multas_acumuladas);
};



#endif //CENTRALDEMONITOREO_HPP
