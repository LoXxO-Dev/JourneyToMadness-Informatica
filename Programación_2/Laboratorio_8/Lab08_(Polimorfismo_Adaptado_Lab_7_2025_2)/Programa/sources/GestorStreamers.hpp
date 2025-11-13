//
// Created by User on 11/11/2025.
//

#ifndef GESTORSTREAMERS_HPP
#define GESTORSTREAMERS_HPP


#include "Arbol.hpp"
#include "utils.hpp"
class GestorStreamers {
private:
    class Arbol arbol;
public:
    void cargar_datos_streamers(const char *nombArch);
    void actualizar_datos_metricas(const char *nombArch);
    void generar_reportes(const char *nomb);
};



#endif //GESTORSTREAMERS_HPP
