//
// Created by User on 11/11/2025.
//

#include "Restaurante.hpp"

void Restaurante::carga(const char *nombArch) {
    ifstream arch;
    apertura_archivos_entrada(arch,nombArch);
    int id;
    while (true) {
        arch>>id;
        if (arch.eof()) break;
        Ccomanda.leer(arch,id);
    }
}

void Restaurante::atiende(const char *nombArch) {
    ofstream arch;
    apertura_archivos_salida(arch,nombArch);
    arch<<fixed<<setprecision(2);
    arch<<"Detalle de Comandas"<<endl;
    imprimir_linea(arch,TAM_LINEA,'=');
    Ccomanda.imprimir(arch);
}

void Restaurante::elimina(int num) {

    Ccomanda.elimina(num);
}
