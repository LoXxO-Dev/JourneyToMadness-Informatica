//
// Created by User on 1/10/2025.
//

#ifndef MINISTERIODETRANSPORTES_HPP
#define MINISTERIODETRANSPORTES_HPP


#include "Infraccion.hpp"
#include "Empresa.hpp"

class MinisterioDeTransportes {
public:
    MinisterioDeTransportes();

    ~MinisterioDeTransportes();

    int get_num_inf() const;

    void set_num_inf(int num_inf);

    int get_num_emp() const;

    void set_num_emp(int num_emp);

    void operator <(const char *nomb);

    void incrementarEspacios(Infraccion *&arreglo, int &cap, int &numInf);

    void operator <=(const char *nomb);

    void operator <<(const char *nomb);

    void operator <<=(const char *nomb);

    void imprimeCar(ofstream &archivo, char car, int cant);

    void imprimirEmpresasYMultas(ofstream &arch);

    int buscarCodigo(int codigo, class Infraccion *infracciones, int cant);

    int buscarEmpresa(char *placa,class Empresa *empre,int numEmp);
// bool placaPresenteEnEmpresa( class Empresa empre,char *placa) {

private:
    class Infraccion *infracciones;
    int numInf;
    class Empresa empresas[50];
    int numEmp;
};


#endif //MINISTERIODETRANSPORTES_HPP
