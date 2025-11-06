//
// Created by User on 5/11/2025.
//

#include "Persona.hpp"


Persona::Persona() {

}

int Persona::get_dato() const {
    return dato;
}

void Persona::set_dato(int dato) {
    this->dato = dato;
}

string Persona::get_nombre() const {
    return nombre;
}

void Persona::set_nombre(const string &nombre) {
    this->nombre = nombre;
}

Persona::Persona(const Persona &orig) {
    cout<<"LLAMAME";
}
