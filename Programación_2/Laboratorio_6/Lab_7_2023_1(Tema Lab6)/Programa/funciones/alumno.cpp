//
// Created by User on 28/10/2025.
//

#include "alumno.hpp"

alumno::alumno() {
    nombre = nullptr;
    numcursos = 0;
    numaprobados = 0;
    numprimera = 0;
    numsegunda = 0;
    numtercera = 0;
}

alumno::alumno(const alumno &alumno) {
    nombre = nullptr;
    *this = alumno;
}

void alumno::operator =(const alumno &orig) {
    char aux[100];
    orig.get_nombre(aux);
    set_nombre(aux);
    codigo = orig.codigo;
    numcursos = orig.numcursos;
    numaprobados = orig.numaprobados;
    numprimera = orig.numprimera;
    numsegunda = orig.numsegunda;
    numtercera = orig.numtercera;
}

void alumno::operator +=(class nota &notita) {
    bool bika = false, primera = true, trika = false;
    char codCurso[100];
    notita.get_codcurso(codCurso);
    for (int i = 0; i < numcursos; i++) {
        char aux[100];
        lnotas[i].get_codcurso(aux);
        if (strcmp(codCurso, aux) == 0) {
            primera = false;
            bika = true;
        }
        if (strcmp(codCurso, aux) == 0 and bika) {
            trika = true;
        }
    }
    this->lnotas[numcursos] = notita;
    int nota = notita.get_nota();
    if (nota >= 11) {
        if (primera)
            numprimera++;
        if (bika)
            numsegunda++;
        if (trika)
            numtercera++;
        numaprobados++;
    }
    numcursos++;
}

void alumno::leer(ifstream &arch) {
    //202123703,GAMARRA TABORI PAUL RONAL,S,30,G5
    char aux[100];
    arch >> this->codigo;
    if (arch.eof())return;
    arch.get();
    arch.getline(aux, 100, ',');
    set_nombre(aux);
    while (arch.get() != '\n');
}

void alumno::imprmir(ofstream &arch) {
    char aux[100];
    get_nombre(aux);
    arch<<left<<"Codigo del ALumno: "<<this->codigo<<endl<<
        "Nombre del Alumno: "<<aux<<endl<<
            "Detalle de Cursos: "<<endl;
    arch<<left<<setw(10)<<"Cursados"<<setw(10)<<"Aprobados"<<setw(10)<<"1ra Vez"<<setw(10)<<"2da Vez"<<
        setw(10)<<"3ra Vez"<<endl;
    arch<<right<<setw(5)<<numcursos<<setw(10)<<numaprobados<<setw(10)<<numprimera<<setw(10)<<
        numsegunda<<setw(10)<<numtercera<<endl;
}

int alumno::get_codigo() const {
    return codigo;
}

void alumno::set_codigo(int codigo) {
    this->codigo = codigo;
}

void alumno::get_nombre(char *nombre) const {
    if (this->nombre == nullptr)nombre[0] = 0;
    else strcpy(nombre, this->nombre);
}

void alumno::set_nombre(const char *nombre) {
    if (this->nombre != nullptr)delete this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

int alumno::get_numcursos() const {
    return numcursos;
}

void alumno::set_numcursos(int numcursos) {
    this->numcursos = numcursos;
}

int alumno::get_numaprobados() const {
    return numaprobados;
}

void alumno::set_numaprobados(int numaprobados) {
    this->numaprobados = numaprobados;
}

int alumno::get_numprimera() const {
    return numprimera;
}

void alumno::set_numprimera(int numprimera) {
    this->numprimera = numprimera;
}

int alumno::get_numsegunda() const {
    return numsegunda;
}

void alumno::set_numsegunda(int numsegunda) {
    this->numsegunda = numsegunda;
}

int alumno::get_numtercera() const {
    return numtercera;
}

void alumno::set_numtercera(int numtercera) {
    this->numtercera = numtercera;
}

void operator >>(ifstream &arch, class alumno &alu) {
    alu.leer(arch);
}

void operator <<(ofstream &arch, class alumno &alu) {
    alu.imprmir(arch);
}
