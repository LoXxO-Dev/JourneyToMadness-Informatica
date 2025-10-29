//
// Created by User on 29/10/2025.
//

#ifndef PRESENCIAL_HPP
#define PRESENCIAL_HPP


#include "Alumno.hpp"
#include "utils.hpp"

class Presencial : public Alumno {
private :
    double recargo;
    double total;

public:
    Presencial();

    void lee(ifstream &arch);

    void imprime(ofstream &arch) ;
     void actualizaboleta( Escala *arreEscala);
    double get_recargo() const;

    void set_recargo(double recargo);

    double get_total() const;

    void set_total(double total);
};


#endif //PRESENCIAL_HPP
