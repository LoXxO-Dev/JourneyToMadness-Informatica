//
// Created by User on 11/11/2025.
//

#ifndef NODO_HPP
#define NODO_HPP

#include "Libro.hpp"
#include "utils.hpp"
class Nodo {
    private:
    class Libro *plibro;
    class Nodo *sig;
public:
    Nodo() {
        sig=nullptr;
    }
    friend class Lista;

};



#endif //NODO_HPP
