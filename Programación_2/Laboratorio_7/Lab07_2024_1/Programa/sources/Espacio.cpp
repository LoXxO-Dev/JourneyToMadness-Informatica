//
// Created by User on 2/11/2025.
//

#include "Espacio.hpp"

char Espacio::get_contenido() const {
    return contenido;
}

void Espacio::set_contenido(char contenido) {
    this->contenido = contenido;
}

int Espacio::get_posx() const {
    return posx;
}

void Espacio::set_posx(int posx) {
    this->posx = posx;
}

int Espacio::get_posy() const {
    return posy;
}

void Espacio::set_posy(int posy) {
    this->posy = posy;
}
