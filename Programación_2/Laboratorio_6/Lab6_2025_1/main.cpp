#include "sources/utils.hpp"
#include "sources/MinisterioDeTransportes.hpp"
#include "sources/Infraccion.hpp"

int main() {
    class MinisterioDeTransportes ministerio;
    ministerio < "data/TablaDeInfracciones.csv";
    ministerio <= "data/EmpresasRegistradas.csv";
    ministerio<<="data/InfraccionesCometidas.csv";
    ministerio << "reportes/ReporteParaElMinisterio.txt";



    return 0;
}
