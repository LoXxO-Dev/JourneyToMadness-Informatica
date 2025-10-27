//
// Created by User on 1/10/2025.
//

#include "FlotaGenerica.hpp"
#include "PilaConEnteros.hpp"

void cargaCamiones(void *&flota, int numMax, double pesomaximo,
                   void *(*lee)(ifstream &), int (*calcula)(double, void **, void *, int), const char *nomb) {
    ifstream arch;
    aperturaArchivoEntrada(arch, nomb);
    void *nodo, **pilas = new void *[numMax]{};
    while (true) {
        nodo = lee(arch);
        if (arch.eof())break;
        //   cout << *(double *) (((void **) nodo)[1]) << " ";

        int pos = calcula(pesomaximo, pilas, nodo, numMax);
        //  cout << pos << endl;
        int tipo=2;
        if (lee==leenum)
            tipo=1;
       if (pos != -1)
            push(pilas[pos], nodo,tipo);
    }
    flota = pilas;
}

void push(void *&pila, void *nodo,int tipo) {
    if (tipo==1) {
        void **nod = (void **) nodo;
        double *ptrPeso = (double *) nod[1];
        if (pila == nullptr) {
            double *nuevo = new double;
            *nuevo = ptrPeso[0];
            void **inicio = new void *[2]{};
            inicio[0] = nodo;
            inicio[1] = nuevo;
            pila = inicio;
        } else {
            void **nodoControla = (void **) pila;
            double *pesoActual = (double *) nodoControla[1];

            *pesoActual += ptrPeso[0];
            nodoControla = (void **) nodoControla[0];

            while (nodoControla) {
                if (not nodoControla[0])break;
                nodoControla = (void **) nodoControla[0];
            }
            nodoControla[0] = (void **) nodo;
        }
    }else {
        void **nod = (void **) nodo;
        void **regNodo = (void **) nod[1];
        double *ptrPeso = (double *) regNodo[2];
     //   cout<<*ptrPeso<<endl;
        if (pila == nullptr) {
            double *nuevo = new double;
            *nuevo = ptrPeso[0];
            void **inicio = new void *[2]{};
            inicio[0] = nodo;
            inicio[1] = nuevo;
            pila = inicio;
        } else {
            void **nodoControla = (void **) pila;
            double *pesoActual = (double *) nodoControla[1];
            *pesoActual += ptrPeso[0];
            nodoControla = (void **) nodoControla[0];
            while (nodoControla) {
                if (not nodoControla[0])break;
                nodoControla = (void **) nodoControla[0];
            }
            nodoControla[0] = (void **) nodo;
        }
    }

}

void aperturaArchivoEntrada(ifstream &arch, const char *nomb) {
    arch.open(nomb, ios::in);
    if (not arch) {
        cout << "ERROR:No se pudo abrir el archivo con nombre " << nomb << endl;
        exit(1);
    }
}

void aperturaArchivosSalida(ofstream &arch, const char *nomb) {
    arch.open(nomb, ios::out);
    if (not arch) {
        cout << "ERROR:No se pudo abrir el archivo con nombre " << nomb << endl;
        exit(1);
    }
}

void muestracamiones(void *flota, int num, void (*imprime)(ofstream &, void *), const char *nomb) {
    ofstream arch;
    aperturaArchivosSalida(arch, nomb);
    void **pila = (void **) flota;
    arch << fixed << setprecision(2);
    for (int i = 0; i < num; i++) {
        arch << left << "Camion " << i + 1 << ":" << setw(10) << right << "Peso:";
        imprime(arch, pila[i]);
    }
}
