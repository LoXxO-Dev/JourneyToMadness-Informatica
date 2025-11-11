#include "sources/utils.hpp"
#include "sources/Restaurante.hpp"
int main() {
    Restaurante res;
    res.carga("data/comandas2.csv");
    res.elimina(3);
    res.atiende("reportes/reporte.txt");
    return 0;
}