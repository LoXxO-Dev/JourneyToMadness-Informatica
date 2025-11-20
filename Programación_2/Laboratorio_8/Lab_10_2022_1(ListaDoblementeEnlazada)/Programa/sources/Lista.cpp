//
// Created by User on 20/11/2025.
//

#include "Lista.hpp"

#include "Nodo.hpp"
#include "PedidoEspecial.hpp"
#include "PedidoEventual.hpp"
#include "PedidoUsual.hpp"
Lista::Lista() {
    lfin=nullptr;
    lini=nullptr;
}

void Lista::leer(int codigo, ifstream &arch) {
    class Pedido *ptr;
    arch.get();
    if (codigo <400000)
        ptr=new class PedidoEspecial();
    else if (codigo >=400000 and codigo <600000)
        ptr=new class PedidoUsual();
    else if (codigo >=600000 )
        ptr=new class PedidoEventual();
    ptr->set_codigo(codigo);
    ptr->lee(arch);
    insertar(ptr);


}

void Lista::insertar(class Pedido *dato) {
    class Nodo *nuevo,*anterior=nullptr,*recorrido=lini;
    nuevo=new Nodo();
    nuevo->ped=dato;

    while(recorrido) {
        if (recorrido->ped->get_dni()>dato->get_dni() or
            recorrido->ped->get_dni()==dato->get_dni() and
            recorrido->ped->get_fecha()==dato->get_fecha()) break;
        anterior=recorrido;
        recorrido=recorrido->sig;
    }
    nuevo->sig=recorrido;
    nuevo->ant=anterior;


    if (recorrido) {
        recorrido->ant=nuevo;
    }else {
        lfin=nuevo;
    }
    if (anterior) anterior->sig=nuevo;
    else lini=nuevo;
}

void Lista::imprimir(ofstream &arch) {
    class Nodo *recorrido=lini;
    arch<<endl;
    while(recorrido) {
        recorrido->ped->imprimir(arch);
        recorrido=recorrido->sig;
    }


}

void Lista::actualizar(int dni, int fecha) {
    class Nodo *recorrido=lfin;
    while(recorrido) {
        if (dni==recorrido->ped->get_dni() )
            recorrido->ped->actualiza(fecha);
        recorrido=recorrido->ant;
    }
}
