//
// Created by User on 29/10/2025.
//

#include "Semipresencial.hpp"

Semipresencial::Semipresencial() {
    total=0;
}
void Semipresencial::lee(ifstream &arch) {
    Alumno::lee(arch);
    arch>>descuento;
}
void Semipresencial::imprime(ofstream &arch) {
    Alumno::imprime(arch);
    arch<<setw(35)<<right<<get_total()<<endl;
}
double Semipresencial::get_descuento() const {
    return descuento;
}
void Semipresencial::actualizaboleta(Escala *arreEscala) {
    int posEscala=buscarEscala(arreEscala,get_escala());
    double bruto=get_creditos()*arreEscala[posEscala].get_precio();
    total=bruto*descuento/100;
    set_total(bruto-total);
}
void Semipresencial::set_descuento(double descuento) {
    this->descuento = descuento;
}

double Semipresencial::get_total() const {
    return total;
}

void Semipresencial::set_total(double total) {
    this->total = total;
}
