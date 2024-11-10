# Proyecto: Torneo de Ajedrez - Simulación y Ordenamiento por ELO

Por: Ricardo Ruiz Cano    A01707233

## Overview General del Proyecto

Este proyecto simula un torneo de ajedrez en el cual los jugadores están registrados con sus nombres y valores de ELO, que reflejan su nivel de habilidad en el juego. Los jugadores se organizan de mayor a menor según su ELO utilizando el algoritmo **Merge Sort** y compiten en un torneo simulado, donde se enfrentan y sus ELOs se actualizan en función de los resultados de cada partida.

---

## Descripción del Avance 1

En el primer avance del proyecto, se implementaron las funcionalidades principales del programa:

- Registro de jugadores con sus nombres y valores de ELO.
- Visualización de la lista de jugadores con sus ELOs.
- Ordenamiento de los jugadores usando **Merge Sort** para organizar de mayor a menor ELO.
- Simulación de un torneo, donde los jugadores se enfrentan y sus ELOs se ajustan según los resultados de cada partida.
- Se muestra la lista de jugadores ordenados por ELO después del torneo.

---

## Descripción del Avance 2

En el segundo avance, se realizaron mejoras significativas en la funcionalidad del programa.

### Cambios sobre el Primer Avance

1. **Unificación de Datos en una Clase**:
   - **Cambio**: La información de los jugadores (nombre y ELO) se integró en una única clase `Jugador`.
   - **Razón del cambio**: Mejora la organización y el manejo de los datos de los jugadores, haciendo que el código sea más limpio y formal y previniendo posibles fallos.

2. **Reestructuración de la Salida**:
   - **Cambio**: Se mejoró la presentación de los resultados al mostrar la lista de jugadores después del torneo, incluyendo su posición en la lista.
   - **Razón del cambio**: Facilita la lectura y comprensión de los resultados por parte del usuario.

3. **Mejora en la Simulación del Torneo**:
   - **Cambio**: Se optimizó la simulación de partidas y ajuste de ELOs, haciéndolo más representativo de la competencia real.
   - **Razón del cambio**: Proporciona una experiencia más realista y refleja mejor cómo funciona el sistema de ELO en el ajedrez.

4. **Actualización del README**:
   - **Cambio**: Se modificó el README para describir más claramente las funcionalidades y avances del proyecto.
   - **Razón del cambio**: La documentación fue reorganizada para hacerla más formal y accesible.

5. **Implementación de Búsqueda por ELO**:
   - **Cambio**: Se añadió la opción de buscar jugadores por su ELO usando un árbol binario de búsqueda (BST).
   - **Razón del cambio**: Permite a los usuarios encontrar jugadores específicos de manera más eficiente.

---

## Descripción del Avance 3

En este avance, se agregaron nuevas funcionalidades y mejoras al programa.

### Cambios sobre el Segundo Avance

1. **Opción para Imprimir en Archivo**:
   - **Cambio**: Se añadió la opción de imprimir la lista de jugadores en un archivo de texto (`jugadores.txt`).
   - **Razón del cambio**: Permite a los usuarios conservar una copia de los datos generados durante la ejecución del programa.

2. **Reubicación de la Opción de Salida**:
   - **Cambio**: La opción de salida del programa fue asignada a la opción 6 en el menú.
   - **Razón del cambio**: Mejora la organización y claridad del menú de opciones.

---

## Instrucciones para Compilar el Avance de Proyecto

Ejecuta el siguiente comando en la terminal:

    g++ main.cpp -o torneo_ajedrez

## Instrucciones para Ejecutar el Avance de Proyecto

Ejecuta el siguiente comando en la terminal:

    ./torneo_ajedrez

---

## Descripción de las Entradas del Avance de Proyecto

El programa no requiere archivos externos para las entradas. Se inicializa con una lista de jugadores predefinidos, pero permite agregar nuevos jugadores durante la ejecución. Al agregar un jugador, se solicita:

