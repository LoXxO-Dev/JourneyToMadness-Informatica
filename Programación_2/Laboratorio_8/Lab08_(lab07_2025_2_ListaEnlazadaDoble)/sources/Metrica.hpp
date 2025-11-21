//
// Created by User on 20/11/2025.
//

#ifndef METRICA_HPP
#define METRICA_HPP


#include "utils.hpp"
class Metrica {
private:
    int id;
    string descripcion;
    int fecha_calculo;
    int fecha_expiracion;

public:
    virtual void leer(ifstream &archivo);
    virtual void imprimir(ofstream &archivo);
    int get_id() const;

    void set_id(int id);

    string get_descripcion() const;

    void set_descripcion(const string &descripcion);

    int get_fecha_calculo() const;

    void set_fecha_calculo(int fecha_calculo);

    int get_fecha_expiracion() const;

    void set_fecha_expiracion(int fecha_expiracion);

    bool is_estado() const;

    void set_estado(bool estado);

private:
    bool estado;
};



#endif //METRICA_HPP
