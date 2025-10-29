#include "funciones/utils.hpp"
#include "funciones/Tesoreria.hpp"
int main() {
    Tesoreria Oteso;
    Oteso.cargaescalas();
    Oteso.cargaalumnos();
    Oteso.actualizaboleta();
    Oteso.imprimeboleta();
    return 0;
}