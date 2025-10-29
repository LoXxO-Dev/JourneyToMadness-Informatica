//
// Created by User on 28/10/2025.
//

#ifndef ALUMNO_HPP
#define ALUMNO_HPP


#include "nota.hpp"
#include "utils.hpp"

class alumno {
public:
    alumno();

    alumno(const alumno &alumno);

    void operator =(const alumno &alumno);

    void operator +=(class nota &notita);

    void leer(ifstream &arch);

    void imprmir(ofstream &arch);

    int get_codigo() const;

    void set_codigo(int codigo);

    void get_nombre(char *nombre) const;

    void set_nombre(const char *nombre);

    int get_numcursos() const;

    void set_numcursos(int numcursos);

    int get_numaprobados() const;

    void set_numaprobados(int numaprobados);

    int get_numprimera() const;

    void set_numprimera(int numprimera);

    int get_numsegunda() const;

    void set_numsegunda(int numsegunda);

    int get_numtercera() const;

    void set_numtercera(int numtercera);

private:
    int codigo;
    char *nombre;
    int numcursos;
    int numaprobados;
    int numprimera;
    int numsegunda;
    int numtercera;
    nota lnotas[100];
};

void operator >>(ifstream &arch, class alumno &alu);

void operator <<(ofstream &arch, class alumno &alu);

#endif //ALUMNO_HPP
