//
// Created by User on 11/11/2025.
//

#include "Entrada.hpp"

void Entrada::leer(ifstream &archivo) {
    Producto::leer(archivo);
    char aux[100];
    archivo.get(aux,100,'\n');
    if (strcmp(aux,"picante")==0)
        picante = true;
    else picante = false;
}

void Entrada::imprimir(ofstream &archivo) {
    Producto::imprimir(archivo);
    if (picante)
        archivo<<"Sin Picante"<<endl;
    else     archivo<<"Picante"<<endl;
}



bool Entrada::verificar(int num) {
    return false;
}

bool Entrada::is_picante() const {
    return picante;
}

void Entrada::set_picante(bool picante) {
    this->picante = picante;
}
