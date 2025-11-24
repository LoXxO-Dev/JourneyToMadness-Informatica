//
// Created by User on 24/11/2025.
//

#include "NVehiculo.hpp"
#include "Camion.hpp"
#include "Furgon.hpp"

void NVehiculo::leer(ifstream &arch) {
    char tipo;
    arch >> tipo;
    if (arch.eof()) return;
    arch.get();
    if (tipo == 'F')
        unidad = new class Furgon();
    else if (tipo == 'C')
        unidad = new class Camion();
    unidad->lee(arch);
}

void NVehiculo::imprimir(ofstream &arch) {
    unidad->imprime(arch);
    arch<<endl;
}

bool NVehiculo::operator<(const class NVehiculo &aux) const {
    return unidad->get_cliente()<aux.unidad->get_cliente();
}

bool NVehiculo::encontrarPosicion(int dni) {
    return unidad->get_cliente()==dni;
}

void NVehiculo::ingresasPedido(ifstream &arch) {
    unidad->cargarDatos(arch);

}
