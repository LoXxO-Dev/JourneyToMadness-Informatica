//
// Created by User on 5/11/2025.
//

#ifndef PERSONA_HPP
#define PERSONA_HPP


#include "utils.hpp"
class Persona {
private:
    int dato;
    string nombre;

public:
    Persona();
    int get_dato() const;

    void set_dato(int dato);

    string get_nombre() const;

    void set_nombre(const string &nombre);

    Persona(const Persona &orig);
};



#endif //PERSONA_HPP
