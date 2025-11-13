#include <iostream>
#include <iomanip>
using namespace std;

int buscarSolo(int *arr, int ini, int fin) {
    if (ini == fin)return arr[ini];
    int medio = (ini + fin) / 2;
    if (medio % 2 != 0)medio--;
    if (arr[medio] == arr[medio + 1])
        return buscarSolo(arr, medio + 2, fin);
    else return buscarSolo(arr, ini, medio);
}

int cuentaCeros(int *arr, int ini, int fin, int contador) {
    if (ini > fin)return contador;
    int medio = (ini + fin) / 2;
    if (arr[medio] == 1)
        return cuentaCeros(arr, medio + 1, fin, contador);
    else {
        return cuentaCeros(arr, ini, medio - 1, contador + (fin - medio + 1));
    }
}

int encontrarRotado(int *arreglo, int inicio, int fin) {
    if (inicio == fin) return arreglo[inicio];
    int med = (inicio + fin) / 2;
    if (arreglo[med] > arreglo[fin])
        return encontrarRotado(arreglo, med + 1, fin);
    else
        return encontrarRotado(arreglo, inicio, med);
}

//5,6,1,2,3,4
int maximo(int a, int b) {
    return a > b ? a : b;
}

int mergeMaxSuma(int *arr, int ini, int med, int fin) {
    int suma = 0;
    int sumaizq = -99, sumaDer = -99;
    bool primero = 1;
    for (int i = med; i >= ini; i--) {
        suma += arr[i];
        if (suma > sumaizq or primero) {
            sumaizq = suma;
            primero = false;
        } else break;
    }
    suma = 0;
    primero = 1;
    for (int i = med + 1; i <= fin; i++) {
        suma += arr[i];
        if (suma > sumaDer or primero) {
            sumaDer = suma;
            primero = false;
        } else break;
    }
    return maximo(sumaDer, max(sumaizq, sumaizq + sumaDer));
}

//    int arreglo5[]{-2, -5, 6, -2, -3, 1, 5, -6};


int sumaMaximaContigua(int *arr, int ini, int fin) {
    if (ini == fin)return arr[ini];
    int med = (ini + fin) / 2;
    int sumIza = sumaMaximaContigua(arr, ini, med);
    int sumDer = sumaMaximaContigua(arr, med + 1, fin);
    int sumMed = mergeMaxSuma(arr, ini, med, fin);
    //cout<<sumIza<<" "<<sumDer<<" "<<sumMed<<endl;
    return maximo(sumIza, max(sumDer, sumMed));
}

int buscaMontana(int *arr, int ini, int fin) {
    if (ini == fin)return arr[ini];
    int medio = (ini + fin) / 2;
    if (arr[medio] < arr[medio + 1])
        return buscaMontana(arr, medio + 1, fin);
    else return buscaMontana(arr, ini, medio);
}

int mergeInversiones(int *arr, int ini, int medio, int fin) {
    int cantIzq=0,cantDer=0;
    for (int i=medio;i>ini;i--) {
        if (arr[i]<arr[i-1])
            cantIzq++;
        else break;
    }
    for (int i=medio+1;i<fin;i++) {
        if (arr[i]>arr[i+1])
            cantDer++;
        else break;
    }
    return cantIzq+cantDer;
}

int contarInversiones(int *arr, int ini, int fin) {
    if (ini == fin)return 0;
    int medio = (ini + fin) / 2;
    int cantIzq = contarInversiones(arr, ini, medio);
    int cantDer = contarInversiones(arr, medio + 1, fin);
    int cantCentr = mergeInversiones(arr, ini, medio, fin);
    return cantCentr+cantDer+cantIzq;
}





int main() {
    //Ejercicio 1
    int arreglo1[]{1, 1, 3, 3, 4, 4, 5, 5, 7, 8, 8};
    int n1 = sizeof(arreglo1) / sizeof(arreglo1[0]);
    cout << buscarSolo(arreglo1, 0, n1 - 1) << endl;

    //Ejercicio 2
    int arreglo2[]{0, 0, 0, 0, 0, 0};
    int n2 = sizeof(arreglo2) / sizeof(arreglo2[0]);
    cout << cuentaCeros(arreglo2, 0, n2 - 1, 0) << endl;


    int arreglo3[]{1, 1, 1, 1, 1};
    int n3 = sizeof(arreglo3) / sizeof(arreglo3[0]);
    cout << cuentaCeros(arreglo3, 0, n3 - 3, 0) << endl;

    //Ejercicio 3
    int arreglo4[]{6, 1, 2, 3, 4, 5};
    int n4 = sizeof(arreglo4) / sizeof(arreglo4[0]);
    cout << "Rotado: " << encontrarRotado(arreglo4, 0, n4 - 1) << endl;

    //Ejercicio 4
    int arreglo5[]{-2, -5, 6, -2, -3, 1, 5, -6};
    int n5 = sizeof(arreglo5) / sizeof(arreglo5[0]);
    cout << "Suma MaX: " << sumaMaximaContigua(arreglo5, 0, n5 - 1) << endl;


    //Ejercicio 5
    int arreglo6[]{8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
    int n6 = sizeof(arreglo6) / sizeof(arreglo6[0]);
    cout << buscaMontana(arreglo6, 0, n6 - 1) << endl;


    //Ejercicio 6
    int arreglo7[]{3, 8, 4, 2, 1};
    int n7 = sizeof(arreglo7) / sizeof(arreglo7[0]);
    cout << contarInversiones(arreglo7, 0, n7 - 1) << endl;

    return 0;
}
