//
// Created by User on 11/11/2025.
//

#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP


#include "utils.hpp"
class Producto {
private:
    char *nombre;
    double precio;

public:
    Producto();
    virtual ~Producto();
    virtual void leer(ifstream &archivo);
    virtual void imprimir(ofstream &archivo);
    virtual bool verificar(int num)=0;
   void  get_nombre(char *nombre) const;

    void set_nombre(const char *nombre);

    double get_precio() const;

    void set_precio(double precio);
};



#endif //PRODUCTO_HPP
