//
// Created by User on 6/10/2025.
//

#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include "utils.hpp"
#include "Estate.hpp"
#include "Libro.hpp"

class Biblioteca {
public:
    void cargar_libros();

    void cargar_estantes();

    void posicionar_libros();

    void mostrar_datos();

    void imprimiLinea(ofstream &archivo, char car, int cantidad);

    int get_cantidad_estantes() const;

    void set_cantidad_estantes(int cantidad_estantes);

    int get_cantidad_libros() const;

    void set_cantidad_libros(int cantidad_libros);

private:
    Estate estantes[10];
    int cantidad_estantes;
    Libro libros[10];
    int cantidad_libros;
};


#endif //BIBLIOTECA_HPP
