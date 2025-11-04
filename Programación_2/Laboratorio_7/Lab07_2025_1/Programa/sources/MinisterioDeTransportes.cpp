//
// Created by User on 4/11/2025.
//

#include "MinisterioDeTransportes.hpp"

MinisterioDeTransportes::MinisterioDeTransportes() {
    cantidad_centros = 0;
}

void MinisterioDeTransportes::apertura_archivo_leer(ifstream &arch, const char *nomb) {
    arch.open(nomb, ios::in);
    if (not arch) {
        cout << "ERROR:No se pudo abrir el archivo con nombre " << nomb << endl;
        exit(1);
    }
}

void MinisterioDeTransportes::apertura_archivo_imprimir(ofstream &arch, const char *nomb) {
    arch.open(nomb, ios::out);
    if (not arch) {
        cout << "ERROR:No se pudo abrir el archivo con nombre " << nomb << endl;
        exit(1);
    }
}

void MinisterioDeTransportes::cargar_drones(const char *ruta_base) {
    ifstream arch;
    apertura_archivo_leer(arch, ruta_base);
    char ruta[100], zona[100], tipo[100]{"Drones"}, carpeta[100]{"data"}, tipo_dron[100];
    while (true) {
        arch >> zona;
        if (obtener_ruta(carpeta, tipo, zona, ruta)) {
            zonas[cantidad_centros] = reservarEspacio(zona);
            ifstream archivo_drones;
            apertura_archivo_leer(archivo_drones, ruta);
            while (true) {
                archivo_drones.getline(tipo_dron, 100, ',');
                if (archivo_drones.eof()) break;
                centros[cantidad_centros].leer(archivo_drones, tipo_dron);
            }
            cantidad_centros++;
        }
        if (arch.eof()) break;
    }
}

int MinisterioDeTransportes::obtener_ruta(const char *carpeta_base, const char *tipo, const char *zona,
                                          char *ruta) const {
    ruta[0] = 0;

    strcpy(ruta, carpeta_base);
    strcat(ruta, "/");
    strcat(ruta, tipo);
    strcat(ruta, "_");
    strcat(ruta, zona);
    strcat(ruta, ".csv");
    //  cout << ruta << endl;
    ifstream arch(ruta, ios::in);
    if (not arch.is_open()) {
        arch.close();
        return 0;
    } else {
        arch.close();
        return 1;
    }
}
int MinisterioDeTransportes::obtener_ruta_salida(const char *carpeta_base, const char *tipo, const char *zona,
                                          char *ruta,const char *delim) const {
    ruta[0] = 0;
    strcpy(ruta, carpeta_base);
    strcat(ruta, tipo);
    strcat(ruta, zona);
    strcat(ruta, delim);
    //  cout << ruta << endl;
    ofstream arch(ruta, ios::out);
    if (not arch.is_open()) {
        arch.close();
        return 0;
    } else {
        arch.close();
        return 1;
    }
}

void MinisterioDeTransportes::imprimir() {
    char ruta[100], tipo[100]{"/"}, carpeta[100]{"reportes"},zonita[100],arch_tip[10]{".txt"};

    for (int i = 0; i < cantidad_centros; i++) {
        char *zona = zonas[i];
        strcpy(zonita, zona);
        if (obtener_ruta_salida(carpeta, tipo, zona, ruta,arch_tip)) {
            ofstream archivo;
            apertura_archivo_imprimir(archivo, ruta);
            archivo<<fixed<<setprecision(2);
            archivo<<setw(50)<<"Reporte de "<<zonita<<endl;
            imprimirLinea(archivo,TAM_LINEA,'=');
           this->centros[i].imprimir(archivo);
        }
    }
}

char *MinisterioDeTransportes::reservarEspacio(char *zona) {
    char *ptr;
    ptr = new char[strlen(zona) + 1];
    strcpy(ptr, zona);
    return ptr;
}

void MinisterioDeTransportes::procesar_todos_los_eventos() {
    char ruta[100], tipo[100]{"Eventos"}, carpeta[100]{"data"},zonita[100];

    for (int i = 0; i < cantidad_centros; i++) {
        char *zona = zonas[i];
        strcpy(zonita, zona);
        if (obtener_ruta(carpeta, tipo, zona, ruta)) {
            ifstream archivo;
            apertura_archivo_leer(archivo, ruta);
            while (true) {
                this->centros[i].cargar_infracciones(archivo);
                if (archivo.eof())break;
            }
        }

    }
}
