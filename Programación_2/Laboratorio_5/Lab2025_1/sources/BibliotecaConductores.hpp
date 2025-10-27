//
// Created by User on 23/09/2025.
//

#ifndef BIBLIOTECACONDUCTORES_HPP
#define BIBLIOTECACONDUCTORES_HPP
#include "utils.hpp"
void *leeconducores(ifstream &archivo) ;
int cmpconductores (void *a,void *b) ;
int buscalistaconductores(void *lista,void *dato) ;
void imprimeconductores(ofstream &archivo,void *dato) ;
void imprimirListaInfra(void *listaInfra,ofstream & archivo) ;
void imprimeInfoInfraccion(void *dato, ofstream &arch) ;
void imprimirPlacas(void *plac, ofstream &arch);
#endif //BIBLIOTECACONDUCTORES_HPP
