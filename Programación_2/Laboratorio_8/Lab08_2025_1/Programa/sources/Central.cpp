//
// Created by User on 7/11/2025.
//

#include "Central.hpp"

#include "DroneEstacionamiento.hpp"
#include "DroneSemaforo.hpp"
#include "DroneVelocidad.hpp"

void Central::carga() {
    ifstream arch("data/Drones.csv", ios::in);
    if (not arch.is_open()) {
        cout << "ERROR";
        exit(1);
    }
    //     Velocidad,DV001,Avenida A,5,60
    // Semaforo,DS473,Avenida B,10,true
    char tipo[100];
    while (true) {
        arch.getline(tipo, 100, ',');
        if (arch.eof()) break;
        Dron *aux;
        if (strcmp(tipo, "Velocidad") == 0)
            aux = new class DroneVelocidad;
        else if (strcmp(tipo, "Semaforo") == 0)
            aux = new class DroneSemaforo;
        else if (strcmp(tipo, "Estacionamiento") == 0)
            aux = new class DroneEstacionamiento;
        aux->leer(arch);
        ADrones.insertar(aux);

    }
}

void Central::actualiza() {
    this->ADrones.actualiza();

}

void Central::muestra() {
    ofstream arch("Reporte/reporte.txt", ios::out);
    if (not arch.is_open()) {
        cout << "ERROR:  no se pudo abrir el archivo reporte.txt"<<endl;
        exit(1);
    }
    arch<<fixed<<setprecision(2);
    arch<<setw(50)<<"REPORTE DE DRONES"<<endl;
    imprimirLinea(arch,TAM_LINEA,'=');
    arch<<setw(10)<<" "<<left<<setw(10)<<"Codigo"
    <<setw(15)<<"Ubicacion"<<setw(15)<<"Capacidad"<<"Velocidad/Zona/Luz"<<endl;
    imprimirLinea(arch,TAM_LINEA,'=');
    this->ADrones.imprimir(arch);

}
