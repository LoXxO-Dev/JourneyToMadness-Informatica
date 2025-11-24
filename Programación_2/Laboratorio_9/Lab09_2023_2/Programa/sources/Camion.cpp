//
// Created by User on 24/11/2025.
//

#include "Camion.hpp"
#include "NPedido.hpp"
void Camion::lee(ifstream &arch) {
    Vehiculo::lee(arch);

    arch >> ejes;
    arch.get();
    arch >> llantas;
}

void Camion::imprime(ofstream &arch) {
    Vehiculo::imprime(arch);
    arch << left << setw(15) << "#Ejes:" << right << setw(10) << ejes << endl;
    arch << left << setw(15) << "#Llantas:" << right << setw(10) << llantas << endl;
    if (NPedido.size() == 0)
        arch << "No hay pedidos para el cliente" << endl;
    else {
        arch << "Lista de  Pedidos: " << endl;
        for (auto &x:NPedido) {
            arch<<right<<setw(5)<<x.first;
            x.second.imprimir(arch);
        }

    }
}

void Camion::cargarDatos(ifstream &arch) {
    class NPedido ped;
    ped.leer(arch);
    if (NPedido.size() <5) {
        NPedido[NPedido.size()+1]=ped;
        double pesoActu=Vehiculo::get_actcarga();
        set_actcarga(pesoActu-ped.get_peso());
    }

}

int Camion::get_ejes() const {
    return ejes;
}

void Camion::set_ejes(int ejes) {
    this->ejes = ejes;
}

int Camion::get_llantas() const {
    return llantas;
}

void Camion::set_llantas(int llantas) {
    this->llantas = llantas;
}
