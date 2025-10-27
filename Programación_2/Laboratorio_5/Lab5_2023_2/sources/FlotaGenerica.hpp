//
// Created by User on 1/10/2025.
//

#ifndef FLOTAGENERICA_HPP
#define FLOTAGENERICA_HPP
#include "utils.hpp"
void cargaCamiones(void *&flota,int numcamiones,double pesomaximo,
                   void *(*lee)(ifstream &),int (*calcula)(double,void **,void *,int ),const char *nomb);

void push(void *&pila,void * nodo,int tipo) ;
void muestracamiones(void *flota,int num,void (*imprime)(ofstream &,void *),const char *nomb);
void aperturaArchivoEntrada(ifstream &arch,const char *nomb) ;
void aperturaArchivosSalida(ofstream &arch,const char *nomb) ;
#endif //FLOTAGENERICA_HPP
