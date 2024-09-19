**Proyecto: Torneo de Ajedrez - Ordenamiento por ELO**


**Descripción del Programa:**

Este proyecto simula un torneo de ajedrez donde los jugadores se ordenan por su valor de ELO utilizando un algoritmo recursivo. Cada jugador tiene un valor de ELO que representa su nivel de habilidad. El objetivo es registrar a los jugadores, ordenar los valores de ELO de mayor a menor y mostrar los resultados.


**Funcionalidad:**

># Torneo de Ajedrez
>
>Este programa simula un torneo de ajedrez y ordena a los jugadores por su ELO.
>
>## Funciones
>
>1. **Ver jugadores**: Muestra una lista de jugadores y sus ELOs.
>   
>2. **Ordenar jugadores**: Ordena a los jugadores por ELO (de mayor a menor) usando **Merge Sort**.
>
>3. **Agregar jugador**: Permite ingresar el nombre y el ELO de un nuevo jugador.
>
>4. **Salir**: Cierra el programa.


**Registro de Jugadores:**

Los jugadores se registran con su nombre y su valor de ELO. Estos valores se almacenan en vectores.


**Ordenamiento por ELO (Merge Sort):**


El programa utiliza el algoritmo Merge Sort para ordenar los jugadores de manera eficiente según su ELO. Merge Sort es un algoritmo con una complejidad de (nlogn), lo que lo hace ideal para este tipo de ordenamientos.


**Impresión de Resultados:**

El programa permite imprimir la lista de jugadores y sus valores de ELO antes y después de ordenar.


**Componentes Principales:**


Registro de Jugadores: El programa permite registrar jugadores y sus ELOs. Estos datos se almacenan en dos vectores, uno para los nombres y otro para los ELOs.

**Ordenamiento por Merge Sort:**


Este algoritmo recursivo divide la lista de jugadores en dos partes, las ordena de forma recursiva y luego combina las listas ordenadas. Esto garantiza que los jugadores se ordenen de manera eficiente por su ELO.



**Imprimir Jugadores:**

Esta función muestra los nombres de los jugadores junto con sus valores de ELO, lo que permite verificar el estado antes y después del torneo.


**Estructura del Código:**


Lista de Jugadores: Se usa un vector para los nombres y otro para los ELOs.


**Merge Sort:**

El algoritmo se encarga de ordenar los jugadores según su valor de ELO, de mayor a menor.


**Imprimir Resultados:**


Al finalizar el ordenamiento, el programa imprime los resultados del torneo, mostrando los jugadores en orden descendente de acuerdo con su ELO.

**Análisis de Complejidad:**


Inserción de Jugadores: O(1) para agregar un jugador al final del vector.

Búsqueda de Jugadores: O(n) al recorrer la lista para imprimir los jugadores.

Ordenamiento por ELO (Merge Sort): O(n log n) ya que divide los jugadores en mitades y los ordena recursivamente.

Este proyecto permite simular un torneo en el que los jugadores se ordenan por su habilidad en base a su ELO, lo que lo hace una herramienta educativa para entender cómo funciona el ordenamiento de datos en C++ utilizando estructuras básicas como vectores y algoritmos eficientes como Merge Sort.
