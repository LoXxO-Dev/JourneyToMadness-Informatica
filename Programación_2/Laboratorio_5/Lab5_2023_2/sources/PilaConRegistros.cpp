//
// Created by User on 1/10/2025.
//

#include "PilaConRegistros.hpp"
enum REGIS{COD,CANT,PESO};
enum NODO{SIG,DATO};
void *leeregistro(ifstream &arch) {
    void **reg,**nodo;
    int dni,cantidad,*ptr_cant;
    double peso,*ptr_peso;
    char  *cod=leerCadenaExacta(arch,','),car;
    if (arch.eof()) return nullptr;
    arch>>dni>>car;
    arch>>cantidad>>car;
    ptr_cant=new int;
    *ptr_cant=cantidad;
    arch>>peso;
    arch.get();
    ptr_peso=new double;
    *ptr_peso=peso;
    reg=new void*[3]{};
    reg[0]=cod;
    reg[1]=ptr_cant;
    reg[2]=ptr_peso;
    nodo=new void *[2]{};
    nodo[1]=reg;
    return nodo;
}
char *leerCadenaExacta(ifstream &arch,char delim) {
    char *ptr,buffer[100];
    arch.getline(buffer,100,delim);
    ptr=new char[strlen(buffer)+1];
    strcpy(ptr,buffer);
    return ptr;
}
int calcularegistro(double peso, void **pilas, void *dato, int num) {
    void **dat = (void **) dato;
    for (int i = 0; i < num; i++) {
        if (sePuedeAñadirRegistro(pilas[i], dat[1], peso))
            return i;
    }
    return -1;
}

bool sePuedeAñadirRegistro(void *pila, void *dato, double pesoMax) {
    if (pila == nullptr)return true;
    else {
        void **reg=(void **)dato;
        double *peso = (double *) reg[PESO];
       // cout<<" "<<*peso<<" "<<pesoMax<<endl;

        void **nodo = (void **) pila;
        double *pesoActual = (double *) nodo[1];
        //cout<<*(double *)pesoActual<<" dadd";

        if (*pesoActual + *peso <= pesoMax)
            return true;
        else return false;
    }
}

int cmpregistro(const void *a,const void *b) {
    void **ai = (void **) a, **bi = (void **) b;
    void  **aii = (void **) ai[0], **bii = (void **) bi[0];
    double  *aiii=(double *)aii[1],*biii=(double *)bii[1];
   // cout<<fixed<<setprecision(2)<<*aiii<<endl<<*biii<<" -----"<<endl;
    if (*aiii > *biii)return 1;
    if (*aiii <*biii)return -1;
    if (*aiii == *biii)return 0;
}
void imprimeregistro(ofstream &arch, void *nodo) {
    void **nod = (void **) nodo;

    double *ptr = (double *) nod[DATO];
    arch << setw(10) << *ptr << endl;
    nod = (void **) nod[SIG];
    while (nod) {
        void **reg = (void  **) nod[DATO];
        char *cod=(char  *)reg[COD];
        int *cant=(int *)reg[CANT];
        double *peso = (double *)reg[PESO];
        arch <<setw(20)<<right<<cod<<setw(10)<<*cant<<setw(10)<<*peso << endl;
        nod = (void **) nod[0];
    }
}