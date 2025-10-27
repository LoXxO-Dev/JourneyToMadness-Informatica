#include "sources/BibliotecaGenerica.hpp"
#include "sources/FuncionesEnteras.hpp"
#include "sources/FuncionesRegistros.hpp"
using namespace std;
int main() {
    void *pedidos1,*pedidos2,*pedidosfinal;
//numeros
    crealista(pedidos1,leenum,"data/RegistroNum1.txt");
    imprimeLista(pedidos1,imprimenum,"reportes/Repnum1.txt");

    crealista(pedidos2,leenum,"data/RegistroNum2.txt");
    imprimeLista(pedidos2,imprimenum,"reportes/Repnum2.txt");

    combinalista(pedidos1,pedidos2,pedidosfinal,cmpnum);
    imprimeLista(pedidosfinal,imprimenum,"reportes/RepnumFinal.txt");

//registros
    crealista(pedidos1,leeregistro,"data/Pedidos31.csv");
     imprimeLista(pedidos1,imprimeregistro,"reportes/Repreg1.txt");

    crealista(pedidos2,leeregistro,"data/Pedidos32.csv");
     imprimeLista(pedidos2,imprimeregistro,"reportes/Repreg2.txt");

     combinalista(pedidos1,pedidos2,pedidosfinal,cmpregistro);
     imprimeLista(pedidosfinal,imprimeregistro,"reportes/RepregFinal.txt");
    return 0;
}