//
// Created by User on 23/11/2025.
//

#ifndef MINISTERIODETRANSPORTE_HPP
#define MINISTERIODETRANSPORTE_HPP

#include "utils.hpp"
#include "Infraccion.hpp"
#include "Empresa.hpp"
class MinisterioDeTransporte {
private:
    vector<class Infraccion> tablaInfracciones;
    vector<class Empresa> vectorEmpresas;

public:
    void cargaDeInfracciones(const char *nomb);
    void cargaEmpresas(const char *nomb);
    void cargaVehiculos(const char *nomb);
    void cargaInfraccionesCometidas(const char *nomb);
    void reporteDeEmpresasConInfracciones(const char *nomb);
    void eliminaInfraccionesPagadas();
};


#endif //MINISTERIODETRANSPORTE_HPP
