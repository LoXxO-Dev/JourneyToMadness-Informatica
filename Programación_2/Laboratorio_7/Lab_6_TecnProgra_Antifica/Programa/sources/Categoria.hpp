//
// Created by User on 5/11/2025.
//

#ifndef CATEGORIA_HPP
#define CATEGORIA_HPP


#include "utils.hpp"
class Categoria {
    private:
    char *codigo;
    char *nombre;

public:
    Categoria();
    void leer(ifstream &arch);
    virtual ~Categoria();
    Categoria(const Categoria &cate);
    void operator =(const Categoria &cate);
   void  get_codigo(char *codigo) const;

    void set_codigo(const char *codigo);

   void  get_nombre(char *nombre) const;

    void set_nombre(const char *nombre);
};
void operator >>(ifstream &arch,Categoria &cate);



#endif //CATEGORIA_HPP
