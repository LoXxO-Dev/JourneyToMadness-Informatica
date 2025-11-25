#include "sources/utils.hpp"
#include "sources/AdministrarMetricas.hpp"

int main() {
    class AdministrarMetricas administrar;
    administrar.cargarArchivo("data/metricas (1).csv");
    administrar.generarReporte("reportes/Reporte.txt");
    administrar.eliminarNodos();
    administrar.generarReporte("reportes/ReporteSoloActivos.txt");
    administrar.eliminarLista();
    //Ojo hay un metodo en el sort pongo esto
    /*
    void AdministrarMetricas::ordenar() {
    listaDeMetricas.sort([](class Metrica *a, class Metrica *b) {
        return *a < *b;
    });
}
Esto lo  puse de ChatGpt porque no me dejaba comparar dos puntero a la clase padre
     */
    return 0;
}
