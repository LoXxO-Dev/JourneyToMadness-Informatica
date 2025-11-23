//
// Created by User on 23/11/2025.
//

#ifndef EMPRESA_HPP
#define EMPRESA_HPP
#include "utils.hpp"
#include "Vehiculo.hpp"
#include "Multa.hpp"
class Empresa {
private:
    int dni;
    string nombre;
    string distrito;
    map<string,class Vehiculo> vehiculos;
    vector<class Multa>multasRecibidas;

public:
    Empresa();
    Empresa(const Empresa &);
    virtual ~Empresa();
    void ingresarVehiculos(ifstream &arch);
    bool placaPresente(string placa);
    void ingresarMultasRecibidas(class Multa &mult);
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
    void elimminar();
    int get_dni() const;
    bool operator <(const class Empresa &empre) const;
    void set_dni(int dni);

    string get_nombre() const;

    void set_nombre(const string &nombre);

    string get_distrito() const;

    void set_distrito(const string &distrito);
};
void operator >>(ifstream &arch,Empresa &empre);



#endif //EMPRESA_HPP
