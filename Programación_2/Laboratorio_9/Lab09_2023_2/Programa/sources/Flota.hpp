//
// Created by User on 24/11/2025.
//

#ifndef FLOTA_HPP
#define FLOTA_HPP

#include "NVehiculo.hpp"
#include "utils.hpp"
#include "Vehiculo.hpp"

class Flota {
private:
    vector<NVehiculo> vflot;
public:
    void cargaflota();
    void muestracarga();
    void cargapedidos();
};
#endif //FLOTA_HPP
