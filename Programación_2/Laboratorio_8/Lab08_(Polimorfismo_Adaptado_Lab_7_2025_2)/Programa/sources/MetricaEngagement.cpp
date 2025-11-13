//
// Created by User on 11/11/2025.
//

#include "MetricaEngagement.hpp"

void MetricaEngagement::leer(ifstream &arch) {
    Metrica::leer(arch);
    arch >> mensajes_chat;
    arch.get();
    arch >> usuarios_unicos_chat;
    arch.get();
    arch >> clips_generados;
    arch.get();
}

void MetricaEngagement::imprimir(ofstream &arch) {
    arch << setw(5) << " " <<left<< "ME-";
    Metrica::imprimir(arch);
    char aux[100];
    get_descripcion(aux);
    arch << setw(10) <<right<< mensajes_chat << setw(10) <<
            this->usuarios_unicos_chat << setw(10) << clips_generados <<
            setw(15) << " "
            << aux << endl;
}

int MetricaEngagement::get_mensajes_chat() const {
    return mensajes_chat;
}

void MetricaEngagement::set_mensajes_chat(int mensajes_chat) {
    this->mensajes_chat = mensajes_chat;
}

int MetricaEngagement::get_usuarios_unicos_chat() const {
    return usuarios_unicos_chat;
}

void MetricaEngagement::set_usuarios_unicos_chat(int usuarios_unicos_chat) {
    this->usuarios_unicos_chat = usuarios_unicos_chat;
}

int MetricaEngagement::get_clips_generados() const {
    return clips_generados;
}

void MetricaEngagement::set_clips_generados(int clips_generados) {
    this->clips_generados = clips_generados;
}
