//
// Created by User on 11/11/2025.
//

#include "PlatoFondo.hpp"

void PlatoFondo::leer(ifstream &archivo) {
    Producto::leer(archivo);
    archivo>>proteina;
}

bool PlatoFondo::verificar(int num) {
    return num==proteina;
}

void PlatoFondo::imprimir(ofstream &archivo) {
    Producto::imprimir(archivo);
    archivo<<"Proteina:";
    if (proteina==1)archivo<<"Pollo";
    if (proteina==2)archivo<<"Carne";
    if (proteina==3)archivo<<"Pescado";
    if (proteina==4)archivo<<"Lácteos";



}

int PlatoFondo::get_proteina() const {
    return proteina;
}

void PlatoFondo::set_proteina(int proteina) {
    this->proteina = proteina;
}
