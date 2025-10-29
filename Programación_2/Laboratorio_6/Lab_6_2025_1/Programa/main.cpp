#include "funciones/utils.hpp"
#include "funciones/MinisterioDeTransporte.hpp"
int main() {
    class MinisterioDeTransporte ministerio;
    ministerio<"data/TablaDeInfracciones.csv";
    ministerio<="data/EmpresasRegistradas.csv";
    ministerio<<="data/InfraccionesCometidas.csv";
    ministerio>>"reportes/ReporteParaElMinisterio.txt";
    return 0;
}