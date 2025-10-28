//
// Created by User on 27/10/2025.
//

#ifndef INFRACCION_HPP
#define INFRACCION_HPP


#include "utils.hpp"
class Infraccion {
public:
    Infraccion();
    Infraccion(const Infraccion &orig);
void operator =(const Infraccion &orig) ;
    virtual ~Infraccion();
    int get_codigo() const;

    void set_codigo(int codigo);

   void get_descripcion(char *descripcion ) const;

    void set_descripcion(const char *descripcion);

   void get_gravedad(char  * gravedad) const;

    void set_gravedad(const char *gravedad);

    double get_multa() const;

    void set_multa(double multa);
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
private:
    int codigo;
    char *descripcion;
    char *gravedad;
    double multa;
};

void operator >>(ifstream &arch,class Infraccion &infra);
void operator <<(ofstream &arch, class Infraccion & infra);
#endif //INFRACCION_HPP
