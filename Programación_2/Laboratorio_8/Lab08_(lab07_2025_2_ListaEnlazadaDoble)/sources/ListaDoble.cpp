//
// Created by User on 20/11/2025.
//

#include "ListaDoble.hpp"

#include "NodoLista.hpp"
#include "StreamerPago.hpp"
#include "StreamerGratuito.hpp"

ListaDoble::ListaDoble() {
    cabeza = nullptr;
    cola = nullptr;
}

void ListaDoble::leer(char *tipo, ifstream &arch) {
    class Streamer *ptr;
    if (strcmp(tipo, "Pagado") == 0)
        ptr = new class StreamerPago();
    else if (strcmp(tipo, "Gratuito") == 0)
        ptr = new class StreamerGratuito();
    ptr->leer(arch);
    //insertar(ptr);
    //insertarSinColar(ptr);
    insertarEnOrden(ptr);
}

void ListaDoble::insertar(class Streamer *dato) {
    class NodoLista *nuevo;
    nuevo = new class NodoLista();
    nuevo->streamer = dato;
    if (cabeza == nullptr) {
        cabeza = nuevo;
        cola = nuevo;
    } else {
        nuevo->ant = cola;
        cola->sig = nuevo;
        cola = nuevo;
    }
}

void ListaDoble::insertarSinColar(class Streamer *dato) {
    class NodoLista *nuevo;
    nuevo = new class NodoLista();
    nuevo->streamer = dato;
    if (cabeza == nullptr) {
        cabeza = nuevo;
    } else {
        class NodoLista *recorrido = cabeza;
        while (true) {
            if (recorrido->sig == nullptr) break;
            recorrido = recorrido->sig;
        }
        recorrido->sig = nuevo;
        nuevo->ant = recorrido;
    }
}

void ListaDoble::insertarEnOrden(class Streamer *dato) {
    class NodoLista *nuevo, *anterior = nullptr;
    nuevo = new class NodoLista();
    nuevo->streamer = dato;

    class NodoLista *recorrido = cabeza;
    while (recorrido) {
        if (recorrido->streamer->get_id() > dato->get_id()) break;
        anterior = recorrido;
        recorrido = recorrido->sig;
    }
    nuevo->ant = anterior;
    nuevo->sig = recorrido;
    if (recorrido)
        recorrido->ant = nuevo;
    if (anterior)
        anterior->sig = nuevo;
    else cabeza = nuevo;
}

void ListaDoble::actualizar(char *tipo, ifstream &arch) {
    int id;
    arch >> id;
    arch.get();
    class NodoLista *nodo = buscarNodo(id);
    nodo->streamer->actualiza(tipo, arch);
}

void ListaDoble::eliminar() {
    class NodoLista *recorrido=cabeza,*anterior=nullptr;
    while (recorrido) {
        if ( not recorrido->streamer->eliminable()) {
            if (anterior) {
                anterior->sig=recorrido->sig;
            }else {
                cabeza = recorrido->sig;
            }
            delete recorrido;
            if (anterior) {
                recorrido=anterior->sig;
            }else {
                recorrido=cabeza;
            }
        }else {
            anterior = recorrido;
            recorrido = recorrido->sig;
        }
    }
}

void ListaDoble::eliminarSinAnterior() {
    class NodoLista *recorrido=cabeza;
    while (recorrido) {
        if ( not recorrido->streamer->eliminable()) {
            class NodoLista *sale=recorrido;
            recorrido=recorrido->sig;
            if (sale == cabeza) {
                cabeza = sale->sig;
                if (cabeza) cabeza->ant = nullptr;
            } else {
                sale->ant->sig = sale->sig;
                if (sale->sig) sale->sig->ant = sale->ant;
            }
            delete sale;
        }else {
            recorrido = recorrido->sig;
        }
    }
}

void ListaDoble::imprimir(ofstream &arch) {
    class NodoLista *recorrido = cabeza;
    while (recorrido) {
        recorrido->streamer->imprimir(arch);
        recorrido = recorrido->sig;
    }
}

class NodoLista *ListaDoble::buscarNodo(int id) {
    class NodoLista *recorrido = cabeza;
    while (recorrido) {
        if (recorrido->streamer->get_id() == id) return recorrido;
        recorrido = recorrido->sig;
    }
}
