//
// Created by User on 20/11/2025.
//

#ifndef STREAMERGRATUITO_HPP
#define STREAMERGRATUITO_HPP


#include "Streamer.hpp"
#include "utils.hpp"
class StreamerGratuito:public Streamer{
private:
    int fecha_fin_trial;
    class Metrica *metricas[100];
    int cantidad_metricas_basicas;

public:
    StreamerGratuito();
    void actualiza(char *tipo,ifstream &arch);
    void leer(ifstream &archivo);
    void imprimir(ofstream &archivo) ;
    bool eliminable();
    int get_fecha_fin_trial() const;

    void set_fecha_fin_trial(int fecha_fin_trial);

    int get_cantidad_metricas_basicas() const;

    void set_cantidad_metricas_basicas(int cantidad_metricas_basicas);
};



#endif //STREAMERGRATUITO_HPP
