//
// Created by User on 11/11/2025.
//

#include "Biblioteca.hpp"
#include  "Novela.hpp"
#include "Revista.hpp"
#include "Enciclopedia.hpp"

void Biblioteca::carga() {
    ifstream arch;
    apertura_archivos_entrada(arch, "data/Estantes2.csv");
    int i = 0;
    while (true) {
        AEstantes[i].leer(arch);
        if (arch.eof())break;
        i++;
    }
}

void Biblioteca::llena() {
    ifstream arch;
    apertura_archivos_entrada(arch, "data/Libros3.csv");
    char tipo;
    int pos;
    while (true) {
        arch >> tipo;
        if (arch.eof()) break;
        arch.get();
        class Libro *aux;
        if (tipo == 'N') aux = new class Novela();
        else if (tipo == 'E') aux = new class Enciclopedia();
        else if (tipo == 'R') aux = new class Revista();
        aux->leer(arch);
        if (buscarEspacio(aux->get_peso(), pos)) {
            AEstantes[pos].inserta(aux);
        } else {

            delete aux;
        }

    }
}

void Biblioteca::baja() {
    for (int i = 0; this->AEstantes[i].get_id() != -1; i++) {
        AEstantes[i].actualiza();
    }
}

void Biblioteca::muestra() {
    ofstream arch;
    apertura_archivos_salida(arch, "reportes/Reporte.txt");
    arch << "Estantes" << endl;
    imprimirLinea(arch,TAM_LINEA, '=');
    for (int i = 0; this->AEstantes[i].get_id() != -1; i++) {
        AEstantes[i].imprimir(arch);
        imprimirLinea(arch,TAM_LINEA, '*');
    }
}

bool Biblioteca::buscarEspacio(double peso, int &pos) {
    for (int i = 0; this->AEstantes[i].get_id() != -1; i++) {
        double capa = AEstantes[i].get_capacidad();
        double pesoActual=AEstantes[i].obtenerPeso();
        if (capa  >= pesoActual+peso) {
            pos = i;
            return true;
        }
    }
    return false;
}
