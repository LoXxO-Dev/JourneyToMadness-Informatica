//
// Created by User on 11/11/2025.
//

#ifndef METRICAENGAGEMENT_HPP
#define METRICAENGAGEMENT_HPP


#include "Metrica.hpp"
#include "utils.hpp"
class MetricaEngagement:public Metrica{
private:
    int mensajes_chat;
    int usuarios_unicos_chat;
    int clips_generados;

public:
    void leer(ifstream &arch);
    void imprimir(ofstream &arch) override;
    int get_mensajes_chat() const;

    void set_mensajes_chat(int mensajes_chat);

    int get_usuarios_unicos_chat() const;

    void set_usuarios_unicos_chat(int usuarios_unicos_chat);

    int get_clips_generados() const;

    void set_clips_generados(int clips_generados);
};



#endif //METRICAENGAGEMENT_HPP
