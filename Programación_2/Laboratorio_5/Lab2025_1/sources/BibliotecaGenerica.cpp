//
// Created by User on 23/09/2025.
//

#include "BibliotecaGenerica.hpp"
#include "BibliotecaConductores.hpp"
#include "BibliotecaInfracciones.hpp"

void generaLista(void *&lista) {
    void **nodo1, **nodo2, **nodo3;
    nodo1 = new void *[2]{};
    nodo2 = new void *[2]{};
    nodo3 = new void *[2]{};

    nodo1[SIGUIENTE] = nodo2;
    nodo2[SIGUIENTE] = nodo3;

    lista = new void *;
    lista = nodo1;
}

void creaLista(void *&lista, void *(*lee)(ifstream &), int (*cmp)(void *, void *),
               int (*busca)(void *, void *), const char *nombArch) {
    ifstream archivo;
    aperturaArchivosEntrada(archivo, nombArch);
    void *dato;

    int pos;
    while (true) {
        dato = lee(archivo);
        if (archivo.eof()) break;
        if (busca != buscainfraccion)
            insertarLista(lista, dato, cmp);
        else {
            int pos = busca(lista, dato);
            void **lst = (void **) lista;
            for (int i = 0; i < pos; i++)lst = (void **) lst[SIGUIENTE];
            void **infra = (void **) lst[DATO];
            insertarLista(infra[LIST], dato, cmp);
        }
    }
}

void insertarLista(void *&lista, void *dato, int (*cmp)(void *, void *)) {
    void **p = (void **) lista, **anterior = nullptr, **nuevo;
    nuevo = new void *[2]{};
    nuevo[DATO] = dato;
    while (p and p[DATO] != nullptr) {
        if (cmp(dato, p[DATO]) > 0) break;
        anterior = p;
        p = (void **) p[SIGUIENTE];
    }
    nuevo[SIGUIENTE] = p;
    if (anterior == nullptr)
        lista = nuevo;
    else anterior[SIGUIENTE] = nuevo;
}

void imprimeLista(void *lista, void (*imprime)(ofstream &, void *), const char *nombr) {
    ofstream archivo;
    aperturaArchivosSalida(archivo, nombr);
    void **p = (void **) lista;
    while (p and p[DATO] != nullptr) {
        imprime(archivo, p[DATO]);
        p = (void **) p[SIGUIENTE];
    }
}

void aperturaArchivosEntrada(ifstream &archivo, const char *nombArch) {
    archivo.open(nombArch, ios::in);
    if (!archivo) {
        cout << "ERROR: No se pudo abrir el archivo con nombre " << nombArch << endl;
        exit(1);
    }
}

void aperturaArchivosSalida(ofstream &archivo, const char *nombArch) {
    archivo.open(nombArch, ios::out);
    if (!archivo) {
        cout << "ERROR: No se pudo abrir el archivo con nombre " << nombArch << endl;
        exit(1);
    }
}

char *leerCadenaExacta(ifstream &arch, char car) {
    char *ptr, buffer[200];
    arch.getline(buffer, 200, car);
    if (arch.eof()) return nullptr;
    ptr = new char[strlen(buffer) + 1];
    strcpy(ptr, buffer);
    return ptr;
}

void cargaUnidades(void *&lista, const char *nombrArch) {
    ifstream archivo;
    aperturaArchivosEntrada(archivo, nombrArch);
    //15029228,N0Z-560
    int licencia, posDni;
    char *placa;
    void **lst = (void **) lista;
    int nd = 0;
    while (lst) {
        nd++;
        lst = (void **) lst[SIGUIENTE];
    }
    int capcidad[nd]{}, nDatos[nd]{};
    while (true) {
        archivo >> licencia;
        if (archivo.eof()) break;
        archivo.get();
        placa = leerCadenaExacta(archivo, '\n');
        posDni = buscarIndividuo(lista, licencia);
        if (posDni != -1) {
            insertarPlaca(lista, posDni, placa, capcidad[posDni], nDatos[posDni]);
        }
    }
}

void insertarPlaca(void *lista, int posDni, char *placa, int &cap, int &nDatos) {
    void **lst = (void **) lista;
    for (int i = 0; i < posDni; i++)
        lst = (void **) lst[SIGUIENTE];
    void **dato = (void **) lst[DATO];
    void **aux = (void **) dato[PLAC];
    if (nDatos == cap)incrementarEspacios(aux, nDatos, cap);
    aux[nDatos - 1] = placa;
    dato[PLAC] = aux;
    nDatos++;
}

void incrementarEspacios(void **&arreglo, int &nDatos, int &cap) {
    void **aux;
    cap += INCREMENTO;
    if (arreglo == nullptr) {
        arreglo = new void *[cap]{};
        nDatos = 1;
    } else {
        aux = new void *[cap]{};
        for (int i = 0; i < nDatos; i++)
            aux[i] = arreglo[i];
        delete [] arreglo;
        arreglo = aux;
    }
}

int buscarIndividuo(void *lista, int licencia) {
    void **lst = (void **) lista;
    int i = 0;
    while (lst) {
        if (sonIguales(licencia, lst[DATO]))
            return i;
        lst = (void **) lst[SIGUIENTE];
        i++;
    }
    return -1;
}

bool sonIguales(int licencia, void *lista) {
    void **lst = (void **) lista;
    int *lic = (int *) lst[LIC];
    return (*lic) == licencia ? true : false;
}
