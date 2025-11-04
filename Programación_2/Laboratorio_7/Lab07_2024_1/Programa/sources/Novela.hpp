//
// Created by User on 2/11/2025.
//

#ifndef NOVELA_HPP
#define NOVELA_HPP

#include "Libro.hpp"
#include "utils.hpp"

class Novela:public Libro {
private:
    char *tipo;
    double peso;

public:
    Novela();
    virtual ~Novela();
    Novela(const Novela &nove);
    void imprimir(ofstream &arch);
    void operator =(const class Novela &nove);
    void leer(ifstream &arch);
    void  get_tipo(char *tipo) const;

    void set_tipo(const char *tipo);

    double get_peso() const;

    void set_peso(double peso);
};
void operator >>(ifstream &arch,Novela &nove);


#endif //NOVELA_HPP
