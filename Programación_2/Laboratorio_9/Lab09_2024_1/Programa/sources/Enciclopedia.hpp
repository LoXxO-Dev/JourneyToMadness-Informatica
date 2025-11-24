//
// Created by User on 23/11/2025.
//

#ifndef ENCICLOPEDIA_HPP
#define ENCICLOPEDIA_HPP
#include "Libro.hpp"
#include "utils.hpp"


class Enciclopedia :public Libro{
private:
    int sku;
    int anho;

public:
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
    int get_sku() const;

    void set_sku(int sku);

    int get_anho() const;

    void set_anho(int anho);
};



#endif //ENCICLOPEDIA_HPP