- **Nombre del jugador**: Una cadena de texto.
- **ELO del jugador**: Un número entero entre 1 y 4000.

**Ejemplo de jugadores predefinidos**:

- Magnus Carlsen, ELO: 2852
- Ian Nepomniachtchi, ELO: 2793
- Ding Liren, ELO: 2811
- Fabiano Caruana, ELO: 2786
- Anish Giri, ELO: 2779

---

## Descripción de las Salidas del Avance de Proyecto

El programa genera las siguientes salidas:

1. **Lista de jugadores antes del torneo**: Muestra los jugadores con sus nombres y ELO iniciales.

2. **Resultados del torneo**: Durante la simulación, se muestran los resultados de cada partida y cómo se ajustan los ELOs de los jugadores.

3. **Lista de jugadores después del torneo**: Muestra los jugadores ordenados por su ELO actualizado.

4. **Archivo de jugadores**: Al seleccionar la opción correspondiente, se genera un archivo `jugadores.txt` con la lista de jugadores y sus ELOs.

---

## Desarrollo de Competencias

### SICT0301: Evalúa los Componentes

**Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.**

He realizado un análisis del algoritmo **Merge Sort** utilizado en el programa. Este algoritmo tiene una complejidad temporal de **O(n log n)** en el mejor, promedio y peor caso. Esto se debe a que siempre divide el conjunto en mitades y requiere recombinar los subarreglos ordenados. Esta eficiencia es crucial para ordenar listas grandes de jugadores de manera rápida y efectiva.

**Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.**

El árbol binario de búsqueda (BST) utilizado para la búsqueda de jugadores por ELO tiene una complejidad promedio de **O(log n)** para operaciones de inserción y búsqueda, asumiendo que el árbol está equilibrado. Esto mejora la eficiencia en comparación con una búsqueda lineal y es esencial para manejar consultas rápidas dentro del programa.

**Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.**

Las operaciones de simulación de partidas tienen una complejidad de **O(n^2)**, ya que cada jugador se enfrenta a todos los demás. Aunque es menos eficiente para grandes cantidades de jugadores, es aceptable para el tamaño manejado en este proyecto. La complejidad general del programa está dominada por esta sección, pero se mantiene dentro de límites razonables.

### SICT0302: Toma Decisiones

**Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.**

Elegí **Merge Sort** debido a su eficiencia y estabilidad. A diferencia de otros algoritmos como **Quick Sort**, **Merge Sort** garantiza un tiempo de ejecución consistente y maneja bien listas ya ordenadas o con muchos elementos iguales. Esto es fundamental para mantener la eficiencia al ordenar los ELOs de los jugadores después del torneo.

**Selecciona una estructura de datos adecuada al problema y la usa correctamente.**

Implementé un árbol binario de búsqueda (BST) para gestionar los jugadores por ELO. Esta estructura permite realizar búsquedas eficientes y mantiene los datos organizados, lo cual es esencial para manejar consultas rápidas y eficientes dentro del programa, mejorando la experiencia del usuario.

### SICT0303: Implementa Acciones Científicas

**Implementa mecanismos para consultar información de las estructuras correctos.**

Se desarrollaron métodos para buscar jugadores por ELO en el BST, lo que permite acceder a la información de manera eficiente y demuestra el uso correcto de estructuras de datos avanzadas.

**Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.**

Aunque en este avance no se implementó la lectura de archivos para cargar datos, el código está estructurado para facilitar la inclusión de esta funcionalidad en el futuro. La clase `Jugador` y las estructuras utilizadas pueden adaptarse fácilmente para leer desde archivos.

**Implementa mecanismos de escritura de archivos para guardar los datos de las estructuras de manera correcta.**

Se agregó la funcionalidad de exportar la lista de jugadores a un archivo de texto (`jugadores.txt`). Esto implica manejar operaciones de entrada/salida de archivos y permite que los datos sean accesibles fuera del programa, demostrando la implementación exitosa de acciones científicas en el manejo de archivos.

---
