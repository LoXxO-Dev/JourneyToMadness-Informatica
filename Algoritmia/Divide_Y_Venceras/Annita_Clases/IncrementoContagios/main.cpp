/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 7 de mayo de 2024, 11:09 PM
 */

#include <iostream>
#include "funciones.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int arreglo[] {7, 2, 9, 10, 16, 10, 13, 8, 2, 10};
    //int arreglo[] {10, 20, 15, 10, 12, 10, 13, 18};
    int n = sizeof(arreglo)/sizeof(arreglo[0]);
    int cuenta = cuentaIncrementos(arreglo, 0, n - 1);
    cout << "Incrementos: " << cuenta;
    return 0;
}

