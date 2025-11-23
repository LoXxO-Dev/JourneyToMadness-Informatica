//
// Created by User on 18/11/2025.
//

#include "Infraccion.hpp"

Infraccion::Infraccion() {
}

Infraccion::Infraccion(const Infraccion &orig) {
    *this=orig;
}

void Infraccion::operator=(const Infraccion &orig) {
    codigo = orig.codigo;
    multa = orig.multa;
    gravedad = orig.gravedad;
    descripcion = orig.descripcion;
}

void Infraccion::leer(ifstream &arch) {
    string  buffer;
    getline(arch,buffer,',');
    if (arch.eof()) return;
    codigo = buffer;
    arch>>multa;
    arch.get();
    getline(arch,gravedad,',');
    getline(arch,gravedad,'\n');
}

void Infraccion::imprimir(ofstream &arch) {
}

bool Infraccion::operator<(const Infraccion &infraccion) const {
    return this->codigo < infraccion.codigo;
}

string Infraccion::get_codigo() const {
    return codigo;
}

void Infraccion::set_codigo(const string &codigo) {
    this->codigo = codigo;
}

double Infraccion::get_multa() const {
    return multa;
}

void Infraccion::set_multa(double multa) {
    this->multa = multa;
}

string Infraccion::get_gravedad() const {
    return gravedad;
}

void Infraccion::set_gravedad(const string &gravedad) {
    this->gravedad = gravedad;
}

string Infraccion::get_descripcion() const {
    return descripcion;
}

void Infraccion::set_descripcion(const string &descripcion) {
    this->descripcion = descripcion;
}

void operator>>(ifstream &arch, Infraccion &infra) {
    infra.leer(arch);
}

void operator<<(ofstream &arch, Infraccion infra) {
    infra.imprimir(arch);
}
