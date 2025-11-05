//
// Created by User on 4/11/2025.
//

#ifndef DRONESEMAFORO_HPP
#define DRONESEMAFORO_HPP


#include "Drone.hpp"
#include "utils.hpp"
class DroneSemaforo :public Drone{
    private:
    int luz_roja;

public:
    int get_luz_roja() const;

    void set_luz_roja(int luz_roja);
    void leer(ifstream &arch);
    void leerInfra( ifstream &arch,double &multa);
    void imprimir(ofstream & arch);
};



#endif //DRONESEMAFORO_HPP
