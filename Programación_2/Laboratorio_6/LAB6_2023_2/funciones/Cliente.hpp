//
// Created by User on 7/10/2025.
//

#ifndef CLIENTE_HPP
#define CLIENTE_HPP
#include "utils.hpp"
#include "ProductoEntregado.hpp"

class Cliente {
public:
    Cliente();

    Cliente(const Cliente &copia);

    ~Cliente();

    void operator =(const Cliente &copia);

    void operator +=(class Pedido &ped);

    int get_dni() const;

    void set_dni(int dni);

    void get_nombre(char *nombre) const;

    void set_nombre(const char *nombre);

    int get_telefono() const;

    void set_telefono(int telefono);

    int get_cantidad_productos_entregados() const;

    void set_cantidad_productos_entregados(int cantidad_productos_entregados);

    double get_monto_total() const;

    void set_monto_total(double monto_total);

    bool leer_cliente(ifstream &arch);

    void imprimir(ofstream &arch);

private:
    int dni;
    char *nombre;
    int telefono;
    ProductoEntregado productos_entregados[15];
    int cantidad_productos_entregados;
    double monto_total;
};

bool operator >>(ifstream &arch, Cliente &clie);

void operator <<(ofstream &arch, Cliente &clie);


#endif //CLIENTE_HPP
