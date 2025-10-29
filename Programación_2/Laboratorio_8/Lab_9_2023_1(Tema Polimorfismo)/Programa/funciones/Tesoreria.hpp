//
// Created by User on 29/10/2025.
//

#ifndef TESORERIA_HPP
#define TESORERIA_HPP


#include "Boleta.hpp"
#include "Escala.hpp"
#include "utils.hpp"

class Tesoreria {
private:
    Boleta lboleta[100]{};
    Escala lescala[10]{};
    int nd;
public:
    void cargaescalas();

    void cargaalumnos();

    void imprimeboleta();

    void actualizaboleta();

    void imprimeLinea(ofstream &arch, int cant, char car);
};


#endif //TESORERIA_HPP
