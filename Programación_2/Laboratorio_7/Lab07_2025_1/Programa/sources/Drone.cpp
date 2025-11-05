//
// Created by User on 4/11/2025.
//

#include "Drone.hpp"

Drone::Drone() {
    id=nullptr;
    ubicacion=nullptr;
    cantidad_infracciones=0;
}

Drone::Drone(const Drone &orig) {
    id=nullptr;
    ubicacion=nullptr;

    *this=orig;
}

void Drone::operator=(const Drone &orig) {
    char aux[100];
    orig.get_ubicacion(aux);
    set_ubicacion(aux);
    orig.get_id(aux);
    set_id(aux);
    capacidad=orig.get_capacidad();
    cantidad_infracciones=orig.get_cantidad_infracciones();
    for (int i=0;i<cantidad_infracciones;i++)
        infracciones[i]=orig.infracciones[i];
}

Drone::~Drone() {
    if (id)delete id;
    if (ubicacion)delete ubicacion;
}

void Drone::leer(ifstream &arch) {

    char aux[100];
    arch.getline(aux, 100,',');
    set_id(aux);
    arch.getline(aux, 100,',');
    set_ubicacion(aux);
    arch>>capacidad;
    arch.get();

}

void Drone::leerInfra(ifstream &arch,int dato,double& multa) {
    infracciones[cantidad_infracciones].leer(arch, dato,multa);
    cantidad_infracciones++;
}

void Drone::imprimir(ofstream &arch) {
    char aux[100],id_aux[20];
    get_id(id_aux);
    get_ubicacion(aux);
    arch<<left<<setw(20)<<id_aux<<setw(20)<<aux<<right<<
        setw(10)<<capacidad;



}

void Drone::imprimirInfra(ofstream &arch) {
    arch<<setw(10)<<" "<<"Infracciones registradas"<<endl;
    imprimirLinea(arch,TAM_LINEA-40,'=');
    arch<<setw(10)<<" "<<left<<setw(15)<<"Placa"<<setw(20)<<
        "Tipo"<<setw(20)<<"Fecha Suceso"<<setw(15)<<"Fecha Pago"<<"Monto"<<endl;
    imprimirLinea(arch,TAM_LINEA-40,'=');

    for (int i=0;i<cantidad_infracciones;i++)
        infracciones[i].imprimir(arch);
}

void Drone::get_id(char *id) const {
    if (this->id == nullptr)id[0] = 0;
    else strcpy(id, this->id);
}

void Drone::set_id(const char *id) {
    if (this->id)delete this->id;
    this->id = new char[strlen(id) + 1];
    strcpy(this->id, id);

}

void Drone::get_ubicacion(char *ubicacion) const {
    if (this->ubicacion == nullptr)ubicacion[0] = 0;
    else strcpy(ubicacion, this->ubicacion);
}

void Drone::set_ubicacion(const char *ubicacion) {
    if (this->ubicacion)delete this->ubicacion;
    this->ubicacion = new char[strlen(ubicacion) + 1];
    strcpy(this->ubicacion, ubicacion);
}

int Drone::get_capacidad() const {
    return capacidad;
}

void Drone::set_capacidad(int capacidad) {
    this->capacidad = capacidad;
}

int Drone::get_cantidad_infracciones() const {
    return cantidad_infracciones;
}

void Drone::set_cantidad_infracciones(int cantidad_infracciones) {
    this->cantidad_infracciones = cantidad_infracciones;
}
