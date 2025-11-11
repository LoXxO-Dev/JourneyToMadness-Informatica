//
// Created by User on 11/11/2025.
//

#include "Novela.hpp"

Novela::Novela() {
    autor=nullptr;
}

Novela::~Novela() {
    if (autor)delete  autor;
}

void Novela::actualiza() {


}

void Novela::imprime(ofstream &arch) {
    Libro::imprime(arch);
    char aux[100];
    get_autor(aux);
    arch<<"Autor :"<<aux<<endl<<endl;
}

void Novela::leer(ifstream &arch) {
    Libro::leer(arch);
    char aux[100];
 arch.get(aux,100,'\n');
    set_autor(aux);

}

void  Novela::get_autor(char *autor) const {
    if (this->autor==nullptr)autor[0]=0;
    else strcpy(autor,this->autor);
}

void Novela::set_autor(const char *autor) {
    if (this->autor)delete [] this->autor;
    this->autor=new char[strlen(autor)+1];
    strcpy(this->autor,autor);
}
