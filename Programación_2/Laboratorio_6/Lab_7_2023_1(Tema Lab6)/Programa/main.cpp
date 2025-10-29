#include "funciones/utils.hpp"
#include "funciones/alumno.hpp"
#include "funciones/alumnonota.hpp"
#include "funciones/sources.hpp"

int main() {
    alumno lalumnos[100];
    alumnonota lnotas[200];

    cargaalumno(lalumnos);
    carganotas(lnotas);
    actualizanotas(lalumnos, lnotas);
    imprimealummno(lalumnos);
    /* Comentario de error de logica(no soy perfecto solo Dios lo es)
     * al momento de buscar los bikas y los trikas si aparece primera la nota aprobatoria lo registra
     * como primera y si luego aparece donde jalo tendria que reducir la prime y aumentar en la bika pero eso no pasa pip
     * despues todo esta bien en las sobrecargar e impresion solo ese detalle
     */

    return 0;
}
