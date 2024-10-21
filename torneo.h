//Proyecto integrador, torneo de Ajedrez
//Ricardo Ruiz Cano     A01707233


#ifndef TORNEO_H
#define TORNEO_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

// Clase Jugador para encapsular nombre y ELO
class Jugador {
public:
    string nombre;
    int elo;

    // Creo un constructor para inicializar un jugador
    Jugador(const string& nombre, int elo) : nombre(nombre), elo(elo) {}

    // Muestro la información del jugador
    void mostrar() const {
        cout << "Nombre: " << nombre << ", ELO: " << elo << endl;
    }
};

// Clase Nodo para el árbol BST
class Nodo {
public:
    Jugador jugador;
    Nodo* izquierda;
    Nodo* derecha;

    // Inicializo el nodo con el jugador, apuntadores a NULL
    Nodo(Jugador j) : jugador(j), izquierda(NULL), derecha(NULL) {}
};

// Clase BST para gestionar los jugadores por ELO
class ArbolBST {
private:
    Nodo* raiz;

    // Inserto un nodo en el árbol BST de forma recursiva
    Nodo* insertar(Nodo* nodo, Jugador jugador) {
        if (nodo == NULL) {  // Si el nodo está vacío, lo creo
            return new Nodo(jugador);
        }
        // Verifico dónde insertar al comparar el ELO
        if (jugador.elo < nodo->jugador.elo) {
            nodo->izquierda = insertar(nodo->izquierda, jugador);
        } else if (jugador.elo > nodo->jugador.elo) {
            nodo->derecha = insertar(nodo->derecha, jugador);
        }
        return nodo;
    }

    // Busco un jugador por su ELO de forma recursiva
    Jugador* buscar(Nodo* nodo, int elo) {
        if (nodo == NULL) {  // Si no encuentro el nodo, regreso NULL
            return NULL;
        }
        // Verifico si el ELO coincide o hacia dónde buscar
        if (elo == nodo->jugador.elo) {
            return &nodo->jugador;
        } else if (elo < nodo->jugador.elo) {
            return buscar(nodo->izquierda, elo);
        } else {
            return buscar(nodo->derecha, elo);
        }
    }

public:
    ArbolBST() : raiz(NULL) {}  // Inicializo la raíz en NULL

    // Inserto un jugador en el árbol llamando a la función recursiva
    void insertarJugador(Jugador jugador) {
        raiz = insertar(raiz, jugador);
    }

    // Busco un jugador por su ELO llamando a la función recursiva
    Jugador* buscarJugadorPorELO(int elo) {
        return buscar(raiz, elo);
    }

    // Imprimo los jugadores en orden (recorro el árbol en inorden)
    void imprimirEnOrden(Nodo* nodo) {
        if (nodo != NULL) {  // Si el nodo no es NULL, continuo imprimiendo
            imprimirEnOrden(nodo->izquierda);
            nodo->jugador.mostrar();
            imprimirEnOrden(nodo->derecha);
        }
    }

    // Imprimo todos los jugadores desde la raíz del árbol
    void imprimirJugadores() {
        imprimirEnOrden(raiz);
    }
};

// Imprimo los jugadores desde el vector
void imprimirJugadores(const vector<Jugador>& jugadores) {
    for (size_t i = 0; i < jugadores.size(); ++i) {
        jugadores[i].mostrar();
    }
}

// Calculo la probabilidad de ganar basado en los ELOs
double calcularProbabilidad(int eloA, int eloB) {
    return 1.0 / (1.0 + pow(10.0, (eloB - eloA) / 400.0));
}

// Comparo los ELOs de dos jugadores para el ordenamiento
bool compararELO(const Jugador& a, const Jugador& b) {
    return a.elo > b.elo;
}

// Ordeno los jugadores por ELO usando sort
void ordenarELO(vector<Jugador>& jugadores) {
    sort(jugadores.begin(), jugadores.end(), compararELO);
}

// Simulación del torneo
void simularTorneo(vector<Jugador>& jugadores) {
    const int K = 32;  // Constante de ajuste para el cálculo del nuevo ELO
    int contadorPartido = 1;

    // Simulo las partidas entre los jugadores
    for (size_t i = 0; i < jugadores.size(); ++i) {
        for (size_t j = i + 1; j < jugadores.size(); ++j) {
            double probA = calcularProbabilidad(jugadores[i].elo, jugadores[j].elo);
            double probB = calcularProbabilidad(jugadores[j].elo, jugadores[i].elo);

            int eloAntesA = jugadores[i].elo;
            int eloAntesB = jugadores[j].elo;

            // Genero un valor aleatorio para determinar el resultado
            double randomValue = static_cast<double>(rand()) / RAND_MAX;
            double resultado;

            // Verifico quién gana basado en el valor aleatorio y las probabilidades
            if (randomValue < probA) {
                resultado = 1;
                cout << jugadores[i].nombre << " gana contra " << jugadores[j].nombre << endl;
            } else if (randomValue < (probA + probB) / 10 && abs(jugadores[i].elo - jugadores[j].elo) < 100) {
                resultado = 0.5;
                cout << jugadores[i].nombre << " empata con " << jugadores[j].nombre << endl;
            } else {
                resultado = 0;
                cout << jugadores[j].nombre << " gana contra " << jugadores[i].nombre << endl;
            }

            // Actualizo los ELOs de ambos jugadores
            jugadores[i].elo += K * (resultado - probA);
            jugadores[j].elo += K * ((1 - resultado) - probB);

            cout << jugadores[i].nombre << " ELO: " << eloAntesA << " -> " << jugadores[i].elo << endl;
            cout << jugadores[j].nombre << " ELO: " << eloAntesB << " -> " << jugadores[j].elo << endl;
            cout << "======================================\n" << endl;
        }
    }

    ordenarELO(jugadores);  // Ordeno a los jugadores por su nuevo ELO
}

#endif
