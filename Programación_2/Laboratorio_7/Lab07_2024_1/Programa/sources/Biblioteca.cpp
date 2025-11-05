
//
// Created by User on 3/11/2025.
//

#include "Biblioteca.hpp"

Biblioteca::Biblioteca() {
    cantidad_estantes_horizontales = 0;
    cantidad_estantes_verticales = 0;
    cantidad_total_novelas = 0;
    cantidad_total_enciclopedias = 0;
}

void Biblioteca::imprimir_libro(ofstream &arch) {
    arch << "Informacion de todos los Libros" << endl;
    arch << "Cantidad de Libros Total " << cantidad_total_enciclopedias + cantidad_total_novelas << endl;
    for (int i = 0; i < cantidad_total_novelas; i++) {
        if (not novelas[i].is_colocado()) {
            char aux[100]{"NO SE PUDO COLOCAR"};
            novelas[i].set_nombre(aux);
        }
        novelas[i].imprimir(arch);
    }
    for (int i = 0; i < cantidad_total_enciclopedias; i++) {
        if (not enciclopedias[i].is_colocado()) {
            char aux[100]{"NO SE PUDO COLOCAR"};
            enciclopedias[i].set_nombre(aux);
        }
        enciclopedias[i].imprimir(arch);
    }
    imprimir_linea(arch, '=',TAM_LINEA);
}

void Biblioteca::imprimir(ofstream &arch, char car, int cant) {
    for (int i = 0; i < cant; i++)
        arch.put(car);
    arch << endl;
}

void Biblioteca::cargar_libros() {
    ifstream arch("data/libros2.csv", ios::in);
    if (not arch) {
        cout << "ERROR:No se pudo abrir el archivo libros2.csv" << endl;
        exit(1);
    }
    //N, ABC123, El libro de la Selva, 2, 5, Aventura, 0.75
    char tipo;
    while (true) {
        arch >> tipo;
        if (arch.eof()) break;
        arch.get();
        if (tipo == 'N') {
            Novela aux;
            arch >> aux;
            this->novelas[cantidad_total_novelas++] = aux;
        } else {
            Enciclopedia enci;
            arch >> enci;
            enciclopedias[cantidad_total_enciclopedias++] = enci;
        }
    }
}

void Biblioteca::cargar_estantes() {
    ifstream arch("data/estantes2.csv", ios::in);
    if (not arch) {
        cout << "ERROR:No se pudo abrir el archivo estantes2.csv" << endl;
        exit(1);
    }
    char tipo;
    while (true) {
        arch >> tipo;
        if (arch.eof()) break;
        arch.get();
        if (tipo == 'H') {
            estanteHorizontales[cantidad_estantes_horizontales++].leer(arch);
        } else {
            estantesVerticales[cantidad_estantes_verticales++].leer(arch);
        }
    }
}

void Biblioteca::posicionar_libros() {
    for (int i = 0; i < cantidad_total_novelas; i++) {
        int k = 0;
        while (true) {
            if (k == cantidad_estantes_horizontales) break;
            bool verif = estanteHorizontales[k].posicionarNovelas(novelas[i]);
            if (verif) {
                novelas[i].set_colocado(true);
                break;
            }
            k++;
        }
    }
    for (int i = 0; i < cantidad_total_enciclopedias; i++) {
        int k = 0;
        while (true) {
            if (k == cantidad_estantes_verticales) break;
            bool verif = estantesVerticales[k].posicionarEnciclopedias(enciclopedias[i]);
            if (verif) {
                enciclopedias[i].set_colocado(true);
                break;
            }
            k++;
        }
    }
}

void Biblioteca::mostrar_datos() {
    ofstream arch("reportes/reporte.txt", ios::out);
    if (not arch) {
        cout << "ERROR:No se pudo abrir el archivo reporte.txt" << endl;
        exit(1);
    }
    imprimir_linea(arch, '=',TAM_LINEA);
    arch << setw(60) << "Información del posicionamiento de Libros" << endl << setw(60) << "en los estantes "
            "de la Biblioteca" << endl;
    imprimir_linea(arch, '=',TAM_LINEA);
    arch << "Cantidad de Estantes: " << cantidad_estantes_horizontales + cantidad_estantes_verticales << endl;
    imprimir_linea(arch, '-',TAM_LINEA);
    for (int i = 0; i < cantidad_estantes_horizontales; i++) {
        estanteHorizontales[i].imprimir(arch);
    }
    for (int i = 0; i < cantidad_estantes_verticales; i++) {
        estantesVerticales[i].imprimir(arch);
    }
    imprimir_libro(arch);
}

void Biblioteca::imprimir_linea(ofstream &arch, char car, int cant) {
    for (int i = 0; i < cant; i++)
        arch.put(car);
    arch << endl;
}

int Biblioteca::get_cantidad_estantes_verticales() const {
    return cantidad_estantes_verticales;
}

void Biblioteca::set_cantidad_estantes_verticales(int cantidad_estantes_verticales) {
    this->cantidad_estantes_verticales = cantidad_estantes_verticales;
}

int Biblioteca::get_cantidad_estantes_horizontales() const {
    return cantidad_estantes_horizontales;
}

void Biblioteca::set_cantidad_estantes_horizontales(int cantidad_estantes_horizontales) {
    this->cantidad_estantes_horizontales = cantidad_estantes_horizontales;
}

int Biblioteca::get_cantidad_total_enciclopedias() const {
    return cantidad_total_enciclopedias;
}

void Biblioteca::set_cantidad_total_enciclopedias(int cantidad_total_enciclopedias) {
    this->cantidad_total_enciclopedias = cantidad_total_enciclopedias;
}

int Biblioteca::get_cantidad_total_novelas() const {
    return cantidad_total_novelas;
}

void Biblioteca::set_cantidad_total_novelas(int cantidad_total_novelas) {
    this->cantidad_total_novelas = cantidad_total_novelas;
}
