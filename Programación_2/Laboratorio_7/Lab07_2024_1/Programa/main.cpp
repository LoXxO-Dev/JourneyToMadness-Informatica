#include "sources/utils.hpp"
#include "sources/Biblioteca.hpp"
int main() {
    Biblioteca biblioteca;
    biblioteca.cargar_libros();
    biblioteca.cargar_estantes();
    biblioteca.posicionar_libros();
    biblioteca.mostrar_datos();
    return 0;
}