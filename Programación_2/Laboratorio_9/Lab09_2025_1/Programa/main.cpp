#include "sources/utils.hpp"
#include "sources/MinisterioDeTransporte.hpp"
int main() {
    class MinisterioDeTransporte ministerio;
    ministerio.cargaDeInfracciones("Datos/TablaDeInfracciones (3).csv");
    ministerio.cargaEmpresas("Datos/EmpresasRegistradas (2).csv");
    ministerio.cargaVehiculos("Datos/VehiculosRegistrados.csv");
    ministerio.cargaInfraccionesCometidas("Datos/InfraccionesCometidas (3).csv");
    ministerio.reporteDeEmpresasConInfracciones("Reportes/Reporte.txt");
    ministerio.eliminaInfraccionesPagadas();
    ministerio.reporteDeEmpresasConInfracciones("Reportes/ReportePostEliminacion.txt");
//EM LA CLASE MINISTERIO EL PDF DICE QUE LO TRABAJEN COMO LISTAS PERO EN PLENO LAB ESA VEZ DIJERON QUE LO TRABAJEN COMO
    //VECTOR POR ESO ESTA COMO VECTOR


    //PSDT:
    //ESPERO QUE TE SIRVA S...
    //SUERTE EN ESTA ULTIMA ETAPA DE FINALES .....
    //UN ESFUERZO MAS PARA CERRAR ESTE CICLO...ANIMO

    return 0;
}