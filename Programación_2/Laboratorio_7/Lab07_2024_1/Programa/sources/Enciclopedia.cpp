//
// Created by User on 2/11/2025.
//

#include "Enciclopedia.hpp"

Enciclopedia::Enciclopedia() {

}

Enciclopedia::Enciclopedia(const Enciclopedia &enci) {
    *this=enci;
}

void Enciclopedia::operator=(const Enciclopedia &enci) {
    char aux[100];
    volumen = enci.volumen;
    peso = enci.peso;
    set_ancho(enci.get_ancho());
    set_alto(enci.get_alto());
    enci.get_codigo(aux);
    set_codigo(aux);
    enci.get_nombre(aux);
    set_nombre(aux);
}

void Enciclopedia::leer(ifstream &arch) {
    Libro::leer(arch);
    arch>>volumen;
    arch.get();
    arch>>peso;
}

int Enciclopedia::get_volumen() const {
    return volumen;
}

void Enciclopedia::imprimir(ofstream &arch) {
    char aux[100],nombre[100];
    get_codigo(aux);
    get_nombre(nombre);
    arch<<left<<setw(20)<<aux<<setw(30)<<nombre<<right<<setw(10)<<get_ancho()<<setw(10)<<get_alto()<<setw(10)<<peso<<endl;
}

void Enciclopedia::set_volumen(int volumen) {
    this->volumen = volumen;
}

double Enciclopedia::get_peso() const {
    return peso;
}

void Enciclopedia::set_peso(double peso) {
    this->peso = peso;
}

void operator>>(ifstream &arch, class Enciclopedia &enci) {
    enci.leer(arch);
}
