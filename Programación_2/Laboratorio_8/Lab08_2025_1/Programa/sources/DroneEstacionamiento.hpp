//
// Created by User on 7/11/2025.
//

#ifndef DRONEESTACIONAMIENTO_HPP
#define DRONEESTACIONAMIENTO_HPP


#include "Dron.hpp"
#include "utils.hpp"
class DroneEstacionamiento:public  Dron {
private:
    int zona_carga;

public:
    int get_zona_carga() const;
    bool operator >(const  class Dron &dron) const  ;
     void actualiza() ;
     void imprimir(ofstream &arch);
    void leer(ifstream &arch);
    void set_zona_carga(int zona_carga);
};



#endif //DRONEESTACIONAMIENTO_HPP
