//
// Created by User on 20/11/2025.
//

#ifndef STREAMER_HPP
#define STREAMER_HPP


#include "utils.hpp"
class Streamer {
private:
    int id;
    string nombre;
    int n_seguidores;
    string categoria;

public:
    virtual void leer(ifstream &archivo);
    virtual void imprimir(ofstream &archivo);
    virtual void actualiza(char *tipo,ifstream &arch)=0;
    virtual bool eliminable()=0;
    int get_id() const;

    void set_id(int id);

    string get_nombre() const;

    void set_nombre(const string &nombre);

    int get_n_seguidores() const;

    void set_n_seguidores(int n_seguidores);

    string get_categoria() const;

    void set_categoria(const string &categoria);
};



#endif //STREAMER_HPP
