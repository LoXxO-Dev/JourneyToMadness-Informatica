//
// Created by User on 31/10/2025.
//

#ifndef ALMACEN_HPP
#define ALMACEN_HPP


#include "OrdenVenta.hpp"
#include "utils.hpp"
class Almacen {
private:
    OrdenVenta ordenes[600];
    int cantidad_ordenes;

public:
    Almacen();
    void cargar_pedidos();
    void actualizar_pedidos();
    void imprimir_ordenes_ventas();
    void imprimir_linea(ofstream &arch,int cant,char car);
    int get_cantidad_ordenes() const;

    void set_cantidad_ordenes(int cantidad_ordenes);
};



#endif //ALMACEN_HPP
