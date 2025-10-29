//
// Created by User on 29/10/2025.
//

#include "Presencial.hpp"

Presencial::Presencial() {
    total = 0;
}

void Presencial::lee(ifstream &arch) {
    Alumno::lee(arch);
    arch >> recargo;
}

void Presencial::imprime(ofstream &arch) {
    Alumno::imprime(arch);
    arch<<setw(35)<<right<<get_total()<<endl;
}
void Presencial::actualizaboleta(Escala *arreEscala) {
    int posEscala=buscarEscala(arreEscala,get_escala());
    double bruto=get_creditos()*arreEscala[posEscala].get_precio();
    total=bruto*this->recargo/100;
    set_total(bruto+total);
}

double Presencial::get_recargo() const {
    return recargo;
}

void Presencial::set_recargo(double recargo) {
    this->recargo = recargo;
}

double Presencial::get_total() const {
    return total;
}

void Presencial::set_total(double total) {
    this->total = total;
}
