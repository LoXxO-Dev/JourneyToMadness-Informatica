//
// Created by User on 31/10/2025.
//

#include "Almacen.hpp"

Almacen::Almacen() {
    cantidad_ordenes = 0;
}

void Almacen::cargar_pedidos() {
    ifstream arch("data/Pedidos.csv", ios::in);
    if (not arch) {
        cout << "ERROR:No se pudo abrir el archivo con nombre " << endl;
        exit(1);
    }

    while (true) {
        arch >> ordenes[cantidad_ordenes];
        if (arch.eof()) break;
        cantidad_ordenes++;
    }
}

void Almacen::actualizar_pedidos() {
    for (int i=0;i<cantidad_ordenes;i++)
        this->ordenes[i].actualiza();
}

void Almacen::imprimir_ordenes_ventas() {
    ofstream arch("reportes/Reporte.txt", ios::out);
    if (not arch) {
        cout << "Error:No se pudo abrir el archivo con nombre Reporte.txt" << endl;
        exit(1);
    }
    arch<<setw(50)<<"REPORTE ORDENES"<<endl;
    imprimir_linea(arch,CANT_LINEA,'=');
    arch<<left<<setw(15)<<"Prioridad"<<setw(12)<<"Codigo"<<setw(11)<<
        "Dni"<<setw(15)<<"Subtotal"<<setw(15)<<"Fecha"<<setw(15)<<"Pedido"<<
            setw(10)<<"Total"<<"Recargo,Estado,FechaEntrega "<<endl;
    imprimir_linea(arch,CANT_LINEA,'-');

    arch << fixed << setprecision(2);
    for (int i = 0; i < cantidad_ordenes; i++) {
        arch<<this->ordenes[i];
    }
}

void Almacen::imprimir_linea(ofstream &arch,int cant,char car) {
    for (int i=0;i<cant;i++)
        arch.put(car);
    arch<<endl;

}

int Almacen::get_cantidad_ordenes() const {
    return cantidad_ordenes;
}

void Almacen::set_cantidad_ordenes(int cantidad_ordenes) {
    this->cantidad_ordenes = cantidad_ordenes;
}
