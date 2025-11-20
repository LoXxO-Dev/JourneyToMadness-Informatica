//
// Created by User on 20/11/2025.
//

#ifndef UTILS_HPP
#define UTILS_HPP
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;
#define TAM_LINEA 120

void imprimir_linea(ofstream &arch,int cant,char car);
void apertura_archivos_entrada(ifstream &arch,const char *nomb);
void apertura_archivos_salida(ofstream &arch,const char *nomb);
#endif //UTILS_HPP
