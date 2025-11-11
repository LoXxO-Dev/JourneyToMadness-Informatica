//
// Created by User on 11/11/2025.
//

#ifndef UTILS_HPP
#define UTILS_HPP
#include <iomanip>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
#define TAM_LINEA 120
void imprimirLinea(ofstream &arch,int cant,char car);
void apertura_archivos_entrada(ifstream &arch,const char *nomb);
void apertura_archivos_salida(ofstream &arch,const char *nomb);
#endif //UTILS_HPP
