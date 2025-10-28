//
// Created by User on 28/10/2025.
//

#ifndef PLATO_HPP
#define PLATO_HPP
#include "Utils.hpp"


class Plato {
private:
    char *codigo;
    char *nombre;
    double precio;
    char *categoria;
    int preparados;
    double descuento;
    int atendidos;
    int noAtendidos;
    double totalEsperado;
    double totalBruto;
    double totalNeto;

public:
    Plato();

    virtual ~Plato();

    Plato(const Plato &orig);

    void operator=(const Plato &orig);

    void leer(ifstream &archivo);
    void imprimir(ofstream &archivo);
    bool esAtendible(int cantidad,double descClie,double &totalPagadoCliente);

    void get_codigo(char *codigo) const;

    void set_codigo(const char *codigo);

    void get_nombre(char *nombre) const;

    void set_nombre(const char *nombre);

    double get_precio() const;

    void set_precio(double precio);

    void get_categoria(char *categoria) const;

    void set_categoria(const char *categoria);

    int get_preparados() const;

    void set_preparados(int preparados);

    double get_descuento() const;

    void set_descuento(double descuento);

    int get_atendidos() const;

    void set_atendidos(int atendidos);

    int get_no_atendidos() const;

    void set_no_atendidos(int no_atendidos);

    double get_total_esperado() const;

    void set_total_esperado(double total_esperado);

    double get_total_bruto() const;

    void set_total_bruto(double total_bruto);

    double get_total_neto() const;

    void set_total_neto(double total_neto);
};

void operator >>(ifstream &arch, class Plato &plat);
void operator <<(ofstream &arch,class Plato &plat);
#endif //PLATO_HPP
