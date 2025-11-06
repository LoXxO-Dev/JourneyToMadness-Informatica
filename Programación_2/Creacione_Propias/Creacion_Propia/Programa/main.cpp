#include <list>
#include <map>

#include "sources/utils.hpp"

void imprimirLinea(int cant, char car) {
    for (int i = 0; i < cant; i++)
        cout.put(car);
    cout << endl;
}

void imprimir(int cantidad, int cantDias) {
    int j;
    for (int i = 1; i <= cantDias; i++) {
        cout << right << setw(5) << i;
        if (i % 7 == 0)cout << endl;
    }
}

#include "sources/Persona.hpp"

int main() {
    int cantMese = 12;
    int cantDias;
    map<int, string> meses{
        {1, "Enero"},
        {2, "Febrero"},
        {3, "Marzo"},
        {4, "Abril"},
        {5, "Mayo"},
        {6, "Junio"},
        {7, "Julio"},
        {8, "Agosto"},
        {9, "Septiembre "},
        {10, "Octubre"},
        {11, "Noviembre"},
        {12, "Diciembre"},
    };
    int primerDia = 1;
    for (int i = 1; i <= cantMese; i++) {
        cout << meses.at(i) << endl;
        if (i == 1 or i == 3 or i == 5 or i == 7 or i == 8 or i == 10 or i == 12) cantDias = 31;
        else if (i == 2) cantDias = 28;
        else cantDias = 30;

        cout << setw(5) << "Lu" << setw(5) << "Ma" << setw(5) << "Mi" << setw(5) << "Ju" << setw(5) << "Vi"
                << setw(5) << "Sa" << setw(5) << "Do" << endl;
        for (int i = 1; i < primerDia; i++) {
            cout << setw(5) << " ";
        }

        for (int i = 1; i <= cantDias; i++) {
            cout << setw(5) << i;
            if (++primerDia > 7) primerDia = 1; // Ajusta al próximo día de la semana
            if (primerDia == 1) cout << endl; // Nueva línea después del domingo
        }

        cout << endl;
        imprimirLinea(30, '=');

        //-------------------------------------------------
        // imprimir(cantidad, cantDias);
        // cout << endl;
        // imprimirLinea(TAM_LINEA, '=');
    }


    return 0;
}
