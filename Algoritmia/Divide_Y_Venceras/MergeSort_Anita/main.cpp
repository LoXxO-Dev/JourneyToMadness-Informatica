#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;

void imprimir(int *arreglo, int n) {
    for (int i = 0; i < n; i++) {
        cout << setw(5) << arreglo[i];
    }
    cout<<endl;
}

void merge(int *arreglo, int ini, int medio, int fin) {
    int size = fin - ini + 1;
    int aux[size];
    for (int i = 0; i < size; i++)
        aux[i] = arreglo[ini + i];
    int izq = 0;
    int dere = medio - ini + 1;
    for (int indice = 0; indice < size; indice++) {
        if (izq <=( medio - ini)) {
            if (dere <= (fin - ini)) {
                if (aux[izq] < aux[dere]) {
                    arreglo[indice + ini] = aux[izq++];
                } else
                    arreglo[indice + ini] = aux[dere++];
            } else
                arreglo[indice + ini] = aux[izq++];
        } else
            arreglo[indice + ini] = aux[dere++];
    }
}

void mergeSort(int *arreglo, int ini, int fin) {
    if (ini ==fin)
        return;
    int medio = (ini + fin) / 2;
    mergeSort(arreglo, ini, medio);
    mergeSort(arreglo, medio + 1, fin);
    merge(arreglo, ini, medio, fin);
}

int main() {
    int arreglo[]{15, 1, 25, 26, 38, 98, 74, 52, 6, 2, 45, 22, 36, 19};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);
    imprimir(arreglo, n);
    mergeSort(arreglo, 0, n - 1);
    imprimir(arreglo, n);
    return 0;
}
