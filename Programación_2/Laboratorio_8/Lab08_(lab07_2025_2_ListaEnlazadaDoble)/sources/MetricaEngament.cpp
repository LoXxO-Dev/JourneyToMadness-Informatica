//
// Created by User on 20/11/2025.
//

#include "MetricaEngament.hpp"

void MetricaEngament::leer(ifstream &archivo) {
    Metrica::leer(archivo);
    archivo>>mensajes_chat;
    archivo.get();
    archivo>>usuarios_unicos_chat;
    archivo.get();
    archivo>>clips_generados;
    archivo.get();
}

void MetricaEngament::imprimir(ofstream &arch) {
    arch << setw(5) << " " <<left<< "ME-";
    Metrica::imprimir(arch);

    arch << setw(10) <<right<< mensajes_chat << setw(10) <<
            this->usuarios_unicos_chat << setw(10) << clips_generados <<
            setw(15) << " "
            << get_descripcion()<< endl;
}

int MetricaEngament::get_mensajes_chat() const {
    return mensajes_chat;
}

void MetricaEngament::set_mensajes_chat(int mensajes_chat) {
    this->mensajes_chat = mensajes_chat;
}

int MetricaEngament::get_usuarios_unicos_chat() const {
    return usuarios_unicos_chat;
}

void MetricaEngament::set_usuarios_unicos_chat(int usuarios_unicos_chat) {
    this->usuarios_unicos_chat = usuarios_unicos_chat;
}

int MetricaEngament::get_clips_generados() const {
    return clips_generados;
}

void MetricaEngament::set_clips_generados(int clips_generados) {
    this->clips_generados = clips_generados;
}
