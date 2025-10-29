//
// Created by User on 6/10/2025.
//

#ifndef ESTATE_HPP
#define ESTATE_HPP


#include "utils.hpp"
#include "Libro.hpp"
#include "Espacio.hpp"

class Estate {
public:
    Estate();

    void operator =(const Estate &esta);

    Estate(const Estate &esta);

    bool operator +=( class Libro &lib);


    void leerEstante(ifstream &arch);

    void get_codigo(char *codigo) const;

    void set_codigo(const char *codigo);

    int get_anchura() const;

    void set_anchura(int anchura);

    int get_altura() const;

    void set_altura(int altura);

    int get_cantidad_libros() const;

    void set_cantidad_libros(int cantidad_libros);

    void imprime(ofstream &arch);

    void imprimiLinea(ofstream &archivo, char car, int cantidad);

private:
    char *codigo;
    int anchura;
    int altura;
    Libro libro[10];
    Espacio *espacios;
    int cantidad_libros;
};

void operator>>(ifstream &arch, class Estate &esta);

void operator <<(ofstream &arch,  class Estate& esta);

#endif //ESTATE_HPP
