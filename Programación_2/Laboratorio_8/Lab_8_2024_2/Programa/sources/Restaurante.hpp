//
// Created by User on 11/11/2025.
//

#ifndef RESTAURANTE_HPP
#define RESTAURANTE_HPP


#include "Cola.hpp"
#include "utils.hpp"
class Restaurante {
private:
    class Cola Ccomanda;
    public:
    void carga(const char *nombArch);
    void atiende(const char *nombArch);
    void elimina(int num);
};



#endif //RESTAURANTE_HPP
