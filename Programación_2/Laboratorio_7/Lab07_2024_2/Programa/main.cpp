#include "funciones/utils.hpp"
#include "funciones/Restaurante.hpp"
int main() {
    Restaurante restaurante;
    restaurante.cargar_comandas();
    restaurante.actualizar_comandas();
    restaurante.imprimir_comandas();
    //S
    return 0;
}