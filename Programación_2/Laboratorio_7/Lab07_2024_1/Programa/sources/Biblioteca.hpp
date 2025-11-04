//
// Created by User on 3/11/2025.
//

#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include "EstanteHorizontal.hpp"
#include "EstanteVertical.hpp"
#include "utils.hpp"

class Biblioteca {
private:
    EstanteVertical estantesVerticales[10];
    int cantidad_estantes_verticales;
    EstanteHorizontal estanteHorizontales[10];
    int cantidad_estantes_horizontales;
    Enciclopedia enciclopedias[10];
    int cantidad_total_enciclopedias;
    Novela novelas[10];
    int cantidad_total_novelas;

public:
    Biblioteca();
    void imprimir_libro(ofstream &arch);
    void imprimir(ofstream &arch,char car,int cant);
    void cargar_libros();
    void cargar_estantes();
    void posicionar_libros();
    void mostrar_datos();
    void imprimir_linea(ofstream &arch,char car,int cant);
    int get_cantidad_estantes_verticales() const;

    void set_cantidad_estantes_verticales(int cantidad_estantes_verticales);

    int get_cantidad_estantes_horizontales() const;

    void set_cantidad_estantes_horizontales(int cantidad_estantes_horizontales);

    int get_cantidad_total_enciclopedias() const;

    void set_cantidad_total_enciclopedias(int cantidad_total_enciclopedias);

    int get_cantidad_total_novelas() const;

    void set_cantidad_total_novelas(int cantidad_total_novelas);
};


#endif //BIBLIOTECA_HPP
