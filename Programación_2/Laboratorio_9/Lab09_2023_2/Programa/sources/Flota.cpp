//
// Created by User on 24/11/2025.
//

#include "Flota.hpp"

void Flota::cargaflota() {
    ifstream arch;
    apertura_archivos_entrada(arch,"data/Vehiculos (1).csv");

    while (true) {
        class NVehiculo aux;
        aux.leer(arch);
        if (arch.eof()) break;
        vflot.push_back(aux);
    }
    sort(vflot.begin(),vflot.end());

}

void Flota::muestracarga() {
    ofstream arch;
    apertura_archivos_salida(arch,"reportes/Reporte.txt");
    arch<<fixed<<setprecision(2);
    arch<<setw(60)<<"REPORTE DE FLOTA"<<endl;
    imprimir_linea(arch,TAM_LINEA,'=');


    for (auto &x : vflot) {
        x.imprimir(arch);
    }
}

void Flota::cargapedidos() {
    ifstream arch;
    apertura_archivos_entrada(arch,"data/Pedidos3 (2).csv");

    int cliente;
    while (true) {
        arch>>cliente;
        if (arch.eof()) break;
        arch.get();
        for (auto &x:vflot) {
            if (x.encontrarPosicion(cliente)) {
                x.ingresasPedido(arch);
            }
        }
        while (arch.get()!='\n');
    }
}
