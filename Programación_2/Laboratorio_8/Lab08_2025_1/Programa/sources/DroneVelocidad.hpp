//
// Created by User on 7/11/2025.
//

#ifndef DRONEVELOCIDAD_HPP
#define DRONEVELOCIDAD_HPP

#include "Dron.hpp"
#include "utils.hpp"

class DroneVelocidad:public Dron {
private:
    double velocidad_maxima_permitida;

public:
    bool operator >(const  class Dron &dron)const   ;
    void imprimir(ofstream &arch);
    double get_velocidad_maxima_permitida() const;
    void leer(ifstream &arch);
    void actualiza();
    void set_velocidad_maxima_permitida(double velocidad_maxima_permitida);

};



#endif //DRONEVELOCIDAD_HPP
