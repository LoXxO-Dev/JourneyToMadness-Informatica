/* 
 * File:   funciones.cpp
 * Author: ANA RONCAL
 * Created on 2 de mayo de 2024, 12:37 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "funciones.h"

//int arreglo[] = {0, 0, 0, 0, 0, 1, 1, 1};
/*cuenta los ceros a la izquierda*/
int cuentaUnos(int * arr, int ini, int fin) {
    int cont = 0;
    if (ini > fin) return cont;
    int med = (ini + fin) / 2;

    if (arr[med] != 0)
        return cont = cont + cuentaUnos(arr, med + 1, fin); // como busco unos y
        //caí en cero, debo moverme a la derecha, en la cuenta no tengo unos
    else
        return cont = cont + fin - med + 1 + cuentaUnos(arr, ini, med - 1); //voy a la izq
    //tengo todos los unos de la derecha
}

//int arreglo[] = {0, 0, 0, 0, 0, 1, 1, 1};
/*cuenta los ceros a la derecha*/
int cuentaCeros(int * arr, int ini, int fin, int cont) {

    if (ini > fin) return cont;
    int med = (ini + fin) / 2;

    if (arr[med] == 0)
        return cuentaCeros(arr, med + 1, fin, med + 1); //voy a la derecha y ya
        // tengo los ceros de la izquierda
    else
        return cuentaCeros(arr, ini, med - 1, cont); //voy a la izquierda y no
    // tengo ceros porque di en 1
}

//int arreglo2[] = {1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8};

void buscaSolo(int *arr, int ini, int fin) {

    if (ini > fin) return;
    if (ini == fin) {
        cout << "BUSCA SOLO: " << arr[ini] ;
        return;
    }
    int med = (ini + fin) / 2;

    if(arr[med - 1] != arr[med] and arr[med]!= arr[med +1]) {
        cout << "BUSCA SOLO: " << arr[med] ;
        return;
    }
    if (med % 2 == 0) { //med es par
        if (arr[med] == arr[med + 1]) // significa que están emparejados
            buscaSolo(arr, med + 2, fin); // segunda mitad comenzando de med +2
        else
            buscaSolo(arr, ini, med); // debe estar en la primera mitad
    } else { //med es impar
        if (arr[med] == arr[med - 1]) // este par está bien, el número en la posición con respecto al anterior
            buscaSolo(arr, med + 1, fin); //buscar en la segunda mitad del arreglo
        else
            buscaSolo(arr, ini, med - 1); //buscar en el otro intervalo
    }
}

// int arreglo3[] = {12, 24, 32, 12, 11, 10};

int buscaMontana(int *arreglo, int inicio, int fin, int & jMax) {

    if (inicio == fin) {
        jMax = inicio;
        return arreglo[inicio];
    }
    int med = (inicio + fin) / 2;
    /*Dado que son 3 hay que poner una condición más*/
    if(arreglo[med] == arreglo[med + 1])
        if(arreglo[med + 1] < arreglo[med + 2])
            return buscaMontana(arreglo, med + 1, fin, jMax);
    if (arreglo[med] >= arreglo[med + 1])
        return buscaMontana(arreglo, inicio, med, jMax);
    else
        return buscaMontana(arreglo, med + 1, fin, jMax);
}

/*int arreglo4[] {5, 6, 1, 2, 3, 4};*/
int buscaMenor(int * arreglo, int inicio, int fin) {

    if (inicio == fin) return arreglo[inicio];
    int med = (inicio + fin) / 2;
    if (arreglo[med - 1] > arreglo[med])
        return buscaMenor(arreglo, med, fin);
    else
        return buscaMenor(arreglo, inicio, med - 1);

}

int sumaMaximaConsecutiva(int * arreglo, int inicio, int fin) {

    if (inicio == fin) return arreglo[inicio];
    int med = (inicio + fin) / 2;

    int izq = sumaMaximaConsecutiva(arreglo, inicio, med);
    int der = sumaMaximaConsecutiva(arreglo, med + 1, fin);
    int centro = sumaCentroMaximaConsecutiva(arreglo, inicio, med, fin);

    return max(max(izq, der), centro);

}

int sumaCentroMaximaConsecutiva(int * arreglo, int inicio, int med, int fin) {

    int suma = 0;
    int sumaIzq = -99, sumaDer = -99;
    for (int i = med; i >= inicio; i--) {
        suma += arreglo[i];
        if (suma > sumaIzq)
            sumaIzq = suma;
    }
    suma = 0;
    for (int i = med + 1; i <= fin; i++) {
        suma += arreglo[i];
        if (suma > sumaDer)
            sumaDer = suma;
    }
    return max(max(sumaIzq, sumaDer), sumaDer + sumaIzq);
}

int sumaMinimaConsecutiva(int * arreglo, int inicio, int fin) {

    if (inicio == fin) return arreglo[inicio];
    int med = (inicio + fin) / 2;

    int izq = sumaMinimaConsecutiva(arreglo, inicio, med);
    int der = sumaMinimaConsecutiva(arreglo, med + 1, fin);
    int centro = sumaCentroMinimaConsecutiva(arreglo, inicio, med, fin);

    return min(min(izq, der), centro);

}

int sumaCentroMinimaConsecutiva(int * arreglo, int inicio, int med, int fin) {
    int suma = 0;
    int sumaIzq = 10000, sumaDer = 10000;
    for (int i = med; i >= inicio; i--) {
        suma += arreglo[i];
        if (suma < sumaIzq)
            sumaIzq = suma;
    }
    suma = 0;
    for (int i = med + 1; i <= fin; i++) {
        suma += arreglo[i];
        if (suma < sumaDer)
            sumaDer = suma;
    }
    return min(min(sumaIzq, sumaDer), sumaDer + sumaIzq);


}

int numeroInversiones(int * arreglo, int inicio, int fin) {

}

int mergeInversionesCentro(int * arreglo, int inicio, int centro, int fin) {

}

int max(int a, int b) {
    if (a >= b)
        return a;
    else
        return b;
}

int min(int a, int b) {
    if (a <= b)
        return a;
    else
        return b;
}

