//
// Created by User on 20/11/2025.
//

#ifndef UTILS_HPP
#define UTILS_HPP
#include <iomanip>
#include <iostream>
#include <string>
#include <cstring>

#include <fstream>

using namespace std;

#define TAM_LINEA 120
void imprimir_linea(ofstream &arch,int cant,char car) ;
void apertura_archivo_entrada(ifstream &archivo,const char *nomb) ;
void apertura_archivo_salida(ofstream &archivo,const char *nomb) ;

#endif //UTILS_HPP
