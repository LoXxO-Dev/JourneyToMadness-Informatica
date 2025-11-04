//
// Created by User on 3/11/2025.
//

#ifndef ESTANTEHORIZONTAL_HPP
#define ESTANTEHORIZONTAL_HPP
#include "Estante.hpp"
#include "Novela.hpp"


class EstanteHorizontal : public Estante {
private:
    Novela novelas[100];
    int cantidad_novelas;

public:
    EstanteHorizontal();
    void imprimir(ofstream &arch);
    bool posicionarNovelas(Novela nove);

    int obtenerEspaciosRestantes( int anchura);

    void operator =(const EstanteHorizontal &orig);

    void leer(ifstream &archivo);

    int get_cantidad_novelas() const;

    void set_cantidad_novelas(int cantidad_novelas);
};

void operator>>(ifstream &arch, EstanteHorizontal &estantehorizontal);


#endif //ESTANTEHORIZONTAL_HPP
