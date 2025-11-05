//
// Created by User on 29/10/2025.
//

#ifndef RESTAURANTE_HPP
#define RESTAURANTE_HPP


#include "Comanda.hpp"
#include "utils.hpp"

class Restaurante {
private:
    Comanda comandas[100];
    int cantidad_comandas;

public:
    Restaurante();

    void cargar_comandas();
    void imprimir_comandas();
    void actualizar_comandas();
    void imprimir_linea(ofstream &arch,int cant,char car);
    int get_cantidad_comandas() const;

    void leerAtenciones(ifstream &arch);

    void leerComandas(ifstream &arch);

    int buscarComanda(int id);

    void set_cantidad_comandas(int cantidad_comandas);
};


#endif //RESTAURANTE_HPP
