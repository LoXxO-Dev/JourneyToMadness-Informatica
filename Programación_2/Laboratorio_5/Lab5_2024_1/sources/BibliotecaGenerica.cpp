//
// Created by User on 1/10/2025.
//

#include "BibliotecaGenerica.hpp"

void crealista(void *&lista, void *(*lee)(ifstream &),
               const char *nombArch) {
    ifstream arch;
    aperturaArchivosEntrada(arch, nombArch);
    void *nodo, **lst;
    lst = new void *[2]{};
    while (true) {
        nodo = lee(arch);
        if (arch.eof())break;
        insertaLista(lst, nodo);
    }

    lista = lst;
}

void insertaLista(void **&lst, void *nodo) {
    if (lst[0] == nullptr) {
        lst[0] = nodo;
        lst[1] = nodo;
    } else {
        void **final = (void **) lst[1];
        final[1] = nodo;
        lst[1] = nodo;
    }
}

void imprimeLista(void *lista, void (*imprime)(void *, ofstream &), const char *nomb) {
    ofstream arch;
    aperturaArchivosSalida(arch, nomb);
    void **lst = (void **) lista;
    void **recorrido = (void **) lst[0];
    while (recorrido) {
        imprime(recorrido[0], arch);
        recorrido = (void **) recorrido[1];
    }
}







void combinalista(void *&lista1, void *&lista2, void *&listaFinal, int (*compare)(void *, void *)) {
    void *nodo, **lst = new void *[2]{}, **lst1 = (void **) lista1, **lst2 = (void **) lista2;
    void **recorrido1 = (void **) lst1[0], **recorrido2 = (void **) lst2[0];
    while (recorrido1 and recorrido2) {
        int numCompara = compare(lista1, lista2);;
        //cout << numCompara << endl;
        if (numCompara == 0) {
            recorrido1 = (void **) recorrido1[1];
            recorrido2 = (void **) recorrido2[1];
            nodo = quitalista(lista1);
            nodo = quitalista(lista2);
        } else {
            if (numCompara > 0) {
                recorrido2 = (void **) recorrido2[1];
                nodo = quitalista(lista2);
            } else {
                recorrido1 = (void **) recorrido1[1];
                nodo = quitalista(lista1);
            }
        }
        insertaLista(lst, nodo);
    }
    if (esListaVacia(lista1))insertarRestantes(lst, nodo, recorrido2,lista2);
    if (esListaVacia(lista2))insertarRestantes(lst, nodo, recorrido1,lista1);
    listaFinal = lst;
}
void insertarRestantes(void **&lst, void *nodo, void **recorrido,void *&lista) {
    while (recorrido) {
        recorrido= (void **) recorrido[1];
        nodo=quitalista(lista);
        insertaLista(lst, nodo);
    }
}

bool esListaVacia(void *lista) {
    void **lst = (void **) lista;
    return lst[0] == nullptr;
}

void *quitalista(void *&lista) {
    if (not esListaVacia(lista)) {
        void **lst = (void **) lista;
        void **recorrido = (void **) lst[0];
        void **sale;
        sale = new void *[2]{};
        sale[0] = recorrido[0];
        lst[0] = recorrido[1];
        delete recorrido;
        return sale;
    }
}

void aperturaArchivosEntrada(ifstream &arch, const char *nombArch) {
    arch.open(nombArch, ios::in);
    if (!arch) {
        cout << "ERROR:No se pudo abrir el archivo con nombre " << endl;
        exit(1);
    }
}

void aperturaArchivosSalida(ofstream &arch, const char *nombArch) {
    arch.open(nombArch, ios::out);
    if (!arch) {
        cout << "ERROR:No se pudo abrir el archivo con nombre " << endl;
        exit(1);
    }
}
