//
// Created by User on 11/11/2025.
//

#ifndef ARBOL_HPP
#define ARBOL_HPP


#include "utils.hpp"

class Arbol {
private:
    class Nodo *raiz;

    void insertarR(class Nodo *&raiz, class Streamer *ptr);

   class Nodo *buscar(class Nodo *raiz, int dato);
   void  impresionRe( Nodo *raiz,ofstream &arch);

public:
    Arbol();
    void impresion(ofstream &arch);
    void leer(char *tipo, ifstream &arch);
    void buscarEInsertarInfo(int id, ifstream &arch, char *tipo);

};


#endif //ARBOL_HPP
