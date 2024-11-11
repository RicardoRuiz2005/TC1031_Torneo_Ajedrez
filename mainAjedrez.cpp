// Proyecto integrador, torneo de Ajedrez
// Ricardo Ruiz Cano     A01707233

#include <iostream>
#include <vector>
#include <fstream>  // Para manejar archivos de texto
#include <sstream>  // Para dividir lineas de un archivo de texto
#include <string>   // Para manejar cadenas de texto
#include <ctime>    // Para inicializacion de numeros aleatorios con srand y rand
#include <algorithm> // Para eliminar espacios adicionales
#include "torneo.h"  // Incluye las definiciones de clases y funciones del torneo

using namespace std;

// Funcion para eliminar espacios en blanco al inicio y al final de una cadena
/* La funcion Trim recibe una cadena de texto y elimina los espacios en blanco al inicio y al final.
   Esto es util para normalizar el nombre de los jugadores al compararlos, evitando duplicados
   causados por diferencias en espacios. */
string Trim(const string& str) {
    size_t first = str.find_first_not_of(" \t");
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, (last - first + 1));
}

// Funcion para verificar si un jugador ya existe en la lista (ignora espacios adicionales)
/* La funcion JugadorExiste verifica si un jugador con el mismo nombre ya esta en el vector de jugadores.
   Esto se hace para evitar duplicados al cargar datos desde un archivo. Normaliza los nombres usando Trim
   para comparar correctamente, incluso si hay diferencias en espacios. */
bool JugadorExiste(const vector<Jugador>& jugadores, const string& nombre) {
    string nombre_normalizado = Trim(nombre);  // Eliminar espacios al inicio y final del nombre
    for (size_t i = 0; i < jugadores.size(); ++i) {
        if (Trim(jugadores[i].nombre) == nombre_normalizado) {
            return true;  // Jugador encontrado, existe en la lista
        }
    }
    return false;  // Jugador no encontrado, no existe en la lista
}

// Funcion para cargar jugadores desde un archivo en el formato especificado
/* La funcion CargarJugadoresDesdeArchivo abre un archivo especificado por el usuario,
   lee cada linea y extrae el nombre y el ELO de cada jugador. 
   Verifica si el jugador ya existe para evitar duplicados y normaliza el formato del nombre. */
