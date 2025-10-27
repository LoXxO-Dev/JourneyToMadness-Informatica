//
// Created by User on 1/10/2025.
//

#ifndef PILACONREGISTROS_HPP
#define PILACONREGISTROS_HPP
#include "utils.hpp"

void *leeregistro(ifstream &arch) ;
char *leerCadenaExacta(ifstream &arch,char delim) ;
int calcularegistro(double peso, void **pilas, void *dato, int num) ;
bool sePuedeAñadirRegistro(void *pila, void *dato, double pesoMax) ;
int cmpregistro(const void *a,const void *b) ;
void imprimeregistro(ofstream &arch, void *nodo) ;
#endif //PILACONREGISTROS_HPP
