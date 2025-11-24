//
// Created by User on 23/11/2025.
//

#ifndef NESTANTE_HPP
#define NESTANTE_HPP


#include "NLibro.hpp"
#include "utils.hpp"

class NEstante {
private:
    int id;
    double capacidad;
    double disponible;
    vector<NLibro> vlibros;
    class NEstante *izq;

public:
    void imprimir(ofstream &arch);
    int get_id() const;

    void set_id(int id);

    double get_capacidad() const;

    void set_capacidad(double capacidad);

    double get_disponible() const;

    void set_disponible(double disponible);

private:
    class NEstante *der;

public:
    NEstante();
    void leer(ifstream &arch,int id,ifstream &arch2);
    friend class Arbol;
};


#endif //NESTANTE_HPP
