//
// Created by User on 20/11/2025.
//

#include "GestorStreamers.hpp"

void GestorStreamers::cargar_datos_streamers(const char *nombArch) {
    ifstream arch;
    apertura_archivo_entrada(arch, nombArch);
    char tipo[100];
    while(true) {
        arch.getline(tipo, 100,',');
        if (arch.eof()) break;
        lista.leer(tipo, arch);
    }
}

void GestorStreamers::actualizar_datos_metricas(const char *nombArch) {
    ifstream arch;
    apertura_archivo_entrada(arch, nombArch);
    char tipo[100];
    while(true) {
        arch.getline(tipo, 100,',');
        if (arch.eof()) break;
        lista.actualizar(tipo, arch);
    }
}

void GestorStreamers::generar_reportes(const char *nombArch) {
    ofstream arch;
    apertura_archivo_salida(arch, nombArch);
    imprimir_linea(arch,TAM_LINEA,'=');
    arch<<setw(50)<<"REPORTE DE STREAMERS"<<endl;
    imprimir_linea(arch,TAM_LINEA,'=');
    lista.imprimir(arch);

}

void GestorStreamers::eliminar_streamersGratuitos() {
    //lista.eliminar();
    lista.eliminarSinAnterior();
}

