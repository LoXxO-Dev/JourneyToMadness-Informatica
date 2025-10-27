//
// Created by User on 1/10/2025.
//

#ifndef BIBLIOTECAGENERICA_HPP
#define BIBLIOTECAGENERICA_HPP
#include "utils.hpp"

void crealista(void *&lista, void *(*lee)(ifstream &),
               const char *nombArch);

void aperturaArchivosEntrada(ifstream &arch, const char *nombArch);

void aperturaArchivosSalida(ofstream &arch, const char *nombArch);

void insertaLista(void **&lst, void *nodo);

void imprimeLista(void *lista, void (*imprime)(void *, ofstream &), const char *nomb);

void combinalista(void *&lista1, void *&lista2, void *&listaFinal, int (*compare)(void *, void *));
void insertarRestantes(void **&lst, void *nodo, void **recorrido,void *&lista) ;
void *quitalista(void *&lst) ;

bool esListaVacia(void *lista) ;
#endif //BIBLIOTECAGENERICA_HPP
