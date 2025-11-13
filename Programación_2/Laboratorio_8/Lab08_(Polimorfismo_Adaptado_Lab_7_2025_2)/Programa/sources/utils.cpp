//
// Created by User on 11/11/2025.
//

#include "utils.hpp"

void imprimir_linea(ofstream &arc, int cant, char car) {
    for (int i=0;i<cant;i++)
        arc.put(car);
    arc<<endl;
}
