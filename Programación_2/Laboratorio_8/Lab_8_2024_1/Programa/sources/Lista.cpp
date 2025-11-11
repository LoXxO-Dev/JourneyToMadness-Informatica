//
// Created by User on 11/11/2025.
//

#include "Lista.hpp"
#include "Nodo.hpp"


double Lista::obtenerTotal() {
    class Nodo *aux = ini;
    double total=0;
    while (aux) {
        total+=aux->plibro->get_peso();
        aux=aux->sig;
    }
    return total;
}

void Lista::actualiza() {
    Nodo *aux = ini;
    while (aux) {
        aux->plibro->actualiza();
        aux = aux->sig;
    }
}

void Lista::imprimir(ofstream &arch) {
    class Nodo *aux = ini;
    while (aux) {
        aux->plibro->imprime(arch);
        aux = aux->sig;
    }
}

void Lista::insertar(class Libro *aux) {
    class Nodo *nod, *anterior;
    nod = new class Nodo();
    nod->plibro = aux;
    if (ini == nullptr) {
        ini = nod;
    } else {
        class Nodo *aux = ini;
        while (aux) {
            anterior = aux;
            aux = aux->sig;
        }
        anterior->sig = nod;
    }
}
