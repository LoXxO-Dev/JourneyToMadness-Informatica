//
// Created by User on 9/11/2025.
//
#include "utils.hpp"

void imprimirLinea(ofstream &arch,int cant,char car) {
    for (int i=0;i<cant;i++)
        arch.put(car);
    arch<<endl;
}