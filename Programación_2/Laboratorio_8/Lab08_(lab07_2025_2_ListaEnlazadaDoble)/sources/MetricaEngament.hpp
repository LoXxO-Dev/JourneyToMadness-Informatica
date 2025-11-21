//
// Created by User on 20/11/2025.
//

#ifndef METRICAENGAMENT_HPP
#define METRICAENGAMENT_HPP


#include "Metrica.hpp"
#include "utils.hpp"

class MetricaEngament : public Metrica {
private:
    int mensajes_chat;
    int usuarios_unicos_chat;
    int clips_generados;

public:
    void leer(ifstream &archivo);
    void imprimir(ofstream &archivo) ;
    int get_mensajes_chat() const;

    void set_mensajes_chat(int mensajes_chat);

    int get_usuarios_unicos_chat() const;

    void set_usuarios_unicos_chat(int usuarios_unicos_chat);

    int get_clips_generados() const;

    void set_clips_generados(int clips_generados);
};


#endif //METRICAENGAMENT_HPP
