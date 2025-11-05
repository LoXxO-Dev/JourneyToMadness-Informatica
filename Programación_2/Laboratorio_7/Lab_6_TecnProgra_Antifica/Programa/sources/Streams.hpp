//
// Created by User on 4/11/2025.
//

#ifndef STREAMS_HPP
#define STREAMS_HPP


#include "utils.hpp"
class Streams {
private:
    int fecha;
    char *nombre;
    char *categoria;
    double rating;
    double tasa_abandono;
    int duracion;
public:
    Streams();
    virtual ~Streams();
    void leer(ifstream &arch);
    Streams(const Streams &s);
    void operator =(const Streams &s);
    void imprimir(ofstream &arch);
    int get_fecha() const;

    void set_fecha(int fecha);

   void  get_nombre(char *nombre) const;

    void set_nombre(const char *nombre);

   void  get_categoria(char *categoria) const;

    void set_categoria(const char *categoria);

    double get_rating() const;

    void set_rating(double rating);

   double  get_tasa_abandono() const;

    void set_tasa_abandono(double tasa_abandono);

    int get_duracion() const;

    void set_duracion(int duracion);
};
void  operator >>(ifstream &arch,Streams &s);



#endif //STREAMS_HPP
