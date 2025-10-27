//
// Created by User on 7/10/2025.
//

#include "Producto.hpp"

#include "Pedido.hpp"
char *codigo;
char *descripcion;
int stock;
double precio;
int clientes_servidos;
int clientes_no_servidos;
int cantidad_clientes_servidos;
int cantidad_clientes_no_servidos;

Producto::Producto() {
    inicializa();
}

Producto::Producto(const Producto &copia) {
    inicializa();
    *this = copia;
}

Producto::~Producto() {
    if (codigo != nullptr) delete codigo;
    if (descripcion != nullptr) delete descripcion;
}

void Producto::operator =(const Producto &copia) {
    char cod[10], descri[100];
    copia.get_codigo(cod);
    copia.get_descripcion(descri);
    set_codigo(cod);
    set_descripcion(descri);
    stock = copia.stock;
    precio = copia.precio;

    cantidad_clientes_no_servidos = copia.cantidad_clientes_no_servidos;
    cantidad_clientes_servidos = copia.cantidad_clientes_servidos;
}

void Producto::inicializa() {
    codigo = nullptr;
    descripcion = nullptr;

    cantidad_clientes_servidos = 0;
    cantidad_clientes_no_servidos = 0;
}

bool Producto::operator +=(class Pedido &ped) {
    ped.set_precio_producto(precio);
    if (this->stock > 1) {
        stock--;
        this->clientes_servidos[cantidad_clientes_servidos++] = ped.get_dni_cliente();
        return true;
    } else {
        this->clientes_no_servidos[cantidad_clientes_no_servidos++] = ped.get_dni_cliente();
        return false;
    }
}

bool Producto::leer_producto(ifstream &arch) {
    //    BIT-434,Campana Extractora modelo Glass,375.09,10
    char codigo[10], nombre[100];
    arch.getline(codigo, 10, ',');
    if (arch.eof()) return false;
    arch.getline(nombre, 100, ',');
    arch >> precio;
    arch.get();
    arch >> stock;
    arch.get();
    set_descripcion(nombre);
    set_codigo(codigo);

    cantidad_clientes_servidos = 0;
    cantidad_clientes_no_servidos = 0;
    return true;
}

void Producto::imprimir(ofstream &arch) {
    bool bandera = 1;
    char cod[10], descri[100];
    get_codigo(cod);
    get_descripcion(descri);
    arch << setw(10) << left << cod << setw(60) << descri << right <<
            setw(10) << precio << setw(10) << stock << endl;
    imprimiLinea(arch, '*',TAMLINEA);
    if (cantidad_clientes_servidos > 0) {
        arch << setw(20) << "Clientes atendidos: ";
        for (int i = 0; i < cantidad_clientes_servidos; i++)
            arch << setw(10) << this->clientes_servidos[i];
        arch << endl;
    } else {
        arch << "NO SE ATENDIERON PEDIDOS" << endl;
        bandera = 0;
    }
    if (cantidad_clientes_no_servidos > 0) {
        arch << setw(20) << "Clientes no atendidos: ";
        for (int i = 0; i < cantidad_clientes_no_servidos; i++)
            arch << setw(10) << this->clientes_no_servidos[i];
        arch << endl;
    } else {
        if ( bandera)
            arch << "NO HAY CLIENTES SIN ATENDER" << endl;
    }
}

void Producto::imprimiLinea(ofstream &archivo, char car, int cantidad) {
    for (int i = 0; i < cantidad; i++)
        archivo.put(car);
    archivo << endl;
}

double Producto::get_precio() const {
    return precio;
}

void Producto::set_precio(double precio) {
    this->precio = precio;
}


int Producto::get_cantidad_clientes_servidos() const {
    return cantidad_clientes_servidos;
}

void Producto::set_cantidad_clientes_servidos(int cantidad_clientes_servidos) {
    this->cantidad_clientes_servidos = cantidad_clientes_servidos;
}

int Producto::get_cantidad_clientes_no_servidos() const {
    return cantidad_clientes_no_servidos;
}

void Producto::set_cantidad_clientes_no_servidos(int cantidad_clientes_no_servidos) {
    this->cantidad_clientes_no_servidos = cantidad_clientes_no_servidos;
}

void Producto::get_codigo(char *codigo) const {
    if (this->codigo == nullptr)codigo[0] = 0;
    else strcpy(codigo, this->codigo);
}

void Producto::set_codigo(const char *codigo) {
    if (this->codigo != nullptr)delete this->codigo;
    this->codigo = new char[strlen(codigo) + 1];
    strcpy(this->codigo, codigo);
}


void Producto::get_descripcion(char *descripcion) const {
    if (this->descripcion == nullptr)descripcion[0] = 0;
    else strcpy(descripcion, this->descripcion);
}

void Producto::set_descripcion(const char *descripcion) {
    if (this->descripcion != nullptr)delete this->descripcion;
    this->descripcion = new char[strlen(descripcion) + 1];
    strcpy(this->descripcion, descripcion);
}

int Producto::get_stock() const {
    return stock;
}

void Producto::set_stock(int stock) {
    this->stock = stock;
}

bool operator>>(ifstream &arch, Producto &prod) {
    return prod.leer_producto(arch);
}

void operator<<(ofstream &arch, Producto &prod) {
    prod.imprimir(arch);
}
