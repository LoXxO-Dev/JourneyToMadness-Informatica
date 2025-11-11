//
// Created by User on 11/11/2025.
//

#ifndef ESTANTE_HPP
#define ESTANTE_HPP

#include "Lista.hpp"
#include "utils.hpp"

class Estante {
private:
    char clase;
    int id=-1;
    double capacidad;
    class Lista llibros;

public:
    Estante();
    double obtenerPeso();
    void inserta(class Libro *aux);
    void actualiza();
    void imprimir(ofstream& arch);
    void leer(ifstream &arch);
    char get_clase() const;

    void set_clase(char clase);

    int get_id() const;

    void set_id(int id);

    double get_capacidad() const;

    void set_capacidad(double capacidad);
};


#endif //ESTANTE_HPP
