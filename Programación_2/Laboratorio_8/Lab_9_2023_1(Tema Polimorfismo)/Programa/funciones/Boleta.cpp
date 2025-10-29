//
// Created by User on 29/10/2025.
//

#include "Boleta.hpp"

#include "Presencial.hpp"
#include "Semipresencial.hpp"
#include "Virtual.hpp"


void Boleta::asignartipo(char tipo) {
    switch (tipo) {
        case 'S':
            this->pboleta = new class Semipresencial;
            break;
        case 'P':
            this->pboleta = new class Presencial;

            break;
        case 'V':
            this->pboleta = new class Virtual;
            break;
        default:
            break;
    }
}



void Boleta::lee(ifstream &arch) {
    this->pboleta->lee(arch);
}
void Boleta::actualizaboleta(Escala *arreEscala) {
    this->pboleta->actualizaboleta(arreEscala);
}
void Boleta::imprime(ofstream &arch) {
    this->pboleta->imprime(arch);
}
