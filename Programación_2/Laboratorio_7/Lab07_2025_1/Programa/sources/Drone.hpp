//
// Created by User on 4/11/2025.
//

#ifndef DRONE_HPP
#define DRONE_HPP


#include "Infraccion.hpp"
#include "utils.hpp"

class Drone {
private:
    char *id;
    char *ubicacion;
    int capacidad;
    int cantidad_infracciones;
    Infraccion infracciones[20];

public:
    Drone();
    Drone(const Drone &orig);

    void operator =(const Drone &orig);
     ~Drone();
    void leer(ifstream &arch);
    void leerInfra(ifstream &arch,int dato,double &multa);
    void imprimir(ofstream & arch);
    void imprimirInfra(ofstream & arch);
    void get_id(char *id) const;

    void set_id(const char *id);

    void get_ubicacion(char *ubicacion) const;

    void set_ubicacion(const char *ubicacion);

    int get_capacidad() const;

    void set_capacidad(int capacidad);

    int get_cantidad_infracciones() const;

    void set_cantidad_infracciones(int cantidad_infracciones);
};


#endif //DRONE_HPP
