//
// Created by User on 4/11/2025.
//

#ifndef DRONEVELOCIDAD_HPP
#define DRONEVELOCIDAD_HPP
#include "Drone.hpp"

#include "utils.hpp"
class DroneVelocidad:public Drone {
private:
    int velocidad_maxima_permitida;

public:
    int get_velocidad_maxima_permitida() const;

    void set_velocidad_maxima_permitida(int velocidad_maxima_permitida);
    void leer(ifstream &arch);
    void leerInfra( ifstream &arch,double &multa);
    void imprimir(ofstream & arch);
};



#endif //DRONEVELOCIDAD_HPP
