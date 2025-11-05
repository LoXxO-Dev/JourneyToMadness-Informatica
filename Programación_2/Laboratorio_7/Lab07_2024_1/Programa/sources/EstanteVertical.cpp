//
// Created by User on 3/11/2025.
//

#include "EstanteVertical.hpp"

void EstanteVertical::leer(ifstream &archivo) {
    Estante::leer(archivo);
}

bool EstanteVertical::posicionarEnciclopedias(Enciclopedia enci) {
    int espaciosSobrantes;
    int alto = get_altura();
    if (alto < enci.get_alto()) return false;

    espaciosSobrantes = obtenerEspaciosRestantes(get_anchura());
    if (espaciosSobrantes >= enci.get_ancho() and get_peso_soportado() >= get_peso_actual() + enci.get_peso()) {
        this->enciclopedias[cantidad_enciclopedias++] = enci;
        set_peso_actual(get_peso_actual() + enci.get_peso());
        pintar(enci.get_alto(), enci.get_ancho(), espaciosSobrantes);
        return true;
    } else return false;
}
void EstanteVertical::imprimir(ofstream &arch) {
    Estante::imprimir(arch,cantidad_enciclopedias,false);
    arch<<setw(20)<<"CODIGO"<<setw(35)<<"NOMBRE"<<setw(10)<<"ANCHO"<<setw(10)<<"ALTO"<<"PESO"<<endl;
    imprimirLinea(arch,TAM_LINEA,'-');
    for (int i=0;i<cantidad_enciclopedias;i++) {
        enciclopedias[i].imprimir(arch);

    }
    imprimirLinea(arch,TAM_LINEA,'-');
}
int EstanteVertical::obtenerEspaciosRestantes(int anchura) {
    int resultado = anchura;
    for (int i = 0; i < cantidad_enciclopedias; i++) {
        resultado -= enciclopedias[i].get_ancho();
    }
    return resultado;
}

void EstanteVertical::operator=(const class EstanteVertical &esta) {
    cantidad_enciclopedias = esta.cantidad_enciclopedias;
}

int EstanteVertical::get_cantidad_enciclopedias() const {
    return cantidad_enciclopedias;
}

void EstanteVertical::set_cantidad_enciclopedias(int cantidad_enciclopedias) {
    this->cantidad_enciclopedias = cantidad_enciclopedias;
}

void operator>>(ifstream &arch, EstanteVertical &esta) {
    esta.leer(arch);
}
