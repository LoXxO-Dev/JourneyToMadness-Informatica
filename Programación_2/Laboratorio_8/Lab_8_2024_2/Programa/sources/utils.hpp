//
// Created by User on 11/11/2025.
//

#ifndef UTILS_HPP
#define UTILS_HPP
#include <iomanip>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;
#define TAM_LINEA 120
void imprimir_linea(ofstream &arch,int cant,char car);
void apertura_archivos_entrada(ifstream &archivo,const char *nomb);
void apertura_archivos_salida(ofstream &archivo,const char *nomb);

#endif //UTILS_HPP
