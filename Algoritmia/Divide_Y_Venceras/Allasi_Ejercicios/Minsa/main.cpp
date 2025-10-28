#include <iostream>
#define N 10

using namespace std;

int contarCentro(int dias[N],int inicio,int medio,int fin)
{
    /*Vamos a contar del centro para la izquierda cuantos consecutivos crecientes hay*/
    int cuentaIzquierda = 1;
    for (int i=medio; i>=inicio; i--)
    {
        if (dias[i]>dias[i-1])
        {
            cuentaIzquierda++;
        }
        else
        {
            break;
        }
    }
    /*Vamos a contar del centro para la derecha cuantos consecutivos crecientes hay*/
    int cuentaDerecha = 1;
    for (int i=medio+1; i<=fin; i++)
    {
        if (dias[i]<dias[i+1])
        {
            cuentaDerecha++;
        }
        else
        {
            break;
        }
    }
    int cuentaCentro = 1;
    if (dias[medio]<dias[medio+1])
    {
        cuentaCentro = cuentaIzquierda + cuentaDerecha;
    }
    if (cuentaIzquierda>=cuentaDerecha && cuentaIzquierda>=cuentaCentro)
    {
        return cuentaIzquierda;
    }
    else
    {
        if (cuentaDerecha>=cuentaIzquierda && cuentaDerecha>=cuentaCentro)
        {
            return cuentaDerecha;
        }
        else
        {
            return cuentaCentro;
        }
    }
}

int cuentaDias(int dias[N],int inicio,int fin)
{
    if (inicio==fin)
    {
        return 1;
    }
    int medio = (inicio+fin)/2;
    int cuentaIzq = cuentaDias(dias,inicio,medio);
    int cuentaDer = cuentaDias(dias,medio+1,fin);
    int cuentaCentro = contarCentro(dias,inicio,medio,fin);
    if (cuentaIzq>=cuentaDer && cuentaIzq>=cuentaCentro)
    {
        return cuentaIzq;
    }
    else
    {
        if (cuentaDer>=cuentaIzq && cuentaDer>=cuentaCentro)
        {
            return cuentaDer;
        }
        else
        {
            return cuentaCentro;
        }
    }
}

int main()
{
    int dias[N] = {7,2,9,10,16,10,13,8,2,10};
    int n = 10;
    int contador = cuentaDias(dias,0,n-1);
    cout << "Contador:  " << contador << endl;
    cout << "El índice es: " << (double)contador/n;
    return 0;
}