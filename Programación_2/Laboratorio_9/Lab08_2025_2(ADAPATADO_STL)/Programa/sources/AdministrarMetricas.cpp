//
// Created by User on 25/11/2025.
//

#include "AdministrarMetricas.hpp"
#include "MetricaBasica.hpp"
#include "MetricaEngagement.hpp"
#include "MetricaCalidad.hpp"

void AdministrarMetricas::cargarArchivo(const char *nomb) {
    ifstream arch;
    apertura_archivos_entrada(arch, nomb);
    //ENGAGEMENT,320975,121,Maratón de chat,2025-10-17,2025-10-31,1535,553,54
    char tipo[100];
    while (true) {
        class Metrica *aux;
        arch.getline(tipo, 100, ',');
        if (arch.eof()) break;
        if (strcmp(tipo, "ENGAGEMENT") == 0)
            aux = new class MetricaEngagement();
        else if (strcmp(tipo, "BASIC") == 0)
            aux = new class MetricaBasica();
        else if (strcmp(tipo, "QUALITY") == 0)
            aux = new class MetricaCalidad();
        aux->leer(arch);
        listaDeMetricas.push_back(aux);
    }
    ordenar();
}

void AdministrarMetricas::generarReporte(const char *nomb) {
    ofstream arch;
    apertura_archivos_salida(arch, nomb);
    arch << fixed << setprecision(2);
    imprimir_Linea(arch,TAM_LINEA, '=');
    arch << setw(60) << "REPORTE DE METRICAS" << endl;
    imprimir_Linea(arch,TAM_LINEA, '=');
    int tipo, tipoEntrante, cantAct = 0, cantExpira = 0;
    bool primero = true, cambio = false;
    for (auto &x: listaDeMetricas) {
        tipoEntrante = x->obtener_tipo();
        if (tipo != tipoEntrante) cambio = true;
        else cambio = false;
        if (primero or cambio) {
            if (not primero) imprimir_Linea(arch,TAM_LINEA, '-');
            tipo = tipoEntrante;
            if (tipoEntrante == BASICA)encabezadoBasica(arch);
            else if (tipoEntrante == ENGAGEMENT)encabezadoEngage(arch);
            else if (tipoEntrante == CALIDAD)encabezadoCalidad(arch);
            cambio = primero = false;
        }
        x->imprimir(arch);
        if (x->is_estado())cantAct++;
        else cantExpira++;
    }
    imprimirEstadisticas(arch, cantAct, cantExpira);
}

void AdministrarMetricas::ordenar() {
    listaDeMetricas.sort([](class Metrica *a, class Metrica *b) {
        return *a < *b;
    });
}

void AdministrarMetricas::eliminarNodos() {
    for (list<class Metrica *>::iterator it = listaDeMetricas.begin(); it != listaDeMetricas.end();) {
        if (not (*it)->is_estado())
            it = listaDeMetricas.erase(it);
        else it++;
    }
}

void AdministrarMetricas::eliminarLista() {
    listaDeMetricas.erase(listaDeMetricas.begin(),listaDeMetricas.end());

}

void AdministrarMetricas::encabezadoCalidad(ofstream &arch) {
    arch << "[METRICAS QUALITY]" << endl;
    encabezadoGlobal(arch);
    arch << setw(15) << "Bitrate" << setw(15) << "Drop%" << setw(15) <<
            "FPS" << endl;
}

void AdministrarMetricas::encabezadoEngage(ofstream &arch) {
    arch << "[METRICAS ENGAGE]" << endl;
    encabezadoGlobal(arch);
    arch << setw(15) << "Msgs" << setw(15) << "Chatters" <<
            setw(15) << "Clips" << endl;
}

void AdministrarMetricas::encabezadoBasica(ofstream &arch) {
    arch << "[METRICAS BASIC]" << endl;
    encabezadoGlobal(arch);
    arch << setw(15) << "Horas" << setw(15) << "Viewers" << endl;
}

void AdministrarMetricas::encabezadoGlobal(ofstream &arch) {
    arch << setw(5) << " " << left << setw(15) << "Código" <<
            setw(30) << "Descripción" << setw(15) << "Fecha Calc." <<
            setw(15) << "Expira" << setw(20) << "Estado";
}

void AdministrarMetricas::imprimirEstadisticas(ofstream &arch, int cantAct, int cantExpi) {
    imprimir_Linea(arch,TAM_LINEA, '-');
    arch << "[TOTAL] METRICAS ACTIVAS: " << cantAct << " |MÉTRICAS EXPIRADAS: " << cantExpi << " |FECHA DE REPORTE: " <<
            FECHA_ACTUAL / 10000 << "-" << FECHA_ACTUAL % 10000 / 100 << "-" << FECHA_ACTUAL % 100 << endl;
    imprimir_Linea(arch,TAM_LINEA, '=');
}
