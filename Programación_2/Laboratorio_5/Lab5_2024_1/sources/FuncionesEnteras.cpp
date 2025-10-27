//
// Created by User on 1/10/2025.
//

#include "FuncionesEnteras.hpp"

void *leenum(ifstream &arch) {
    void **nodo, **reg;
    int dato,*ptr_dat;
    arch>>dato;
    if (arch.eof())return nullptr;
    ptr_dat=new int;
    *ptr_dat=dato;
    reg = new void *;
    reg[0]=ptr_dat;
    nodo = new void *[2]{};
    nodo[0] = reg;
    return nodo;
}
void imprimenum(void *dato,ofstream &arch) {
    void **dat=(void **)dato;
    int *ptr_dato=(int *)dat[0];
    arch<<*ptr_dato<<endl;
}
int cmpnum(void *a,void *b) {
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