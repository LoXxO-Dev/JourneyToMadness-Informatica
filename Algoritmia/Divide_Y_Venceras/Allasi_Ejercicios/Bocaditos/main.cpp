#include <iostream>
#define N 11
#define M 8

using namespace std;

char ubicaSobrante(char arreglo[N],int inicio,int fin)
{
    if (fin-inicio==2 && arreglo[inicio]==arreglo[fin] && arreglo[inicio]==arreglo[inicio+1])
    {
        return arreglo[inicio];
    }
    if (inicio==fin)
    {
        return ' ';
    }
    int medio = (inicio+fin)/2;
    if (medio%2==1)
    {
        if (arreglo[medio-1]==arreglo[medio] && arreglo[medio]!=arreglo[medio+1])
        {
            return ubicaSobrante(arreglo,medio+1,fin);
        }
        else
        {
            if (arreglo[medio-1]==arreglo[medio] && arreglo[medio]==arreglo[medio+1])
            {
                return arreglo[medio];
            }
            else
            {
                return ubicaSobrante(arreglo, inicio, medio-1);
            }
        }
    }
    else
    {
        if (arreglo[medio]!=arreglo[medio-1])
        {
            return ubicaSobrante(arreglo,medio,fin);
        }
        else
        {
            return ubicaSobrante(arreglo,inicio,medio);
        }
    }
}

int main()
{
    char arreglo[M][N] = {
        {'O','O','C','C','A','A','E','E','R','R','R'},
        {'C','C','A','A','R','R','E','E','B','B',' '},
        {'R','R','E','E','C','C','F','F','A','A',' '},
        {'E','E','F','F','A','A','A','B','B','R','R'}
    };
    int n=11, m=4;
    for (int i = 0; i < m; i++)
    {
        char solo = ubicaSobrante(arreglo[i],0,n-1);
        if (solo!=' ')
        {
            cout << "La fila " << i+1 << " tiene un " << solo << " adicional" << endl;
        }
    }
    return 0;
}