//
// Created by User on 11/11/2025.
//

#include "Cola.hpp"

#include "DetalleComanda.hpp"
#include "Nodo.hpp"

void Cola::Encolar(class DetalleComanda &aux) {
    class Nodo *nod;
    nod = new class Nodo();
    nod->dato = aux;
    if (cabeza == nullptr) {
        cabeza = nod;
        cola = nod;
    } else {
        cola->sig = nod;
        cola = nod;
    }
    longitud++;
}

class Nodo *Cola::desencolar() {
    class Nodo *aux;
    aux = cabeza;
    cabeza = cabeza->sig;
    longitud--;
    return aux;
}

void Cola::elimina(int num) {
    int aux = longitud;
    for (int i=0; i<aux; i++) {
        class Nodo *ptr = desencolar();
        if (ptr->dato.verifica(num)) {
        } else {
            Encolar(ptr->dato) ;
        }
    }
}

void Cola::imprimir(ofstream &arch) {
    while (longitud > 0) {
        Nodo *aux = desencolar();
        aux->dato.imprimir(arch);
        longitud--;
    }
}

void Cola::leer(ifstream &archivo,int id) {
    class Nodo aux;
    aux.dato.leer(archivo,id);
    Encolar(aux.dato);

}
