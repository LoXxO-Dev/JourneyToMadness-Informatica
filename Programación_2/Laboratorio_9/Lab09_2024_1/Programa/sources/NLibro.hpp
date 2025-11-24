//
// Created by User on 23/11/2025.
//

#ifndef NLIBRO_HPP
#define NLIBRO_HPP


#include "Libro.hpp"
#include "utils.hpp"
class NLibro {
private:
    class Libro *plibro;
public:
    void leer(ifstream &arch,double &disponible);
    void imprimir(ofstream &arch);
};



#endif //NLIBRO_HPP
