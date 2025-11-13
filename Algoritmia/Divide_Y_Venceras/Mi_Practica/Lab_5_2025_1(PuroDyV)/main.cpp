#include <iostream>
#include <iomanip>
using namespace std;


int buscarPico(int *arr, int ini, int fin) {
    if (ini == fin)return ini;
    int medio = (ini + fin) / 2;
    if (arr[medio] < arr[medio + 1])
        return buscarPico(arr, medio + 1, fin);
    else return buscarPico(arr, ini, medio);
}

int buscarSuperacion(int *arr, int ini, int fin, int dato) {
    int medio = (ini + fin) / 2;
    if (arr[ini] > dato)return ini;
    else {
        if (arr[medio] < dato)
            return buscarSuperacion(arr, medio + 1, fin, dato);
        else return buscarSuperacion(arr, ini, medio, dato);
    }
}

void merge(int *arr, int ini, int medio, int fin) {
    int size = fin - ini + 1;
    int aux[size];
    for (int i = 0; i < size; i++) {
        aux[i] = arr[ini + i];
    }
    int izq = 0;
    int dere = medio - ini + 1;
    for (int i = 0; i < size; i++) {
        if (izq <= medio - ini ) {
            if (dere <= fin - ini ) {
                if (aux[dere] < aux[izq]) {
                    arr[ini + i] = aux[izq++];
                } else
                    arr[ini + i] = aux[dere++];
            } else
                arr[ini + i] = aux[izq++];
        } else
            arr[ini + i] = aux[dere++];
    }
}

void mergeSort(int *arr, int ini, int fin) {
    if (ini == fin)return ;
    int medio = (ini + fin) / 2;
    mergeSort(arr, ini, medio);
    mergeSort(arr, medio + 1, fin);
    merge(arr, ini, medio, fin);
}
int cuentaCeros(int *arr,int ini,int fin,int contador) {
    if (ini>fin)return contador;
    int medio=(fin+ini)/2;
    if (arr[medio]==0)
        return cuentaCeros(arr,ini,medio-1,contador+fin-medio+1);
    else return cuentaCeros(arr,medio+1,fin,contador);
}
int cuentaUnos(int *arr,int ini,int fin,int contador) {
    if (ini>fin)return contador;
    int medio=(ini+fin)/2;
    if (arr[medio]==2)
        return cuentaUnos(arr,medio+1,fin,contador);
    else return  cuentaUnos(arr,ini,medio-1,contador+fin-medio+1);

}
int main() {
    //Pregunta 1

    //Ejemplo 1
    int arreglo1[]{20, 50, 80, 120, 200, 150, 90};
    int n1 = sizeof(arreglo1) / sizeof(arreglo1[0]);
    int pospico = buscarPico(arreglo1, 0, n1 - 1);
    cout << "Pico de ventas_original " << pospico + 1 << " - valor " << arreglo1[pospico] << endl;
    int arreglo1_nuevo[]{10, 20, 30, 80, 150, 220, 250, 256, 300};
    int n1_nuevo = sizeof(arreglo1_nuevo) / sizeof(arreglo1_nuevo[0]);
    int poSupera = buscarSuperacion(arreglo1_nuevo, 0, n1_nuevo - 1, arreglo1[pospico]);
    cout << "Primer día de ventas_nueva que supera el pico " << poSupera + 1 <<
            " - valor " << arreglo1_nuevo[poSupera] << endl;

    //Ejemplo 2

    int arreglo1_2[]{50, 80, 120, 160, 210, 180, 140};
    int n1_2 = sizeof(arreglo1_2) / sizeof(arreglo1_2[0]);
    int pospico_2 = buscarPico(arreglo1_2, 0, n1_2 - 1);
    cout << "Pico de ventas_original " << pospico_2 + 1 << " - valor " << arreglo1_2[pospico_2] << endl;
    int arreglo1_nuevo_2[]{300, 380, 450, 570, 620, 740, 860};
    int n1_nuevo_2 = sizeof(arreglo1_nuevo_2) / sizeof(arreglo1_nuevo_2[0]);
    int poSupera_2 = buscarSuperacion(arreglo1_nuevo_2, 0, n1_nuevo_2 - 1, arreglo1_2[pospico_2]);
    cout << "Primer día de ventas_nueva que supera el pico " << poSupera_2 + 1 <<
            " - valor " << arreglo1_nuevo_2[poSupera_2] << endl;

    cout << endl;
    //Pregunta 2
    int M = 6, N = 8;
    double P = 0.7;
    //el 1 representa los Productos Correctos
    //el 2 representa los Productos Faltantes
    //el 0 representa los espacios en blanco que existe
    int matriz[M][N]{
        {2, 2, 2, 1, 1, 2, 0, 0},
        {1, 2, 1, 1, 1, 2, 1, 2},
        {2, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 2, 1, 0},
        {1, 2, 2, 2, 2, 1, 0, 0},
        {1, 1, 2, 1, 2, 1, 1, 0},
    };
    int n = sizeof(matriz[0]) / sizeof(int);
    cout<<left<<setw(10)<<"Lote"<<"Estado"<<endl;
    for (int i = 0; i < M; i++) {
        mergeSort(matriz[i], 0, n - 1);
        int cantCeros=cuentaCeros(matriz[i],0,n-1,0);
        int cantUnos=cuentaUnos(matriz[i],0,n-1-cantCeros,0);
        double resultado=cantUnos*1.0/(n-cantCeros);
        cout<<left<<setw(10)<<i+1;
        if (resultado>P)
            cout<<"Aprobado"<<endl;
        else cout<<"Rechazado"<<endl;
    }

    return 0;
}
