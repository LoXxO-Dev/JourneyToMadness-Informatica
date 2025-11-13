//
// Created by User on 11/11/2025.
//

#include "Streamer.hpp"

Streamer::Streamer() {
    cuenta = nullptr;
    categoria= nullptr;
}

void Streamer::leer(ifstream &arch) {
    char aux[100];
    arch>>id;
    arch.get();
    arch.getline(aux,100,',');
    set_cuenta(aux);
    arch.getline(aux,100,',');
    set_categoria(aux);
    arch>>n_seguidores;
    arch.get();

}

void Streamer::imprimir(ofstream &arch) {
    char cuenta[100],cate[100];
    get_cuenta(cuenta);
    get_categoria(cate);
    arch<<"[ST]CUENTA: "<<left<<setw(15)<<cuenta<<
        "|SEGUIDORES:"<<right<<setw(10)<<n_seguidores<<
            "|CATEGORIA: "<<left<<setw(20)<<cate<<
                "|TIPO: ";
}

bool Streamer::operator>(class Streamer *ptr) {
    // char aux[100],aux2[100];
    // get_cuenta(aux);
    // ptr->get_cuenta(aux2);
    // return strcmp(aux,aux2)>0;
    return id>ptr->id;
}

int Streamer::get_id() const {
    return id;
}

void Streamer::set_id(int id) {
    this->id = id;
}

void  Streamer::get_cuenta(char *cuenta) const {
    if (this->cuenta==nullptr)cuenta[0]=0;
    else strcpy(cuenta,this->cuenta);
}

void Streamer::set_cuenta(const char *cuenta) {
    if (this->cuenta)delete [] this->cuenta;
    this->cuenta = new char[strlen(cuenta)+1];
    strcpy(this->cuenta,cuenta);
}

int Streamer::get_n_seguidores() const {
    return n_seguidores;
}

void Streamer::set_n_seguidores(int n_seguidores) {
    this->n_seguidores = n_seguidores;
}

void  Streamer::get_categoria(char *categoria) const {
    if (this->categoria==nullptr)categoria[0]=0;
    else strcpy(categoria,this->categoria);
}

void Streamer::set_categoria(const char *categoria) {
    if (this->categoria)delete [] this->categoria;
    this->categoria = new char[strlen(categoria)+1];
    strcpy(this->categoria,categoria);
}
