//
// Created by User on 23/11/2025.
//

#include "Arbol.hpp"

#include "Biblioteca.hpp"

void Arbol::insertar(class NEstante *&raiz, class NEstante *aux) {
    if (raiz==nullptr) {
        raiz=new class NEstante();
        raiz=aux;
        return;
    }
    if (raiz->get_disponible()>aux->get_disponible())
        insertar(raiz->izq,aux);
    else
        insertar(raiz->der,aux);
}

void Arbol::imprimirR(class NEstante *raiz, ofstream &arch) {
    if (raiz!=nullptr) {
        imprimirR(raiz->izq,arch);
        raiz->imprimir(arch);
        imprimirR(raiz->der,arch);

    }
}

class NEstante * Arbol::buscarEspacio(class NEstante *raiz, double peso) {
    if (raiz==nullptr) return nullptr;
    if (raiz->get_disponible()>=peso)
        return raiz;
    else if (raiz->get_disponible()<peso)
        return buscarEspacio(raiz->der,peso);
}

Arbol::Arbol() {
    raiz =nullptr;
}

void Arbol::imprimir(ofstream &arch) {
    imprimirR(raiz,arch);
}

void Arbol::leer(int id, ifstream &arch,ifstream &arch2) {
    class NEstante *aux;
    aux=new class NEstante();

    aux->leer(arch,id,arch2);
    insertar(raiz,aux);

}

void Arbol::ingresar(double peso) {
    ofstream arch;
    apertura_archivo_salida(arch,"Reportes/reporteNuevoPeso.txt");
    class NEstante *aux;
    aux=buscarEspacio(raiz,peso);
    if (aux!=nullptr) {
       arch<<"Si hay espacio"<<endl;
        aux->imprimir(arch);
    }
    else
       arch<<" No es posible colocar el libro"<<endl;

}
