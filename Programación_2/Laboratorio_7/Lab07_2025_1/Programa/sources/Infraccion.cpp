//
// Created by User on 4/11/2025.
//

#include "Infraccion.hpp"

Infraccion::Infraccion() {
    tipo_infraccion = nullptr;
    placa = nullptr;
}

Infraccion::Infraccion(const Infraccion &infraccion) {
    tipo_infraccion = nullptr;
    placa = nullptr;

    *this = infraccion;
}

void Infraccion::operator=(const Infraccion &infraccion) {
    char aux[100];
    infraccion.get_tipo_infraccion(aux);
    set_tipo_infraccion(aux);
    infraccion.get_placa(aux);
    set_placa(aux);

    fecha_evento = infraccion.get_fecha_evento();
    monto = infraccion.get_monto();
    fecha_pago_limite = infraccion.get_fecha_pago_limite();
}

Infraccion::~Infraccion() {
    if (tipo_infraccion) delete tipo_infraccion;
    if (placa) delete placa;
}

void Infraccion::leer(ifstream &arch, int verificador, double &multa) {
    char aux[100], car;
    int dd, mm, aa, dato;
    double porcentaje;
    arch.getline(aux, 100, ',');
    if (arch.eof()) return;
    set_placa(aux);
    arch >> dd >> car >> mm >> car >> aa >> car;
    fecha_evento = dd + mm * 100 + aa * 10000;
    dd += 30;
    fecha_pago_limite = obtenerFechaPago(dd, mm, aa);
    arch >> dato;
    if (dato < verificador) {
        strcpy(aux, "Leve");
        porcentaje = 5;
    } else {
        strcpy(aux, "Grave");
        porcentaje = 8;
    }
    set_tipo_infraccion(aux);
    monto = UIT * porcentaje / 100;
    multa = monto;
}


void Infraccion::imprimir(ofstream &arch) const {
    char auxPlaca[100], aux_tipo[100];
    get_placa(auxPlaca);
    get_tipo_infraccion(aux_tipo);

    arch <<setw(10)<<" "<< left << setw(15) << auxPlaca << setw(15) << aux_tipo << right << setw(10) <<
            fecha_evento % 100 << "/" << fecha_evento % 10000 / 100 << "/" << fecha_evento / 10000 << setw(10) <<
            fecha_pago_limite % 100 << "/" << fecha_pago_limite % 10000 / 100 << "/" << fecha_pago_limite / 10000 <<
            setw(10) <<
            monto << endl;
}

int Infraccion::obtenerFechaPago(int dd, int mm, int aa) {
    if (mm == 1 or mm == 3 or mm == 5 or mm == 7 or mm == 8 or mm == 10 or mm == 12) {
        if (dd > 31) {
            dd = dd - 31;
            mm++;
        }
        if (mm > 13) {
            mm = 1;
            aa++;
        }
    } else if (mm == 2) {
        if (dd > 28) {
            dd = dd - 28;
            mm++;
        }
    } else {
        if (dd > 30) {
            dd = dd - 30;
            mm++;
        }
    }
    return dd + mm * 100 + aa * 10000;
}

int Infraccion::get_fecha_evento() const {
    return fecha_evento;
}

void Infraccion::set_fecha_evento(int fecha_evento) {
    this->fecha_evento = fecha_evento;
}

void Infraccion::get_tipo_infraccion(char *tipo_infraccion) const {
    if (this->tipo_infraccion == nullptr) tipo_infraccion[0] = 0;
    else strcpy(tipo_infraccion, this->tipo_infraccion);
}

void Infraccion::set_tipo_infraccion(const char *tipo_infraccion) {
    if (this->tipo_infraccion)delete this->tipo_infraccion;
    this->tipo_infraccion = new char[strlen(tipo_infraccion) + 1];
    strcpy(this->tipo_infraccion, tipo_infraccion);
}

double Infraccion::get_monto() const {
    return monto;
}

void Infraccion::set_monto(double monto) {
    this->monto = monto;
}

int Infraccion::get_fecha_pago_limite() const {
    return fecha_pago_limite;
}

void Infraccion::set_fecha_pago_limite(int fecha_pago_limite) {
    this->fecha_pago_limite = fecha_pago_limite;
}

void Infraccion::get_placa(char *placa) const {
    if (this->placa == nullptr) placa[0] = 0;
    else strcpy(placa, this->placa);
}

void Infraccion::set_placa(const char *placa) {
    if (this->placa)delete this->placa;
    this->placa = new char[strlen(placa) + 1];
    strcpy(this->placa, placa);
}
