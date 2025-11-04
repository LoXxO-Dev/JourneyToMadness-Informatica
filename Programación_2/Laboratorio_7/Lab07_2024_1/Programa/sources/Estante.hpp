//
// Created by User on 2/11/2025.
//

#ifndef ESTANTE_HPP
#define ESTANTE_HPP


#include "Espacio.hpp"
#include "utils.hpp"

class Estante {
private:
    char *codigo;
    int anchura;
    int altura;
    Espacio *espacios;
    double pesoSoportado;
    double pesoActual;

public:
    Estante();
    void imprimir(ofstream &arch,int cant,bool condicion);
    void imprimirEstante(ofstream &arch);
    void imprimirLinea(ofstream &arch,int cant,char car);
    void pintar(int alto, int ancho, int espaciosSobra);

    void leer(ifstream &arch);

    void get_codigo(char *codigo) const;

    void set_codigo(const char *codigo);

    int get_anchura() const;

    void set_anchura(int anchura);

    int get_altura() const;

    void set_altura(int altura);

    double get_peso_soportado() const;

    void set_peso_soportado(double peso_soportado);

    double get_peso_actual() const;

    void set_peso_actual(double peso_actual);
};


#endif //ESTANTE_HPP
