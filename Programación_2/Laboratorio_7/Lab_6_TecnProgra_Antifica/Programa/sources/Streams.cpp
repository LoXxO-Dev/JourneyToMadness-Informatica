//
// Created by User on 4/11/2025.
//

#include "Streams.hpp"

Streams::Streams() {
    nombre=nullptr;
    categoria=nullptr;
}

Streams::~Streams() {
    if (nombre !=nullptr)delete nombre;
    if (categoria !=nullptr)delete categoria;
}

void Streams::leer(ifstream &arch) {
    int dd,mm,aa,ss,min,hh;
    char car,aux[100];
    arch>>dd;
    if (arch.eof())return;
    arch>>car>>mm>>car>>aa;
    arch>>aux;
    set_nombre(aux);
    arch>>aux;
    set_categoria(aux);
    arch>>rating;
    arch>>tasa_abandono;
    arch>>hh>>car>>min>>car>>ss;
    duracion=ss+min*60+hh*3600;
    fecha=dd+mm*100+aa*10000;

}

Streams::Streams(const Streams &s) {
    nombre=nullptr;
    categoria=nullptr;
    *this=s;
}

void Streams::operator=(const Streams &s) {
    char aux[100];
    s.get_nombre(aux);
    set_nombre(aux);
    s.get_categoria(aux);
    set_categoria(aux);
    fecha=s.get_fecha();
    rating=s.get_rating();
    tasa_abandono=s.get_tasa_abandono();
    duracion=s.get_duracion();

}

void Streams::imprimir(ofstream &arch) {
    char nombre[100];
    get_nombre(nombre);
    arch<<right<<setw(2)<<setfill('0')<<fecha%100
    <<"/"<<setw(2)<<fecha%10000/100<<"/"<<
        setw(4)<<fecha/10000<<setfill(' ');
    arch<<setw(5)<<" "<<left<<setw(23)<<nombre<<right<<
        setw(10)<<rating<<setw(20)<<tasa_abandono<<
            setw(5)<<" "<<setw(8)<<" "<<setfill('0')<<setw(2)<<duracion/3600 <<":"<<
        setw(2)<<duracion%3600/60<<":"<<setw(2)<<duracion%3600%60<<setfill(' ')<<endl;
}


int Streams::get_fecha() const {
    return fecha;
}

void Streams::set_fecha(int fecha) {
    this->fecha = fecha;
}

void  Streams::get_nombre(char *nombre) const {
    if (this->nombre ==nullptr)nombre[0]=0;
    else strcpy(nombre,this->nombre);
}

void Streams::set_nombre(const char *nombre) {
   if (this->nombre !=nullptr)delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

void  Streams::get_categoria(char *categoria) const {
    if (this->categoria ==nullptr)categoria[0]=0;
    else strcpy(categoria,this->categoria);
}

void Streams::set_categoria(const char *categoria) {
    if (this->categoria !=nullptr)delete this->categoria;
    this->categoria = new char[strlen(categoria)+1];
    strcpy(this->categoria,categoria);
}

double Streams::get_rating() const {
    return rating;
}

void Streams::set_rating(double rating) {
    this->rating = rating;
}

double Streams::get_tasa_abandono() const {
    return tasa_abandono;
}

void Streams::set_tasa_abandono(double tasa_abandono) {
    this->tasa_abandono = tasa_abandono;
}

int Streams::get_duracion() const {
    return duracion;
}

void Streams::set_duracion(int duracion) {
    this->duracion = duracion;
}

void operator>>(ifstream &arch, Streams &s) {
    s.leer(arch);
}
