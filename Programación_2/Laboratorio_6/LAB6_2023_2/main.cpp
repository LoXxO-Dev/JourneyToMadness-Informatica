#include "funciones/utils.hpp"
#include "funciones/Almacen.hpp"
int main() {
Almacen almacen;
    almacen.cargar_clientes();
    almacen.cargar_produtos();
    almacen.cargar_pedidos();
    almacen.mostrar_datos();

    return 0;
}