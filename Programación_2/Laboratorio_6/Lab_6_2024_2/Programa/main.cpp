#include "funciones/Utils.hpp"
#include "funciones/Restaurante.hpp"
int main() {
    Restaurante restaurante;
    restaurante<"data/Clientes.csv";
    restaurante<="data/PlatosOfrecidos.csv";
    restaurante<<="data/Pedidos.csv";
    restaurante>>"reportes/ReporteDeVentasDelDia.txt";
    return 0;
}