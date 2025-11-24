//
// Created by User on 23/11/2025.
//

#include "Biblioteca.hpp"

void Biblioteca::carga() {
    ifstream arch,arch2;
    apertura_archivo_entrada(arch,"data/Estantes3.csv");
    apertura_archivo_entrada(arch2,"data/Libros31.csv");

        int id;

    while (true) {
        arch>>id;
        if (arch.eof()) break;
        AEstante.leer(id,arch,arch2);

    }


}

void Biblioteca::muestra() {
    ofstream arch;
    apertura_archivo_salida(arch,"Reportes/reporte.txt");
    arch<<fixed<<setprecision(2);
    AEstante.imprimir(arch);
}

void Biblioteca::prueba(double num) {
    AEstante.ingresar(num);
}
