//
// Created by User on 28/10/2025.
//

#ifndef ALUMNONOTA_HPP
#define ALUMNONOTA_HPP

#include "utils.hpp"

class alumnonota {
public:
    alumnonota();

    void operator &(class nota &nota);

    alumnonota(const class alumnonota &orig);

    void operator =(const alumnonota &orig);

    void leer(ifstream &arch);

    int get_codigo() const;

    void set_codigo(int codigo);

    void get_codcurso(char *codcurso) const;

    void set_codcurso(const char *codcurso);

    int get_ciclo() const;

    void set_ciclo(int ciclo);

    int get_nota() const;

    void set_nota(int nota);

private:
    int codigo;
    char *codcurso;
    int ciclo;
    int nota;
};

void operator >>(ifstream &arch, class alumnonota &aluno);


#endif //ALUMNONOTA_HPP
