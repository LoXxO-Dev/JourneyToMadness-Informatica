//
// Created by User on 1/10/2025.
//

#include "FuncionesRegistros.hpp"
void *leeregistro(ifstream &arch) {
//2,14268463,BHD6079
    void **reg,**nodo;
    int numPed,*ptrPed,dni,*ptrDni;
    arch>>numPed;
    if (arch.eof()) return nullptr;
    arch.get();
    arch>>dni;
    arch.get();
    char *codLibr=leerCadenaExacta(arch,'\n');
    ptrDni=new int;
    ptrPed=new int;
    *ptrPed=numPed;
    *ptrDni=dni;
    reg=new void *[3]{};
    reg[0]=ptrPed;
    reg[1]=ptrDni;
    reg[2]=codLibr;
    nodo=new void *[2]{};
    nodo[0]=reg;
    return nodo;
}
char *leerCadenaExacta(ifstream &arch,char delim) {
    char *ptr,buffer[100];
    arch.getline(buffer,100,delim);
    ptr=new char[strlen(buffer)+1];
    strcpy(ptr,buffer);
    return ptr;
}
void imprimeregistro(void *dato,ofstream &arch) {
    void **reg=(void**)dato;
    int *ptrCod=(int *)reg[0];
    int *ptrDni=(int *)reg[1];
    char *cod=(char *)reg[2];
    arch<<left<<setw(10)<<*ptrCod<<setw(20)<<*ptrDni<<cod<<endl;

}
int cmpregistro(void *a,void *b) {
    void **lst1=(void **)a,**lst2=(void **)b;
    void **nodo1=(void **)lst1[0],**nodo2=(void **)lst2[0];
    void **enum1=(void **)nodo1[0],**enum2=(void  **)nodo2[0];
    int *dato1=(int *)enum1[0],*dato2=(int *)enum2[0];
    //cout<<*dato1<<" "<<*dato2<<endl;
    if (*dato1 > *dato2) {
        return 1;
    }else {
        if (*dato1 < *dato2) {
            return -1;
        }else return 0;
    }
}