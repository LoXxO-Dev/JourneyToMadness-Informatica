//
// Created by User on 24/11/2025.
//

#include "Furgon.hpp"
#include "NPedido.hpp"

void Furgon::lee(ifstream &arch) {
    Vehiculo::lee(arch);
    arch >> filas;
    arch.get();
    arch >> puertas;
}

void Furgon::imprime(ofstream &arch) {
    Vehiculo::imprime(arch);
    arch << left << setw(15) << "#filas:" << right << setw(10) << filas << endl;
    arch << left << setw(15) << "#puertas:" << right << setw(10) << puertas << endl;
    if (pdeposito.size() == 0)
        arch << "No hay pedidos para el cliente" << endl;
    else {
        arch << "Lista de  Pedidos: " << endl;
        class NPedido aux;
        while (!pdeposito.empty()) {
            aux = pdeposito.front();
            pdeposito.pop_front();
            aux.imprimir(arch);
        }
    }
}

void Furgon::cargarDatos(ifstream &arch) {
    class NPedido ped;
    ped.leer(arch);
    double pesoActu=Vehiculo::get_actcarga();
    if (pesoActu-ped.get_peso()>=0) {
        pdeposito.push_front(ped);

        set_actcarga(pesoActu-ped.get_peso());
    }

}

int Furgon::get_filas() const {
    return filas;
}

void Furgon::set_filas(int filas) {
    this->filas = filas;
}

int Furgon::get_puertas() const {
    return puertas;
}

void Furgon::set_puertas(int puertas) {
    this->puertas = puertas;
}

list<NPedido> Furgon::get_pdeposito() const {
    return pdeposito;
}

void Furgon::set_pdeposito(const list<NPedido> &pdeposito) {
    this->pdeposito = pdeposito;
}
