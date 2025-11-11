//
// Created by User on 11/11/2025.
//

#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP


#include "utils.hpp"
#include "Estante.hpp"
class Biblioteca {
private:
    class Estante AEstantes[10];
public:
    void carga();
    void llena();
    void baja();
    void muestra();
    bool buscarEspacio(double  peso,int &pos);
};


#endif //BIBLIOTECA_HPP
