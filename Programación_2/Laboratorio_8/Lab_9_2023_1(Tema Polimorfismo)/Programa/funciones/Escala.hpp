//
// Created by User on 29/10/2025.
//

#ifndef ESCALA_HPP
#define ESCALA_HPP

#include "utils.hpp"

class Escala {
private:
    int codigo;
    double precio;

public:
    int get_codigo() const;

    void set_codigo(int codigo);

    double get_precio() const;

    void set_precio(double precio);
};



#endif //ESCALA_HPP
