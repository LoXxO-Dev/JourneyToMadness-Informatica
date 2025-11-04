//
// Created by User on 4/11/2025.
//

#ifndef DRONEESTACIONAMIENTO_HPP
#define DRONEESTACIONAMIENTO_HPP

#include "utils.hpp"
#include "Drone.hpp"

class DroneEstacionamiento:public Drone {
private:
    int zona_carga;

public:
    int get_zona_carga() const;

    void set_zona_carga(int zona_carga);
    void leer(ifstream &arch);
    void leerInfra( ifstream &arch,double &multa);
    void imprimir(ofstream & arch);
};



#endif //DRONEESTACIONAMIENTO_HPP
