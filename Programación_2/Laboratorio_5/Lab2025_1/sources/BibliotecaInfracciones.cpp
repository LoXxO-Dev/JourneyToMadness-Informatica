//
// Created by User on 23/09/2025.
//

#include "BibliotecaInfracciones.hpp"

#include "BibliotecaGenerica.hpp"


void *leeinfracciones(ifstream &arch) {
    void **reg;
    int licencia, fecha, infraccion, *lic, *fec, *infra;
    char *placa;
    arch >> licencia;
    if (arch.eof())return nullptr;
    arch.get();
    placa = leerCadenaExacta(arch, ',');
    fecha = leerFecha(arch);
    arch >> infraccion;
    lic = new int;
    *lic = licencia;
    fec = new int;
    *fec = fecha;
    infra = new int;
    *infra = infraccion;
    reg = new void *[4]{};
    reg[LICEN] = lic;
    reg[FECHA] = fec;
    reg[PLACA] = placa;
    reg[INFRA] = infra;
    return reg;
}

//enum FALTAS{LICEN,FECHA,PLACA,INFRA};

int leerFecha(ifstream &arch) {
    int dd, mm, aa;
    char car;
    arch >> dd >> car >> mm >> car >> aa >> car;
    return aa * 10000 + mm * 100 + dd;
}

int cmpinfracciones(void *a, void *b) {
    void **a1 = (void **) a, **b1 = (void **) b;
    int *a11 = (int *) a1[FECHA], *b11 = (int *) b1[FECHA];
    return *b11 - *a11;
}

int buscainfraccion(void *lista, void *dato) {

    void **lst = (void **) lista;

    void **dat = (void **) dato;
    int *lice = (int *) dat[LICEN];
    int i = 0;
    while (lst) {
        if (sonIguales(*lice,lst[DATO]))
            break;
        lst = (void **) lst[SIGUIENTE];
        i++;
    }
   return i;
}
