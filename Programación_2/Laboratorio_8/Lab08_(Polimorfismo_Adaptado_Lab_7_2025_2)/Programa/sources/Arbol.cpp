//
// Created by User on 11/11/2025.
//

#include "Arbol.hpp"

#include <regex>

#include "StreamerPago.hpp"
#include "StreamerGratuito.hpp"
#include  "Nodo.hpp"
void Arbol::insertarR(class Nodo *&raiz, class Streamer *ptr) {
    if (raiz==nullptr) {
        raiz=new class Nodo();
        raiz->dato=ptr;
        return;
    }
    if (*raiz->dato>ptr)
        insertarR(raiz->izq,ptr);
    else insertarR(raiz->der,ptr);
}

class Nodo * Arbol::buscar(class Nodo *raiz, int dato) {
    if (raiz->dato->get_id()==dato)
        return raiz;
    if (raiz->dato->get_id()>dato)
       return  buscar(raiz->izq,dato);
    else return buscar(raiz->der,dato);
}

void Arbol::impresionRe(Nodo *raiz, ofstream &arch) {
    if (raiz==nullptr) {
        return ;
    }
    impresionRe(raiz->izq,arch);
    raiz->dato->imprimir(arch);
    imprimir_linea(arch,TAM_LINEA,'=');
    arch<<endl;

    impresionRe(raiz->der,arch);
}

Arbol::Arbol() {
    raiz=nullptr;
}

void Arbol::impresion(ofstream &arch) {
    impresionRe(raiz,arch);


}

void Arbol::leer(char *tipo, ifstream &arch) {
    class Streamer *ptr;
    if (strcmp(tipo,"Pagado")==0) {
        ptr=new class StreamerPago();
    }else if (strcmp(tipo,"Gratuito")==0) {
        ptr=new class StreamerGratuito();
    }
    ptr->leer(arch);
    insertarR(raiz,ptr);
}

void Arbol::buscarEInsertarInfo(int id, ifstream &arch, char *tipo) {
    class Nodo *nodo;
    nodo=buscar(raiz,id);
    nodo->dato->actualiza(tipo,arch);


}
