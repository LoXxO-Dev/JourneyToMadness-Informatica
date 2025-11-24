//
// Created by User on 23/11/2025.
//

#ifndef UTILS_HPP
#define UTILS_HPP
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>

#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;
#define TAM_LINEA 120
void imprimir_linea(ofstream &arch,int cant,char car);
void apertura_archivo_entrada(ifstream &arch,const char *nomb);
void apertura_archivo_salida(ofstream &arch,const char *nomb);
#endif //UTILS_HPP
