#include <iostream>
#define N 20
using namespace std;

int evaluaSolo(int arreglo[N],int inicio,int fin)
{
    if (inicio == fin)
    {
        return arreglo[inicio];
    }
    if (fin-inicio==1 && arreglo[inicio]==arreglo[fin])
    {
        return -1;
    }
    int medio = (inicio+fin)/2;
    if (medio%2==1)
    {
        if (arreglo[medio]==arreglo[medio-1])
        {
            return evaluaSolo(arreglo,medio+1,fin);
        }
        else
        {
            return evaluaSolo(arreglo,inicio,medio-1);
        }
    }
    else
    {
        if (arreglo[medio]!=arreglo[medio-1])
        {
            return evaluaSolo(arreglo,medio,fin);
        }
        else
        {
            return evaluaSolo(arreglo,inicio,medio-2);
        }
    }
}

int main()
{
    int arreglo[N] = {1,1,3,3,4,4,5,5,7,7,8};
    int n = 11;
    int elemento = evaluaSolo(arreglo,0,n-1);
    cout << "El elemento solo es: " << elemento << endl;
    return 0;
}