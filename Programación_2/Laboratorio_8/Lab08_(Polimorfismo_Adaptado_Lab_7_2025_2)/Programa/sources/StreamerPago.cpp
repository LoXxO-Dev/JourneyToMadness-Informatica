//
// Created by User on 11/11/2025.
//

#include "StreamerPago.hpp"
#include "MetricaBasica.hpp"
#include "MetricaCalidad.hpp"
#include "MetricaEngagement.hpp"
void StreamerPago::leer(ifstream &arch) {
    Streamer::leer(arch);
    int dd,aa,mm;
    char car;
    arch>>aa>>car>>mm>>car>>dd;
    arch.get();
    fecha_inicio_plan=aa*10000*mm*100+dd;
}

void StreamerPago::imprimir(ofstream &arch) {
    Streamer::imprimir(arch);
    arch<<"Streamer Pago"<<endl;
    imprimir_linea(arch,TAM_LINEA,'-');
    arch<<left<<setw(5)<<" "<<setw(15)<<"Código"<<
    setw(15)<<"Fecha Calc"<<setw(15)<<"Expira"<<
        setw(15)<<"Estado"<<setw(40)<<"Datos adicionales"<<
            setw(15)<<"Descripcion"<<endl;
    for (int i=0;i<cantidad_metricas;i++) {
        metricas[i]->imprimir(arch);
    }

}
// ENGAGEMENT,491652,127,Q&A largo,2025-07-03,2025-12-31,520,886,80
// BASIC,702634,3032,FPS sólidos,2025-12-31,2025-12-31,0.194,48
// QUALITY,360198,3054,FPS sólidos,2025-08-22,2025-10-31,4673,0.013,60
void StreamerPago::actualiza(char *tipo, ifstream &arch) {
    if (strcmp(tipo,"ENGAGEMENT")==0)
        metricas[cantidad_metricas]=new class MetricaEngagement();
    else if (strcmp(tipo,"BASIC")==0)
        metricas[cantidad_metricas]=new class MetricaBasica();
    else if (strcmp(tipo,"QUALITY")==0)
        metricas[cantidad_metricas]=new class MetricaCalidad();
    metricas[cantidad_metricas]->leer(arch);
    cantidad_metricas++;

}

int StreamerPago::get_fecha_inicio_plan() const {
    return fecha_inicio_plan;
}

void StreamerPago::set_fecha_inicio_plan(int fecha_inicio_plan) {
    this->fecha_inicio_plan = fecha_inicio_plan;
}

int StreamerPago::get_cantidad_metricas() const {
    return cantidad_metricas;
}

void StreamerPago::set_cantidad_metricas(int cantidad_metricas) {
    this->cantidad_metricas = cantidad_metricas;
}
