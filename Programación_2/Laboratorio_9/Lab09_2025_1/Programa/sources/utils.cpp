//
// Created by User on 18/11/2025.
//

#include "utils.hpp"

void imprimir_linea(ofstream &arch, int cant, char car) {
    for (int i=0;i<cant;i++)
        arch.put(car);
    arch<<endl;
}

void apertura_archivos_entrada(ifstream &arch, const char *nomb) {
    arch.open(nomb,ios::in);
    if (not arch) {
        cout<<"ERROR:No se pudo abrir el archivo con nombre"<<endl;
        exit(1);
    }
}

void apertura_archivos_salida(ofstream &arch, const char *nomb) {
    arch.open(nomb,ios::out);
    if (not arch) {
        cout<<"ERROR:No se pudo abrir el archivo con nombre"<<endl;
        exit(1);
    }
}
