//
// Created by User on 27/10/2025.
//

#include "Multa.hpp"


Multa::Multa() {
    this->placa = nullptr;
}

Multa::Multa(const Multa &orig) {
    placa = nullptr;
    *this = orig;
}

Multa::~Multa() {
    if (this->placa != nullptr)delete this->placa;
}

void Multa::operator=(const Multa &orig) {
    char aux[100];
    orig.get_placa(aux);
    set_placa(aux);
    fechaDeInfraccion = orig.fechaDeInfraccion;
    fechaDePago = orig.fechaDePago;
    codigoInfraccion = orig.codigoInfraccion;
    multa = orig.multa;
}

void Multa::leer(ifstream &arch) {
    // 1/12/2020,G760-721,2022
    //23/7/2023,P474-593,2060,P,22/8/2023
    char buffer[100];
    fechaDeInfraccion = leerFecha(arch);
    arch.get();
    arch.getline(buffer, 100, ',');
    set_placa(buffer);
    arch >> codigoInfraccion;
    if (arch.get() == ',') {
        arch.get();
        arch.get();
        fechaDePago = leerFecha(arch);
    }
}

void Multa::imprimir(ofstream &arch) {
    char buffer[100];
    get_placa(buffer);
    arch<<left<<setw(10)<<" "<<setw(20)<<buffer;
    imprimirFecha(arch,fechaDeInfraccion);
    arch<<setw(20)<<codigoInfraccion<<setw(30)<<multa<<setw(15)<<" ";
    imprimirFecha(arch,fechaDePago);
        arch<<endl;

}
void Multa::imprimirFecha(ofstream &arch,int fecha) {
    int dd=fecha%100;
    int aa=fecha/10000;
    int mm=fecha%10000/100;
    arch<<right<<setfill('0')<<setw(2)<<dd<<"/"<<setw(2)<<
        mm<<"/"<<setw(4)<<aa<<setfill(' ');
}

int Multa::leerFecha(ifstream &arch) {
    int dd, mm, aa;
    char car;
    arch >> dd >> car >> mm >> car >> aa;
    return aa * 10000 + mm * 100 + dd;
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

void operator >>(ifstream &arch, class Multa &multa) {
    multa.leer(arch);
}

void operator <<(ofstream &arch, class Multa &multa) {
    multa.imprimir(arch);
}
