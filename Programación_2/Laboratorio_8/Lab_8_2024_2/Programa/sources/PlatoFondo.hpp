//
// Created by User on 11/11/2025.
//

#ifndef PLATOFONDO_HPP
#define PLATOFONDO_HPP

#include "Producto.hpp"
#include "utils.hpp"

class PlatoFondo :public Producto{
private:
    int proteina;

public:
    void leer(ifstream &archivo);
    bool verificar(int num);
    void imprimir(ofstream &archivo);
    int get_proteina() const;

    void set_proteina(int proteina);
};



#endif //PLATOFONDO_HPP
