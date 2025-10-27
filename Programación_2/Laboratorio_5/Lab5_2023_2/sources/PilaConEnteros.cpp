//
// Created by User on 1/10/2025.
//

#include "PilaConEnteros.hpp"

void *leenum(ifstream &arch) {
    void **nodo;
    double num, *ptrNum;
    arch >> num;
    if (arch.eof())return nullptr;
    ptrNum = new double;
    *ptrNum = num;
    nodo = new void *[2]{};
    nodo[1] = ptrNum;
    return nodo;
}

int calculanumero(double peso, void **pilas, void *dato, int num) {
    void **dat = (void **) dato;
    for (int i = 0; i < num; i++) {
        if (sePuedeAñadir(pilas[i], dat[1], peso))
            return i;
    }
    return -1;
}

bool sePuedeAñadir(void *pila, void *dato, double pesoMax) {
    if (pila == nullptr)return true;
    else {
        double *peso = (double *) dato;
        void **nodo = (void **) pila;
        double *pesoActual = (double *) nodo[1];
        if (*pesoActual + *peso <= pesoMax)
            return true;
        else return false;
    }
}

int cmpnumero(const void *a, const void *b) {
    void **ai = (void **) a, **bi = (void **) b;
    void  **aii = (void **) ai[0], **bii = (void **) bi[0];
    double *aiii=(double *)aii[1],*biii=(double *)bii[1];
    //cout<<fixed<<setprecision(2)<<*aiii<<endl<<*biii<<" -----"<<endl;
    if (*aiii > *biii)return 1;
    if (*aiii <*biii)return -1;
    if (*aiii == *biii)return 0;


}

void imprimenumero(ofstream &arch, void *nodo) {
    void **nod = (void **) nodo;

    double *ptr = (double *) nod[1];
    arch << setw(10) << *ptr << endl;
    nod = (void **) nod[0];
    while (nod) {
        ptr = (double *) nod[1];
        arch << *ptr << endl;
        nod = (void **) nod[0];
    }
}
