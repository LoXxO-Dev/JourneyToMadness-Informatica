//
// Created by User on 11/11/2025.
//

#ifndef DETALLECOMANDA_HPP
#define DETALLECOMANDA_HPP

#include "Producto.hpp"
#include "utils.hpp"

class DetalleComanda {
private:
    int id;
    Producto* pedido;

public:
    void leer(ifstream &archivo,int id);
    void imprimir(ofstream &arch);
    virtual ~DetalleComanda();
    int get_id() const;
    void operator =( class DetalleComanda &orig);
    void set_id(int id);
    bool verifica(int num);
};



#endif //DETALLECOMANDA_HPP
