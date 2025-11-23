//
// Created by User on 23/11/2025.
//

#include "MinisterioDeTransporte.hpp"

void MinisterioDeTransporte::cargaDeInfracciones(const char *nomb) {
    ifstream arch;
    apertura_archivos_entrada(arch, nomb);

    while (true) {
        class Infraccion aux;
        arch >> aux;
        if (arch.eof()) break;
        tablaInfracciones.push_back(aux);
    }
    sort(tablaInfracciones.begin(), tablaInfracciones.end());
}

void MinisterioDeTransporte::cargaEmpresas(const char *nomb) {
    ifstream arch;
    apertura_archivos_entrada(arch, nomb);
    while (true) {
        class Empresa aux;
        arch >> aux;
        if (arch.eof()) break;
        vectorEmpresas.push_back(aux);
    }
    sort(vectorEmpresas.begin(), vectorEmpresas.end());
}

void MinisterioDeTransporte::cargaVehiculos(const char *nomb) {
    ifstream arch;
    apertura_archivos_entrada(arch, nomb);
    int dni;
    bool entre;
    while (true) {
        arch >> dni;
        if (arch.eof()) break;
        arch.get();
        entre = false;
        for (auto &ite: vectorEmpresas) {
            if (ite.get_dni() == dni) {
                ite.ingresarVehiculos(arch);
                entre = true;
                break;
            }
        }
        if (not entre) while (arch.get() != '\n');
    }
}

void MinisterioDeTransporte::cargaInfraccionesCometidas(const char *nomb) {
    ifstream arch;
    apertura_archivos_entrada(arch, nomb);
    bool bandera;
    while (true) {
        class Multa aux;
        arch >> aux;
        if (arch.eof()) break;
        bandera = false;
        for (auto &x: tablaInfracciones)
            if (x.get_codigo() == aux.get_cod_multa())
                aux.set_multa(x.get_multa());
        for (auto &x: vectorEmpresas) {
            if (x.placaPresente(aux.get_placa())) {
                x.ingresarMultasRecibidas(aux);
                bandera = true;
                break;
            }
        }
        if (not bandera) while (arch.get() != '\n');
    }
}

void MinisterioDeTransporte::reporteDeEmpresasConInfracciones(const char *nomb) {
    ofstream arch;
    apertura_archivos_salida(arch, nomb);
    arch << fixed << setprecision(2);
    imprimir_linea(arch,TAM_LINEA, '=');
    arch << setw(60) << "RELACIÓN DE EMPRESAS CON INFRACCIONES DE TRANSITO" << endl;
    for (auto &x: vectorEmpresas) {
        imprimir_linea(arch,TAM_LINEA, '-');

        x.imprimir(arch);
    }
}

void MinisterioDeTransporte::eliminaInfraccionesPagadas() {
    for (auto &x: vectorEmpresas) {
        x.elimminar();
    }
}
