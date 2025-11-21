//
// Created by User on 20/11/2025.
//

#include "Streamer.hpp"

void Streamer::leer(ifstream &archivo) {
    archivo>>id;
    archivo.get();
    getline(archivo,nombre,',');
    getline(archivo,categoria,',');
    archivo>>n_seguidores;
    archivo.get();

}

void Streamer::imprimir(ofstream &archivo) {
    archivo<<"[ST]CUENTA: "<<left<<setw(15)<<nombre<<
        "|Seguidores :"<<right<<setw(7)<<n_seguidores<<
            "|CATEGORIA "<<left<<setw(15)<<categoria<<"|ID :"<<right<<setw(10)<<id<<
                "|TIPO";

}

int Streamer::get_id() const {
    return id;
}

void Streamer::set_id(int id) {
    this->id = id;
}

string Streamer::get_nombre() const {
    return nombre;
}

void Streamer::set_nombre(const string &nombre) {
    this->nombre = nombre;
}

int Streamer::get_n_seguidores() const {
    return n_seguidores;
}

void Streamer::set_n_seguidores(int n_seguidores) {
    this->n_seguidores = n_seguidores;
}

string Streamer::get_categoria() const {
    return categoria;
}

void Streamer::set_categoria(const string &categoria) {
    this->categoria = categoria;
}
