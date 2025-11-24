//
// Created by User on 23/11/2025.
//

#ifndef NOVELA_HPP
#define NOVELA_HPP

#include "Libro.hpp"
#include "utils.hpp"

class Novela :public Libro{
private:
    string autor;

public:
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
    string get_autor() const;

    void set_autor(const string &autor);
};



#endif //NOVELA_HPP
