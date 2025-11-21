//
// Created by User on 20/11/2025.
//

#include "StreamerPago.hpp"
#include "MetricaBasica.hpp"
#include "MetricaCalidad.hpp"
#include "MetricaEngament.hpp"
StreamerPago::StreamerPago() {
    cantidad_metricas = 0;
}

void StreamerPago::actualiza(char *tipo, ifstream &arch) {
    class Metrica *ptr;
    if (strcmp(tipo, "ENGAGEMENT") == 0)
        ptr = new class MetricaEngament();
    else if (strcmp(tipo, "BASIC") == 0)
        ptr = new class MetricaBasica();
    else if (strcmp(tipo, "QUALITY") == 0)
        ptr = new class MetricaCalidad();

    ptr->leer(arch);
    metricas[cantidad_metricas] = ptr;
    cantidad_metricas++;
}

bool StreamerPago::eliminable() {
    return false;
}

void StreamerPago::leer(ifstream &archivo) {
    Streamer::leer(archivo);
    int dd, mm, aa;
    char car;
    archivo >> aa >> car >> mm >> car >> dd;
    archivo.get();
    fecha_fin_plan = aa * 10000 + mm * 100 + dd;
}

void StreamerPago::imprimir(ofstream &archivo) {
    Streamer::imprimir(archivo);
    archivo<<"Streamer Pago"<<endl;
    imprimir_linea(archivo,TAM_LINEA,'-');
    archivo<<left<<setw(5)<<" "<<setw(15)<<"Código"<<
    setw(15)<<"Fecha Calc"<<setw(15)<<"Expira"<<
        setw(15)<<"Estado"<<setw(40)<<"Datos adicionales"<<
            setw(15)<<"Descripcion"<<endl;
    for (int i=0;i<cantidad_metricas;i++) {
        metricas[i]->imprimir(archivo);
    }
    imprimir_linea(archivo,TAM_LINEA,'=');

}

int StreamerPago::get_fecha_fin_plan() const {
    return fecha_fin_plan;
}

void StreamerPago::set_fecha_fin_plan(int fecha_fin_plan) {
    this->fecha_fin_plan = fecha_fin_plan;
}

int StreamerPago::get_cantidad_metricas() const {
    return cantidad_metricas;
}

void StreamerPago::set_cantidad_metricas(int cantidad_metricas) {
    this->cantidad_metricas = cantidad_metricas;
}
