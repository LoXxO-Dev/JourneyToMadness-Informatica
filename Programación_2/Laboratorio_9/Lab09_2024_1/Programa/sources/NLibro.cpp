//
// Created by User on 23/11/2025.
//

#include "NLibro.hpp"
#include "Revista.hpp"
#include "Enciclopedia.hpp"
#include "Novela.hpp"
void NLibro::leer(ifstream &arch,double &disponible) {
    char tipo;

    arch >> tipo;
    if (arch.eof()) return;

    arch.get();
    if (tipo=='N') plibro=new class Novela();
    else if (tipo=='R') plibro=new class Revista();
    else if (tipo=='E') plibro=new class Enciclopedia();
    plibro->leer(arch);
    disponible-=plibro->get_peso();
}

void NLibro::imprimir(ofstream &arch) {
    plibro->imprimir(arch);
}
