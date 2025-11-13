#include "sources/utils.hpp"
#include "sources/GestorStreamers.hpp"
int main() {
    GestorStreamers gestor;
    gestor.cargar_datos_streamers("data/streamers.csv");
    gestor.actualizar_datos_metricas("data/metricas.csv");
    gestor.generar_reportes("reporte/Reporte.txt");
    return 0;
}