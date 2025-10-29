//
// Created by User on 6/10/2025.
//

#include "Espacio.hpp"
void Espacio::imprime(ofstream &archivo) {
    archivo<<"["<<get_contenido()<<"] ";
}
char Espacio::get_contenido() const {
    return contenido;
}

void Espacio::set_contenido(char contenido) {
    this->contenido = contenido;
}

int Espacio::get_pos_x() const {
    return posX;
}

void Espacio::set_pos_x(int pos_x) {
    posX = pos_x;
}

int Espacio::get_pos_y() const {
    return posY;
}

void Espacio::set_pos_y(int pos_y) {
    posY = pos_y;
}
void operator <<(ofstream &arch,Espacio &espa) {
    espa.imprime(arch);
}