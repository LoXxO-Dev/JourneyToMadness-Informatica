//
// Created by User on 4/11/2025.
//

#include "CentralDeMonitoreo.hpp"

CentralDeMonitoreo::CentralDeMonitoreo() {
    cantidad_multas_registradas=0;
    total_multas_acumuladas=0;
}

void CentralDeMonitoreo::leer(ifstream &arch, char *tipo_dron) {
  flota.cargar_drones(arch,tipo_dron);
}

void CentralDeMonitoreo::cargar_infracciones(ifstream &arch) {
    double multa;
     flota.actualizarDronesInfracciones(arch,multa);
    if (arch.eof()) return;
    cantidad_multas_registradas++;
    total_multas_acumuladas+=multa;

}

int CentralDeMonitoreo::get_cantidad_multas_registradas() const {
    return cantidad_multas_registradas;
}

void CentralDeMonitoreo::imprimir(ofstream &arch) {
    this->flota.imprimir(arch);
    imprimirLinea(arch,TAM_LINEA,'-');
    arch<<left<<setw(30)<<"Cantidad Multas Registradas: "<<cantidad_multas_registradas<<endl;
    arch<<left<<setw(30)<<"Total multas "<<"S/"<<total_multas_acumuladas<<endl;

}

void CentralDeMonitoreo::set_cantidad_multas_registradas(int cantidad_multas_registradas) {
    this->cantidad_multas_registradas = cantidad_multas_registradas;
}

double CentralDeMonitoreo::get_total_multas_acumuladas() const {
    return total_multas_acumuladas;
}

void CentralDeMonitoreo::set_total_multas_acumuladas(double total_multas_acumuladas) {
    this->total_multas_acumuladas = total_multas_acumuladas;
}
