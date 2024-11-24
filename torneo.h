// Proyecto integrador, torneo de Ajedrez
// Ricardo Ruiz Cano     A01707233

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

    // Constructor para inicializar un jugador
    // Complejidad: O(1) (asignación directa de valores).
    Jugador(const string& nombre, int elo) : nombre(nombre), elo(elo) {}

    // Muestra la información del jugador
    // Complejidad: O(1) (operaciones básicas de E/S).
    void Mostrar() const {
        cout << "Nombre: " << nombre << ", ELO: " << elo << endl;
    }
};

// Clase Nodo para el árbol de búsqueda binaria (BST)
class Nodo {
public:
    Jugador jugador;
    Nodo* izquierda;
    Nodo* derecha;

    // Constructor del Nodo
    // Complejidad: O(1) (creación de un nodo con punteros nulos).
    explicit Nodo(Jugador j) : jugador(j), izquierda(NULL), derecha(NULL) {}
};

// Clase BST para gestionar los jugadores por ELO
class ArbolBST {
private:
    Nodo* raiz_;

    // Inserta un nodo en el árbol BST de forma recursiva
    // Complejidad:
    // Mejor caso: O(log n) (árbol balanceado, inserción en profundidad logarítmica).
    // Promedio caso: O(log n) (inserción en un árbol semibalanceado).
    // Peor caso: O(n) (árbol desbalanceado, inserción lineal).
    Nodo* Insertar(Nodo* nodo, const Jugador& jugador) {
        if (nodo == NULL) {
            return new Nodo(jugador);
        }
        if (jugador.elo < nodo->jugador.elo) {
            nodo->izquierda = Insertar(nodo->izquierda, jugador);
        } else if (jugador.elo > nodo->jugador.elo) {
            nodo->derecha = Insertar(nodo->derecha, jugador);
        }
        return nodo;
    }

    // Busca un jugador por su ELO de forma recursiva
    // Complejidad:
    // Mejor caso: O(1) (si el nodo raíz tiene el ELO buscado).
    // Promedio caso: O(log n) (búsqueda en un árbol balanceado).
    // Peor caso: O(n) (árbol completamente desbalanceado).
    Jugador* Buscar(Nodo* nodo, int elo) {
        if (nodo == NULL) {
            return NULL;
        }
        if (elo == nodo->jugador.elo) {
            return &nodo->jugador;
        } else if (elo < nodo->jugador.elo) {
            return Buscar(nodo->izquierda, elo);
        } else {
            return Buscar(nodo->derecha, elo);
        }
    }

    // Función recursiva para imprimir jugadores en orden descendente
    // Complejidad:
    // Mejor caso: O(n) (recorre todos los nodos exactamente una vez).
    // Promedio caso: O(n) (recorrido in-order modificado).
    // Peor caso: O(n) (en un árbol desbalanceado, todos los nodos están en una rama).
    void ImprimirEnOrdenDescendente(Nodo* nodo) {
        if (nodo != NULL) {
            ImprimirEnOrdenDescendente(nodo->derecha); // Subárbol derecho
            nodo->jugador.Mostrar();                  // Procesar la raíz
            ImprimirEnOrdenDescendente(nodo->izquierda); // Subárbol izquierdo
        }
    }

    // Función recursiva para imprimir en orden (ascendente)
    // Complejidad: Igual que la función anterior, O(n) en todos los casos.
    void ImprimirEnOrden(Nodo* nodo) {
        if (nodo != NULL) {
            ImprimirEnOrden(nodo->izquierda);
            nodo->jugador.Mostrar();
            ImprimirEnOrden(nodo->derecha);
        }
    }

public:
    ArbolBST() : raiz_(NULL) {}

    // Inserta un jugador en el árbol llamando a la función recursiva
    // Complejidad: Igual que la función Insertar, O(log n) en promedio.
    void InsertarJugador(const Jugador& jugador) {
        raiz_ = Insertar(raiz_, jugador);
    }

