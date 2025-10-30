//
// Created by User on 29/10/2025.
//

#ifndef COMANDA_HPP
#define COMANDA_HPP


#include "Bebida.hpp"
#include "Entrada.hpp"
#include "PlatoFondo.hpp"
#include "utils.hpp"

class Comanda {
public:
    Comanda();

    virtual ~Comanda();

    Comanda(const class Comanda &orig);

    void operator=(const class Comanda &orig);

    void imprimir_linea(ofstream &arch, int cant, char car);

    void imprimir_detalles_comanda(ofstream &arch);

    void actualizarComandas();

    int get_id() const;

    void set_id(int id);

    int get_cantidad_bebidas() const;

    void set_cantidad_bebidas(int cantidad_bebidas);

    int get_cantidad_entradas() const;

    void set_cantidad_entradas(int cantidad_entradas);

    int get_cantidad_platos_fondo() const;

    void set_cantidad_platos_fondo(int cantidad_platos_fondo);

    int get_hora_atencion() const;

    void set_hora_atencion(int hora_atencion);

    int get_hora_servicio() const;

    void set_hora_servicio(int hora_servicio);

    int get_tiempo_preparacion() const;

    void set_tiempo_preparacion(int tiempo_preparacion);

    double get_total() const;

    void set_total(double total);

    void get_estado(char *estado) const;

    void set_estado(const char *estado);

    void leer(ifstream &arch);

    void leerComanda(ifstream &arch);

    void imprimir(ofstream &arch);

private:
    int id;
    Bebida bebidas[100];
    Entrada entradas[100];
    PlatoFondo platos_fondo[100];
    int cantidad_bebidas;
    int cantidad_entradas;
    int cantidad_platos_fondo;
    int hora_atencion;
    int hora_servicio;
    int tiempo_preparacion;
    double total;
    char *estado;
};

void operator >>(ifstream &arch, class Comanda &comanda);

void operator <<(ofstream &arch, class Comanda &comanda);


#endif //COMANDA_HPP
