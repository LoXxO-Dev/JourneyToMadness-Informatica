//
// Created by User on 28/10/2025.
//

#ifndef RESTAURANTE_HPP
#define RESTAURANTE_HPP
#include "Utils.hpp"


class Restaurante {
private:
    class Cliente *clientes;
    int cantidadDeClientes;
    int capacidadDeClientes;
    class Plato *platos;
    int cantidadDePlatos;
    int capacidadDePlatos;

public:
    Restaurante();

    virtual ~Restaurante();

    void operator <(const char *nomb);

    void operator <=(const char *nomb);

    void operator <<=(const char *nomb);

    void operator >>(const char *nomb);
    void imprimirLinea(ofstream& arch,int cant,char car) ;
    void imprimirPlatos(ofstream &arch) ;
    void imprimirClientes(ofstream &arch) ;
    void incrementarClientes();

    void incrementarPlatos();

    int buscarCliente(int dni);

    int buscarPato(char *plato);

    int get_cantidad_de_clientes() const;

    void set_cantidad_de_clientes(int cantidad_de_clientes);

    int get_capacidad_de_clientes() const;

    void set_capacidad_de_clientes(int capacidad_de_clientes);

    int get_cantidad_de_platos() const;

    void set_cantidad_de_platos(int cantidad_de_platos);

    int get_capacidad_de_platos() const;

    void set_capacidad_de_platos(int capacidad_de_platos);
};


#endif //RESTAURANTE_HPP
