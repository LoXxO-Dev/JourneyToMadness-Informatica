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
   class Nodo *raiz;
   void  insertar_recursivo(Nodo *& raiz, Dron *aux);
    void contarR(Nodo *raiz,int &n_sema,int &n_esta);
    void imprimirR(ofstream &arch,Nodo *&raiz);
     void actualizaR(Nodo * raiz,int &n_esta,int &n_sema);
void cambiar_valores(Nodo *raiz, int &cant_s, int &cant_e) ;

public:
    Arbol();
    void lee(ifstream &arch);
    void imprimir (ofstream & arch);
    void actualiza();
};


#endif //ARBOL_HPP
