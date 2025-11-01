//
// Created by User on 31/10/2025.
//

#ifndef PRIORIDADBAJA_HPP
#define PRIORIDADBAJA_HPP


#include "Pedido.hpp"
#include "utils.hpp"
class PrioridadBaja:public Pedido {
private:
    int dias_espera;
    int nueva_fecha_entrega;

public:
    PrioridadBaja();
      void imprime(ofstream &arch);
    void actualiza();
    void leer(ifstream &arch);
    int get_dias_espera() const;

    void set_dias_espera(int dias_espera);

    int get_nueva_fecha_entrega() const;

    void set_nueva_fecha_entrega(int nueva_fecha_entrega);
};



#endif //PRIORIDADBAJA_HPP
