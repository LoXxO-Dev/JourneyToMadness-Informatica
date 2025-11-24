//
// Created by User on 23/11/2025.
//

#ifndef ARBOL_HPP
#define ARBOL_HPP


#include "NEstante.hpp"
#include "utils.hpp"

class Arbol {
private:
    class NEstante *raiz;
    void insertar(class NEstante* &raiz,class NEstante* aux);
    void imprimirR(class NEstante *raiz, ofstream &arch);
   class NEstante * buscarEspacio(class NEstante *raiz,double peso);
public:
    Arbol();
    void imprimir(ofstream &arch);
    void leer(int id,ifstream &arch,ifstream &arch2);
    void ingresar(double peso);
};


#endif //ARBOL_HPP
