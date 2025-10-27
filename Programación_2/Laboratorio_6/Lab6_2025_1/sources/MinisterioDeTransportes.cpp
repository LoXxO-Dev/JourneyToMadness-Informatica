//
// Created by User on 1/10/2025.
//

#include "MinisterioDeTransportes.hpp"
#define TAM_CAR 200

MinisterioDeTransportes::MinisterioDeTransportes() {
    this->infracciones = nullptr;
}

MinisterioDeTransportes::~MinisterioDeTransportes() {
    if (this->infracciones != nullptr)delete []this->infracciones;
}

int MinisterioDeTransportes::get_num_inf() const {
    return numInf;
}

void MinisterioDeTransportes::set_num_inf(int num_inf) {
    numInf = num_inf;
}

int MinisterioDeTransportes::get_num_emp() const {
    return numEmp;
}

void MinisterioDeTransportes::set_num_emp(int num_emp) {
    numEmp = num_emp;
}

void MinisterioDeTransportes::operator <(const char *nomb) {
    ifstream archivo(nomb, ios::in);
    if (not archivo.is_open()) {
        cout << "GG";
        exit(1);
    }
    numInf = 0;
    class Infraccion infra;
    int cap = 0;
    while (true) {
        archivo >> infra;
        if (archivo.eof()) break;
        if (cap == numInf)incrementarEspacios(infracciones, cap, numInf);
        infracciones[numInf - 1] = infra;
        numInf++;
    }
}

void MinisterioDeTransportes::incrementarEspacios(Infraccion *&arreglo, int &cap, int &numInf) {
    Infraccion *aux;
    cap += 5;
    if (arreglo == nullptr) {
        arreglo = new Infraccion[cap]{};
        numInf = 1;
    } else {
        aux = new Infraccion[cap]{};
        for (int i = 0; i < numInf; i++) {
            aux[i] = arreglo[i];
        }
        delete [] arreglo;
        arreglo = aux;
    }
}

void MinisterioDeTransportes::operator <=(const char *nomb) {
    ifstream archivo(nomb, ios::in);
    if (not archivo.is_open()) {
        cout << "GG";
        exit(1);
    }
    numEmp = 0;
    class Empresa empre;
    while (true) {
        archivo >> empre;
        if (archivo.eof()) break;
        empresas[numEmp] = empre;
        numEmp++;
    }
}

void MinisterioDeTransportes::operator <<=(const char *nomb) {
    ifstream archivo(nomb, ios::in);
    if (not archivo.is_open()) {
        cout << "GG";
        exit(1);
    }
    class Multa infraccionCometida;
    int codigo, posInfra, posEmpresa;
    char placa[10];
    while (true) {
        archivo >> infraccionCometida;

        if (archivo.eof())break;
        codigo = infraccionCometida.get_codigo_infraccion();
        posInfra = buscarCodigo(codigo, this->infracciones, numInf);
        infraccionCometida.get_placa(placa);
        posEmpresa = buscarEmpresa(placa, this->empresas, numEmp);
        if (posInfra != -1 and posEmpresa != -1) {
            infraccionCometida.set_multa(this->infracciones[posInfra].get_multa());
               this->empresas[posEmpresa]+=infraccionCometida;
        } else cout << "GG";
    }
    //3/2/2022,M832-314,1008
    //5/10/2024,M907-605,1002,P,24/10/2024
}

int MinisterioDeTransportes::buscarEmpresa(char *placa, class Empresa *empre, int numEmp) {

    for (int i = 0; i < numEmp; i++) {
        if (empre[i].placaPresenteEnEmpresa(placa))
            return i;
    }
    return -1;
}
// bool MinisterioDeTransportes::placaPresenteEnEmpresa( class Empresa empre,char *placa) {
//     for (int i = 0; i < empre.get_num_placas(); i++) {
//         char aux[10];
//         empre.getPlacaI(aux, i);
//         cout<<placa<<" "<<aux<<endl;
//
//         if (strcmp(aux, placa) == 0)
//             return true;
//     }
//     return false;
// }


int MinisterioDeTransportes::buscarCodigo(int codigo, class Infraccion *infracciones, int cant) {
    for (int i = 0; i < cant; i++) {
        if (codigo ==infracciones[i].get_codigo())
            return i;
    }
    return -1;
}

void MinisterioDeTransportes::operator <<(const char *nomb) {
    ofstream archivo(nomb, ios::out);
    if (not archivo.is_open()) {
        cout << "GG";
        exit(1);
    }
    archivo << fixed << setprecision(2);
    archivo << setw(100) << "MINISTERIO DE TRANSPORTE" << endl;
    imprimeCar(archivo, '=',TAM_CAR);
    archivo << setw(100) << "TABLA DE INFRACCIONES" << endl;
    imprimeCar(archivo, '-',TAM_CAR);
    archivo << left << setw(10) << " " << setw(10) << "CODIGO" << setw(20) << "MULTA"
            << setw(20) << "GRAVEDAD" << setw(15) << "DESCRIPCION" << endl;
    imprimeCar(archivo, '-',TAM_CAR);
    for (int i = 0; i < numInf; i++)
        archivo << this->infracciones[i];
    imprimirEmpresasYMultas(archivo);
}

void MinisterioDeTransportes::imprimirEmpresasYMultas(ofstream &archivo) {
    imprimeCar(archivo, '=',TAM_CAR);
    archivo << right << setw(100) << "RELACION DE EMPRESAS CON INFRACCIONES DE TRANSITO" << endl;
    imprimeCar(archivo, '-',TAM_CAR);
    archivo << left << setw(10) << " " << setw(10) << "DNI" << setw(40) << "NOMBRE"
            << setw(20) << "PLACAS DE SUS VEHICULOAS" << endl;
    imprimeCar(archivo, '-',TAM_CAR);
    for (int i = 0; i < this->numEmp; i++) {
        archivo << empresas[i];
    }
}

void MinisterioDeTransportes::imprimeCar(ofstream &archivo, char car, int cant) {
    for (int i = 0; i < cant; i++) {
        archivo << car;
    }
    archivo << endl;
}
