//
// Created by User on 1/10/2025.
//

#include "Empresa.hpp"
#include <cstring>

Empresa::Empresa() {
    this->nombre = nullptr;
    for (int i = 0; i < 10; i++) {
        this->placas[i] = nullptr;
    }
    numPlacas = 0;
    numMultas = 0;
}


Empresa::~Empresa() {
    if (this->nombre != nullptr)delete this->nombre;
    for (int i = 0; i < 10; i++) {
        this->placas[i] = nullptr;
    }
}

int Empresa::get_dni() const {
    return dni;
}

void Empresa::set_dni(int dni) {
    this->dni = dni;
}

void Empresa::get_nombre(char *nombre) const {
    if (this->nombre == nullptr)nombre[0] = 0;
    else strcpy(nombre, this->nombre);
}

void Empresa::set_nombre(const char *nombre) {
    if (this->nombre)delete this->nombre;

    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

int Empresa::get_num_placas() const {
    return numPlacas;
}

void Empresa::set_num_placas(int num_placas) {
    numPlacas = num_placas;
}

int Empresa::get_num_multas() const {
    return numMultas;
}
void Empresa::set_num_multas(int numMultas )  {
    this->numMultas=numMultas;
}


void Empresa::leerEmpresa(ifstream &arch_nuevo) {
    int dni;
    char nomb[200], placas[9], car;

    arch_nuevo >> dni;

    if (arch_nuevo.eof()) return;
    set_dni(dni);
    arch_nuevo.get();
    arch_nuevo.getline(nomb, 200, ',');
    set_nombre(nomb);
    numPlacas = 0;
    while (true) {
        arch_nuevo.get(placas, 9);
        setPlacaI(placas, numPlacas);
        car = arch_nuevo.get();
        numPlacas++;
        if (car == '\n') {
            arch_nuevo.unget();
            break;
        }
    }
}

void Empresa::imprimir(ofstream &arch) {
    char nombre[100];
    get_nombre(nombre);
    arch <<setw(15) << right << this->dni << setw(5) << " " << left << setw(50) << nombre;
    char placa[10];
    for (int i = 0; i < this->numPlacas; i++) {
        getPlacaI(placa, i);
        arch << setw(15) << placa;
    }
    arch << endl;
    arch<<setw(15)<<" " <<left<<setw(15)<<"Placa"<<setw(30)<<"Fecha de infraccion"<<
        setw(30)<<"Código de infracción"<<setw(15)<<
            "Multa"<<setw(20)<<"Fecha de pago"<<endl;
    for (int j=0;j<this->numMultas;j++) {
        arch<<this->multas[j];
    }
}


void Empresa::operator =(Empresa &copia) {
    char nomb[100];
    copia.get_nombre(nomb);
    set_nombre(nomb);
    for (int i = 0; i < copia.get_num_placas(); i++) {
        char placa[10];
        copia.getPlacaI(placa, i);
        setPlacaI(placa, i);
    }
    dni = copia.get_dni();
    numMultas = copia.get_num_multas();
    numPlacas = copia.get_num_placas();
}

void Empresa::operator +=(const class Multa infraccionCometida) {
    this->multas[numMultas]=infraccionCometida;
    numMultas++;
}


void Empresa::setPlacaI(const char *plac, int i) {
    if (this->placas[i] != nullptr)delete this->placas[i];
    this->placas[i] = new char[strlen(plac) + 1];
    strcpy(this->placas[i], plac);
}

void Empresa::getPlacaI(char *plac, int i) {
    if (this->placas[i] == nullptr)plac[0] = 0;
    else strcpy(plac, this->placas[i]);
}


void operator >>(ifstream &arch, class Empresa &emp) {
    emp.leerEmpresa(arch);
}

void operator <<(ofstream &arch, class Empresa &emp) {
    emp.imprimir(arch);
}
bool Empresa::placaPresenteEnEmpresa( char *placa) {
    for (int i = 0; i < this->numPlacas; i++) {
        char aux[10];
        getPlacaI(aux, i);

        if (strcmp(aux, placa) == 0)
            return true;
    }
    return false;
}