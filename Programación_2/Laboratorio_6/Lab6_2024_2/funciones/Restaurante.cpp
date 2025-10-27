//
// Created by User on 5/10/2025.
//

#include "Restaurante.hpp"

Restaurante::Restaurante() {
    clientes = nullptr;
    cantidadDeClientes = 0;
    capacidadDeClientes = 0;
    platos = nullptr;
    cantidadPlatos = 0;
    capacidadPlatos = 0;
}

void Restaurante::operator <(const char *nombArc) {
    ifstream archivo(nombArc, ios::in);
    if (not archivo) {
        cout << "ERROR:no se pudo abrir el archivo con nombre " << nombArc << endl;
        exit(1);
    }
    class Cliente clie;
    while (true) {
        archivo >> clie;
        if (archivo.eof()) break;
        if (capacidadDeClientes == cantidadDeClientes) aumentarEspacios();
        clientes[cantidadDeClientes] = clie;
        cantidadDeClientes++;
    }
}

void Restaurante::operator <=(const char *nombArc) {
    ifstream archivo(nombArc, ios::in);
    if (not archivo) {
        cout << "ERROR:no se pudo abrir el archivo con nombre " << nombArc << endl;
        exit(1);
    }
    class Plato plat;
    while (true) {
        archivo >> plat;
        if (archivo.eof()) break;
        if (cantidadPlatos == capacidadPlatos) aumentarEspaciosPlatos();
        platos[cantidadPlatos] = plat;
        cantidadPlatos++;
    }
}

void Restaurante::operator <<=(const char *nombArc) {
    ifstream archivo(nombArc, ios::in);
    if (not archivo) {
        cout << "ERROR:no se pudo abrir el archivo con nombre " << nombArc << endl;
        exit(1);
    }
    int codPedido, dni;
    char car;
    while (true) {
        archivo >> codPedido;
        if (archivo.eof()) break;
        archivo >> car >> dni >> car;
        int posCliente = buscarCliente(dni);
        if (posCliente != -1) {
            leerPlatosYAgregar(posCliente, archivo);
        }
    }
}

void Restaurante::leerPlatosYAgregar(int posCliente, ifstream &archivo) {
    int cantidad, posPlato;
    char plato[11];
    while (true) {
        archivo.getline(plato, 11, ',');
        archivo >> cantidad;
        posPlato = buscarPlato(plato);
        if (posPlato != -1) {
            this->platos[posPlato].agregarTotal(cantidad, clientes[posCliente].get_descuento());
            this->clientes[posCliente].agregarSubTotal(cantidad, platos[posPlato].get_descuento(),
                                                       platos[posPlato].get_precio());
        }
        if (archivo.get() == '\n')
            break;
    }
}

int Restaurante::buscarPlato(char *plato) {
    for (int i = 0; i < this->cantidadPlatos; i++) {
        if (platos[i].posPlato(plato))
            return i;
    }
    return -1;
}

void Restaurante::operator >>(const char *nombArc) {
    ofstream arch(nombArc, ios::out);
    if (not arch.is_open()) {
        cout << "ERROR:No se pudo abrir el archivo con nombre " << nombArc << endl;
        exit(1);
    }
    arch << fixed << setprecision(2);
    imprimirPlato(arch);
    imprimirClientes(arch);
}

void Restaurante::imprimirPlato(ofstream &arch) {
    arch<<setw(100)<<"RESTAURANTE 1INF25"<<endl<<setw(100)<<"VENTAS DEL DIAS"<<endl;;
    imprimirLina(arch,'=',CANTCARPLATOS);
    arch<<setw(110)<<"RELACIÓN DE PLATOS VENDIDOS"<<endl;
    imprimirLina(arch,'-',CANTCARPLATOS);
    arch<<right<<setw(150)<<"PLATO"<<setw(30)<<"TOTAL"<<endl;
    arch<<left<<setw(8)<<"No."<<setw(13)<<"CODIGO"<<setw(55)<<"NOMBRE"<<setw(10)<<"PRECIO"<<
        setw(20)<<"CATEGORIA"<<setw(15)<<"DESCUENTO"<<setw(15)<<"PREPARADOS"<<setw(15)<<"ATENDIDOS"<<
            setw(15)<<"NO ATENDIDO"<<setw(13)<<"ESPERADO"<<setw(13)<<"BRUTO"<<setw(5)<<"NETO"<<endl;
    imprimirLina(arch,'-',CANTCARPLATOS);


    for (int i=0;i<cantidadPlatos;i++) {
        arch<<right<<setw(4)<<i+1<<")";
       arch<<platos[i];
    }

}

void Restaurante::imprimirClientes(ofstream &arch) {
    imprimirLina(arch, '=', CANTCAR);
    arch << setw(70) << "RELACION DE CLIENTES VENDIDOS" << endl;
    imprimirLina(arch, '-', CANTCAR);
    arch << endl << left << setw(5) << "No." << setw(15) << "DNI" << setw(50) <<
            "NOMBRE" << setw(30) << "DISTRITO" << setw(15) << "DESCUENTO" << "TOTAL PAGADO" << endl;
    imprimirLina(arch, '-', CANTCAR);

    for (int i = 0; i < cantidadDeClientes; i++) {
        arch << right << setw(3) << i + 1 << ")";
        arch << clientes[i];
    }
    imprimirLina(arch, '=', CANTCAR);
}

void Restaurante::imprimirLina(ofstream &arch, char car, int cant) {
    for (int i = 0; i < cant; i++)
        arch.put(car);
    arch << endl;
}

int Restaurante::buscarCliente(int dni) {
    for (int i = 0; i < this->cantidadDeClientes; i++) {
        if (clientes[i].posCliente(dni))
            return i;
    }
    return -1;
}

void Restaurante::aumentarEspaciosPlatos() {
    Plato *aux;
    this->capacidadPlatos += AUMENTO;
    if (this->platos == nullptr) {
        platos = new Plato[this->capacidadPlatos]{};
    } else {
        aux = new Plato[this->capacidadPlatos]{};
        for (int i = 0; i < cantidadPlatos; i++)
            aux[i] = platos[i];
        delete [] platos;
        platos = aux;
    }
}

void Restaurante::aumentarEspacios() {
    Cliente *aux;
    this->capacidadDeClientes += AUMENTO;
    if (this->clientes == nullptr) {
        clientes = new Cliente[this->capacidadDeClientes]{};
    } else {
        aux = new Cliente[this->capacidadDeClientes]{};
        for (int i = 0; i < cantidadDeClientes; i++)
            aux[i] = clientes[i];
        delete [] clientes;
        clientes = aux;
    }
}

int Restaurante::get_cantidad_de_clientes() const {
    return cantidadDeClientes;
}

void Restaurante::set_cantidad_de_clientes(int cantidad_de_clientes) {
    cantidadDeClientes = cantidad_de_clientes;
}

int Restaurante::get_capacidad_de_clientes() const {
    return capacidadDeClientes;
}

void Restaurante::set_capacidad_de_clientes(int capacidad_de_clientes) {
    capacidadDeClientes = capacidad_de_clientes;
}

int Restaurante::get_cantidad_platos() const {
    return cantidadPlatos;
}

void Restaurante::set_cantidad_platos(int cantidad_platos) {
    cantidadPlatos = cantidad_platos;
}

int Restaurante::get_capacidad_platos() const {
    return capacidadPlatos;
}

void Restaurante::set_capacidad_platos(int capacidad_platos) {
    capacidadPlatos = capacidad_platos;
}
