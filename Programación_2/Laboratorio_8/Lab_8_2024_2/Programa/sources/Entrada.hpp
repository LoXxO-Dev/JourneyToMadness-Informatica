//
// Created by User on 11/11/2025.
//

#ifndef ENTRADA_HPP
#define ENTRADA_HPP
#include "Producto.hpp"

#include "utils.hpp"
class Entrada :public Producto{
private:
    bool picante;

public:
    void leer(ifstream &archivo);
    void imprimir(ofstream &archivo);
    bool verificar(int num);
    bool is_picante() const;

    void set_picante(bool picante);
};



#endif //ENTRADA_HPP
