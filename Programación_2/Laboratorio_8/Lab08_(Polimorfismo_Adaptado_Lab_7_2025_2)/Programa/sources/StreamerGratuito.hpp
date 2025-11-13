//
// Created by User on 11/11/2025.
//

#ifndef STREAMERGRATUITO_HPP
#define STREAMERGRATUITO_HPP

#include "Streamer.hpp"
#include "utils.hpp"

class StreamerGratuito:public Streamer {
private:
    int fecha_fin_trial;
    class Metrica *metricas[100];
    int cantidad_metricas_basicas=0;

public:
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
    int get_fecha_fin_trial() const;
    void actualiza(char  *tipo,ifstream &arch);
    void set_fecha_fin_trial(int fecha_fin_trial);

    int get_cantidad_metricas_basicas() const;

    void set_cantidad_metricas_basicas(int cantidad_metricas_basicas);
};



#endif //STREAMERGRATUITO_HPP
