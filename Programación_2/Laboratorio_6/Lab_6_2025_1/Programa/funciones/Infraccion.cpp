//
// Created by User on 27/10/2025.
//

#include "Infraccion.hpp"

Infraccion::Infraccion() {
    this->descripcion = nullptr;
    this->gravedad = nullptr;
}

Infraccion::Infraccion(const Infraccion &orig) {
    this->descripcion = nullptr;
    this->gravedad = nullptr;
    *this = orig;
}

void Infraccion::operator =(const Infraccion &orig) {
    char aux[200];

    orig.get_descripcion(aux);
    set_descripcion(aux);
    orig.get_gravedad(aux);
    set_gravedad(aux);
    this->codigo = orig.codigo;
    this->multa = orig.multa;
}

Infraccion::~Infraccion() {
    if (this->descripcion != nullptr)delete this->descripcion;
    if (this->gravedad != nullptr)delete this->gravedad;
}

void Infraccion::leer(ifstream &arch) {

    char buffer[200], car;
    arch >> codigo;
    arch >> car >> multa >> car;
    arch.getline(buffer, 200, ',');
    set_gravedad(buffer);
    arch.get(buffer, 200, '\n');
    set_descripcion(buffer);
    //    2007,425.23,Grave,No conducir por el carril de extremo derecho de la calzada un vehiculo de transporte p�blico de pasajeros o de carga.
}

void Infraccion::imprimir(ofstream &arch ) {
    char descr[200], grave[200];
    get_descripcion(descr);
    get_gravedad(grave);
    arch<<setw(5)<<" "<<left<<setw(12)<<this->codigo<<right<<setw(8)<<
        this->multa<<setw(5)<<" "<<left<<setw(15)<<grave<<setw(20)<<descr<<endl;

}
void operator >>(ifstream &arch, class Infraccion &infra) {
    infra.leer(arch);
}
void operator <<(ofstream &arch, class Infraccion &infra) {
    infra.imprimir(arch);
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
