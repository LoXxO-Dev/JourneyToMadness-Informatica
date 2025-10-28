//
// Created by User on 28/10/2025.
//

#include "Restaurante.hpp"

#include "Cliente.hpp"
#include "Plato.hpp"

Restaurante::Restaurante() {
    capacidadDeClientes = 0;
    cantidadDeClientes = 0;
    capacidadDePlatos = 0;
    cantidadDePlatos = 0;
    platos = nullptr;
    clientes = nullptr;
}

Restaurante::~Restaurante() {
    if (this->platos != nullptr)delete []platos;
    if (this->clientes != nullptr) delete []clientes;
}

void Restaurante::operator <(const char *nomb) {
    ifstream archivo(nomb, ios::in);
    if (not archivo) {
        cout << "ERROR:No se pudo abrir el archivo con nombre " << endl;
        exit(1);
    }

    while (true) {
        Cliente clie;
        archivo >> clie;
        if (archivo.eof()) break;
        if (cantidadDeClientes == capacidadDeClientes)incrementarClientes();
        clientes[cantidadDeClientes] = clie;
        cantidadDeClientes++;
    }
}

void Restaurante::incrementarClientes() {
    Cliente *aux;
    capacidadDeClientes += INCREMENTO;
    if (clientes == nullptr) {
        clientes = new Cliente[capacidadDeClientes]{};
    } else {
        aux = new Cliente[capacidadDeClientes]{};
        for (int i = 0; i < cantidadDeClientes; i++) {
            aux[i] = clientes[i];
        }
        delete []clientes;
        clientes = aux;
    }
}

void Restaurante::operator <=(const char *nomb) {
    ifstream archivo(nomb, ios::in);
    if (not archivo) {
        cout << "ERROR:No se pudo abrir el archivo con nombre " << endl;
        exit(1);
    }
    while (true) {
        Plato plato;
        archivo >> plato;
        if (archivo.eof()) break;
        if (capacidadDePlatos == cantidadDePlatos)incrementarPlatos();
        platos[cantidadDePlatos] = plato;
        cantidadDePlatos++;
    }
}

void Restaurante::operator >>(const char *nomb) {
    ofstream archivo(nomb, ios::out);
    if (not archivo) {
        cout << "ERROR:No se pudo abrir el archivo con nombre " << endl;
        exit(1);
    }
    archivo<<fixed<<setprecision(2);
    archivo << setw(110) << "RESTAURANTE 1INF25" << endl << setw(110) << "VENTAS DEL DIA" << endl;
    imprimirPlatos(archivo);
    imprimirClientes(archivo);
}

void Restaurante::imprimirPlatos(ofstream &arch) {
    imprimirLinea(arch,TAMLINEA, '=');
    arch << setw(120) << "RELACIÓN DE PLATOS VENDIDOS" << endl;
    imprimirLinea(arch,TAMLINEA, '-');
    arch<<right<<setw(140)<<"PLATOS"<<setw(40)<<"TOTAL"<<endl;
    arch<<left<<setw(5)<<"No."<<setw(15)<<"CODIGO"<<setw(50)<<"NOMBRE"<<
        setw(10)<<"PRECIO"<<setw(20)<<"CATEGORIA"<<setw(15)<<"DESCUENTO"<<
            setw(15)<<"PREPARADOS"<<setw(15)<<"ATENDIDOS"<<setw(15)<<"NO ATENDIDO"<<
                setw(15)<<"ESPERADO"<<setw(15)<<"BRUTO"<<setw(15)<<"NETO"<<endl;
    imprimirLinea(arch,TAMLINEA, '-');
    for (int i=0;i<cantidadDePlatos;i++) {
        arch<<setw(3)<<right<<i+1<<")";
        arch<<platos[i];
    }
}

void Restaurante::imprimirClientes(ofstream &arch) {
    imprimirLinea(arch,TAMLINEA-40, '=');
    arch << setw(80) << "RELACIÓN DE CLIENTES VENDIDOS" << endl;
    imprimirLinea(arch,TAMLINEA-40, '-');
    arch<<left<<setw(10)<<"No."<<setw(15)<<"DNI"<<setw(50)<<"NOMBRE"<<
        setw(30)<<"DISTRITO"<<setw(20)<<"DESCUENTO"<<setw(15)<<"TOTAL PAGADO"<<endl;

    imprimirLinea(arch,TAMLINEA-40, '-');
    for (int i=0;i<cantidadDeClientes;i++) {
        arch<<setw(3)<<right<<i+1<<")";
        arch<<clientes[i];
    }
    imprimirLinea(arch,TAMLINEA-40, '=');

}

void Restaurante::imprimirLinea(ofstream &arch, int cant, char car) {
    for (int i = 0; i < cant; i++)
        arch.put(car);
    arch << endl;
}

void Restaurante::operator <<=(const char *nomb) {
    ifstream archivo(nomb, ios::in);
    if (not archivo) {
        cout << "ERROR:No se pudo abrir el archivo con nombre " << endl;
        exit(1);
    }
    int numPed, dni, cantidad, posCliente, posPlato;
    char plato[8], car;
    double totalPagado, totalPrevio;
    while (true) {
        archivo >> numPed;
        if (archivo.eof()) break;
        archivo >> car >> dni >> car;
        posCliente = buscarCliente(dni);
        while (true) {
            archivo >> plato >> car >> cantidad;
            posPlato = buscarPato(plato);
            if (platos[posPlato].esAtendible(cantidad, clientes[posCliente].get_descuento(), totalPagado)) {
                totalPrevio = clientes[posCliente].get_total_pagado();
                clientes[posCliente].set_total_pagado(totalPrevio + totalPagado);
            }
            if (archivo.get() == '\n')break;
        }
    }
}

int Restaurante::buscarCliente(int dni) {
    for (int i = 0; i < cantidadDeClientes; i++) {
        if (clientes[i].get_dni() == dni) return i;
    }
    return -1;
}

int Restaurante::buscarPato(char *plato) {
    for (int i = 0; i < cantidadDePlatos; i++) {
        char aux[15];
        platos[i].get_codigo(aux);
        if (strcmp(aux, plato) == 0) return i;
    }
    return -1;
}

void Restaurante::incrementarPlatos() {
    Plato *aux;
    capacidadDePlatos += INCREMENTO;
    if (platos == nullptr) {
        platos = new Plato[capacidadDePlatos]{};
    } else {
        aux = new Plato [capacidadDePlatos]{};
        for (int i = 0; i < cantidadDePlatos; i++) {
            aux[i] = platos[i];
        }
        delete []platos;
        platos = aux;
    }
}

int Restaurante::get_cantidad_de_clientes() const {
    return cantidadDeClientes;
}

void Restaurante::set_cantidad_de_clientes(int cantidad_de_clientes) {
    cantidadDeClientes = cantidad_de_clientes;
}

int Restaurante::get_capacidad_de_clientes() const {
    return capacidadDeClientes;
}

void Restaurante::set_capacidad_de_clientes(int capacidad_de_clientes) {
    capacidadDeClientes = capacidad_de_clientes;
}

int Restaurante::get_cantidad_de_platos() const {
    return cantidadDePlatos;
}

void Restaurante::set_cantidad_de_platos(int cantidad_de_platos) {
    cantidadDePlatos = cantidad_de_platos;
}

int Restaurante::get_capacidad_de_platos() const {
    return capacidadDePlatos;
}

void Restaurante::set_capacidad_de_platos(int capacidad_de_platos) {
    capacidadDePlatos = capacidad_de_platos;
}
