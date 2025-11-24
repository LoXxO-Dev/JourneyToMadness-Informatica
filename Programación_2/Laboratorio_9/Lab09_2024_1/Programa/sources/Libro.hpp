//
// Created by User on 23/11/2025.
//

#ifndef LIBRO_HPP
#define LIBRO_HPP


#include "utils.hpp"
class Libro {
private:
    string nombre;
    int paginas;
    double peso;

public:
   virtual void leer(ifstream &arch);
    virtual void imprimir(ofstream &arch);
    string get_nombre() const;

    void set_nombre(const string &nombre);

    int get_paginas() const;

    void set_paginas(int paginas);

    double get_peso() const;

    void set_peso(double peso);
};



#endif //LIBRO_HPP
