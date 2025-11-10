#include "sources/utils.hpp"
#include "sources/Central.hpp"
int main() {
    Central central;
    central.carga();
    central.actualiza();
    central.muestra();
    /*
     Ojo mi actuliza no se porque teniendo comportamiento ya se de estacionamiento o de semaforo
     entra siempre al de velocidad pipii por los demas esta bieen
     *
     */
    return 0;
}