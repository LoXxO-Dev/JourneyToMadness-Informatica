//
// Created by User on 29/10/2025.
//

#ifndef ALUMNO_HPP
#define ALUMNO_HPP

#include "Escala.hpp"
#include "utils.hpp"

class Alumno {
private:
    int codigo;
    char *nombre;
    int escala;
    double creditos;
    double total;

public:
    Alumno();

    virtual ~Alumno();

    virtual void lee(ifstream &arch);

    virtual void imprime(ofstream &arch);

    int buscarEscala(Escala *arreEscala, int escala);

    virtual void actualizaboleta(Escala *arreEscala) =0;

    int get_codigo() const;

    void set_codigo(int codigo);

    void get_nombre(char *nombre) const;

    void set_nombre(const char *nombre);

    int get_escala() const;

    void set_escala(int escala);

    double get_creditos() const;

    void set_creditos(double creditos);

    double get_total() const;

    void set_total(double total);
};


#endif //ALUMNO_HPP
