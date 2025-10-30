//
// Created by User on 29/10/2025.
//

#include "Comanda.hpp"

Comanda::Comanda() {
    cantidad_bebidas = 0;
    cantidad_entradas = 0;
    cantidad_platos_fondo = 0;
    tiempo_preparacion = 0;
    estado = nullptr;
}

Comanda::~Comanda() {
    if (this->estado != nullptr) delete this->estado;
}

Comanda::Comanda(const class Comanda &orig) {
    estado = nullptr;
    *this = orig;
}

void Comanda::operator=(const class Comanda &orig) {
    char aux[100];
    orig.get_estado(aux);
    set_estado(aux);
    id = orig.id;
    cantidad_bebidas = orig.cantidad_bebidas;
    cantidad_entradas = orig.cantidad_entradas;
    cantidad_platos_fondo = orig.cantidad_platos_fondo;

    hora_atencion = orig.hora_atencion;
    hora_servicio = orig.hora_servicio;
    tiempo_preparacion = orig.tiempo_preparacion;
    total = orig.total;
}

//738,11:40,12:43
void Comanda::leer(ifstream &arch) {
    int hh, mm;
    char car;
    arch >> id;
    if (arch.eof())return;
    arch.get();
    arch >> hh >> car >> mm >> car;
    hora_atencion = hh * 60 + mm;
    arch >> hh >> car >> mm;
    hora_servicio = hh * 60 + mm;
}

void Comanda::leerComanda(ifstream &arch) {
    char tipo;
    arch >> tipo;
    arch.get();
    switch (tipo) {
        case 'B':
            this->bebidas[cantidad_bebidas].leer(arch);
            cantidad_bebidas++;
            break;
        case 'E':
            this->entradas[cantidad_entradas].leer(arch);
            cantidad_entradas++;
            break;
        case 'P':
            this->platos_fondo[cantidad_platos_fondo].leer(arch);
            cantidad_platos_fondo++;
            break;
        default:
            break;
    }
}

void Comanda::imprimir(ofstream &arch) {
    char aux[100];
    get_estado(aux);
    arch << setw(15) << left << id << right << setw(5) << hora_atencion / 60 << ":" << setw(2) << hora_atencion % 60
            << setw(10) << hora_servicio / 60 << ":" << setw(2) << hora_servicio % 60
            << setw(18) << tiempo_preparacion / 60 << ":" << setw(2) << tiempo_preparacion % 60 << setw(13) <<
            total << setw(25) << aux << endl;
        imprimir_detalles_comanda(arch);
}


void Comanda::imprimir_linea(ofstream &arch, int cant, char car) {
    for (int i=0;i<cant;i++)
        arch.put(car);
    arch<<endl;
}

void Comanda::imprimir_detalles_comanda(ofstream &arch) {
    imprimir_linea(arch,TAM_LINEA-40,'-');
    arch << setw(5) << " " << "Reporte Bebidas" << endl;
    imprimir_linea(arch,TAM_LINEA-40,'-');
    arch<<setw(10)<<" "<<left<<setw(30)<<"NOMBRE"<<setw(15)<<"PRECIO"<<"TAMANO"<<endl;
    imprimir_linea(arch,TAM_LINEA-40,'-');

    for (int i = 0; i < cantidad_bebidas; i++)
        arch << bebidas[i];
    imprimir_linea(arch,TAM_LINEA-40,'-');
    arch << setw(5) << " " << "Reporte Entradas" << endl;
    imprimir_linea(arch,TAM_LINEA-40,'-');
    arch<<setw(10)<<" "<<left<<setw(30)<<"NOMBRE"<<setw(15)<<"PRECIO"<<"PICANTE"<<endl;
    imprimir_linea(arch,TAM_LINEA-40,'-');
    for (int i = 0; i < cantidad_entradas; i++)
        arch << entradas[i];
    imprimir_linea(arch,TAM_LINEA-40,'-');
    arch << setw(5) << " " << "Reporte Platos Fondo" << endl;
    imprimir_linea(arch,TAM_LINEA-40,'-');
    arch<<setw(10)<<" "<<left<<setw(30)<<"NOMBRE"<<setw(15)<<"PRECIO"<<"PROTEINAS"<<endl;
    imprimir_linea(arch,TAM_LINEA-40,'-');
    for (int i = 0; i < cantidad_platos_fondo; i++)
        arch << platos_fondo[i];

}

void Comanda::actualizarComandas() {

    for (int i = 0; i < cantidad_bebidas; i++) {
        tiempo_preparacion +=TIME_BE;
        total+=this->bebidas[i].get_precio();

    }
    for (int i = 0; i < cantidad_entradas; i++) {
        tiempo_preparacion +=TIME_EN;
        total+=this->entradas[i].get_precio();
    }


    for (int i = 0; i < cantidad_platos_fondo; i++) {
        tiempo_preparacion +=TIME_PL;
        total+=this->platos_fondo[i].get_precio();
    }char  aux[100];
    if (hora_servicio-hora_atencion-tiempo_preparacion>=0) {
        strcpy(aux,"ATENDIDA");
    }else {
        strcpy(aux,"ATENDIDA CON RETRASO");
    }
    set_estado(aux);

}


int Comanda::get_id() const {
    return id;
}

void Comanda::set_id(int id) {
    this->id = id;
}

int Comanda::get_cantidad_bebidas() const {
    return cantidad_bebidas;
}

void Comanda::set_cantidad_bebidas(int cantidad_bebidas) {
    this->cantidad_bebidas = cantidad_bebidas;
}

int Comanda::get_cantidad_entradas() const {
    return cantidad_entradas;
}

void Comanda::set_cantidad_entradas(int cantidad_entradas) {
    this->cantidad_entradas = cantidad_entradas;
}

int Comanda::get_cantidad_platos_fondo() const {
    return cantidad_platos_fondo;
}

void Comanda::set_cantidad_platos_fondo(int cantidad_platos_fondo) {
    this->cantidad_platos_fondo = cantidad_platos_fondo;
}

int Comanda::get_hora_atencion() const {
    return hora_atencion;
}

void Comanda::set_hora_atencion(int hora_atencion) {
    this->hora_atencion = hora_atencion;
}

int Comanda::get_hora_servicio() const {
    return hora_servicio;
}

void Comanda::set_hora_servicio(int hora_servicio) {
    this->hora_servicio = hora_servicio;
}

int Comanda::get_tiempo_preparacion() const {
    return tiempo_preparacion;
}

void Comanda::set_tiempo_preparacion(int tiempo_preparacion) {
    this->tiempo_preparacion = tiempo_preparacion;
}

double Comanda::get_total() const {
    return total;
}

void Comanda::set_total(double total) {
    this->total = total;
}

void Comanda::get_estado(char *estado) const {
    if (this->estado == nullptr)delete this->estado;
    else strcpy(estado, this->estado);
}

void Comanda::set_estado(const char *estado) {
    if (this->estado != nullptr)delete this->estado;
    this->estado = new char[strlen(estado) + 1];
    strcpy(this->estado, estado);
}

void operator >>(ifstream &arch, class Comanda &comanda) {
    comanda.leer(arch);
}

void operator<<(ofstream &arch, class Comanda &comanda) {
    comanda.imprimir(arch);
}
