//
// Created by User on 1/10/2025.
//

#ifndef EMPRESA_HPP
#define EMPRESA_HPP


#include "utils.hpp"
#include "Multa.hpp"

class Empresa {
public:
    Empresa();

    ~Empresa();

    int get_dni() const;

    void set_dni(int dni);

    void get_nombre(char *nombre) const;

    void set_nombre(const char *nombre);

    int get_num_placas() const;

    void set_num_placas(int num_placas);

    int get_num_multas() const;

    void set_num_multas(int num_multas);

    void leerEmpresa(ifstream &arch);

    void setPlacaI(const char *, int i);

    void getPlacaI(char *, int i);

    void operator =(Empresa &copia);

    void imprimir(ofstream &arch);

    void operator +=(const class Multa infraccionCometida);
bool placaPresenteEnEmpresa( char *placa) ;

private:
    int dni;
    char *nombre;
    char *placas[10];
    int numPlacas;
    class Multa multas[100];
    int numMultas;
};

void operator >>(ifstream &arch, class Empresa &emp);

void operator <<(ofstream &arch, class Empresa &emp);

#endif //EMPRESA_HPP
