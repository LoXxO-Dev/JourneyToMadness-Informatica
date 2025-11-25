//
// Created by User on 25/11/2025.
//

#include "MetricaEngagement.hpp"

MetricaEngagement::MetricaEngagement() {
}

MetricaEngagement::~MetricaEngagement() {
}

int MetricaEngagement::obtener_tipo()const {
    return ENGAGEMENT;
}

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
    arch<<setw(5)<<" "<<"ME-"<<right;
    Metrica::imprimir(arch);
    arch<<setw(15)<<mensajes_chat<<setw(15)<<usuarios_unicos_chat
    <<setw(15)<<clips_generados<<endl;
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
