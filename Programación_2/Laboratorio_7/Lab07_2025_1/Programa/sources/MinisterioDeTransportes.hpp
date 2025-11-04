//
// Created by User on 4/11/2025.
//

#ifndef MINISTERIODETRANSPORTES_HPP
#define MINISTERIODETRANSPORTES_HPP
#include "CentralDeMonitoreo.hpp"
#include "utils.hpp"


class MinisterioDeTransportes {
private:
    CentralDeMonitoreo centros[10];
    char *zonas[10]{};
    int cantidad_centros;

public:
    MinisterioDeTransportes();
    void apertura_archivo_leer(ifstream &arch,const char  *nomb);
    void apertura_archivo_imprimir(ofstream &arch,const char  *nomb);
    void cargar_drones(const char *ruta_base);
    int obtener_ruta(const char *carpeta_base,const char *tipo,
        const char *zona,char *ruta)const ;
    void imprimir();
    int obtener_ruta_salida(const char *carpeta_base, const char *tipo, const char *zona,
                                          char *ruta,const char *delim) const;
   char * reservarEspacio(char *zona);
    void procesar_todos_los_eventos();

};


#endif //MINISTERIODETRANSPORTES_HPP
