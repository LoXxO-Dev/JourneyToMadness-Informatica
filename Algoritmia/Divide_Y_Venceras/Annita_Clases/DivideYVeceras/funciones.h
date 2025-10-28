/*
 * File:   funciones.h
 * Author: ANA RONCAL
 * Created on 2 de mayo de 2024, 12:36 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

int cuentaCeros(int *arr, int ini, int fin, int cont);
int cuentaUnos(int *arr, int ini, int fin);
void buscaSolo(int *arr, int ini, int fin);
int buscaMontana(int *arr, int ini, int fin, int & jMax);
int buscaMenor(int * arreglo, int inicio, int fin);
int sumaMaximaConsecutiva(int * arreglo, int inicio, int fin);
int sumaMinimaConsecutiva(int * arreglo, int inicio, int fin);
int sumaCentroMaximaConsecutiva(int * arreglo, int inicio, int med, int fin);
int sumaCentroMinimaConsecutiva(int * arreglo, int inicio, int med, int fin);
int numeroInversiones(int * arreglo, int inicio, int fin);
 int mergeInversionesCentro(int * arreglo, int inicio, int med, int fin);
int max(int a, int b);
int min(int a, int b);

#endif /* FUNCIONES_H */

