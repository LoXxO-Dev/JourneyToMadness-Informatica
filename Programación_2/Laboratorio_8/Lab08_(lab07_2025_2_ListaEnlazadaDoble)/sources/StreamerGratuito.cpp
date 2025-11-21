//
// Created by User on 20/11/2025.
//

#include "StreamerGratuito.hpp"

#include "Metrica.hpp"
#include "MetricaBasica.hpp"

StreamerGratuito::StreamerGratuito() {
    cantidad_metricas_basicas=0;
}

void StreamerGratuito::actualiza(char *tipo, ifstream &arch) {
    class Metrica *ptr;
    ptr=new class MetricaBasica();
    ptr->leer(arch);
    metricas[cantidad_metricas_basicas]=ptr;
    cantidad_metricas_basicas++;
}

void StreamerGratuito::leer(ifstream &archivo) {
    Streamer::leer(archivo);
    int dd,mm,aa;
    char car;
    archivo>>aa>>car>>mm>>car>>dd;
    archivo.get();
    fecha_fin_trial=aa*10000+mm*100+dd;
}

void StreamerGratuito::imprimir(ofstream &archivo) {
    Streamer::imprimir(archivo);
    archivo<<"StreamerGratuito"<<endl;
    imprimir_linea(archivo,TAM_LINEA,'-');
    archivo<<left<<setw(5)<<" "<<setw(15)<<"Código"<<
    setw(15)<<"Fecha Calc"<<setw(15)<<"Expira"<<
        setw(15)<<"Estado"<<setw(40)<<"Datos adicionales"<<
            setw(15)<<"Descripcion"<<endl;
    for (int i=0;i<cantidad_metricas_basicas;i++) {
        metricas[i]->imprimir(archivo);
    }
    imprimir_linea(archivo,TAM_LINEA,'=');

}

bool StreamerGratuito::eliminable() {
    return true;
}

int StreamerGratuito::get_fecha_fin_trial() const {
    return fecha_fin_trial;
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
