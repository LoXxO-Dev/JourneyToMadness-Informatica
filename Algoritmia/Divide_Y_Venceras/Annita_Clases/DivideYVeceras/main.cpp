/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 2 de mayo de 2024, 12:35 PM
 */

#include <iostream>

using namespace std;
#include "funciones.h"

/*
 * Ejercicios de la separata
 */
int main(int argc, char** argv) {

    int arreglo[]{-5, -4, 0, -1, 0, 1, 1, 1};
    int n = sizeof (arreglo) / sizeof (arreglo[0]);

    //cout << "CUENTA UNOS: " << cuentaUnos(arreglo, 0, n - 1) << endl;

    cout << "CUENTA CEROS: " << cuentaCeros(arreglo, 0, n - 1, 0) << endl;

    int arreglo2[]{1, 1, 3, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7};
    //int arreglo2[]{1, 6, 3, 4, 5, 6, 3, 7, 5, 4, 3, 1, 7};

    n = sizeof (arreglo2) / sizeof (arreglo2[0]);
    buscaSolo(arreglo2, 0, n - 1);


    cout << endl;
    int arreglo3[]{8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1}; //funciona por que se forma una montaña
    n = sizeof (arreglo3) / sizeof (arreglo3[0]);
    //cout << "EL PUNTO MÁS ALTO DE LA MONTAÑA: " << buscaMontana(arreglo3, 0, n - 1) << endl;

    /* Busca el menor*/
    int arreglo4[]{5, 6, 1, 2, 3, 4};
    n = sizeof (arreglo4) / sizeof (arreglo4[0]);

    cout << "EL PUNTO MÁS BAJO ES: " << buscaMenor(arreglo4, 0, n - 1) << endl << endl;

    /*suma máxima consecutiva*/
    int arreglo5[8]{-2, -5, 6, -2, -3, 1, 5, -6};
    n = sizeof (arreglo5) / sizeof (arreglo5[0]);
    cout << "Salida máxima: " << sumaMaximaConsecutiva(arreglo5, 0, n - 1) << endl << endl;

    /*Tráfico de la red de una organización - 2024-1_Lab3*/
    /*suma mínima consecutiva*/
    /* int arreglo6[] {2, 5, -6, 2, 3, -1, -5, 6} ; 
       int arreglo6[] {2, -3, 4, -5, -7} ; n = 5;
       int arreglo6[] {-4, 5, 6, -4, 3, -1, -5, 6} ;
     */
    int arreglo6[]{2, -3, 4, -5, -7};
    n = sizeof (arreglo6) / sizeof (arreglo6[0]);
    cout << "Salida mínima: " << sumaMinimaConsecutiva(arreglo6, 0, n - 1) << endl;


    /*Ejercicio Oppenheimer - 2024-1_Lab3*/
    //int arreglo7[]{-1, 0, -1, 0, 1, 1, 2, 2, 3, 3, 4, 3, 3, 2, 2, 1, 1};
    int arreglo7[10][10]{
        {0, 0,  0, 3, 3, 7, 5, 5, 1, 1},
        {8, 8, 10, 9, 9, 5, 4, 4, 2, 0},
        {3, 5,  8, 9, 7, 6, 4, 2, 0, 0},
        {9, 7,  7, 4, 4, 4, 2, 0, 0, 0},
        {0, 2,  2, 3, 3, 4, 4, 5, 3, 3},
        {0, 0,  0, 0, 0, 0, 2, 3, 4, 5},
        {1, 2,  2, 3, 3, 4, 3, 2, 0, 0},
        {0, 0,  0, 0, 0, 0, 3, 5, 5, 7},
        {6, 5,  5, 2, 2, 1, 0, 0, 0, 0},
        {3, 2,  2, 0, 0, 0, 0, 0, 0, 0}};

    //int arreglo7[]{0, -1, 0, -1, 0, 1, 1, 2, 2, 3, 2, 2, 1, 1};  
    n = 10;
    int max = -99, iMax, j, jMax;
    cout << endl << "7, 10, 9, 9, 5, 5, 4, 7, 6, 3" << endl;
    for(int i = 0; i < n; i++){
        int dato = buscaMontana(arreglo7[i], 0, n - 1, j);
        cout << dato << ", ";
        if(dato > max) {
            max = dato;
            iMax = i;
            jMax = j;
        }
    }
    cout <<endl<< "La máxima pureza de las muestras es: "<< max << " (encontrado en la muestra " << iMax + 1 
            << ", en el estrato " << jMax + 1<<")" <<endl;
    
    max = -99;
    int dato;
    for(int i = 0; i < n; i++){
        if(arreglo7[i][0]==0)
            dato = 10 - cuentaCeros(arreglo7[i], 0, n - 1, 0);
        else
            dato = 10 - cuentaUnos(arreglo7[i], 0, n - 1);
        //cout << "DATO: " << dato << endl;
        if(dato > max) 
            max = dato;
        
    }
    cout << "Las muestras con mayor cantidad de niveles con minerales son: ";
    
    for(int i = 0; i < n; i++){
       if(arreglo7[i][0]==0)
            dato = 10 - cuentaCeros(arreglo7[i], 0, n - 1, 0);
        else
            dato = 10 - cuentaUnos(arreglo7[i], 0, n - 1);
        //cout << "DATO: " << dato << endl;
        if(dato == max) 
            cout << i + 1<< ", ";
        
    }        
    cout << " ambos con " << max << " estratos de minerales. ";
    
    // int inicio = cuentaCeros(arreglo7, 0, n - 1, 0);
//    cout << endl << "La radiación empieza a " << 0 << " km. " <<
//            "Potencia máxima " << buscaMontana(arreglo7[0], 0, n - 1) << " megatones" << endl;


//    int arreglo8[]{3, 8, 4, 2, 1};
//    n = sizeof (arreglo8) / sizeof (arreglo8[0]);
//    cout << "Número de inversiones: " << numeroInversiones(arreglo8, 0, n - 1) << endl;
//    return 0;
}

