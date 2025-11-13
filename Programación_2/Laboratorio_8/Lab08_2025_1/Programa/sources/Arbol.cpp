//
// Created by User on 7/11/2025.
//

#include "Arbol.hpp"
#include "DroneEstacionamiento.hpp"
#include "DroneVelocidad.hpp"
#include "DroneSemaforo.hpp"
void Arbol::insertar_recursivo(Nodo *&raiz, Dron *aux) {
    if (raiz == nullptr) {
        raiz = new class Nodo;
        raiz->dron = aux;
        return;
    }
    if (*raiz->dron > aux)
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
    if (strcmp(tipo, "DS") == 0 and raiz->dron->verificar()) {
        n_sema++;
    } else if (strcmp(tipo, "DE")==0 and raiz->dron->verificar() ) {
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

void Arbol::actualizaR(class Nodo *raiz, int &n_esta, int &n_sema) {
    if (raiz == nullptr) {
        return;
    }
    char aux[100];
    raiz->dron->get_id(aux);
    aux[2] = 0;
    if (strcmp(aux, "DS") == 0) {
        if (n_sema > 0) {
            raiz->dron->actualiza();
        }

        n_sema--;
    } else if (strcmp(aux, "DE") == 0) {
        if (n_esta > 0) {
            raiz->dron->actualiza();
        }
        n_esta--;
    }else if (strcmp(aux,"DV")==0)
        this->raiz->dron->actualiza();
    actualizaR(raiz->izq, n_esta, n_sema);
    actualizaR(raiz->der, n_esta, n_sema);
}

Arbol::Arbol() {
    raiz = nullptr;
}

void Arbol::lee(ifstream &arch) {
    char tipo[100];
    arch.getline(tipo, 100, ',');
    if (arch.eof()) return;;
    class Dron *aux;
    if (strcmp(tipo, "Velocidad") == 0)
        aux = new class DroneVelocidad();
    else if (strcmp(tipo, "Semaforo") == 0)
        aux = new class DroneSemaforo();
    else if (strcmp(tipo, "Estacionamiento") == 0)
        aux = new class DroneEstacionamiento();
    aux->leer(arch);
    insertar_recursivo(raiz,aux);
}

void Arbol::imprimir(ofstream &arch) {
    imprimirR(arch, raiz);
}



void Arbol::actualiza() {
    int n_sema = 0, n_esta = 0;
   contarR(raiz, n_sema, n_esta);

    n_sema /= 2;
    n_esta /= 2;
    actualizaR(raiz, n_esta, n_sema);
   //cambiar_valores(raiz,n_sema,n_esta);
}
void Arbol::cambiar_valores(Nodo *raiz, int &cant_s, int &cant_e) {
    if (raiz) {
        if (cant_s == 0 and cant_e == 0)
            return;
        cambiar_valores(raiz->izq, cant_s, cant_e);
        bool ver = raiz->dron->verificar();
        if (ver) {
            char aux[10];
            raiz->dron->get_id(aux);
            if (cant_s > 0 and aux[1] == 'S') {
                raiz->dron->actualiza();
                cant_s--;
            } else if (cant_e > 0 and aux[1] == 'E') {
                raiz->dron->actualiza();
                cant_e--;
            }
        }
        cambiar_valores(raiz->der, cant_s, cant_e);

    }
}
