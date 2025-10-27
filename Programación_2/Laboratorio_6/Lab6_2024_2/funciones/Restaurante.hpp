//
// Created by User on 5/10/2025.
//

#ifndef RESTAURANTE_HPP
#define RESTAURANTE_HPP
#include "Cliente.hpp"

#include "Plato.hpp"
#include "utils.hpp"

class Restaurante {
public:
    Restaurante();

    int get_cantidad_de_clientes() const;

    void set_cantidad_de_clientes(int cantidad_de_clientes);

    int get_capacidad_de_clientes() const;

    void set_capacidad_de_clientes(int capacidad_de_clientes);

    int get_cantidad_platos() const;

    void set_cantidad_platos(int cantidad_platos);

    int get_capacidad_platos() const;

    void set_capacidad_platos(int capacidad_platos);

    void operator <(const char *nombArc);

    void aumentarEspacios();

    void aumentarEspaciosPlatos();

    void operator <=(const char *nombArc);

    void operator <<=(const char *nombArc);

    void leerPlatosYAgregar(int posCliente, ifstream &archivo);

    int buscarPlato(char *plato);

    int buscarCliente(int dni);

    void operator >>(const char *nombArc);

    void imprimirPlato(ofstream &arch);

    void imprimirClientes(ofstream &arch);

    void imprimirLina(ofstream &arch, char car, int cant);

private:
    class Cliente *clientes;
    int cantidadDeClientes;
    int capacidadDeClientes;
    class Plato *platos;
    int cantidadPlatos;
    int capacidadPlatos;
};


#endif //RESTAURANTE_HPP
