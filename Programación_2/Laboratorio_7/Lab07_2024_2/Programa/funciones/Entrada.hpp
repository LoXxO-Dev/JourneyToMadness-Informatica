//
// Created by User on 29/10/2025.
//

#ifndef ENTRADA_HPP
#define ENTRADA_HPP


#include "Producto.hpp"
#include "utils.hpp"

class Entrada : public Producto {
private:
    bool picante;

public:
    Entrada();

    bool is_picante() const;

    void set_picante(bool picante);

    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
};
void operator <<(ofstream &arch,class Entrada &entr);


#endif //ENTRADA_HPP
