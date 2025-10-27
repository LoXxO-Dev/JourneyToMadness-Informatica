//
// Created by User on 6/10/2025.
//

#ifndef LIBRO_HPP
#define LIBRO_HPP

#include "utils.hpp"


class Libro {
public:
    Libro();

    Libro(const Libro &copia);

    void operator =(const Libro &copia);

    void leerLibro(ifstream &arch);

    void iniciliza();


    void get_codigo(char *codigo) const;

    void set_codigo(const char *codigo);

    void get_nombre(char *nombre) const;

    void set_nombre(const char *nombre);

    int get_ancho() const;

    void set_ancho(int ancho);

    int get_alto() const;

    void set_alto(int alto);

    bool is_colocado() const;

    void set_colocado(bool colocado);

    void imprime(ofstream &arch);

private:
    char *codigo;
    char *nombre;
    int ancho;
    int alto;
    bool colocado;
};
void operator >>(ifstream &arch, class Libro &lib);
void operator <<(ofstream &arch, class Libro lib);

#endif //LIBRO_HPP
