//
// Created by User on 28/10/2025.
//

#include "Plato.hpp"


Plato::Plato() {
    codigo = nullptr;
    nombre = nullptr;
    categoria = nullptr;
    preparados = 0;
    atendidos = 0;
    noAtendidos = 0;
    totalEsperado = 0;
    totalBruto = 0;
    totalNeto = 0;
    descuento=0;
}

Plato::~Plato() {
    if (this->codigo != nullptr) delete this->codigo;
    if (this->nombre != nullptr) delete this->nombre;
    if (this->categoria != nullptr) delete this->categoria;
}

Plato::Plato(const Plato &orig) {
    codigo = nullptr;
    nombre = nullptr;
    categoria = nullptr;
    *this = orig;
}

void Plato::operator=(const Plato &orig) {
    char buffer[100];
    orig.get_codigo(buffer);
    set_codigo(buffer);
    orig.get_nombre(buffer);
    set_nombre(buffer);
    orig.get_categoria(buffer);
    set_categoria(buffer);
    precio = orig.get_precio();
    preparados = orig.get_preparados();
    descuento = orig.get_descuento();
    atendidos = orig.get_atendidos();
    noAtendidos = orig.get_no_atendidos();
    totalEsperado = orig.get_total_esperado();
    totalBruto = orig.get_total_bruto();
    totalNeto = orig.get_total_neto();
}

void Plato::leer(ifstream &archivo) {
    char buffer[100];
    archivo.getline(buffer, 100, ',');
    if (archivo.eof()) return;
    set_codigo(buffer);
    archivo.getline(buffer, 100, ',');
    set_nombre(buffer);
    archivo >> precio;
    archivo.get();
    archivo.getline(buffer, 100, ',');
    set_categoria(buffer);
    archivo >> preparados;
    if (archivo.get() == ',') {
        archivo >> descuento;
        archivo.get();
        archivo.get();
    }
}

bool Plato::esAtendible(int cantidad, double descClie, double &totalPagadoCliente) {
    if (preparados - atendidos - cantidad >= 0) {
        totalEsperado = preparados * precio;
        totalBruto += cantidad * precio;
        totalPagadoCliente = cantidad * precio * (100 - descuento) / 100 * (100 - descClie) / 100;
        totalNeto += totalPagadoCliente;
        atendidos += cantidad;
        return true;
    } else {
        totalPagadoCliente = 0;
        noAtendidos += cantidad;
        return false;
    }
}
void Plato::imprimir(ofstream &arch) {
    char codigo[20],nombre[150],categoria[20];
    get_codigo(codigo);
    get_nombre(nombre);
    get_categoria(categoria);
    arch<<left<<setw(3)<<" "<<left<<setw(15)<<codigo<<setw(50)<<nombre<<
        setw(5)<<right<<precio<<setw(3)<<" "<<left<<setw(15)<<categoria<<right<<
            setw(10)<<descuento<<"%"<<setw(15)<<preparados<<setw(15)<<atendidos<<
                setw(15)<<noAtendidos<<setw(15)<<totalEsperado<<setw(15)<<totalBruto<<
                    setw(15)<<totalNeto<<endl;
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

void operator >>(ifstream &arch, class Plato &plat) {
    plat.leer(arch);
}

void operator <<(ofstream &arch, class Plato &plat) {
    plat.imprimir(arch);
}
