//
// Created by User on 11/11/2025.
//

#ifndef ENCICLOPEDIA_HPP
#define ENCICLOPEDIA_HPP


#include "Libro.hpp"
#include "utils.hpp"
class Enciclopedia:public Libro {
private:
    int sku;
    int anho;
    int vigencia=1;

public:
    void leer(ifstream &arch);
    void actualiza();
    void imprime(ofstream &arch);
    int get_sku() const;

    void set_sku(int sku);

    int get_anho() const;

    void set_anho(int anho);

    int get_vigencia() const;

    void set_vigencia(int vigencia);
};



#endif //ENCICLOPEDIA_HPP
