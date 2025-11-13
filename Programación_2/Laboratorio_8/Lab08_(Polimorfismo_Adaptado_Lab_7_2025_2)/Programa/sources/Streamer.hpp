//
// Created by User on 11/11/2025.
//

#ifndef STREAMER_HPP
#define STREAMER_HPP


#include "utils.hpp"
class Streamer {
private:
    int id;
    char *cuenta;
    int n_seguidores;
    char *categoria;

public:
    Streamer();
    virtual void leer(ifstream &arch);
    virtual void imprimir(ofstream &arch);
    virtual void actualiza(char  *tipo,ifstream &arch)=0;
    bool operator >(class Streamer *ptr);
    int get_id() const;

    void set_id(int id);

    void  get_cuenta(char *cuenta) const;

    void set_cuenta(const char *cuenta);

    int get_n_seguidores() const;

    void set_n_seguidores(int n_seguidores);

    void  get_categoria(char *categoria) const;

    void set_categoria(const char *categoria);
};



#endif //STREAMER_HPP
