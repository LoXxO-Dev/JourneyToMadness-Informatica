//
// Created by User on 23/09/2025.
//

#include "BibliotecaConductores.hpp"
#include "BibliotecaGenerica.hpp"
//enum DATO{LIC,NOM,PLAC,LIST};
//99950484,CORTES CORTEZ RAUL ALEX

void *leeconducores(ifstream &archivo) {
    void **reg;
    int licencia, *lic;
    archivo >> licencia;
    if (archivo.eof()) return nullptr;
    archivo.get();
    char *nombre = leerCadenaExacta(archivo, '\n');
    lic = new int;
    *lic = licencia;
    reg = new void *[4]{};
    void **lista = new void *{};
    reg[LIC] = lic;
    reg[NOM] = nombre;
    reg[LIST] = lista;
    return reg;
}

int cmpconductores(void *a, void *b) {
    void **a1 = (void **) a, **b1 = (void **) b;
    int *a11 = (int *) a1[LIC], *b11 = (int *) b1[LIC];
    return *b11 - *a11;
}

int buscalistaconductores(void *lista, void *dato) {
}

void imprimeconductores(ofstream &archivo, void *dato) {
    void **dat = (void **) dato;
    int *lice = (int *) dat[LIC];
    char *nombre = (char *) dat[NOM];

    archivo << left << setw(10) << *lice << setw(30) << nombre << endl;
    if (dat[PLAC]) {
        archivo << setw(10) << "Placas: ";
        imprimirPlacas(dat[PLAC], archivo);
    }
    archivo << endl << setw(10) << "Fecha" << setw(10) << "Placa" << setw(10) << setw(10) << "Infraccion" << endl;
    void **listaInfra = (void **) dat[LIST];
    if (dat[LIST] and listaInfra[0]!=nullptr) {
        imprimirListaInfra(dat[LIST], archivo);
    }
    archivo << endl << endl;
}

void imprimirListaInfra(void *listaInfra, ofstream &archivo) {
    void **lst = (void **) listaInfra;
    imprimeInfoInfraccion(lst[DATO], archivo);

    while (lst and lst[DATO] != nullptr) {
        imprimeInfoInfraccion(lst[DATO], archivo);
        lst = (void **) lst[SIGUIENTE];
    }
}

void imprimeInfoInfraccion(void *dato, ofstream &arch) {
    void **dat = (void **) dato;
    int *fecha = (int *) dat[FECHA];
    char *placa = (char *) dat[PLAC];
    int *infraccion = (int *) dat[INFRA];
    int aa = *fecha / 10000;
    int mm = *fecha % 10000 / 100;
    int dd = *fecha % 100;
    arch << setfill('0') << right << setw(4) << aa << "/" << setw(2) << mm << "/" <<
            setw(2) << dd << setfill(' ') <<
            setw(10) << placa << setw(10) << *infraccion << endl;
}


void imprimirPlacas(void *plac, ofstream &arch) {
    void **placas = (void **) plac;
    for (int i = 0; placas[i]; i++) {
        char *codPlaca = (char *) placas[i];
        arch << setw(10) << codPlaca;
    }
}
