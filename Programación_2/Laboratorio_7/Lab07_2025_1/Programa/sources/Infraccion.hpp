//
// Created by User on 4/11/2025.
//

#ifndef INFRACCION_HPP
#define INFRACCION_HPP


#include "utils.hpp"
class Infraccion {
private:
    int fecha_evento;
    char *tipo_infraccion;
    double monto;
    int fecha_pago_limite;
    char *placa;

public:
    Infraccion();
    Infraccion(const Infraccion &infraccion);
    void operator =(const Infraccion &infraccion);
    virtual ~Infraccion();
    void leer(ifstream &arch,int verificador,double &multa);
    void imprimir(ofstream &arch)const;
    int obtenerFechaPago(int dd, int mm, int aa);
    int get_fecha_evento() const;

    void set_fecha_evento(int fecha_evento);

    void get_tipo_infraccion(char  *tipo_infraccion) const;

    void set_tipo_infraccion(const char *tipo_infraccion);

    double get_monto() const;

    void set_monto(double monto);

    int get_fecha_pago_limite() const;

    void set_fecha_pago_limite(int fecha_pago_limite);

   void get_placa(char *placa) const;

    void set_placa(const char *placa);
};



#endif //INFRACCION_HPP
