//
// Created by User on 11/11/2025.
//

#ifndef NOVELA_HPP
#define NOVELA_HPP


#include "Libro.hpp"
#include "utils.hpp"
class Novela :public Libro{
private:
    char *autor;

public:
    Novela();
    virtual ~Novela();
    void actualiza();
    void imprime(ofstream &arch);
    void leer(ifstream &arch);
   void  get_autor(char *autor) const;

    void set_autor(const char *autor);
};



#endif //NOVELA_HPP
