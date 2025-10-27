//
// Created by User on 23/09/2025.
//

#ifndef BIBLIOTECAINFRACCIONES_HPP
#define BIBLIOTECAINFRACCIONES_HPP
#include "utils.hpp"
void *leeinfracciones(ifstream &arch) ;
int leerFecha(ifstream & arch) ;
int cmpinfracciones(void *a, void *b) ;
int buscainfraccion(void *lista,void *dato) ;
#endif //BIBLIOTECAINFRACCIONES_HPP
