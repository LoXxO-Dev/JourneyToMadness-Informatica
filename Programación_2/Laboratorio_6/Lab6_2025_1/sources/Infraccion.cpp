//
// Created by User on 1/10/2025.
//

#include "Infraccion.hpp"

#include <string.h>

Infraccion::Infraccion() {
    descripcion = nullptr;
    gravedad = nullptr;
}

Infraccion::Infraccion(const Infraccion &copia) {
    descripcion = nullptr;
    gravedad = nullptr;
    *this = copia;
}

Infraccion::~Infraccion() {
    if (this->descripcion != nullptr)delete this->descripcion;
    if (this->gravedad != nullptr)delete this->gravedad;
}

void Infraccion::operator =(const Infraccion &copia) {

    char descrip[300], grave[100];
    copia.get_descripcion(descrip);
    copia.get_gravedad(grave);
    set_descripcion(descrip);
    set_gravedad(grave);
    this->codigo=copia.get_codigo();
    this->multa=copia.get_multa();

}

int Infraccion::get_codigo() const {
    return codigo;
}

void Infraccion::set_codigo(int codigo) {
    this->codigo = codigo;
}

void Infraccion::get_descripcion(char *descripcion) const {
    if (this->descripcion == nullptr)descripcion[0] = 0;
    else strcpy(descripcion, this->descripcion);
}

void Infraccion::set_descripcion(const char *descripcion) {
    if (this->descripcion != nullptr)delete this->descripcion;

    this->descripcion = new char[strlen(descripcion) + 1];
    strcpy(this->descripcion, descripcion);
}

void Infraccion::get_gravedad(char *gravedad) const {
    if (this->gravedad == nullptr)gravedad[0] = 0;
    else strcpy(gravedad, this->gravedad);
}

void Infraccion::set_gravedad(const char *gravedad) {
    if (this->gravedad != nullptr)delete this->gravedad;

    this->gravedad = new char[strlen(gravedad) + 1];
    strcpy(this->gravedad, gravedad);
}

double Infraccion::get_multa() const {
    return multa;
}

void Infraccion::set_multa(double multa) {
    this->multa = multa;
}

void operator >>(ifstream &arch, class Infraccion &infra) {
    infra.leerUnaInfraccion(arch);
}

void Infraccion::leerUnaInfraccion(ifstream &archivo) {
    char descrip[300], grave[100];
    int cod;
    archivo >> cod;
    if (archivo.eof()) return;
    set_codigo(cod);
    archivo.get();
    archivo >> multa;
    archivo.get();
    archivo.getline(grave, 100, ',');
    archivo.getline(descrip, 300, '\n');
    set_gravedad(grave);
    set_descripcion(descrip);
}



 void   Infraccion::mostrarInfra(ofstream &arch) {
    char gra[20], descrip[200];
    get_descripcion(descrip);
    get_gravedad(gra);
    arch<<right<<setw(15)<<codigo<<setw(10)<<multa<<
      setw(10)<<" "<<left<< setw(20)<<gra<<setw(100)<<descrip <<endl;
}


void operator <<(ofstream &arch, class Infraccion infra){
    infra.mostrarInfra(arch);
}