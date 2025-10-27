//
// Created by User on 7/10/2025.
//

#ifndef ALMACEN_HPP
#define ALMACEN_HPP

#include "utils.hpp"
#include "Cliente.hpp"
#include "Producto.hpp"

class Almacen {
private:
    Cliente arreglo_clientes[150];
    int cantidad_clientes;
    Producto arreglo_productos[180];
    int cantidad_productos;

public:
    Almacen();

    void cargar_clientes();

    void cargar_produtos();

    void cargar_pedidos();

    void mostrar_datos();

    int buscarClie(int dni);

    int buscarProduto(char *aux);

    void imprimiLinea(ofstream &archivo, char car, int cantidad);

    void imprimirReporteProductos();

    int get_cantidad_clientes() const;

    void set_cantidad_clientes(int cantidad_clientes);

    int get_cantidad_productos() const;

    void set_cantidad_productos(int cantidad_productos);
};


#endif //ALMACEN_HPP
