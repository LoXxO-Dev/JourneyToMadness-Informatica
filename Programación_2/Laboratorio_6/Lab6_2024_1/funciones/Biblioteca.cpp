//
// Created by User on 6/10/2025.
//

#include "Biblioteca.hpp"

void Biblioteca::cargar_libros() {
    ifstream archivo("data/libros.csv", ios::in);
    if (!archivo) {
        cout << "ERROR:No se pudo abrir el archivo con nombre " << endl;
        exit(1);
    }
    Libro lib;
    this->cantidad_libros = 0;
    while (true) {
        archivo>>lib;
        //====
        lib.leerLibro(archivo);
        if (archivo.eof()) break;
        libros[cantidad_libros++] = lib;
    }
}

void Biblioteca::cargar_estantes() {
    ifstream arch("data/estantes.csv", ios::in);
    if (!arch) {
        cout << "GG";
        exit(1);
    }
    this->cantidad_estantes = 0;
    Estate esta;
    while (true) {
        arch >> esta;
        if (arch.eof()) break;
        estantes[cantidad_estantes++] = esta;
    }
}

void Biblioteca::posicionar_libros() {
    int numEstan = 0;
    for (int i = 0; i < this->cantidad_libros; i++) {
        if (this->estantes[numEstan] += libros[i]) {
        } else {
            if (numEstan + 1 < this->cantidad_estantes) {
                i--;
                numEstan++;
            } else {
                this->libros[i].set_nombre("NO SE PUDO COLOCAR");
            }
        }
    }
}

void Biblioteca::mostrar_datos() {
    ofstream archivo("reportes/datos.txt", ios::out);
    if (not archivo) {
        cout << "Error";
        exit(1);
    }
    imprimiLinea(archivo, '=',TAM);
    archivo << setw(70) << "Informacion del posicionamiento de Libros " << endl;
    archivo << setw(60) << "en los estantes de la Biblioteca" << endl;
    imprimiLinea(archivo, '=',TAM);
    archivo << "Cantidad de Estantes :" << setw(3) << right << cantidad_estantes << endl;
    for (int i = 0; i < cantidad_estantes; i++) {
        imprimiLinea(archivo, '-',TAM);
        archivo << estantes[i];
    }
    imprimiLinea(archivo, '=',TAM);
    archivo<<"Informacion de todos los libros:"<<endl<<"Cantidad de Libros Total: "<<cantidad_libros<<endl;
    for (int i = 0; i < cantidad_libros; i++) {
        archivo << libros[i];
    }
    imprimiLinea(archivo, '=',TAM);

}

void Biblioteca::imprimiLinea(ofstream &archivo, char car, int cantidad) {
    for (int i = 0; i < cantidad; i++)
        archivo << car;
    archivo << endl;
}

int Biblioteca::get_cantidad_estantes() const {
    return cantidad_estantes;
}

void Biblioteca::set_cantidad_estantes(int cantidad_estantes) {
    this->cantidad_estantes = cantidad_estantes;
}

int Biblioteca::get_cantidad_libros() const {
    return cantidad_libros;
}

void Biblioteca::set_cantidad_libros(int cantidad_libros) {
    this->cantidad_libros = cantidad_libros;
}
