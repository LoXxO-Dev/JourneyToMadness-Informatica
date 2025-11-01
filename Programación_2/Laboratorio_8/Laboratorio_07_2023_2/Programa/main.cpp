#include "sources/utils.hpp"
#include "sources/Almacen.hpp"

int main() {
    Almacen almacen;
    almacen.cargar_pedidos();
    almacen.actualizar_pedidos();
    almacen.imprimir_ordenes_ventas();
    return 0;
}
