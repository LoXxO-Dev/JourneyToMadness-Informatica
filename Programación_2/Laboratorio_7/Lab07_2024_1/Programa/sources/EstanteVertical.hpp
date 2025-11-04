//
// Created by User on 3/11/2025.
//

#ifndef ESTANTEVERTICAL_HPP
#define ESTANTEVERTICAL_HPP
#include "Enciclopedia.hpp"
#include "Estante.hpp"
#include "utils.hpp"


class EstanteVertical :public Estante {
private:
    Enciclopedia enciclopedias[100];
    int cantidad_enciclopedias;

public:
    void leer(ifstream &archivo);
    void operator =(const class EstanteVertical &);
    int get_cantidad_enciclopedias() const;
    bool posicionarEnciclopedias(Enciclopedia enci) ;
    int obtenerEspaciosRestantes(int anchura);
    void set_cantidad_enciclopedias(int cantidad_enciclopedias);
    void imprimir(ofstream &arch) ;
};
void operator >>(ifstream &arch, EstanteVertical &esta);



#endif //ESTANTEVERTICAL_HPP
