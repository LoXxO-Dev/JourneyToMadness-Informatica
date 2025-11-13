//
// Created by User on 11/11/2025.
//

#ifndef STREAMERPAGO_HPP
#define STREAMERPAGO_HPP


#include "Streamer.hpp"
#include "utils.hpp"
class StreamerPago :public Streamer{
private:
    int fecha_inicio_plan;
    class Metrica *metricas[200];
    int cantidad_metricas=0;

public:
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
    void actualiza(char  *tipo,ifstream &arch);
    int get_fecha_inicio_plan() const;

    void set_fecha_inicio_plan(int fecha_inicio_plan);

    int get_cantidad_metricas() const;

    void set_cantidad_metricas(int cantidad_metricas);
};



#endif //STREAMERPAGO_HPP
