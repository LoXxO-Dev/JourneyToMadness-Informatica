//
// Created by User on 7/11/2025.
//

#ifndef DRONESEMAFORO_HPP
#define DRONESEMAFORO_HPP


#include "Dron.hpp"
#include "utils.hpp"
class DroneSemaforo :public  Dron{

private:
    int luz_roja;

public:
    bool operator >(const  class Dron &dron) const  ;
     void imprimir(ofstream &arch);
     void actualiza() ;
    int get_luz_roja() const;
    void leer(ifstream &arch);
    void set_luz_roja(int luz_roja);
};



#endif //DRONESEMAFORO_HPP
