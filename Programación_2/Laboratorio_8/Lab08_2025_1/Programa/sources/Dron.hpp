//
// Created by User on 7/11/2025.
//

#ifndef DRON_HPP
#define DRON_HPP


#include "utils.hpp"
class Dron {
    private:
    char *id;
    char *ubicacion;
    int capacidad;

public:
    Dron();
    virtual ~Dron();
    virtual void leer(ifstream &arch);
    virtual bool operator >(const  class Dron &dron)const  ;
    virtual  void actualiza()=0;
    virtual void imprimir(ofstream &arch);
    void  get_id(char *id) const;

    void set_id(const char *id);

    void get_ubicacion(char *ubicacion) const;

    void set_ubicacion( const char* ubicacion);

    int get_capacidad() const;

    void set_capacidad(int capacidad);
};



#endif //DRON_HPP
