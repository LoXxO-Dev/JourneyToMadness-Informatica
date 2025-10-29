//
// Created by User on 7/10/2025.
//

#include "Almacen.hpp"

#include "Pedido.hpp"

Almacen::Almacen() {
    this->cantidad_clientes = 0;
    this->cantidad_productos = 0;
}

void Almacen::cargar_clientes() {
    ifstream archivo("data/Clientes.csv", ios::in);
    if (not archivo) {
        cout << "GG";
        exit(1);
    }
    Cliente clie;
    while (true) {
        if (not(archivo >> clie))break;
        this->arreglo_clientes[cantidad_clientes++] = clie;
    }
}

void Almacen::cargar_produtos() {
    ifstream archivo("data/Productos.csv", ios::in);
    if (not archivo) {
        cout << "GG";
        exit(1);
    }
    Producto pro;
    while (true) {
        if (not(archivo >> pro))break;
        this->arreglo_productos[cantidad_productos++] = pro;
    }
}

void Almacen::cargar_pedidos() {
    ifstream archivo("data/Pedidos.csv", ios::in);
    if (not archivo) {
        cout << "GG";
        exit(1);
    }
    Pedido ped;
    int posClie, posProd;
    char cod[10];

    double precio;
    while (true) {
        if (not(archivo >> ped))break;
        posClie = buscarClie(ped.get_dni_cliente());
        ped.get_codigo(cod);
        posProd = buscarProduto(cod);
        if (posClie != -1 && posProd != -1) {
            if (arreglo_productos[posProd] += ped)
                arreglo_clientes[posClie] += ped;
        }
    }
}

int Almacen::buscarClie(int dni) {
    for (int i = 0; i < cantidad_clientes; i++) {
        if (arreglo_clientes[i].get_dni() == dni) return i;
    }
    return -1;
}

int Almacen::buscarProduto(char *aux) {
    for (int i = 0; i < cantidad_productos; i++) {
        char cod[10];
        arreglo_productos[i].get_codigo(cod);
        if (strcmp(cod, aux) == 0) return i;
    }
    return -1;
}

void Almacen::mostrar_datos() {
    ofstream archivo("reportes/ReporteClientes.txt", ios::out);
    if (not archivo) {
        cout << "GG";
        exit(1);
    }
    archivo << setprecision(2) << fixed;
    imprimiLinea(archivo, '=',TAMLINEA);
    archivo << setw(70) << "REPORTE CLIENTES" << endl;
    imprimiLinea(archivo, '=',TAMLINEA);

    archivo <<left<< setw(10) << "DNI"<<setw(40) <<"NOMBRE"<<setw(15)<<
        "TELEFONO"<<setw(20)<<"MONTO TOTAL"<< setw(20)<<"PRODUCTOS ENTREGADOS"<< endl;
    imprimiLinea(archivo, '-',TAMLINEA);
    for (int i=0;i<cantidad_clientes;i++)
        archivo<<arreglo_clientes[i];
    imprimirReporteProductos();
}


void Almacen::imprimirReporteProductos() {
    ofstream archivo("reportes/ReporteProductos.txt", ios::out);
    if (not archivo) {
        cout << "GG";
        exit(1);
    }
    archivo << setprecision(2) << fixed;
    imprimiLinea(archivo, '=',TAMLINEA);
    archivo << setw(70) << "REPORTE PRODUCTOS" << endl;
    imprimiLinea(archivo, '=',TAMLINEA);

    archivo <<left<< setw(10) << "CODIGO"<<setw(65) <<"DESCRIPCION"<<setw(15)<<
        "PRECIO"<<setw(20)<<"STOCK FINAL"<<endl;
    imprimiLinea(archivo, '-',TAMLINEA);
    for (int i=0;i<cantidad_productos;i++) {
        archivo<<arreglo_productos[i];
        imprimiLinea(archivo, '-',TAMLINEA);
        archivo<<endl;
    }

}

void Almacen::imprimiLinea(ofstream &archivo, char car, int cantidad) {
    for (int i = 0; i < cantidad; i++)
        archivo.put(car);
    archivo << endl;
}

int Almacen::get_cantidad_clientes() const {
    return cantidad_clientes;
}

void Almacen::set_cantidad_clientes(int cantidad_clientes) {
    this->cantidad_clientes = cantidad_clientes;
}

int Almacen::get_cantidad_productos() const {
    return cantidad_productos;
}

void Almacen::set_cantidad_productos(int cantidad_productos) {
    this->cantidad_productos = cantidad_productos;
}
