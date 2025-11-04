//
// Created by User on 2/11/2025.
//

#ifndef ENCICLOPEDIA_HPP
#define ENCICLOPEDIA_HPP
#include "Libro.hpp"
#include "utils.hpp"


class Enciclopedia :public Libro{
private:
    int volumen;
    double peso;

public:
    Enciclopedia();
    Enciclopedia(const Enciclopedia &enci);
    void operator =(const Enciclopedia &enci) ;
    void leer(ifstream &arch);
    int get_volumen() const;
    void imprimir(ofstream &arch);
    void set_volumen(int volumen);

    double get_peso() const;

    void set_peso(double peso);
};
void operator >>(ifstream &arch,class Enciclopedia &enci);



#endif //ENCICLOPEDIA_HPP
