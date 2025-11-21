#include "sources/utils.hpp"
#include "sources/GestorStreamers.hpp"

int main() {
    class GestorStreamers gestor;
    gestor.cargar_datos_streamers("data/streamers.csv");
    gestor.actualizar_datos_metricas("data/metricas.csv");
    gestor.generar_reportes("reportes/Reporte.txt");
    gestor.eliminar_streamersGratuitos();
    gestor.generar_reportes("reportes/ReportePostEliminacion.txt");

    return 0;
}
