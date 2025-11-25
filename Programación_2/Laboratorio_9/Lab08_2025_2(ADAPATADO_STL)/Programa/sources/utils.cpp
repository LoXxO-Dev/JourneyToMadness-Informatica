//
// Created by User on 25/11/2025.
//

#include "utils.hpp"
void imprimir_Linea(ofstream &arch,int cant ,char car) {
    for (int i=0;i<cant;i++)
        arch.put(car);
    arch<<endl;
}
void apertura_archivos_entrada(ifstream &arch,const char *nombArch) {
    arch.open(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR:No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
}
void apertura_archivos_salida(ofstream &arch,const char *nombArch) {
    arch.open(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR:No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
}