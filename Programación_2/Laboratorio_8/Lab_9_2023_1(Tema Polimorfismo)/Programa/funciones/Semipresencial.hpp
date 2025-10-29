//
// Created by User on 29/10/2025.
//

#ifndef SEMIPRESENCIAL_HPP
#define SEMIPRESENCIAL_HPP


#include "Alumno.hpp"
#include "utils.hpp"

class Semipresencial : public Alumno {
private:
    double descuento;
    double total;

public:
    Semipresencial();

    void lee(ifstream &arch);

    void imprime(ofstream &arch);
     void actualizaboleta( Escala *arreEscala);
    double get_descuento() const;

    void set_descuento(double descuento);

    double get_total() const;

    void set_total(double total);
};


#endif //SEMIPRESENCIAL_HPP
