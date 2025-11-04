//
// Created by User on 4/11/2025.
//

#include "Comunes.hpp"
void imprimirLinea(ofstream &arch,int cant,char car) {
    for (int i=0;i<cant;i++)
        arch.put(car);
    arch<<endl;
}