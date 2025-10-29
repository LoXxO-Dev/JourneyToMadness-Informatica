//
// Created by User on 29/10/2025.
//

#include "Virtual.hpp"

Virtual::Virtual() {
    licencia = nullptr;
    total = 0;
}

Virtual::~Virtual() {
    if (this->licencia != nullptr)delete this->licencia;
}

void Virtual::lee(ifstream &arch) {
    char aux[100];
    Alumno::lee(arch);
    arch.get(aux, 100, '\n');
    set_licencia(aux);
}

void Virtual::imprime(ofstream &arch) {
    char aux[100];
    get_licencia(aux);

    Alumno::imprime(arch);
    arch <<setw(10)<<" "<<left<<setw(15)<<aux<<right<<setw(10)<<get_total()<<endl;
}
void Virtual::actualizaboleta(Escala *arreEscala) {
    int posEscala=buscarEscala(arreEscala,get_escala());
    double bruto=get_creditos()*arreEscala[posEscala].get_precio();
    this->total=100;
    set_total(this->total+bruto);
}
void Virtual::get_licencia(char *licencia) const {
    if (this->licencia == nullptr)licencia[0] = 0;
    else strcpy(licencia, this->licencia);
}

void Virtual::set_licencia(const char *licencia) {
    if (this->licencia != nullptr)delete this->licencia;
    this->licencia = new char[strlen(licencia) + 1];
    strcpy(this->licencia, licencia);
}

double Virtual::get_total() const {
    return total;
}

void Virtual::set_total(double total) {
    this->total = total;
}
