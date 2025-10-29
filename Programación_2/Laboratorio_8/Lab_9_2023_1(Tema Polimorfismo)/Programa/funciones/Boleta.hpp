//
// Created by User on 29/10/2025.
//

#ifndef BOLETA_HPP
#define BOLETA_HPP


#include "Alumno.hpp"
#include "Escala.hpp"
#include "utils.hpp"

class Boleta {
private:
    Alumno *pboleta;

public:
    void asignartipo(char tipo);

    void lee(ifstream &arch);

    void actualizaboleta(Escala *arreEscala);

    void imprime(ofstream &arch);
};


#endif //BOLETA_HPP
