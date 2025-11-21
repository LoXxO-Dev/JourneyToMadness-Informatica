//
// Created by User on 20/11/2025.
//

#ifndef GESTORSTREAMERS_HPP
#define GESTORSTREAMERS_HPP


#include "ListaDoble.hpp"
#include "utils.hpp"
class GestorStreamers {
private:
    class ListaDoble lista;
public:
    void cargar_datos_streamers(const char *nombArch);
    void actualizar_datos_metricas(const char *nombArch);
    void generar_reportes(const char *nombArch);
    void eliminar_streamersGratuitos();


};



#endif //GESTORSTREAMERS_HPP
