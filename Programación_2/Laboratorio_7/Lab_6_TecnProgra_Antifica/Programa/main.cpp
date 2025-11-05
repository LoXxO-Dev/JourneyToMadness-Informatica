#include <iostream>

#include "sources/Plataforma.hpp"

int main() {

    Plataforma plataforma;
    plataforma.leerCategorias("data/Categorias.txt");

    plataforma.leerStreams("data/Reproducciones.txt");
    plataforma.imprimirReportes();
    return 0;
}
