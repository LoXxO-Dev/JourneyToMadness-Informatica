//
// Created by User on 2/11/2025.
//

#ifndef LIBRO_HPP
#define LIBRO_HPP


#include "utils.hpp"

class Libro {
private:
    char *codigo;
    char *nombre;
    int ancho;
    int alto;
    double peso;
    bool colocado;

public:
    Libro();
    virtual ~Libro();
    void leer(ifstream &arch);
    void get_codigo(char *codigo) const;

    void set_codigo(const char *codigo);

    void get_nombre(char *nombre) const;

    void set_nombre(const char *nombre);

    int get_ancho() const;

    void set_ancho(int ancho);

    int get_alto() const;

    void set_alto(int alto);

    double get_peso() const;

    void set_peso(double peso);

    bool is_colocado() const;

    void set_colocado(bool colocado);
};


#endif //LIBRO_HPP
