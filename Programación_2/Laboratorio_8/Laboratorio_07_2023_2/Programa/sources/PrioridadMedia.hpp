//
// Created by User on 31/10/2025.
//

#ifndef PRIORIDADMEDIA_HPP
#define PRIORIDADMEDIA_HPP


#include "Pedido.hpp"
#include "utils.hpp"
class PrioridadMedia :public Pedido{
private:
    char  *descripcion;
    int nueva_fecha_entrega;

public:
    PrioridadMedia();
      void imprime(ofstream &arch);
    virtual ~PrioridadMedia();
    void leer(ifstream &arch);
    void actualiza();
   void  get_descripcion(char *descripcion) const;

    void set_descripcion(const char *descripcion);

    int get_nueva_fecha_entrega() const;

    void set_nueva_fecha_entrega(int nueva_fecha_entrega);
};



#endif //PRIORIDADMEDIA_HPP
