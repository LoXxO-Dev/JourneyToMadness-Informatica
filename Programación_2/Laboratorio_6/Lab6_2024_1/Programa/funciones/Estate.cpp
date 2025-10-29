//
// Created by User on 6/10/2025.
//

#include "Estate.hpp"

bool Estate::operator +=(class Libro &lib) {
    int alturaAcumlada = 0;
    for (int i = 0; i < cantidad_libros; i++) {
        alturaAcumlada += this->libro[i].get_ancho();
    }
    if (alturaAcumlada + lib.get_ancho() <= this->altura and lib.get_alto()<=anchura) {
        lib.set_colocado(true);
        libro[cantidad_libros++] = lib;
        for (int i = anchura - 1; i >= anchura - lib.get_alto(); i--) {
            for (int j = alturaAcumlada ; j < alturaAcumlada+lib.get_ancho(); j++) {
                espacios[i * altura + j].set_contenido('*');
                espacios[i * altura + j].set_pos_x(i + 1);
                espacios[i * altura + j].set_pos_y(j + 1);
            }
        }
        return true;
    } else return false;
}

Estate::Estate() {
    this->codigo = nullptr;
    cantidad_libros = 0;
}

void Estate::operator =(const Estate &esta) {
    char codigo[10];
    esta.get_codigo(codigo);
    set_codigo(codigo);

    anchura = esta.get_anchura();
    altura = esta.get_altura();

    cantidad_libros = esta.get_cantidad_libros();
    this->espacios=new Espacio[anchura*altura];
    for (int i=0;i<anchura*altura;i++)
        this->espacios[i].set_contenido(' ');
}

Estate::Estate(const Estate &esta) {
    this->codigo = nullptr;
    cantidad_libros = 0;
    *this = esta;
}


void Estate::leerEstante(ifstream &arch) {
    // AAA, 6, 4
    //BBB,  10, 8
    char codigo[10];
    arch.getline(codigo, 10, ',');
    if (arch.eof()) return;
    arch >> altura;
    arch.get();
    arch >> anchura;
    arch.get();
    set_codigo(codigo);
    cantidad_libros = 0;
}

void Estate::imprime(ofstream &arch) {
    char codigo[10];
    this->get_codigo(codigo);
    arch << left << setw(20) << "Codigo Estante: " << setw(10) << codigo <<
            setw(20) << "Cantidad de Libros" << setw(3) << right << cantidad_libros << endl;
    arch << left << setw(25) << "Anchura del Estante: " << setw(5) << anchura <<
            setw(20) << "Altura del Estante:" << setw(3) << right << altura << endl;
    imprimiLinea(arch, '-',TAM);
    for (int i = 0; i < anchura; i++) {
        for (int k = 0; k < altura; k++) {
            arch << this->espacios[i * altura + k];;
        }
        arch << endl;
    }
    arch << endl << setw(15) << "CODIGO" << setw(20) << "NOMBRE" << setw(10)
            << "ANCHO" << setw(5) << "ALTO" << endl;
    imprimiLinea(arch, '.',TAM);
    for (int i = 0; i < cantidad_libros; i++)
        arch << libro[i];
}

void Estate::imprimiLinea(ofstream &archivo, char car, int cantidad) {
    for (int i = 0; i < cantidad; i++)
        archivo << car;
    archivo << endl;
}

void Estate::get_codigo(char *codigo) const {
    if (this->codigo == nullptr)codigo[0] = 0;
    else strcpy(codigo, this->codigo);
}

void Estate::set_codigo(const char *codigo) {
    if (this->codigo != nullptr)delete[] this->codigo;
    this->codigo = new char[strlen(codigo) + 1];
    strcpy(this->codigo, codigo);
}

int Estate::get_anchura() const {
    return anchura;
}

void Estate::set_anchura(int anchura) {
    this->anchura = anchura;
}

int Estate::get_altura() const {
    return altura;
}

void Estate::set_altura(int altura) {
    this->altura = altura;
}

int Estate::get_cantidad_libros() const {
    return cantidad_libros;
}

void Estate::set_cantidad_libros(int cantidad_libros) {
    this->cantidad_libros = cantidad_libros;
}

void operator>>(ifstream &arch, class Estate &esta) {
    esta.leerEstante(arch);
}

void operator<<(ofstream &arch,  class Estate& esta) {
    esta.imprime(arch);
}
