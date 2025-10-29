//
// Created by User on 27/10/2025.
//

#ifndef MINISTERIODETRANSPORTE_HPP
#define MINISTERIODETRANSPORTE_HPP


#include "utils.hpp"
#include "Empresa.hpp"
#include "Infraccion.hpp"

class MinisterioDeTransporte {
private:
    class Infraccion *infracciones;
    int numInf;
    class Empresa empresas[50];
    int numEmp;

public:
    virtual ~MinisterioDeTransporte();

    MinisterioDeTransporte();

    void operator <(const char *nomArc);

    void operator <=(const char *nomArc);

    void operator <<=(const char *nomArc);

    void operator >>(const char *nomArc);

    void imprimirLinea(ofstream &arch, int cant, char car);

    void imprimirEmpresas(ofstream &arch);

    int buscarInfra(int codigo);

    int buscarEmpresas(char *placa);

    void incrementarEspacios(int &cap);

    int get_num_inf() const;

    void set_num_inf(int num_inf);

    int get_num_emp() const;

    void set_num_emp(int num_emp);
};


#endif //MINISTERIODETRANSPORTE_HPP
