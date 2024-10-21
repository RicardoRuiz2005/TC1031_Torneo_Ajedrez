# Proyecto: Torneo de Ajedrez - Simulación y Ordenamiento por ELO

Por: Ricardo Ruiz Cano    A1707233

Este proyecto simula un torneo de ajedrez donde los jugadores son registrados con sus nombres y valores de ELO, lo que refleja su nivel de habilidad en el juego. Los jugadores se ordenan de mayor a menor según su ELO usando el algoritmo **Merge Sort**. El objetivo es organizar a los jugadores de manera eficiente y simular sus enfrentamientos, mostrando cómo varía su ELO después de cada partida.

---

## Descripción del avance 1

En este primer avance del proyecto, implemente las funcionalidades principales del programa:

- Registro de jugadores con sus nombres y valores de ELO.
- Visualización de la lista de jugadores con sus ELOs.
- Ordenamiento de los jugadores usando **Merge Sort**, ordenando de mayor a menor ELO.
- Simulación de un torneo, donde se enfrentan los jugadores y sus ELOs se actualizan en función de los resultados de los partidos.
- Al finalizar, se muestra la lista de jugadores ordenados por su ELO actualizado tras el torneo.

---

## Descripción del avance 2

En este segundo avance, realice algunas mejoras significativas en la funcionalidad del programa:

### Cambios Realizados:

1. **Unificación de Datos en una Clase**:
   - **Cambio**: Junte la información de los jugadores (nombre y ELO) en una única clase `Jugador`.
   - **Razón del cambio**: Esto mejora la organización del código y permite un manejo más eficiente de los datos de los jugadores, haciendo que el código sea más limpio y formal, a su vez evita alguna falla en el codigo a futuro (esto gracias a la observación hecha en clase).

2. **Reestructuración de la Salida**:
   - **Cambio**: Mejore la presentación de los resultados al mostrar la lista de jugadores después del torneo, incluyendo su posición en la lista.
   - **Razón del cambio**: Esto hace que los resultados sean más fáciles de leer y comprender para el usuario, añadiendo claridad a la interfaz del programa.

3. **Mejora en la Simulación del Torneo**:
   - **Cambio**: Se mejoro la forma en que se simulan las partidas y se ajustan los ELOs, haciéndolo más representativo de la competencia real.
   - **Razón del cambio**: Esto proporciona una experiencia más realista, al reflejar de mejor manera cómo funciona el sistema de ELO en el ajedrez.

4. **Cambios en el Texto y la Documentación**:
   - **Cambio**: El texto del README lo he modificado para incluir una descripción más clara y detallada de las funcionalidades y los avances del proyecto.
   - **Razón del cambio**: El texto cambió drásticamente para hacer la documentación más formal y accesible, facilitando la comprensión del proyecto (casi iniciandolo el readme desde el principio para aclarar mejor las ideas).

5. **Implementación de Búsqueda por ELO**:
   - **Cambio**: Se añadió la opción de buscar jugadores por su ELO usando un árbol binario de búsqueda (BST).
   - **Razón del cambio**: Esto mejora la funcionalidad del programa, permitiendo a los usuarios encontrar jugadores específicos de manera más eficiente.

---

## Descripción de las entradas del avance de proyecto

El programa no requiere archivos externos para las entradas. Se inicializa con una lista de jugadores predefinidos, pero también permite agregar nuevos jugadores durante la ejecución. El proyecto solo usa el main (mainAjedrez.cpp) y un archivo .h (torneo.h).

**Ejemplo de jugadores predefinidos**:

- Magnus Carlsen, ELO: 2852  
- Ian Nepomniachtchi, ELO: 2793  
- Ding Liren, ELO: 2811  
- Fabiano Caruana, ELO: 2786  
- Anish Giri, ELO: 2779

---

## Descripción de las salidas del avance de proyecto

Al ejecutar el programa, se obtendran los siguientes resultados:

1. **Lista de jugadores antes del torneo**: Se imprime la lista de jugadores con sus nombres y ELO en el orden en que fueron registrados.
2. **Resultados del torneo**: El programa simula los partidos entre los jugadores, mostrando quién ganó o si hubo un empate. Luego, actualiza los ELOs de los jugadores en función de los resultados.
3. **Lista de jugadores después del torneo**: Una vez que el torneo ha concluido, se imprime la lista de jugadores ordenada por su ELO de mayor a menor.

---

## Desarrollo de competencias

### SICT0301: Evalúa los componentes

**Análisis de complejidad de algoritmos de ordenamiento**:

- Durante la elaboración del programa, realice un análisis de la complejidad del algoritmo **Merge Sort**, considerando los casos mejor, peor y promedio. El algoritmo tiene una complejidad de **O(n log n)** en todos los casos, lo que lo hace eficiente para ordenar listas grandes de jugadores.

**Análisis de complejidad de estructuras de datos**:

- Se analizó la complejidad de las operaciones en el árbol binario de búsqueda (BST) que se esta usando para la búsqueda de jugadores por ELO. La inserción y búsqueda en un árbol equilibrado tienen complejidades promedio de **O(log n)**.

### SICT0302: Toma decisiones

**Selección de algoritmo de ordenamiento**:

- Elegi **Merge Sort** por su eficiencia y estabilidad. Se consideraron otros algoritmos, pero **Merge Sort** garantizó un rendimiento consistente incluso en listas grandes y desordenadas.

**Selección de estructura de datos**:

- Se implementó un árbol binario de búsqueda (BST) para gestionar eficientemente los jugadores. Esta elección se justifica por la necesidad de realizar búsquedas rápidas por ELO, permitiendo una experiencia más eficaz al usuario.

### SICT0303: Implementa acciones científicas

**Consulta de información de las estructuras**:

- Implemente algunos mecanismos que permiten consultar la información de los jugadores de forma eficiente utilizando el BST.

**Carga de datos a las estructuras**:

- Aunque en este avance no cargué datos desde archivos, organicé el código de manera que sea fácil incluir esa funcionalidad en el futuro, si es necesario o requerido.
