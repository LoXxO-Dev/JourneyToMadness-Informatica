//
// Created by User on 11/11/2025.
//

#include "StreamerGratuito.hpp"
#include "MetricaBasica.hpp"
void StreamerGratuito::leer(ifstream &arch) {
    Streamer::leer(arch);
    int aa,mm,dd;
    char car;
    arch>>aa>>car>>mm>>car>>dd;
    arch.get();
    fecha_fin_trial=aa*10000*mm*100+dd;
}

void StreamerGratuito::imprimir(ofstream &arch) {
    Streamer::imprimir(arch);
    arch<<"Streamer Gratuito"<<endl;
    imprimir_linea(arch,TAM_LINEA,'-');
arch<<left<<setw(5)<<" "<<setw(15)<<"Código"<<
    setw(15)<<"Fecha Calc"<<setw(15)<<"Expira"<<
        setw(15)<<"Estado"<<setw(40)<<"Datos adicionales"<<
            setw(15)<<"Descripcion"<<endl;
    for (int i=0;i<cantidad_metricas_basicas;i++) {
        metricas[i]->imprimir(arch);
    }

}

int StreamerGratuito::get_fecha_fin_trial() const {
    return fecha_fin_trial;
}

void StreamerGratuito::actualiza(char *tipo, ifstream &arch) {
  metricas[cantidad_metricas_basicas]=new class MetricaBasica();
    metricas[cantidad_metricas_basicas]->leer(arch);
    cantidad_metricas_basicas++;
}

void StreamerGratuito::set_fecha_fin_trial(int fecha_fin_trial) {
    this->fecha_fin_trial = fecha_fin_trial;
}

int StreamerGratuito::get_cantidad_metricas_basicas() const {
    return cantidad_metricas_basicas;
}

void StreamerGratuito::set_cantidad_metricas_basicas(int cantidad_metricas_basicas) {
    this->cantidad_metricas_basicas = cantidad_metricas_basicas;
}
