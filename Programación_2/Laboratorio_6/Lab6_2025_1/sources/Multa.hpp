//
// Created by User on 1/10/2025.
//

#ifndef MULTA_HPP
#define MULTA_HPP


#include "utils.hpp"

class Multa {
public:
    Multa();

    Multa(const Multa &copia);

    ~Multa();

    void operator =(const Multa &copia);

    void get_placa(char *placa) const;

    void set_placa(const char *placa);

    int get_fecha_de_infraccion() const;

    void set_fecha_de_infraccion(int fecha_de_infraccion);

    int get_fecha_de_pago() const;

    void set_fecha_de_pago(int fecha_de_pago);

    int get_codigo_infraccion() const;

    void set_codigo_infraccion(int codigo_infraccion);

    double get_multa() const;

    void set_multa(double multa);

    void leerUnaMulta(ifstream &arch);

    int leerFecha(ifstream &arch);

    void imprimir(ofstream &arch);
    void transformarFecha(ofstream &arch,int fecha) ;
private:
    char *placa;
    int fechaDeInfraccion;
    int fechaDePago;
    int codigoInfraccion;
    double multa;
};

void operator >>(ifstream &arch, class Multa &mul);
void operator <<(ofstream &arch,class Multa mul) ;

#endif //MULTA_HPP
