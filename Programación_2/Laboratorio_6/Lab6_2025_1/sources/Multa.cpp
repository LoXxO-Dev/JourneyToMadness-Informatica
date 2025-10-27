//
// Created by User on 1/10/2025.
//

#include "Multa.hpp"

#include <string.h>


Multa::Multa() {
    placa = nullptr;
}

Multa::Multa(const Multa &copia) {
    placa = nullptr;
    *this = copia;
}

Multa::~Multa() {
    if (this->placa != nullptr) delete this->placa;
}


void Multa::operator =(const Multa &copia) {
    char placa[100];
    copia.get_placa(placa);
    set_placa(placa);

     fechaDeInfraccion=copia.get_fecha_de_infraccion();
     fechaDePago=copia.get_fecha_de_pago();
     codigoInfraccion=copia.get_codigo_infraccion();
     multa=copia.get_multa();
}

void Multa::get_placa(char *placa) const {
    if (this->placa == nullptr)placa[0] = 0;
    else strcpy(placa, this->placa);
}

void Multa::set_placa(const char *placa) {
    if (this->placa != nullptr)delete this->placa;
    this->placa = new char[strlen(placa) + 1];
    strcpy(this->placa, placa);
}

int Multa::get_fecha_de_infraccion() const {
    return fechaDeInfraccion;
}

void Multa::set_fecha_de_infraccion(int fecha_de_infraccion) {
    fechaDeInfraccion = fecha_de_infraccion;
}

int Multa::get_fecha_de_pago() const {
    return fechaDePago;
}

void Multa::set_fecha_de_pago(int fecha_de_pago) {
    fechaDePago = fecha_de_pago;
}

int Multa::get_codigo_infraccion() const {
    return codigoInfraccion;
}

void Multa::set_codigo_infraccion(int codigo_infraccion) {
    codigoInfraccion = codigo_infraccion;
}

double Multa::get_multa() const {
    return multa;
}

void Multa::set_multa(double multa) {
    this->multa = multa;
}

void Multa::leerUnaMulta(ifstream &archivo) {

    char placa[20], car;

    int fecha = leerFecha(archivo);
    set_fecha_de_infraccion(fecha);
    archivo.get();
    archivo.getline(placa, 20, ',');
    set_placa(placa);
    archivo >> codigoInfraccion;
    if (archivo.get() == '\n') archivo.unget();
    else {
        archivo >> car >> car;
        set_fecha_de_pago(leerFecha(archivo));
    }
}

int Multa::leerFecha(ifstream &arch) {
    int dd, mm, aa;
    char car;
    arch >> dd >> car >> mm >> car >> aa;
    if (arch.eof())return 0;

    return aa * 10000 + mm * 100 + dd;
}
void Multa::imprimir(ofstream &arch) {
    char placa[20];
    get_placa(placa);
    arch<<setw(15)<<" "<<left<<setw(20)<<placa;
    transformarFecha(arch,this->fechaDeInfraccion);
    arch<<setw(25)<<codigoInfraccion<<setw(25)<<this->multa;
    arch<<setw(10)<<" ";
    transformarFecha(arch,this->fechaDePago);
    arch<<endl;
}
void Multa::transformarFecha(ofstream &arch,int fecha) {
    int dd=fecha%100;
    int mm=fecha%10000/100;
    int aa=fecha/10000;
    arch<<right<<setw(2)<<setfill('0')<<dd<<"/"<<setw(2)<<mm<<"/"<<setw(4)<<aa<<setfill(' ');

}
void operator >>(ifstream &arch, class Multa &mul) {
    mul.leerUnaMulta(arch);
}
void operator <<(ofstream &arch,class Multa mul) {
    mul.imprimir(arch);
}