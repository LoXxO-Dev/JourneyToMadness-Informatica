//
// Created by User on 31/10/2025.
//

#ifndef PRIORIDADALTA_HPP
#define PRIORIDADALTA_HPP


#include "Pedido.hpp"
#include "utils.hpp"
class PrioridadAlta :public Pedido{
private:
    double recargo;
    double total;

public:
      void imprime(ofstream &arch);
    void actualiza() ;
    double get_recargo() const;

    void set_recargo(double recargo);

    double get_total() const;

    void set_total(double total);
    void leer(ifstream &arch);
};



#endif //PRIORIDADALTA_HPP
