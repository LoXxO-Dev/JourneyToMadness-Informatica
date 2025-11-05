//
// Created by User on 4/11/2025.
//

#include "Flota.hpp"

Flota::Flota() {
    n_drones_velocidad = 0;
    n_drones_semaforo = 0;
    n_drones_estacionamiento = 0;
}

void Flota::cargar_drones(ifstream &arch, char *tipo_dron) {
    if (strcmp(tipo_dron, "Velocidad") == 0) {
        this->drones_velocidad[n_drones_velocidad++].leer(arch);
    } else if (strcmp(tipo_dron, "Semaforo") == 0) {
        this->drones_semaforo[n_drones_semaforo++].leer(arch);
    } else if (strcmp(tipo_dron, "Estacionamiento") == 0) {
        this->drones_estacionamientos[n_drones_estacionamiento++].leer(arch);
    }
}

void Flota::imprimir(ofstream &arch) {
    arch<<"Drones Estacionamiento"<<endl;
    imprimirLinea(arch,TAM_LINEA,'-');
    arch<<left<<setw(20)<<"ID"<<setw(25)<<"Ubicacion"<<setw(15)<<"Capacidad"<<setw(10)<<"Zona carga"<<endl;
    imprimirLinea(arch,TAM_LINEA,'-');
    for (int i=0;i<n_drones_estacionamiento;i++) {
        this->drones_estacionamientos[i].imprimir(arch);
    }
    imprimirLinea(arch,TAM_LINEA,'-');
    arch<<"Drones Semaforo"<<endl;
    arch<<left<<setw(20)<<"ID"<<setw(25)<<"Ubicacion"<<setw(15)<<"Capacidad"<<setw(10)<<"Luz roja"<<endl;
    imprimirLinea(arch,TAM_LINEA,'-');
    for (int i=0;i<n_drones_semaforo;i++) {
        this->drones_semaforo[i].imprimir(arch);
    }
    imprimirLinea(arch,TAM_LINEA,'-');
    arch<<"Drones Velocidad"<<endl;
    arch<<left<<setw(20)<<"ID"<<setw(25)<<"Ubicacion"<<setw(15)<<"Capacidad"<<setw(10)<<"Velo Max"<<endl;
    imprimirLinea(arch,TAM_LINEA,'-');
    for (int i=0;i<n_drones_velocidad;i++) {
        this->drones_velocidad[i].imprimir(arch);
    }
}

void Flota::actualizarDronesInfracciones(ifstream &arch, double &multa) {
    char aux[100], tipo[3], id[100];
    int pos;
    arch >> tipo;
    arch.getline(aux, 100, ',');
    strcpy(id, tipo);
    strcat(id, aux);
    if (strcmp(tipo, "DV") == 0) {
        pos = buscarDroneVelocidad(id);
        drones_velocidad[pos].leerInfra(arch, multa);
    } else if (strcmp(tipo, "DS") == 0) {
        pos = buscarDroneSemaforo(id);
        drones_semaforo[pos].leerInfra(arch, multa);
    } else if (strcmp(tipo, "DE") == 0) {
        pos = buscarDroneEstacionamiento(id);
        drones_estacionamientos[pos].leerInfra(arch, multa);
    }
}

int Flota::buscarDroneVelocidad(const char *id) {
    for (int i = 0; i < n_drones_velocidad; i++) {
        char aux[100];
        drones_velocidad[i].get_id(aux);
        if (strcmp(aux, id) == 0) return i;
    }
    return -1;
}

int Flota::buscarDroneEstacionamiento(const char *id) {
    for (int i = 0; i < n_drones_estacionamiento; i++) {
        char aux[100];
        drones_estacionamientos[i].get_id(aux);
        if (strcmp(aux, id) == 0) return i;
    }
    return -1;
}

int Flota::buscarDroneSemaforo(const char *id) {
    for (int i = 0; i < n_drones_semaforo; i++) {
        char aux[100];
        drones_semaforo[i].get_id(aux);
        if (strcmp(aux, id) == 0) return i;
    }
    return -1;
}

int Flota::get_n_drones_velocidad() const {
    return n_drones_velocidad;
}

void Flota::set_n_drones_velocidad(int n_drones_velocidad) {
    this->n_drones_velocidad = n_drones_velocidad;
}

int Flota::get_n_drones_semaforo() const {
    return n_drones_semaforo;
}

void Flota::set_n_drones_semaforo(int n_drones_semaforo) {
    this->n_drones_semaforo = n_drones_semaforo;
}

int Flota::get_n_drones_estacionamiento() const {
    return n_drones_estacionamiento;
}

void Flota::set_n_drones_estacionamiento(int n_drones_estacionamiento) {
    this->n_drones_estacionamiento = n_drones_estacionamiento;
}
