//
// Created by User on 11/11/2025.
//

#ifndef BEBIDA_HPP
#define BEBIDA_HPP


#include "Producto.hpp"
#include "utils.hpp"
class Bebida :public Producto{
private:
    char *tamano;

public:
    Bebida();
    virtual ~Bebida();
    void leer(ifstream &archivo);
    void imprimir(ofstream &archivo);
    bool verificar(int num);
    void  get_tamano(char *tamano) const;
    void set_tamano(const char *tamano);
};



#endif //BEBIDA_HPP
