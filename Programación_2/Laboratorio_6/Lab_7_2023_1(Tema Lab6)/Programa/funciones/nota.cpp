//
// Created by User on 28/10/2025.
//

#include "nota.hpp"

nota::nota() {
    this->codcurso = nullptr;
}
void nota::operator =(class nota &orig) {
    char aux[100];
    orig.get_codcurso(aux);
    set_codcurso(aux);
    ciclo=orig.get_ciclo();
    notaAtr=orig.get_nota();
}

void nota::get_codcurso(char *codcurso) const {
    if (this->codcurso == nullptr)codcurso[0] = 0;
    else strcpy(codcurso, this->codcurso);
}

void nota::set_codcurso(const char *codcurso) {
    if (this->codcurso != nullptr)delete [] this->codcurso;
    this->codcurso = new char[strlen(codcurso) + 1];
    strcpy(this->codcurso, codcurso);
}

int nota::get_ciclo() const {
    return ciclo;
}

void nota::set_ciclo(int ciclo) {
    this->ciclo = ciclo;
}

int nota::get_nota() const {
    return notaAtr;
}

void nota::set_nota(int nota) {
    this->notaAtr = nota;
}
