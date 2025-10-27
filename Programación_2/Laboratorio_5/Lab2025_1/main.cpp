#include "sources/utils.hpp"
#include "sources/BibliotecaGenerica.hpp"
#include "sources/BibliotecaConductores.hpp"
#include "sources/BibliotecaInfracciones.hpp"
#include <cstdlib>

int main() {
    void *lista;
    generaLista(lista);
    creaLista(lista, leeconducores, cmpconductores,
              buscalistaconductores, "data/Conductores.csv");
    cargaUnidades(lista, "data/Unidades.csv");


    creaLista(lista, leeinfracciones, cmpinfracciones,
              buscainfraccion, "data/Faltas.csv");
    imprimeLista(lista, imprimeconductores, "reportes/repconductores.txt");

    return 0;
}
