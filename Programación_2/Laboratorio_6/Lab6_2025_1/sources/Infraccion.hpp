//
// Created by User on 1/10/2025.
//

#ifndef INFRACCION_HPP
#define INFRACCION_HPP
#include "utils.hpp"

class Infraccion {
public:
    Infraccion();

    Infraccion(const Infraccion &copia);

    ~Infraccion();

    void operator =(const Infraccion &copia);

    int get_codigo() const;

    void set_codigo(int codigo);

    void get_descripcion(char *descripcion) const;

    void set_descripcion(const char *descripcion);

    void get_gravedad(char *gravedad) const;

    void set_gravedad(const char *gravedad);

    double get_multa() const;

    void set_multa(double multa);

    void leerUnaInfraccion(ifstream &arch);

    void mostrarInfra(ofstream &arch);

private
:
    int codigo;
    char *descripcion;
    char *gravedad;
    double multa;
};

void operator<<(ofstream &arch, class Infraccion infra);

void operator >>(ifstream &arch, class Infraccion &infra);

#endif //INFRACCION_HPP
