#include <iostream>
#define N 10

using namespace std;

int cuentaCeros(int arreglo[N],int inicio, int fin, int cuenta)
{
    if (fin<inicio)
    {
        return cuenta;
    }
    if (inicio==fin && arreglo[inicio]==0)
    {
        return 1 + cuenta;
    }
    int medio = (inicio + fin)/2;
    if (arreglo[medio]==0)
    {
        if (arreglo[medio-1]==1)
        {
            return 1 + cuenta + fin - medio;
        }
        else
        {
            return cuentaCeros(arreglo,inicio,medio-1,1 + cuenta + fin - medio);
        }
    }
    else
    {
        return cuentaCeros(arreglo,medio+1,fin,cuenta);
    }
}

int main()
{
    int arreglo[N] = {1,1,1,1,1,1,1};
    int n=7;
    cout << "Cantidad de Ceros: " << cuentaCeros(arreglo,0,n-1,0);
    return 0;
}