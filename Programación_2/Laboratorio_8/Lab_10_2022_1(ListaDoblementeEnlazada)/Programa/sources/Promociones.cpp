//
// Created by User on 20/11/2025.
//

#include "Promociones.hpp"

void Promociones::leepedidos() {
    ifstream arch;
    apertura_archivos_entrada(arch, "data/pedidos.csv");

    int codigo;

    while (true) {
        arch >> codigo;
        if (arch.eof()) break;
        Lpedidos.leer(codigo,arch);
    }
}
//     33713901,06/06/2019
// 57263719,01/10/2020
void Promociones::actualizapedidos() {
    ifstream arch;
    apertura_archivos_entrada(arch, "data/promocion.csv");
    int dni,fecha,dd,mm,aa;
    char car;
    while (true) {
        arch >> dni;
        if (arch.eof()) break;
        arch>>car>>dd>>car>>mm>>car>>aa;
        fecha=aa*10000+mm*100+dd;
        Lpedidos.actualizar(dni,fecha);
    }

}

void Promociones::imprimepedidos() {
    ofstream arch;
    apertura_archivos_salida(arch, "reporte/Reportes.txt");
    arch<<setw(60)<<"REPORTE DE PROMOCIONES"<<endl;
    imprimir_linea(arch,TAM_LINEA,'=');
    arch<<fixed<<setprecision(2);
    Lpedidos.imprimir(arch);
}
