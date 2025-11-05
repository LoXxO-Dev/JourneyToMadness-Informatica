//
// Created by User on 29/10/2025.
//

#include "Entrada.hpp"

Entrada::Entrada() {
    picante=false;
}

bool Entrada::is_picante() const {
    return picante;
}

void Entrada::set_picante(bool picante) {
    this->picante = picante;
}
void Entrada::leer(ifstream &arch) {
    Producto::leer(arch);
    char aux[100];
    arch.getline(aux,100,'\n');
    if (strcmp(aux,"sin picante")==0)
        set_picante(false);
    else set_picante(true);

}

void Entrada::imprimir(ofstream &arch) {
    Producto::imprimir(arch);
    arch<<setw(10)<<" "<<left;
    if (picante) {
        arch<<"PICANTE"<<endl;
    }else arch<<"SIN PICANTE "<<endl;
}

void operator<<(ofstream &arch, class Entrada &entr) {
    entr.imprimir(arch);
}
