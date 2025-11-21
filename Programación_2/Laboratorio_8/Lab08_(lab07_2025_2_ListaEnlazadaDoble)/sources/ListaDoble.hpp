//
// Created by User on 20/11/2025.
//

#ifndef LISTADOBLE_HPP
#define LISTADOBLE_HPP


#include "utils.hpp"

class ListaDoble {
private:
    class NodoLista *cabeza;
    class NodoLista *cola;

public:
    ListaDoble();
    void leer(char  *tipo,ifstream &arch);
    void insertar(class Streamer *dato);
    void insertarSinColar(class Streamer *dato);
    void insertarEnOrden(class Streamer *dato);
    void actualizar(char *tipo,ifstream &arch);
    void eliminar();
    void eliminarSinAnterior();
   class NodoLista * buscarNodo(int id);
    void imprimir(ofstream &arch);

};


#endif //LISTADOBLE_HPP
