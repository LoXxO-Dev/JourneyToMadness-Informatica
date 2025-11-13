//
// Created by User on 11/11/2025.
//

#ifndef METRICA_HPP
#define METRICA_HPP

#include "utils.hpp"

class Metrica {
private:
    int id;
    char *descripcion;
    int fecha_calculo;
    int fecha_expiracion;
    bool estado;

public:
    Metrica();
    virtual ~Metrica();
    virtual void leer(ifstream &arch);
    virtual void imprimir(ofstream &arch);
    int get_id() const;

    void set_id(int id);

    void  get_descripcion(char *descripcion) const;

    void set_descripcion(const  char *descripcion);

    int get_fecha_calculo() const;

    void set_fecha_calculo(int fecha_calculo);

    int get_fecha_expiracion() const;

    void set_fecha_expiracion(int fecha_expiracion);

    bool is_estado() const;

    void set_estado(bool estado);
};



#endif //METRICA_HPP
