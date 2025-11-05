//
// Created by User on 29/10/2025.
//

#include "Restaurante.hpp"

Restaurante::Restaurante() {
    cantidad_comandas = 0;
}

void Restaurante::cargar_comandas() {
    ifstream arch("data/atenciones.csv", ios::in);
    if (not arch) {
        cout << "ERROR:No se pudo abrir el archivo con nombre atenciones.csv"
                << endl;
        exit(1);
    }
    leerAtenciones(arch);
    ifstream archivo("data/comandas.csv", ios::in);
    if (not archivo) {
        cout << "ERROR:No se pudo abrir el archivo con nombre comandas.csv"
                << endl;
        exit(1);
    }
    leerComandas(archivo);
}

void Restaurante::imprimir_comandas() {
ofstream arch("reportes/Reporte.txt",ios::out);
    if (not arch) {
        cout<<"ERROR:No se pudo abrir el archivo con nonbre Reporte.txt "<<endl;
        exit(1);
    }
    arch<<fixed<<setprecision(2);
    arch<<setw(50)<<"REPORTE COMANDAS"<<endl;
        imprimir_linea(arch,TAM_LINEA,'=');
    for (int i=0;i<cantidad_comandas;i++) {
        arch<<left<<setw(15)<<"ID"<<setw(15)<<"HORA ATENCIÓN"<<setw(15)<<"HORA SERVICIO "<<
      setw(20)<<"TIEMPO PREPARACION"<<setw(15)<<"TOTAL"<<setw(15)<<"ESTADO"<<endl;
        imprimir_linea(arch,TAM_LINEA,'=');
        arch<<comandas[i];
        imprimir_linea(arch,TAM_LINEA,'=');

    }
}

void Restaurante::actualizar_comandas() {
    for (int i=0;i<cantidad_comandas;i++) {
        this->comandas[i].actualizarComandas();
    }

}

void Restaurante::imprimir_linea(ofstream &arch, int cant, char car) {
    for (int i=0;i<cant;i++)
        arch.put(car);
    arch<<endl;
}

void Restaurante::leerComandas(ifstream &arch) {
    int id;
    char tipo;
    int posComanda;
    while (true) {
        arch >> id;
        if (arch.eof())break;
        arch.get();
        posComanda = buscarComanda(id);
        comandas[posComanda].leerComanda(arch);
    }
}

int Restaurante::buscarComanda(int id) {
    for (int i=0;i<cantidad_comandas;i++) {
        if (comandas[i].get_id()==id)return i;
    }
    return -1;
}

void Restaurante::leerAtenciones(ifstream &arch) {
    Comanda coma;
    while (true) {
        arch >> coma;
        if (arch.eof())break;
        this->comandas[cantidad_comandas] = coma;
        cantidad_comandas++;
    }
}

int Restaurante::get_cantidad_comandas() const {
    return cantidad_comandas;
}

void Restaurante::set_cantidad_comandas(int cantidad_comandas) {
    this->cantidad_comandas = cantidad_comandas;
}
