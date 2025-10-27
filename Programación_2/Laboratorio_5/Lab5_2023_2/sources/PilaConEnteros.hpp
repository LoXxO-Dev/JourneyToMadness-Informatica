//
// Created by User on 1/10/2025.
//

#ifndef PILACONENTEROS_HPP
#define PILACONENTEROS_HPP
#include "utils.hpp"
void *leenum(ifstream &arch) ;
int calculanumero(double peso,void **pilas,void *dato,int num) ;
bool sePuedeAñadir(void *pila,void *dato,double pesoMax) ;
int cmpnumero(const void *a,const void *b) ;
void imprimenumero(ofstream &arch, void *nodo) ;
#endif //PILACONENTEROS_HPP
