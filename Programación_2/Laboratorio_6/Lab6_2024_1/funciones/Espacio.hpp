//
// Created by User on 6/10/2025.
//

#ifndef ESPACIO_HPP
#define ESPACIO_HPP


#include "utils.hpp"

class Espacio {
public:
    char get_contenido() const;

    void set_contenido(char contenido);

    int get_pos_x() const;

    void set_pos_x(int pos_x);

    int get_pos_y() const;

    void set_pos_y(int pos_y);
void imprime(ofstream &arch);
private:
    char contenido;
    int posX;
    int posY;
};
void operator <<(ofstream &arch,Espacio &espa);



#endif //ESPACIO_HPP
