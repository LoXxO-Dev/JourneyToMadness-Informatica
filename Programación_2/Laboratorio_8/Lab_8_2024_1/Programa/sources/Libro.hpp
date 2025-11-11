//
// Created by User on 11/11/2025.
//

#ifndef LIBRO_HPP
#define LIBRO_HPP


#include "utils.hpp"

class Libro {
private:
    char *nombre;
    int paginas;
    double peso;

public:
    Libro();
    virtual ~Libro();
    virtual void leer(ifstream &arch);
    virtual void imprime(ofstream &arch);
    virtual void actualiza()=0;
    void get_nombre(char *nombre) const;

    void set_nombre(const char *nombre);

    int get_paginas() const;

    void set_paginas(int paginas);

    double get_peso() const;

    void set_peso(double peso);
};


#endif //LIBRO_HPP
