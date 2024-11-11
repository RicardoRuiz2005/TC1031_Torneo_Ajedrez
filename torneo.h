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
    Jugador(const string& nombre, int elo) : nombre(nombre), elo(elo) {}

    // Muestra la informacion del jugador
    void Mostrar() const {
        cout << "Nombre: " << nombre << ", ELO: " << elo << endl;
    }
};

// Clase Nodo para el arbol de busqueda binaria (BST)
class Nodo {
public:
    Jugador jugador;
    Nodo* izquierda;
    Nodo* derecha;

    // Inicializa el nodo con el jugador, apuntadores a NULL
    explicit Nodo(Jugador j) : jugador(j), izquierda(NULL), derecha(NULL) {}
};

// Clase BST para gestionar los jugadores por ELO
class ArbolBST {
private:
    Nodo* raiz_;

    // Inserta un nodo en el arbol BST de forma recursiva
    Nodo* Insertar(Nodo* nodo, const Jugador& jugador) {
        if (nodo == NULL) {  // Si el nodo esta vacio, lo creo
            return new Nodo(jugador);
        }
        // Verifico donde insertar al comparar el ELO
        if (jugador.elo < nodo->jugador.elo) {
            nodo->izquierda = Insertar(nodo->izquierda, jugador);
        } else if (jugador.elo > nodo->jugador.elo) {
            nodo->derecha = Insertar(nodo->derecha, jugador);
        }
        return nodo;
    }

    // Busca un jugador por su ELO de forma recursiva
    Jugador* Buscar(Nodo* nodo, int elo) {
        if (nodo == NULL) {  // Si no encuentro el nodo, regreso NULL
            return NULL;
        }
        // Verifico si el ELO coincide o hacia donde buscar
        if (elo == nodo->jugador.elo) {
            return &nodo->jugador;
        } else if (elo < nodo->jugador.elo) {
            return Buscar(nodo->izquierda, elo);
        } else {
            return Buscar(nodo->derecha, elo);
        }
    }

public:
    ArbolBST() : raiz_(NULL) {}  // Inicializa la raiz en NULL

    // Inserta un jugador en el arbol llamando a la funcion recursiva
    void InsertarJugador(const Jugador& jugador) {
        raiz_ = Insertar(raiz_, jugador);
    }

    // Busca un jugador por su ELO llamando a la funcion recursiva
    Jugador* BuscarJugadorPorELO(int elo) {
        return Buscar(raiz_, elo);
    }

    // Imprime los jugadores en orden (recorre el arbol en inorden)
    void ImprimirEnOrden(Nodo* nodo) {
        if (nodo != NULL) {  // Si el nodo no es NULL, continuo imprimiendo
            ImprimirEnOrden(nodo->izquierda);
            nodo->jugador.Mostrar();
            ImprimirEnOrden(nodo->derecha);
        }
    }

    // Imprime todos los jugadores desde la raiz del arbol
    void ImprimirJugadores() {
        ImprimirEnOrden(raiz_);
    }
};

// Imprime los jugadores desde el vector
void ImprimirJugadores(const vector<Jugador>& jugadores) {
    for (size_t i = 0; i < jugadores.size(); ++i) {
        jugadores[i].Mostrar();
    }
}

// Calcula la probabilidad de ganar basado en los ELOs
double CalcularProbabilidad(int elo_a, int elo_b) {
    return 1.0 / (1.0 + pow(10.0, (elo_b - elo_a) / 400.0));
}

// Compara los ELOs de dos jugadores para el ordenamiento
bool CompararELO(const Jugador& a, const Jugador& b) {
    return a.elo > b.elo;
}

// Ordena los jugadores por ELO usando sort
void OrdenarELO(vector<Jugador>& jugadores) {
    sort(jugadores.begin(), jugadores.end(), CompararELO);
}

// Simulacion del torneo
void SimularTorneo(vector<Jugador>& jugadores, ArbolBST& arbol_jugadores) {
    const int kKFactor = 32;  // Constante de ajuste para el calculo del nuevo ELO

    // Simulo las partidas entre los jugadores
    for (size_t i = 0; i < jugadores.size(); ++i) {
        for (size_t j = i + 1; j < jugadores.size(); ++j) {
            double prob_a = CalcularProbabilidad(jugadores[i].elo, jugadores[j].elo);
            double prob_b = CalcularProbabilidad(jugadores[j].elo, jugadores[i].elo);

            int elo_antes_a = jugadores[i].elo;
            int elo_antes_b = jugadores[j].elo;

            // Genero un valor aleatorio para determinar el resultado
            double random_value = static_cast<double>(rand()) / RAND_MAX;
            double resultado;

            // Verifico quien gana basado en el valor aleatorio y las probabilidades
            if (random_value < prob_a) {
                resultado = 1;
                cout << jugadores[i].nombre << " gana contra " << jugadores[j].nombre << endl;
            } else if (random_value < (prob_a + prob_b) / 10 && abs(jugadores[i].elo - jugadores[j].elo) < 100) {
                resultado = 0.5;
                cout << jugadores[i].nombre << " empata con " << jugadores[j].nombre << endl;
            } else {
                resultado = 0;
                cout << jugadores[j].nombre << " gana contra " << jugadores[i].nombre << endl;
            }

            // Actualizo los ELOs de ambos jugadores
            jugadores[i].elo += kKFactor * (resultado - prob_a);
            jugadores[j].elo += kKFactor * ((1 - resultado) - prob_b);

            cout << jugadores[i].nombre << " ELO: " << elo_antes_a << " -> " << jugadores[i].elo << endl;
            cout << jugadores[j].nombre << " ELO: " << elo_antes_b << " -> " << jugadores[j].elo << endl;
            cout << "======================================\n" << endl;
        }
    }

    OrdenarELO(jugadores);  // Ordena a los jugadores por su nuevo ELO

    // Limpio el arbol actual y vuelvo a insertar los jugadores con sus nuevos ELOs
    arbol_jugadores = ArbolBST();  // Reinicio el arbol
    for (size_t i = 0; i < jugadores.size(); ++i) {
        arbol_jugadores.InsertarJugador(jugadores[i]);  // Inserto los jugadores actualizados
    }
}

#endif