    // Busca un jugador por su ELO llamando a la función recursiva
    // Complejidad: Igual que la función Buscar, O(log n) en promedio.
    Jugador* BuscarJugadorPorELO(int elo) {
        return Buscar(raiz_, elo);
    }

    // Imprime los jugadores en orden (ascendente)
    // Complejidad: Igual que ImprimirEnOrden, O(n) en todos los casos.
    void ImprimirJugadores() {
        ImprimirEnOrden(raiz_);
    }

    // Imprime los jugadores en orden descendente (de mayor a menor)
    // Complejidad: Igual que ImprimirEnOrdenDescendente, O(n) en todos los casos.
    void ImprimirJugadoresDescendente() {
        ImprimirEnOrdenDescendente(raiz_);
    }
};

// Función para imprimir jugadores desde el vector
// Complejidad:
// Mejor caso: O(n) (recorre el vector una vez).
// Promedio caso: O(n) (no depende del contenido del vector).
// Peor caso: O(n) (tamaño máximo del vector).
void ImprimirJugadores(const vector<Jugador>& jugadores) {
    for (size_t i = 0; i < jugadores.size(); ++i) {
        jugadores[i].Mostrar();
    }
}

// Calcula la probabilidad de ganar basado en los ELOs
// Complejidad:
// Mejor caso: O(1) (cálculo constante).
// Promedio caso: O(1) (independiente de los datos).
// Peor caso: O(1) (independiente de los datos).
double CalcularProbabilidad(int elo_a, int elo_b) {
    return 1.0 / (1.0 + pow(10.0, (elo_b - elo_a) / 400.0));
}

// Compara los ELOs de dos jugadores para el ordenamiento
// Complejidad: O(1) (comparación simple entre dos enteros).
bool CompararELO(const Jugador& a, const Jugador& b) {
    return a.elo > b.elo;
}

// Ordena los jugadores por ELO usando std::sort
// Complejidad:
// Mejor caso: O(n log n) (uso de quicksort con buen pivote).
// Promedio caso: O(n log n) (algoritmo estándar de std::sort).
// Peor caso: O(n log n) (se asegura un tiempo logarítmico con optimizaciones internas).
void OrdenarELO(vector<Jugador>& jugadores) {
    sort(jugadores.begin(), jugadores.end(), CompararELO);
}

// Simulación del torneo
// Complejidad:
// Mejor caso: O(n^2) (simulación entre pares de jugadores).
// Promedio caso: O(n^2).
// Peor caso: O(n^2) (combinaciones completas entre n jugadores).
void SimularTorneo(vector<Jugador>& jugadores, ArbolBST& arbol_jugadores) {
    const int kKFactor = 32;

    for (size_t i = 0; i < jugadores.size(); ++i) {
        for (size_t j = i + 1; j < jugadores.size(); ++j) {
            double prob_a = CalcularProbabilidad(jugadores[i].elo, jugadores[j].elo);
            double prob_b = CalcularProbabilidad(jugadores[j].elo, jugadores[i].elo);

            double random_value = static_cast<double>(rand()) / RAND_MAX;
            double resultado;

            if (random_value < prob_a) {
                resultado = 1;
                cout << jugadores[i].nombre << " gana contra " << jugadores[j].nombre << endl;
            } else if (random_value < (prob_a + prob_b) / 2) {
                resultado = 0.5;
                cout << jugadores[i].nombre << " empata con " << jugadores[j].nombre << endl;
            } else {
                resultado = 0;
                cout << jugadores[j].nombre << " gana contra " << jugadores[i].nombre << endl;
            }

            jugadores[i].elo += kKFactor * (resultado - prob_a);
            jugadores[j].elo += kKFactor * ((1 - resultado) - prob_b);
        }
    }

    OrdenarELO(jugadores);

    arbol_jugadores = ArbolBST();
    for (size_t i = 0; i < jugadores.size(); ++i) {
        arbol_jugadores.InsertarJugador(jugadores[i]);
    }
}

#endif
