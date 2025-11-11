//
// Created by User on 11/11/2025.
//

#include "utils.hpp"
void imprimir_linea(ofstream &arch,int cant,char car) {
    for (int i=0;i<cant;i++) {
        arch.put(car);
    }
    arch<<endl;
}
void apertura_archivos_entrada(ifstream &archivo,const char *nomb) {
    archivo.open(nomb,ios::in);
    if (not archivo) {
        cout<<"ERROR:No se pudo abrir el archivo con nombre "<<nomb<<endl;
        exit(1);
    }

}
void apertura_archivos_salida(ofstream &archivo,const char *nomb) {
    archivo.open(nomb,ios::out);
    if (not archivo) {
        cout<<"ERROR:No se pudo abrir el archivo con nombre "<<nomb<<endl;
        exit(1);
    }
}