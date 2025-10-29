//
// Created by User on 29/10/2025.
//

#ifndef VIRTUAL_HPP
#define VIRTUAL_HPP


#include "Alumno.hpp"
#include "utils.hpp"

class Virtual : public Alumno {
private:
    char *licencia;

public:
    Virtual();

    virtual ~Virtual();

    void lee(ifstream &arch);

    void imprime(ofstream &arch);
     void actualizaboleta( Escala *arreEscala);
    void get_licencia(char *licencia) const;

    void set_licencia(const char *licencia);

    double get_total() const;

    void set_total(double total);

private:
    double total;
};


#endif //VIRTUAL_HPP
