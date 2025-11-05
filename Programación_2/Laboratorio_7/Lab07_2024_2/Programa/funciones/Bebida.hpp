//
// Created by User on 29/10/2025.
//

#ifndef BEBIDA_HPP
#define BEBIDA_HPP


#include "Producto.hpp"
#include "utils.hpp"
class Bebida:public Producto {
private:
    char *tamano;

public:
    Bebida();
    virtual ~Bebida();
    void get_tamano(char *tamano) const;

    void set_tamano(const char *tamano);
    void leer(ifstream & arch);
    void imprimir(ofstream & arch);
};
void operator <<(ofstream &arch,class Bebida &bed);



#endif //BEBIDA_HPP
