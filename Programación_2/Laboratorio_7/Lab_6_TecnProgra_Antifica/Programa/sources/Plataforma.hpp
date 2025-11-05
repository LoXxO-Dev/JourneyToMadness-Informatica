//
// Created by User on 4/11/2025.
//

#ifndef PLATAFORMA_HPP
#define PLATAFORMA_HPP


#include "Categoria.hpp"
#include "Streams.hpp"
#include "utils.hpp"

class Plataforma {
private:
    Streams streams[500];
    int cant_streams;
    Categoria categorias[110];
    int cant_categorias;

public:
    void leerCategorias(const char *nombArch);
    void leerStreams(const char *nombArch);
    void generaArchivoEnlace (const char *categoria,char *nombArch,char  *enlace);
    void imprimirReportes();
    void aperturaArchivosSalida(ofstream &salida,const char *nom);
      void  imprimirCabezera( ofstream &arch,char *enlace,char *nombre,char *codigo);
    void imprimirLinea(ofstream &arch,int cant ,char car);
    void    imprimirEstadisticar(ofstream & arch,double promRati,double promDese, int total);

};


#endif //PLATAFORMA_HPP
