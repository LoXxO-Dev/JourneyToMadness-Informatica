//
// Created by User on 1/10/2025.
//

#ifndef FUNCIONESREGISTROS_HPP
#define FUNCIONESREGISTROS_HPP
#include "utils.hpp"
void *leeregistro(ifstream &arch) ;
char *leerCadenaExacta(ifstream &arch,char delim) ;
void imprimeregistro(void *dato,ofstream &arch) ;
int cmpregistro(void *a,void *b) ;
#endif //FUNCIONESREGISTROS_HPP
