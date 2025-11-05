//
// Created by User on 3/11/2025.
//

#include "EstanteHorizontal.hpp"


EstanteHorizontal::EstanteHorizontal() {
    cantidad_novelas=0;
}

void EstanteHorizontal::imprimir(ofstream &arch) {
    Estante::imprimir(arch,cantidad_novelas,true);
    arch<<setw(20)<<"CODIGO"<<setw(35)<<"NOMBRE"<<setw(10)<<"ANCHO"<<setw(10)<<"ALTO"<<"PESO"<<endl;
    imprimirLinea(arch,TAM_LINEA,'-');
    for (int i=0;i<cantidad_novelas;i++) {
       novelas[i].imprimir(arch);

    }
    imprimirLinea(arch,TAM_LINEA,'-');
}

bool EstanteHorizontal::posicionarNovelas(Novela nove) {
    int espaciosSobrantes;
    int alto = get_altura();
    if (alto < nove.get_alto()) return false;

    espaciosSobrantes = obtenerEspaciosRestantes(get_anchura());
    if (espaciosSobrantes >= nove.get_ancho() and get_peso_soportado() >= get_peso_actual() + nove.get_peso()) {
        this->novelas[cantidad_novelas++] = nove;
        set_peso_actual(nove.get_peso()+get_peso_actual());
        pintar(nove.get_alto(),nove.get_ancho(),espaciosSobrantes);
        return true;
    } else return false;
}


int EstanteHorizontal::obtenerEspaciosRestantes(int anchura) {
    int resultado = anchura;
    for (int i = 0; i < cantidad_novelas; i++) {
        resultado -= novelas[i].get_ancho();
    }
    return resultado;
}

void EstanteHorizontal::operator=(const EstanteHorizontal &orig) {
    this->cantidad_novelas=orig.cantidad_novelas;
}

void EstanteHorizontal::leer(ifstream &archivo) {
    Estante::leer(archivo);
    cantidad_novelas=0;
}

int EstanteHorizontal::get_cantidad_novelas() const {
    return cantidad_novelas;
}

void EstanteHorizontal::set_cantidad_novelas(int cantidad_novelas) {
    this->cantidad_novelas = cantidad_novelas;
}

void operator>>(ifstream &arch, EstanteHorizontal &estantehorizontal) {
    estantehorizontal.leer(arch);
}
