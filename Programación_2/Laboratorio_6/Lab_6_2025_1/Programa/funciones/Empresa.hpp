//
// Created by User on 27/10/2025.
//

#ifndef EMPRESA_HPP
#define EMPRESA_HPP


#include "utils.hpp"
#include "Multa.hpp"

class Empresa {
public:
    Empresa();

    void operator=(class Empresa &orig);

    virtual ~Empresa();

    void leer(ifstream &arch);

    int get_dni() const;

    void set_dni(int dni);

    void get_nombre(char *nombre) const;

    void set_nombre(const char *nombre);

    int get_num_placas() const;

    void set_num_placas(int num_placas);

    int get_num_multas() const;

    void set_num_multas(int num_multas);

    void operator +=(const class Multa &multa);

    void setPlacaI(const char *placa, int i);

    void getPlacaI(char *placa, int i);
    void imprimir(ofstream &arch);
private:
    int dni;
    char *nombre;
    char *placas[10];
    int numPlacas;
    Multa multas[100];
    int numMultas;
};

void operator >>(ifstream &arch, class Empresa &empre);
void operator <<(ofstream &arch,class Empresa &empre);

#endif //EMPRESA_HPP
