//
// Created by User on 23/09/2025.
//

#ifndef BIBLIOTECAGENERICA_HPP
#define BIBLIOTECAGENERICA_HPP
#include "utils.hpp"
void generaLista(void *&lista) ;
void creaLista(void *&lista, void *(*lee)(ifstream &), int (*cmp)(void *, void *),
               int (*busca)(void *,void *),const char *nombArch);
void insertarLista(void *&lista, void *dato, int (*cmp)(void *, void *)) ;
void imprimeLista(void *lista, void (*imprime)(ofstream &, void *), const char *nombr) ;
void cargaUnidades(void *&lista, const char *nombrArch) ;
int buscarIndividuo(void *lista,int licencia) ;
bool sonIguales(int licencia, void *lista) ;
void incrementarEspacios(void **&arreglo,int &nDatos,int &cap) ;
void insertarPlaca(void * lista, int posDni,char * placa,int &cap,int &nDatos) ;

void aperturaArchivosEntrada(ifstream &archivo,const char *nombArch) ;
void aperturaArchivosSalida(ofstream &archivo,const char *nombArch) ;
char *leerCadenaExacta(ifstream &arch,char car) ;
#endif //BIBLIOTECAGENERICA_HPP
