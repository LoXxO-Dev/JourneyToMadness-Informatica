//
// Created by User on 25/11/2025.
//

#ifndef UTILS_HPP
#define UTILS_HPP
#include <iomanip>
#include <cstring>
#include <fstream>
#include <string>
#include <iostream>

#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;
#define TAM_LINEA 120
#define FECHA_ACTUAL 20251125
#define ENGAGEMENT 2
#define CALIDAD  3
#define BASICA 1
void imprimir_Linea(ofstream &arch,int cant ,char car);
void apertura_archivos_entrada(ifstream &arch,const char *nombArch);
void apertura_archivos_salida(ofstream &arch,const char *nombArch);

#endif //UTILS_HPP
