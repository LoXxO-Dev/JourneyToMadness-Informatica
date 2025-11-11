//
// Created by User on 11/11/2025.
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
    int vigencia=1;

public:
    void leer(ifstream &arch);
    void imprime(ofstream &arch);
    void actualiza();
    int get_issn() const;

    void set_issn(int issn);

    int get_anho() const;

    void set_anho(int anho);

    int get_numero() const;

    void set_numero(int numero);

    int get_vigencia() const;

    void set_vigencia(int vigencia);
};



#endif //REVISTA_HPP
