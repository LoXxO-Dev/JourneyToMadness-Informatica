//
// Created by User on 28/10/2025.
//

#include "sources.hpp"

#include "alumnonota.hpp"
#include "nota.hpp"

void cargaalumno(alumno *lalumnos) {
    ifstream arch("data/Alumnos.csv", ios::in);
    if (not arch) {
        cout << "ERROR:No se encontro el archivo con nombre Alumnos.csv" << endl;
        exit(1);
    }
    int n = 0;
    while (true) {
        alumno alu;
        arch >> alu;
        if (arch.eof()) break;
        lalumnos[n] = alu;
        n++;
    }
}

void carganotas(alumnonota *lnotas) {
    ifstream arch("data/Notas.csv", ios::in);
    if (not arch) {
        cout << "ERROR:No se encontro el archivo con nombre Alumnos.csv" << endl;
        exit(1);
    }
    int n = 0;
    while (true) {
        alumnonota alunota;
        arch >> alunota;
        if (arch.eof())break;
        lnotas[n] = alunota;
        n++;
    }
}

void actualizanotas(alumno *lalumnos, alumnonota *lnotas) {
    int codigo, posalumnos;
    for (int i = 0; lnotas[i].get_codigo(); i++) {
        codigo = lnotas[i].get_codigo();
        nota notita;
        lnotas[i] & notita;
        posalumnos = buscarAlumno(lalumnos, codigo);
        lalumnos[posalumnos] +=notita;
    }
}

int buscarAlumno(alumno *lalumnos, int codigo) {
    for (int i = 0; lalumnos[i].get_codigo(); i++)
        if (lalumnos[i].get_codigo() == codigo) return i;
    return -1;
}

  void   imprimealummno( alumno *lalumnos) {
    ofstream arch("reportes/Reporte.txt", ios::out);
    if (not arch) {
        cout<<"No se pudo abrir el archivo con nombre Reporte.txt "<<endl;
        exit(1);
    }
    arch<<fixed<<setprecision(2);
    for (int i=0;lalumnos[i].get_codigo();i++) {
        arch << lalumnos[i];
        arch << endl;
    }

}