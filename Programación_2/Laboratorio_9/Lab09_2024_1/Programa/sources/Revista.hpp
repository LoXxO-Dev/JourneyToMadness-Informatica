//
// Created by User on 23/11/2025.
//

#ifndef REVISTA_HPP
#define REVISTA_HPP


#include "Libro.hpp"
#include "utils.hpp"
class Revista :public Libro{
    private:
    int ISSN;
    int anho;
    int numero;

public:
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
    int get_issn() const;

    void set_issn(int issn);

    int get_anho() const;

    void set_anho(int anho);

    int get_numero() const;

    void set_numero(int numero);
};



#endif //REVISTA_HPP
