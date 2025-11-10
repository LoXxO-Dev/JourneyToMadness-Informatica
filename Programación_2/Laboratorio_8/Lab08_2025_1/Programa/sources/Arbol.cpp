//
// Created by User on 7/11/2025.
//

#include "Arbol.hpp"

void Arbol::insertar_recursivo(Nodo *&raiz, Dron *aux) {
    if (raiz == nullptr) {
        raiz = new class Nodo;
        raiz->dron = aux;
        return;
    }
    if (*raiz->dron > *aux)
        insertar_recursivo(raiz->izq, aux);
    else insertar_recursivo(raiz->der, aux);
}

void Arbol::contarR(Nodo *raiz, int &n_sema, int &n_esta) {
    if (raiz == nullptr)
        return;
    char aux[100], tipo[3];
    raiz->dron->get_id(aux);
    aux[2] = 0;
    strcpy(tipo, aux);
    if (strcmp(tipo, "DS") == 0) {
        n_sema++;
    } else if (strcmp(tipo, "DE") == 0) {
        n_esta++;
    }


    contarR(raiz->der, n_sema, n_esta);
    contarR(raiz->izq, n_sema, n_esta);
}

void Arbol::imprimirR(ofstream &arch, Nodo *&raiz) {
    if (raiz == nullptr) {
        return;
    }
    imprimirR(arch, raiz->izq);
    raiz->dron->imprimir(arch);
    imprimirR(arch, raiz->der);
}

void Arbol::actualizaR(Nodo *raiz, int &n_esta, int &n_sema) {
    if (raiz == nullptr) {
        return;
    }
    char aux[100];
    raiz->dron->get_id(aux);
    aux[2] = 0;
   // cout<<aux<<" ";
    if (strcmp(aux, "DS") == 0) {
        if (n_sema > 0)
            this->raiz->dron->actualiza();
        n_sema--;
    } else if (strcmp(aux, "DE") == 0) {
        if (n_esta > 0)
            this->raiz->dron->actualiza();
        n_esta--;
    }else if (strcmp(aux,"DV")==0)
       // this->raiz->dron->actualiza();
    actualizaR(raiz->izq, n_esta, n_sema);
    actualizaR(raiz->der, n_esta, n_sema);
}

Arbol::Arbol() {
    raiz = nullptr;
}

void Arbol::imprimir(ofstream &arch) {
    imprimirR(arch, raiz);
}

void Arbol::insertar(Dron *aux) {
    insertar_recursivo(raiz, aux);
}

void Arbol::actualiza() {
    int n_sema = 0, n_esta = 0;
    contarR(raiz, n_sema, n_esta);
    //int n_sema = 12, n_esta = 14;

    n_sema /= 2;
    n_esta /= 2;
   // cout<<n_sema<<" "<<n_esta<<endl;
    actualizaR(raiz, n_esta, n_sema);
}
