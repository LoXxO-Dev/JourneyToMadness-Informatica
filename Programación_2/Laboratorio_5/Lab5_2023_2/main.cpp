#include "sources/PilaConEnteros.hpp"
#include "sources/FlotaGenerica.hpp"
#include "sources/PilaConRegistros.hpp"
using namespace std;


#include <cstdlib>
int main() {
    int numcamiones;
    double pesomaximo;
    void *flota;
/*
    numcamiones = 5, pesomaximo = 10;
    cargaCamiones(flota, numcamiones, pesomaximo,
                  leenum, calculanumero, "data/numeros.txt");
     qsort(flota, numcamiones,sizeof(void *),cmpnumero);
    muestracamiones(flota,numcamiones,imprimenumero,"reportes/reportenum.txt");

*/
    numcamiones = 100, pesomaximo = 400;
    cargaCamiones(flota, numcamiones, pesomaximo,
                  leeregistro, calcularegistro, "data/Pedidos3.csv");
    qsort(flota, numcamiones,sizeof(void *),cmpregistro);
    muestracamiones(flota,numcamiones,imprimeregistro,"reportes/reporteregistro.txt");




    return 0;
}
