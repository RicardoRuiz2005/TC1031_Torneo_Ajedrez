#ifndef TORNEO_H
#define TORNEO_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

// Funcion para imprimir la lista de los jugadores y su respectivo ELO
void imprimirJugadores(const vector<string>& nombres, const vector<int>& elos) {
    for (size_t i = 0; i < nombres.size(); i++) {
        cout << "Nombre: " << nombres[i] << ", ELO: " << elos[i] << endl;
    }
}

// Funcion recursiva que mezcla y ordena (merge sort)
void merge(vector<string>& nombres, vector<int>& elos, int izquierda, int mid, int derecha) {
    int n1 = mid - izquierda + 1;
    int n2 = derecha - mid;

    // Creo vectores temporales para pasar el ordenamiento de datos
    vector<string> L_nombres(n1), R_nombres(n2);
    vector<int> L_elos(n1), R_elos(n2);

    // Copio datos a los vectores temporales
    for (int i = 0; i < n1; i++) {
        L_nombres[i] = nombres[izquierda + i];
        L_elos[i] = elos[izquierda + i];
    }
    for (int i = 0; i < n2; i++) {
        R_nombres[i] = nombres[mid + 1 + i];
        R_elos[i] = elos[mid + 1 + i];
    }

    // Mezcla los vectores temporales de vuelta a los vectores originales
    int i = 0, j = 0, k = izquierda;
    while (i < n1 && j < n2) {
        if (L_elos[i] >= R_elos[j]) { // Ordenar de mayor a menor los ELOS
            elos[k] = L_elos[i];
            nombres[k] = L_nombres[i];
            i++;
        } else {
            elos[k] = R_elos[j];
            nombres[k] = R_nombres[j];
            j++;
        }
        k++;
    }

    // Copia los elementos restantes
    while (i < n1) {
        elos[k] = L_elos[i];
        nombres[k] = L_nombres[i];
        i++;
        k++;
    }
    while (j < n2) {
        elos[k] = R_elos[j];
        nombres[k] = R_nombres[j];
        j++;
        k++;
    }
}

// Función recursiva para dividir el vector y llamar a merge (merge sort)
void ordenarELO(vector<string>& nombres, vector<int>& elos, int izquierda, int derecha) {
    if (izquierda < derecha) {
        int mid = izquierda + (derecha - izquierda) / 2;

        // Divido el vector en dos mitades
        ordenarELO(nombres, elos, izquierda, mid);
        ordenarELO(nombres, elos, mid + 1, derecha);

        // Mezclo las dos mitades
        merge(nombres, elos, izquierda, mid, derecha);
    }
}

#endif
