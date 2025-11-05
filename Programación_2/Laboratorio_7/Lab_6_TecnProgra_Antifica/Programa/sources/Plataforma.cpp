//
// Created by User on 4/11/2025.
//

#include "Plataforma.hpp"

void Plataforma::leerCategorias(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch) {
        cout << "ERROR:No se pudo abrir el archivo con nombre" << nombArch << endl;
        exit(1);
    }
    cant_categorias = 0;
    while (true) {
        Categoria c;
        arch >> c;
        if (arch.eof())break;;
        categorias[cant_categorias++] = c;
    }
}

void Plataforma::leerStreams(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch) {
        cout << "ERROR:No se pudo abrir el archivo con nombre" << nombArch << endl;;
        exit(1);
    }
    cant_streams = 0;
    while (true) {
        Streams s;
        arch >> s;
        if (arch.eof())break;;
        streams[cant_streams++] = s;
    }
}

void Plataforma::generaArchivoEnlace(const char *categoria, char *nombArch, char *enlace) {
    nombArch[0] = 0;
    enlace[0] = 0;
    char auxCate[100];
    strcpy(auxCate, categoria);
    bool mayus = false, primero = true;
    for (int i = 0; categoria[i]; i++) {
        auxCate[i] = categoria[i];
        if (mayus or primero) {
            auxCate[i] -= 'a' - 'A';
            mayus = false;
            primero = false;
        }
        if (auxCate[i] == '_' and auxCate[i + 1] > 'a' and auxCate[i + 1] < 'z') {
            mayus = true;
        }
    }
    //generarArchivo
    strcpy(nombArch, "reportes/");
    strcat(nombArch, auxCate);
    //genera Enlace
    strcpy(enlace, "https://Laboratorio06_2025_2/");
    strcat(enlace, nombArch);

    strcat(nombArch, ".txt");
}

void Plataforma::imprimirReportes() {
    char nombre[100], nombArch[100], enlace[100], auxCod[100], cod[100];
    for (int i = 0; i < cant_categorias; i++) {
        categorias[i].get_nombre(nombre);
        categorias[i].get_codigo(cod);
        generaArchivoEnlace(nombre, nombArch, enlace);
        ofstream arch;
        aperturaArchivosSalida(arch, nombArch);
        imprimirCabezera(arch, enlace, nombre, cod);
        double rating=0,cant=0,desercion=0,total=0;
        for (int j = 0; j < cant_streams; j++) {
            streams[j].get_categoria(auxCod);
            if (strcmp(auxCod, cod) == 0) {
                streams[j].imprimir(arch);
                cant++;
                rating+=streams[j].get_rating();
                desercion+=streams[j].get_tasa_abandono();
                total+=streams[j].get_duracion();
            }
        }
        imprimirLinea(arch,TAM_LINEA, '=');
        imprimirEstadisticar(arch,rating/cant,desercion/cant,total);
        arch.close();
    }
}

void Plataforma::aperturaArchivosSalida(ofstream &salida, const char *nom) {
    salida.open(nom, ios::out);
    if (not salida.is_open()) {
        cout << "ERROR:No se pudo abrir el archivo con nombre " << nom << endl;
        exit(1);
    }
}

void Plataforma::imprimirCabezera(ofstream &arch, char *enlace, char *nombre, char *codigo) {
    arch << "Código: " << codigo << endl << "Nombre: " << nombre << endl << "Enlace: " << enlace << endl;
    arch << "REPRODUCCIONES:" << endl;
    imprimirLinea(arch,TAM_LINEA, '=');
    arch << left << setw(20) << "FECHA" << setw(20) << "CANAL" <<
            setw(20) << "RATING" << setw(20) << "DROP-OFF" << setw(20) <<
            "DURACION" << endl;
    arch << fixed << setprecision(2);
}

void Plataforma::imprimirLinea(ofstream &arch, int cant, char car) {
    for (int i = 0; i < cant; i++)
        arch.put(car);
    arch << endl;
}

void Plataforma::imprimirEstadisticar(ofstream &arch, double promRati, double promDese, int  total) {
    arch<<left<<setw(30)<<"PROMEDIO DE RATING: "<<right<<setw(10)<<promRati<<endl;
    arch<<left<<setw(30)<<"PROMEDIO DE DROP-OFF: "<<right<<setw(10)<<promDese<<endl;
    arch<<left<<setw(30)<<"DURACION TOTAL: "<<right<<setw(5)<<" "<<setfill('0')<<setw(2)<<total/3600 <<":"<<
        setw(2)<<total%3600/60<<":"<<setw(2)<<total%3600%60<<setfill(' ')<<endl;
}
