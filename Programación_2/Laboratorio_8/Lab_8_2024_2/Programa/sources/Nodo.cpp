//
// Created by User on 11/11/2025.
//

#include "Nodo.hpp"

Nodo::Nodo() {
    sig=nullptr;
}

Nodo::~Nodo() {
    if (sig!=nullptr)sig=nullptr;
}
