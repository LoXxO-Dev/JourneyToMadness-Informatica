//
// Created by User on 27/10/2025.
//

#include "MinisterioDeTransporte.hpp"

MinisterioDeTransporte::MinisterioDeTransporte() {
    this->infracciones = nullptr;
    numInf = 0;
    numEmp = 0;
}

MinisterioDeTransporte::~MinisterioDeTransporte() {
    if (this->infracciones != nullptr)delete [] this->infracciones;
}

void MinisterioDeTransporte::operator >>(const char *nomArc) {
    ofstream archivo(nomArc, ios::out);
    if (not archivo) {
        cout << "ERROR:No se pudo abrir el archivo " << nomArc << endl;
        exit(1);
    }
    archivo << fixed << setprecision(2);
    archivo << setw(80) << "MINISTERIO DE TRANSPORTE" << endl;
    imprimirLinea(archivo,TAM_LINEA, '=');
    archivo << setw(80) << "TABLA DE INFRACCIONES" << endl;
    imprimirLinea(archivo,TAM_LINEA, '-');
    archivo << setw(5) << " " << left << setw(15) << "CODIGO" << setw(10) << "MULTA" <<
            setw(20) << "GRAVEDAD" << setw(20) << "DESCRIPCION" << endl;
    imprimirLinea(archivo,TAM_LINEA, '-');

    for (int i = 0; i < numInf; i++)
        archivo << infracciones[i];
    imprimirEmpresas(archivo);
    imprimirLinea(archivo,TAM_LINEA, '=');
}

void MinisterioDeTransporte::imprimirEmpresas(ofstream &arch) {
    imprimirLinea(arch,TAM_LINEA, '=');
    arch <<right<< setw(100) << "RELACION DE EMPRESAS CON INFRACCIONES DE TRANSITO" << endl;
    imprimirLinea(arch,TAM_LINEA, '-');
    arch<<setw(5)<<" "<<left<<setw(15)<<"CODIGO"<<setw(30)<<"NOMBRE"<<"PLACAS DE LOS VEHICULOS"<<endl;
    imprimirLinea(arch,TAM_LINEA,'-');
    for (int i=0;i<numEmp;i++)
        arch<<empresas[i];
}

void MinisterioDeTransporte::imprimirLinea(ofstream &arch, int cant, char car) {
    for (int i = 0; i < cant; i++)
        arch.put(car);
    arch << endl;
}

void MinisterioDeTransporte::operator <<=(const char *nomArc) {
    ifstream archivo(nomArc, ios::in);
    if (not archivo) {
        cout << "ERROR:No se pudo abrir el archivo " << nomArc << endl;
        exit(1);
    }
    int codigo, posInfra, posEmp;
    char placa[100];
    while (true) {
        Multa multa;
        archivo >> multa;
        if (archivo.eof()) break;
        codigo = multa.get_codigo_infraccion();
        multa.get_placa(placa);
        posInfra = buscarInfra(codigo);
        posEmp = buscarEmpresas(placa);
        if (posEmp != -1 and posInfra != -1) {
            multa.set_multa(infracciones[posInfra].get_multa());
            empresas[posEmp] += multa;
        }
    }
}

int MinisterioDeTransporte::buscarInfra(int codigo) {
    for (int i = 0; i < numInf; i++) {
        if (this->infracciones[i].get_codigo() == codigo) return i;
    }
    return -1;
}

int MinisterioDeTransporte::buscarEmpresas(char *placa) {
    for (int i = 0; i < numEmp; i++) {
        char aux[100];
        for (int j = 0; j < empresas[i].get_num_placas(); j++) {
            empresas[i].getPlacaI(aux, j);
            if (strcmp(placa, aux) == 0) return i;
        }
    }
    return -1;
}


void MinisterioDeTransporte::operator <=(const char *nomArc) {
    ifstream archivo(nomArc, ios::in);
    if (not archivo) {
        cout << "ERROR:No se pudo abrir el archivo " << nomArc << endl;
        exit(1);
    }
    while (true) {
        Empresa empre;
        archivo >> empre;
        if (archivo.eof()) break;
        this->empresas[numEmp] = empre;
        numEmp++;
    }
}

void MinisterioDeTransporte::operator <(const char *nomArc) {
    ifstream archivo(nomArc, ios::in);
    if (not archivo) {
        cout << "ERROR:No se pudo abrir el archivo " << nomArc << endl;
        exit(1);
    }
    int cap = 0;
    while (true) {
        Infraccion infra;
        archivo >> infra;
        if (archivo.eof()) break;
        if (cap == numInf)incrementarEspacios(cap);
        this->infracciones[numInf] = infra;
        numInf++;
    }
}

void MinisterioDeTransporte::incrementarEspacios(int &cap) {
    Infraccion *aux;
    cap += INCREMENTO;
    if (this->infracciones == nullptr) {
        infracciones = new Infraccion[cap]{};
    } else {
        aux = new Infraccion[cap]{};
        for (int i = 0; i < numInf; i++) {
            aux[i] = this->infracciones[i];
        }
        delete [] this->infracciones;
        this->infracciones = aux;
    }
}

int MinisterioDeTransporte::get_num_inf() const {
    return numInf;
}

void MinisterioDeTransporte::set_num_inf(int num_inf) {
    numInf = num_inf;
}

int MinisterioDeTransporte::get_num_emp() const {
    return numEmp;
}

void MinisterioDeTransporte::set_num_emp(int num_emp) {
    numEmp = num_emp;
}