void CargarJugadoresDesdeArchivo(const string& nombre_archivo, vector<Jugador>& jugadores, ArbolBST& arbol_jugadores) {
    ifstream archivo(nombre_archivo.c_str());  // Convertir a const char* usando .c_str() para compatibilidad
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo " << nombre_archivo << ".\n";
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;  // Ignorar lineas en blanco

        stringstream ss(linea);
        string dummy, nombre;
        int elo;

        // Leer el numero inicial, el guion y el nombre hasta " - ELO: "
        /* Este paso analiza el formato especifico "1- Nombre - ELO: 2852", separando
           las partes para extraer el nombre y el ELO. Si el formato no es correcto, 
           la linea se ignora. */
        if (!getline(ss, dummy, '-') || !getline(ss, nombre, '-') || !getline(ss, dummy, ':') || !(ss >> elo)) {
            cout << "Linea de formato incorrecto en el archivo: " << linea << "\n";
            continue;
        }

        // Eliminar espacios en los extremos del nombre
        nombre = Trim(nombre);

        // Validar el rango de ELO y evitar jugadores duplicados
        if (elo > 0 && elo <= 4000) {  // Validacion del rango de ELO permitido
            if (!JugadorExiste(jugadores, nombre)) {
                jugadores.push_back(Jugador(nombre, elo));  // Anadir jugador al vector
                arbol_jugadores.InsertarJugador(Jugador(nombre, elo));  // Insertar jugador en el BST
                cout << "Jugador " << nombre << " agregado con ELO " << elo << ".\n";
            } else {
                cout << "Jugador " << nombre << " ya existe en la lista. No se anadira nuevamente.\n";
            }
        } else {
            cout << "El ELO de " << nombre << " no es valido (debe ser entre 1 y 4000).\n";
        }
    }
    archivo.close();  // Cerrar el archivo despues de la lectura
    cout << "Carga de jugadores desde " << nombre_archivo << " finalizada.\n";
}

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Inicializo los numeros aleatorios para la simulacion

    vector<Jugador> jugadores;  // Vector que almacena los jugadores registrados
    // Inicializacion de jugadores predefinidos con sus ELOs
    jugadores.push_back(Jugador("Magnus Carlsen", 2852));
    jugadores.push_back(Jugador("Ian Nepomniachtchi", 2793));
    jugadores.push_back(Jugador("Ding Liren", 2811));
    jugadores.push_back(Jugador("Fabiano Caruana", 2786));
    jugadores.push_back(Jugador("Anish Giri", 2779));
    jugadores.push_back(Jugador("Levon Aronian", 2775));
    jugadores.push_back(Jugador("Hikaru Nakamura", 2768));
    jugadores.push_back(Jugador("Wesley So", 2766));
    jugadores.push_back(Jugador("Maxime Vachier-Lagrave", 2764));
    jugadores.push_back(Jugador("Shakhriyar Mamedyarov", 2763));
    jugadores.push_back(Jugador("Teimour Radjabov", 2765));
    jugadores.push_back(Jugador("Sergey Karjakin", 2758));
    jugadores.push_back(Jugador("Vladimir Kramnik", 2753));
    jugadores.push_back(Jugador("Veselin Topalov", 2750));
    jugadores.push_back(Jugador("Viswanathan Anand", 2749));

    ArbolBST arbol_jugadores;  // Arbol binario de busqueda para organizar jugadores por ELO

    // Insercion de cada jugador en el arbol de busqueda binaria (BST)
    /* Este bucle inserta cada jugador predefinido en el arbol. El BST permite busquedas eficientes
       por ELO y ordenacion natural, util para buscar y ordenar jugadores rapidamente. */
    for (size_t i = 0; i < jugadores.size(); ++i) {
        arbol_jugadores.InsertarJugador(jugadores[i]);
    }

    int opcion_menu;
    bool salir = false;

    cout << "------------------------------------------" << endl;
    cout << "          Bienvenido al Dojo de Ajedrez   " << endl;
    cout << "------------------------------------------" << endl;

    while (!salir) {
        // Menu principal del programa
        cout << "\nSelecciona una opcion: \n" 
             << "1. Ver jugadores \n"
             << "2. Agregar jugador \n"
             << "3. Hacer torneo \n"
             << "4. Buscar jugador por ELO \n"
             << "5. Imprimir lista de jugadores en archivo \n"
             << "6. Cargar jugadores desde archivo con formato especial \n"
             << "7. Salir del Dojo" << endl;
        cout << "\nIngresa opcion: ";
        cin >> opcion_menu;
        cout << endl;

        if (opcion_menu == 1) {
            // Mostrar lista de jugadores antes del torneo
            cout << "Lista de jugadores y su ELO antes del torneo:\n" << endl;
            ImprimirJugadores(jugadores);  // Imprime jugadores desde el vector

        } else if (opcion_menu == 2) {
            string nuevo_nombre;
            int nuevo_elo;

            cout << "Ingresa el nombre del nuevo jugador: ";
            cin.ignore();
            getline(cin, nuevo_nombre);

            // Validar que el ELO ingresado no sea mayor a 4000
            /* Este bucle asegura que el usuario ingrese un ELO valido (1-4000),
               y repite la solicitud en caso de valores no validos. */
            bool elo_valido = false;
            while (!elo_valido) {
                cout << "Ingresa el ELO del nuevo jugador (maximo 4000): ";
                cin >> nuevo_elo;
                
                if (nuevo_elo > 0 && nuevo_elo <= 4000) {
                    elo_valido = true;
                } else {
                    cout << "Error: El ELO ingresado no es valido. Debe ser un valor entre 1 y 4000.\n";
                }
            }

            // Agregar nuevo jugador si no existe ya en la lista
            if (!JugadorExiste(jugadores, nuevo_nombre)) {
                jugadores.push_back(Jugador(nuevo_nombre, nuevo_elo));
                arbol_jugadores.InsertarJugador(Jugador(nuevo_nombre, nuevo_elo));
                cout << "\nJugador agregado exitosamente.\n" << endl;
            } else {
                cout << "Jugador " << nuevo_nombre << " ya existe en la lista. No se anadira nuevamente.\n";
            }

        } else if (opcion_menu == 3) {
            // Iniciar la simulacion del torneo
            cout << "\nIniciando el torneo...\n";
            SimularTorneo(jugadores, arbol_jugadores);  // Simula el torneo actualizando ELO

            // Mostrar lista ordenada despues del torneo
            cout << "\nLista de jugadores y su ELO despues del torneo (ordenada):\n";
            for (size_t i = 0; i < jugadores.size(); ++i) {
                cout << (i + 1) << "- " << jugadores[i].nombre 
                     << " - ELO: " << jugadores[i].elo << endl;
            }

        } else if (opcion_menu == 4) {
            // Buscar jugador por ELO en el arbol
            int elo_buscar;
            cout << "Ingresa el ELO del jugador a buscar: ";
            cin >> elo_buscar;

            Jugador* encontrado = arbol_jugadores.BuscarJugadorPorELO(elo_buscar);
            if (encontrado) {
                cout << "Jugador encontrado: " << encontrado->nombre 
                     << " - ELO: " << encontrado->elo << endl;
            } else {
                cout << "No se encontro un jugador con ese ELO.\n" << endl;
            }

        } else if (opcion_menu == 5) {
            // Imprimir lista de jugadores en un archivo de texto
            ofstream archivo("jugadores.txt");
            if (archivo.is_open()) {
                archivo << "Lista de jugadores y sus ELOs:\n\n";
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
            // Cargar jugadores desde un archivo con formato especial
            string nombre_archivo;
            cout << "Ingresa el nombre del archivo (Favor de ingresar solmante --jugadores.txt--): ";
            cin >> nombre_archivo;
            CargarJugadoresDesdeArchivo(nombre_archivo, jugadores, arbol_jugadores);

        } else if (opcion_menu == 7) {
            // Salir del programa
            cout << "Saliendo del Dojo..." << endl;
            salir = true;
        } else {
            cout << "Opcion no valida. Intenta de nuevo." << endl;
        }

        cout << "\n------------------------------------------" << endl;
    }

    return 0;
}
