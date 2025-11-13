//
// Created by User on 11/11/2025.
//

#include "GestorStreamers.hpp"

void GestorStreamers::cargar_datos_streamers(const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch) {
        cout<<"ERROR: No se abrio el archivo "<<nombArch<<endl;
        exit(1);
    }
    //ENGAGEMENT,320975,121,Maratón de chat,2025-10-17,2025-10-31,1535,553,54
    char  axu[100];
    while (true) {
        arch.getline(axu,100,',');
        if (arch.eof()) break;
        arbol.leer(axu,arch);
    }
}

void GestorStreamers::actualizar_datos_metricas(const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch) {
        cout<<"ERROR: No se abrio el archivo "<<nombArch<<endl;
        exit(1);
    }
    char tipo[100];
    int id;
    while (true) {
        arch.getline(tipo,100,',');
        if (arch.eof()) break;
        arch>>id;
        arch.get();
        arbol.buscarEInsertarInfo(id,arch,tipo);
    }
}

void GestorStreamers::generar_reportes(const char *nomb) {
    ofstream arch(nomb,ios::out);
    if (not arch) {
        cout<<"ERROR:NO SE PUDO ABRIR EL ARCHIVO CON NOMBRE"<<endl;
        exit(1);
    }
    arch<<fixed<<setprecision(2);
    imprimir_linea(arch,TAM_LINEA,'=');
    arch<<setw(60)<<"REPORTE DE STREAMERS "<<endl;
    imprimir_linea(arch,TAM_LINEA,'=');

    this->arbol.impresion(arch);


}
