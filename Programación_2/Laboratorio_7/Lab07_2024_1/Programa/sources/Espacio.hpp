//
// Created by User on 2/11/2025.
//

#ifndef ESPACIO_HPP
#define ESPACIO_HPP


#include "utils.hpp"

class Espacio {
private:
    char contenido;
    int posx;
    int posy;

public:
    char get_contenido() const;

    void set_contenido(char contenido);

    int get_posx() const;

    void set_posx(int posx);

    int get_posy() const;

    void set_posy(int posy);

};


#endif //ESPACIO_HPP
