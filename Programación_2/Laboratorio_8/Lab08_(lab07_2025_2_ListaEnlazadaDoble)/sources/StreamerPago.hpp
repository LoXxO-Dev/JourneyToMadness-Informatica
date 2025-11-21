//
// Created by User on 20/11/2025.
//

#ifndef STREAMERPAGO_HPP
#define STREAMERPAGO_HPP

#include "Streamer.hpp"
#include "utils.hpp"

class StreamerPago :public Streamer {
private:
    int fecha_fin_plan;
    class Metrica *metricas[200];
    int cantidad_metricas;

public:
    StreamerPago();
    void actualiza(char *tipo,ifstream &arch);
    bool eliminable();
    void leer(ifstream &archivo);
    void imprimir(ofstream &archivo) ;
    int get_fecha_fin_plan() const;

    void set_fecha_fin_plan(int fecha_fin_plan);

    int get_cantidad_metricas() const;

    void set_cantidad_metricas(int cantidad_metricas);
};



#endif //STREAMERPAGO_HPP
