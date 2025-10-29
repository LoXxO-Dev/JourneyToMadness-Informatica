//
// Created by User on 29/10/2025.
//

#include "Tesoreria.hpp"

void Tesoreria::cargaescalas() {
    ifstream arch("data/escalas.csv", ios::in);
    if (not arch) {
        cout << "ERROR :no se pudo abrir el archivo escalas.csv" << endl;
        exit(1);
    }

    //5,666.90
    int escala;
    double precio;
    while (true) {
        arch >> escala;
        if (arch.eof())break;
        arch.get();
        arch >> precio;
        this->lescala[escala-1].set_precio(precio);
        this->lescala[escala-1].set_codigo(escala);
    }
}

void Tesoreria::cargaalumnos() {
    ifstream arch("data/Alumnos.csv", ios::in);
    if (not arch) {
        cout << "ERROR :no se pudo abrir el archivo Alumnos.csv" << endl;
        exit(1);
    }
    //S,202123703,GAMARRA/TABORI/PAUL-RONAL,5,20,30
    char tipo;
    nd=0;
    while (true) {
        arch >> tipo;
        if (arch.eof()) break;
        arch.get();
        lboleta[nd].asignartipo(tipo);
        lboleta[nd].lee(arch);
        nd++;
    }
}
void Tesoreria::actualizaboleta() {
    for (int i = 0; i<nd; i++) {
        lboleta[i].actualizaboleta(lescala);
    }
}
void Tesoreria::imprimeboleta() {
    ofstream arch("reportes/reporte.txt", ios::out);
    if (not arch) {
        cout << "ERROR :no se pudo abrir el archivo reporte.txt" << endl;
        exit(1);
    }
    arch<<left<<setw(20)<<"Código"<<setw(50)<<"Nombre"<<setw(10)<<"Escala"<<setw(15)<<"Cred."<<setw(20)<<
        "Licencia"<<setw(15)<<"Total"<<endl;
    imprimeLinea(arch,TAM_LINEA,'=');
    arch<<fixed<<setprecision(2);
    for (int i = 0; i<nd; i++) {
        lboleta[i].imprime(arch);
    }
}
void Tesoreria::imprimeLinea(ofstream& arch,int cant ,char car) {
    for (int i = 0; i<cant; i++) {
        arch.put(car);
    }
    arch<<endl;

}