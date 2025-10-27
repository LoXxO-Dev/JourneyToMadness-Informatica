#include "funciones/utils.hpp"
#include "funciones/Restaurante.hpp"
int main() {
    class Restaurante rest;
    rest<"data/CLientes.csv";
    rest<="data/PlatosOfrecidos.csv";
    rest<<="data/Pedidos.csv";
    rest>>"reportes/ReporteDeVentasDelDia.txt";
    return 0;
}