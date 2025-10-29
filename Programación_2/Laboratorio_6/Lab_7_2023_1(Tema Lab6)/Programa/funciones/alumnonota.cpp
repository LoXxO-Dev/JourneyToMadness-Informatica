//
// Created by User on 28/10/2025.
//

#include "alumnonota.hpp"

#include "nota.hpp"

alumnonota::alumnonota() {
    this->codcurso = nullptr;
}
void alumnonota::operator &(class nota &nota) {
    nota.set_ciclo(this->ciclo);
    nota.set_nota(this->nota);
    char aux[100];
    get_codcurso(aux);
    nota.set_codcurso(aux);
}

alumnonota::alumnonota(const class alumnonota &orig) {
    this->codcurso = nullptr;
    *this = orig;
}

void alumnonota::operator =(const alumnonota &orig) {
    char aux[100];
    orig.get_codcurso(aux);
    set_codcurso(aux);
    codigo = orig.get_codigo();
    ciclo = orig.get_ciclo();
    nota = orig.get_nota();
}

void alumnonota::leer(ifstream &arch) {
    char  aux[100];
    arch>>codigo;
    if (arch.eof())return;
    arch.get();
    arch.getline(aux, 100,',');
    set_codcurso(aux);
    arch>>ciclo;
    arch.get();
    arch>>nota;
}

int alumnonota::get_codigo() const {
    return codigo;
}

void alumnonota::set_codigo(int codigo) {
    this->codigo = codigo;
}

void alumnonota::get_codcurso(char *codcurso) const {
    if (this->codcurso == nullptr)codcurso[0] = '\0';
    else strcpy(codcurso, this->codcurso);
}

void alumnonota::set_codcurso(const char *codcurso) {
    if (this->codcurso != nullptr)delete [] this->codcurso;
    this->codcurso = new char[strlen(codcurso) + 1];
    strcpy(this->codcurso, codcurso);
}

int alumnonota::get_ciclo() const {
    return ciclo;
}

void alumnonota::set_ciclo(int ciclo) {
    this->ciclo = ciclo;
}

int alumnonota::get_nota() const {
    return nota;
}

void alumnonota::set_nota(int nota) {
    this->nota = nota;
}

void operator >>(ifstream &arch, class alumnonota &aluno) {
    aluno.leer(arch);
}
