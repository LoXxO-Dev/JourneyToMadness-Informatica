#include "sources/MinisterioDeTransportes.hpp"
#include "sources/utils.hpp"
int main() {
    MinisterioDeTransportes Ministerio;
    Ministerio.cargar_drones("data/zonas.txt");
    Ministerio.procesar_todos_los_eventos();
    Ministerio.imprimir();

    //Max Verstappen ur a wordl champion
    //https://www.youtube.com/watch?v=KkkRXSZX0lg
    return 0;
}