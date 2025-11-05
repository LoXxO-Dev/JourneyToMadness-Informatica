//
// Created by User on 2/11/2025.
//

#include "Estante.hpp"

Estante::Estante() {
    codigo=nullptr;
    espacios=nullptr;

    pesoActual=0;
}

void Estante::imprimir(ofstream &arch,int cant,bool condicion) {
    char codigo[10];
    get_codigo(codigo);
    arch<<left<<setw(20)<<"Código Estante:"<<setw(10)<<codigo<<"Cantidad de Libros "<<cant<<endl;
    arch<<setw(20)<<"Anchura x Altura "<<anchura<<" X "<<setw(5)<<altura<<setw(10)<<"Peso Maximo "<<pesoSoportado<<endl;
    if (condicion)arch<<setw(29)<<"Tipo: Horizontal"<<"Peso Total "<<pesoActual<<endl;
    else arch<<setw(29)<<"Tipo: Vertical"<<"Peso Total "<<pesoActual<<endl;
    imprimirLinea(arch,TAM_LINEA,'-');
    imprimirEstante(arch);
}

void Estante::imprimirEstante(ofstream &arch) {
    for (int i=0;i<altura;i++) {
        for (int j=0;j<anchura;j++) {
            if (this->espacios[i*anchura+j].get_contenido()!='*')
                this->espacios[i*anchura+j].set_contenido(' ');
            arch<<"["<<this->espacios[i*anchura+j].get_contenido()<<"]";
        }
        arch<<endl;
    }
}

void Estante::imprimirLinea(ofstream &arch, int cant, char car) {
    for (int i=0;i<cant;i++)
        arch.put(car);
    arch<<endl;
}


void Estante::leer(ifstream &arch) {
    char aux[100],car;
    arch.getline(aux,100,',');
    arch>>anchura>>car>>altura>>car>>pesoSoportado;
    set_codigo(aux);
    espacios=new Espacio[anchura*altura]{};
    pesoActual=0;
}
void Estante::pintar(int alto,int ancho,int espaciosSobra) {
    for (int i=altura-1;i>=altura-alto;i--) {
        for (int j=anchura-espaciosSobra;j<anchura-espaciosSobra+ancho;j++) {
           espacios[i*anchura+j].set_contenido('*');
           espacios[i*anchura+j].set_posx(i);
           espacios[i*anchura+j].set_posy(j);

        }
    }
}
void Estante::get_codigo(char *codigo) const {
    if (this->codigo == nullptr)codigo[0] = 0;
    else strcpy(codigo, this->codigo);
}

void Estante::set_codigo(const char *codigo) {
    if (this->codigo)delete this->codigo;
    this->codigo = new char[strlen(codigo) + 1];
    strcpy(this->codigo, codigo);
}

int Estante::get_anchura() const {
    return anchura;
}

void Estante::set_anchura(int anchura) {
    this->anchura = anchura;
}

int Estante::get_altura() const {
    return altura;
}

void Estante::set_altura(int altura) {
    this->altura = altura;
}

double Estante::get_peso_soportado() const {
    return pesoSoportado;
}

void Estante::set_peso_soportado(double peso_soportado) {
    pesoSoportado = peso_soportado;
}

double Estante::get_peso_actual() const {
    return pesoActual;
}

void Estante::set_peso_actual(double peso_actual) {
    pesoActual = peso_actual;
}
