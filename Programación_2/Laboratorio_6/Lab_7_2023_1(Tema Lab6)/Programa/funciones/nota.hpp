//
// Created by User on 28/10/2025.
//

#ifndef NOTA_HPP
#define NOTA_HPP


#include "utils.hpp"

class nota {
public:
    nota();

    void operator =(class nota &orig);

    void get_codcurso(char *codcurso) const;

    void set_codcurso(const char *codcurso);

    int get_ciclo() const;

    void set_ciclo(int ciclo);

    int get_nota() const;

    void set_nota(int nota);

private:
    char *codcurso;
    int ciclo;
    int notaAtr;
};


#endif //NOTA_HPP
