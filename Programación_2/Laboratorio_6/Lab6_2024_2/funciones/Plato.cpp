//
// Created by User on 5/10/2025.
//

#include "Plato.hpp"

#include <atomic>

Plato::Plato() {
    inicializa();
}

void Plato::inicializa() {
    codigo = nullptr;
    nombre = nullptr;
    categoria = nullptr;
    atendidos = 0;
    noAtendidos = 0;
}

Plato::Plato(const Plato &copia) {
    inicializa();
    *this = copia;
}

Plato::~Plato() {
    if (this->codigo != nullptr)delete this->codigo;
    if (this->nombre != nullptr)delete this->nombre;
    if (this->categoria != nullptr)delete this->categoria;
}

void Plato::operator =(const class Plato &copia) {
    char codigo[100], nombre[100], categoria[100];
    copia.get_codigo(codigo);
    copia.get_nombre(nombre);
    copia.get_categoria(categoria);
    set_codigo(codigo);
    set_nombre(nombre);
    set_categoria(categoria);

    precio = copia.get_precio();
    preparados = copia.get_preparados();
    descuento = copia.get_descuento();
    atendidos = copia.get_atendidos();
    noAtendidos = copia.get_no_atendidos();
    totalEsperado = copia.get_total_esperado();
    totalBruto = copia.get_total_bruto();
    totalNeto = copia.get_total_neto();
}

void Plato::leerPlato(ifstream &arch) {
    char codigo[10], nombre[100], categoria[20];
    //AP31796,ANTICUCHO DE CORAZON AL PLATO,31.90,APERITIVO,43,19.94%
    double descuento=0;
    arch.getline(codigo, 10, ',');
    arch.getline(nombre, 100, ',');
    arch >> precio;
    arch.get();
    arch.getline(categoria, 20, ',');
    arch >> this->preparados;
    if (arch.get() == ',') {
        arch >> descuento;
        arch.get();
        arch.get();
    }
    set_descuento(descuento);
    set_codigo(codigo);
    set_nombre(nombre);
    set_categoria(categoria);
    set_total_esperado(precio*preparados);
}

bool Plato::posPlato(char *plato) {
    if (strcmp(this->codigo, plato)==0)
        return true;
    else return false;
}
void Plato::agregarTotal(double cantidad,double descCliente) {
    if (preparados>=atendidos+cantidad) {
        atendidos+=cantidad;
        totalBruto=atendidos*precio;
        totalNeto+=(100-descCliente)/100*precio*(100-descuento)/100*cantidad;
    }else if (preparados>atendidos) {
        cantidad=preparados-atendidos;
        atendidos+=cantidad;
        totalBruto=atendidos*precio;
        totalNeto+=(100-descCliente)/100*precio*(100-descuento)/100*cantidad;
    }else
        noAtendidos+=cantidad;

}
void Plato::imprimir(ofstream &arch) {
    char codigo[15],nombre[100],categoria[20];
    get_codigo(codigo);
    get_nombre(nombre);
    get_categoria(categoria);

    arch<<left<<setw(3)<<" "<<setw(13)<<codigo<<setw(50)<<nombre<<
        right<<setw(10)<<precio<<setw(5)<<" "<<left<<setw(20)<<categoria<<
            right<<setw(8)<<descuento<<"%"<<setw(10)<<preparados<<setw(15)<<
                atendidos<<setw(15)<<noAtendidos<<setw(20)<<totalEsperado<<
                    setw(10)<<totalBruto<<setw(12)<<totalNeto<<endl;
}

void Plato::get_codigo(char *codigo) const {
    if (this->codigo == nullptr)codigo[0] = 0;
    else strcpy(codigo, this->codigo);
}

void Plato::set_codigo(const char *codigo) {
    if (this->codigo != nullptr)delete this->codigo;
    this->codigo = new char[strlen(codigo) + 1];
    strcpy(this->codigo, codigo);
}

void Plato::get_nombre(char *nombre) const {
    if (this->nombre == nullptr)nombre[0] = 0;
    else strcpy(nombre, this->nombre);
}

void Plato::set_nombre(const char *nombre) {
    if (this->nombre != nullptr)delete this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

double Plato::get_precio() const {
    return precio;
}

void Plato::set_precio(double precio) {
    this->precio = precio;
}

void Plato::get_categoria(char *categoria) const {
    if (this->categoria == nullptr)categoria[0] = 0;
    else strcpy(categoria, this->categoria);
}

void Plato::set_categoria(const char *categoria) {
    if (this->categoria != nullptr)delete this->categoria;
    this->categoria = new char[strlen(categoria) + 1];
    strcpy(this->categoria, categoria);
}

int Plato::get_preparados() const {
    return preparados;
}

void Plato::set_preparados(int preparados) {
    this->preparados = preparados;
}

double Plato::get_descuento() const {
    return descuento;
}

void Plato::set_descuento(double descuento) {
    this->descuento = descuento;
}

int Plato::get_atendidos() const {
    return atendidos;
}

void Plato::set_atendidos(int atendidos) {
    this->atendidos = atendidos;
}

int Plato::get_no_atendidos() const {
    return noAtendidos;
}

void Plato::set_no_atendidos(int no_atendidos) {
    noAtendidos = no_atendidos;
}

double Plato::get_total_esperado() const {
    return totalEsperado;
}

void Plato::set_total_esperado(double total_esperado) {
    totalEsperado = total_esperado;
}

double Plato::get_total_bruto() const {
    return totalBruto;
}

void Plato::set_total_bruto(double total_bruto) {
    totalBruto = total_bruto;
}

double Plato::get_total_neto() const {
    return totalNeto;
}

void Plato::set_total_neto(double total_neto) {
    totalNeto = total_neto;
}

void operator>>(ifstream &arch, class Plato &plat) {
    plat.leerPlato(arch);
}
void operator<<(ofstream &arch, class Plato plat) {
    plat.imprimir(arch);
}