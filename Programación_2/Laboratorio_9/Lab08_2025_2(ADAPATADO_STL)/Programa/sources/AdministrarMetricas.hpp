//
// Created by User on 25/11/2025.
//

#ifndef ADMINISTRARMETRICAS_HPP
#define ADMINISTRARMETRICAS_HPP

#include "Metrica.hpp"
#include "utils.hpp"
class AdministrarMetricas {
    private:
    list<class Metrica *>listaDeMetricas;
public:
    void cargarArchivo(const char *nomb);
    void  generarReporte(const char *nomb);
    void ordenar();
    void eliminarNodos();
    void eliminarLista();
    void encabezadoCalidad(ofstream &arch);
    void encabezadoEngage(ofstream &arch);
    void encabezadoBasica(ofstream &arch);
    void encabezadoGlobal(ofstream &arch);
    void imprimirEstadisticas(ofstream &arch,int cantAct,int cantExpi);
};



#endif //ADMINISTRARMETRICAS_HPP
