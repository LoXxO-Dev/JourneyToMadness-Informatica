//
// Created by User on 20/11/2025.
//

#include "utils.hpp"
void imprimir_linea(ofstream &arch,int cant,char car) {
    for (int i=0;i<cant;i++)
        arch.put(car);
    arch<<endl;
}
void apertura_archivo_entrada(ifstream &archivo,const char *nomb) {
    archivo.open(nomb,ios::in);
    if (not archivo.is_open()) {
        cout<<"ERROR:No se puede abrir el archivo con nombre "<<nomb<<endl;
        exit(1);
    }

}

void apertura_archivo_salida(ofstream &archivo, const char *nomb) {
    archivo.open(nomb,ios::out);
    if (not archivo.is_open()) {
        cout<<"ERROR:No se puede abrir el archivo con nombre "<<nomb<<endl;
        exit(1);
    }
}
