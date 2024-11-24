// Proyecto integrador, torneo de Ajedrez
// Ricardo Ruiz Cano     A01707233

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <algorithm>
#include "torneo.h"

using namespace std;

// Función para eliminar espacios en blanco al inicio y al final de una cadena
// Complejidad: 
// Mejor caso: O(n) (recorre una sola vez la cadena para encontrar espacios).
// Promedio caso: O(n) (la cadena promedio tiene algunos espacios).
// Peor caso: O(n) (recorre toda la cadena en búsqueda de espacios).
string Trim(const string& str) {
    size_t first = str.find_first_not_of(" \t");
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, (last - first + 1));
}

// Función para verificar si un jugador ya existe en la lista
// Complejidad:
// Mejor caso: O(1) (si el primer elemento coincide).
// Promedio caso: O(n) (revisa aproximadamente la mitad de la lista).
// Peor caso: O(n) (revisa toda la lista).
bool JugadorExiste(const vector<Jugador>& jugadores, const string& nombre) {
    string nombre_normalizado = Trim(nombre);
    for (size_t i = 0; i < jugadores.size(); ++i) {
        if (Trim(jugadores[i].nombre) == nombre_normalizado) {
            return true;
        }
    }
    return false;
}

// Función para cargar jugadores desde un archivo
// Complejidad:
// Mejor caso: O(m + n) (m líneas en el archivo, revisa jugadores en O(n)).
// Promedio caso: O(m + n^2) (m líneas y busca jugadores múltiples veces).
// Peor caso: O(m + n^2) (archivo con líneas mal formateadas, búsqueda innecesaria).
void CargarJugadoresDesdeArchivo(const string& nombre_archivo, vector<Jugador>& jugadores, ArbolBST& arbol_jugadores) {
    ifstream archivo(nombre_archivo.c_str());
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo " << nombre_archivo << ".\n";
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;

        stringstream ss(linea);
        string dummy, nombre;
        int elo;

        if (!getline(ss, dummy, '-') || !getline(ss, nombre, '-') || !getline(ss, dummy, ':') || !(ss >> elo)) {
            cout << "Línea de formato incorrecto en el archivo: " << linea << "\n";
            continue;
        }

        nombre = Trim(nombre);

        if (elo > 0 && elo <= 4000) {
            if (!JugadorExiste(jugadores, nombre)) {
                jugadores.push_back(Jugador(nombre, elo)); // O(1) para agregar al final.
                arbol_jugadores.InsertarJugador(Jugador(nombre, elo)); // O(log n) en promedio.
                cout << "Jugador " << nombre << " agregado con ELO " << elo << ".\n";
            } else {
                cout << "Jugador " << nombre << " ya existe en la lista.\n";
            }
        } else {
            cout << "El ELO de " << nombre << " no es válido.\n";
        }
    }
    archivo.close();
    cout << "Carga de jugadores desde " << nombre_archivo << " finalizada.\n";
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    vector<Jugador> jugadores;
    jugadores.push_back(Jugador("Magnus Carlsen", 2852));
    jugadores.push_back(Jugador("Ian Nepomniachtchi", 2793));
    jugadores.push_back(Jugador("Ding Liren", 2811));
    jugadores.push_back(Jugador("Fabiano Caruana", 2786));
    jugadores.push_back(Jugador("Anish Giri", 2779));
    jugadores.push_back(Jugador("Levon Aronian", 2775));

    ArbolBST arbol_jugadores;

    // Inicializa el árbol con jugadores
    // Complejidad total: O(n log n), donde n es el número de jugadores.
    for (size_t i = 0; i < jugadores.size(); ++i) {
        arbol_jugadores.InsertarJugador(jugadores[i]); // Cada inserción es O(log n) en promedio.
    }

    int opcion_menu;
    bool salir = false;

    cout << "------------------------------------------" << endl;
    cout << "          Bienvenido al Dojo de Ajedrez   " << endl;
    cout << "------------------------------------------" << endl;

    while (!salir) {
        cout << "\nSelecciona una opción: \n"
             << "1. Ver jugadores \n"
             << "2. Agregar jugador \n"
             << "3. Hacer torneo \n"
             << "4. Buscar jugador por ELO \n"
             << "5. Imprimir lista de jugadores en archivo \n"
             << "6. Cargar jugadores desde archivo jugadores.txt \n"
             << "7. Observar la lista de ELOs BST de mayor a menor \n"
             << "8. Salir del Dojo" << endl;

        cout << "\nIngresa opción: ";
        cin >> opcion_menu;
        cout << endl;

        if (opcion_menu == 1) {
            // Imprime la lista de jugadores en O(n).
            cout << "Lista de jugadores:\n";
            ImprimirJugadores(jugadores);
        } else if (opcion_menu == 2) {
            string nuevo_nombre;
            int nuevo_elo;

            cout << "Ingresa el nombre del nuevo jugador: ";
            cin.ignore();
            getline(cin, nuevo_nombre);

            bool elo_valido = false;
            while (!elo_valido) {
                cout << "Ingresa el ELO del nuevo jugador (máximo 4000): ";
                cin >> nuevo_elo;

                if (nuevo_elo > 0 && nuevo_elo <= 4000) {
                    elo_valido = true;
                } else {
                    cout << "Error: El ELO ingresado no es válido. Debe ser un valor entre 1 y 4000.\n";
                }
            }

            // Verifica existencia del jugador y lo inserta.
            // Complejidad: O(n) para la verificación + O(1) para agregar al vector.
            if (!JugadorExiste(jugadores, nuevo_nombre)) {
                jugadores.push_back(Jugador(nuevo_nombre, nuevo_elo)); // O(1)
                arbol_jugadores.InsertarJugador(Jugador(nuevo_nombre, nuevo_elo)); // O(log n)
                cout << "\nJugador agregado exitosamente.\n" << endl;
            } else {
                cout << "Jugador " << nuevo_nombre << " ya existe en la lista.\n";
            }

        } else if (opcion_menu == 3) {
            SimularTorneo(jugadores, arbol_jugadores);
            cout << "\nTorneo completado. Resultados actualizados y ordenados:\n";
            OrdenarELO(jugadores); // O(n log n)
            ImprimirJugadores(jugadores); // O(n)

        } else if (opcion_menu == 4) {
            int elo_buscar;
            cout << "Ingresa el ELO del jugador a buscar: ";
            cin >> elo_buscar;

            // Busca jugador en el árbol BST en O(log n) en promedio.
            Jugador* encontrado = arbol_jugadores.BuscarJugadorPorELO(elo_buscar);
            if (encontrado) {
                cout << "Jugador encontrado: " << encontrado->nombre
                     << " - ELO: " << encontrado->elo << endl;
            } else {
                cout << "No se encontró un jugador con ese ELO.\n";
            }
        } else if (opcion_menu == 5) {
            ofstream archivo("jugadores.txt");
            if (archivo.is_open()) {
                archivo << "Lista de jugadores y sus ELOs:\n\n";
                // Escritura en O(n).
                for (size_t i = 0; i < jugadores.size(); ++i) {
                    archivo << (i + 1) << "- " << jugadores[i].nombre
                            << " - ELO: " << jugadores[i].elo << endl;
                }
                archivo.close();
                cout << "La lista de jugadores se ha guardado en el archivo 'jugadores.txt'.\n";
            } else {
                cout << "Error al abrir el archivo para escribir.\n";
            }
        } else if (opcion_menu == 6) {
            CargarJugadoresDesdeArchivo("jugadores.txt", jugadores, arbol_jugadores);
        } else if (opcion_menu == 7) {
            cout << "Jugadores en orden descendente (mayor a menor ELO):\n";
            arbol_jugadores.ImprimirJugadoresDescendente(); // O(n)
        } else if (opcion_menu == 8) {
            cout << "Saliendo del Dojo..." << endl;
            salir = true;
        } else {
            cout << "Opción no válida. Intenta de nuevo." << endl;
        }

        cout << "\n------------------------------------------" << endl;
    }

    return 0;
}
