//
// Created by User on 7/11/2025.
//

#ifndef ARBOL_HPP
#define ARBOL_HPP


#include "Nodo.hpp"
#include "Dron.hpp"
#include "utils.hpp"

class Arbol {
private:
    Nodo *raiz;
   void  insertar_recursivo(Nodo *& raiz, Dron *aux);
    void contarR(Nodo *raiz,int &n_sema,int &n_esta);
    void imprimirR(ofstream &arch,Nodo *&raiz);
     void actualizaR(Nodo * raiz,int &n_esta,int &n_sema);

public:
    Arbol();
    void imprimir (ofstream & arch);
    void insertar(Dron *aux);
    void actualiza();
};


#endif //ARBOL_HPP
