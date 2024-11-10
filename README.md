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
   La información de los jugadores (nombre y ELO) se integró en una única clase `Jugador`. Esto mejora la organización y el manejo de los datos de los jugadores, haciendo que el código sea más limpio y formal, previniendo posibles fallos.

2. **Reestructuración de la Salida**:  
   Se mejoró la presentación de los resultados al mostrar la lista de jugadores después del torneo, incluyendo su posición en la lista, lo cual facilita la lectura y comprensión de los resultados.

3. **Mejora en la Simulación del Torneo**:  
   Se optimizó la simulación de partidas y ajuste de ELOs, haciéndolo más representativo de la competencia real, proporcionando una experiencia más realista y reflejando mejor cómo funciona el sistema de ELO en el ajedrez.

4. **Actualización del README**:  
   Se modificó el README para describir más claramente las funcionalidades y avances del proyecto, haciendo la documentación más formal y accesible.

5. **Implementación de Búsqueda por ELO**:  
   Se añadió la opción de buscar jugadores por su ELO usando un árbol binario de búsqueda (BST), lo que permite a los usuarios encontrar jugadores específicos de manera más eficiente.

---

## Descripción del Avance 3

En este avance, se agregaron nuevas funcionalidades y mejoras al programa.

### Cambios sobre el Segundo Avance

1. **Opción para Imprimir en Archivo**:  
   Se añadió la opción de imprimir la lista de jugadores en un archivo de texto (`jugadores.txt`), lo cual permite conservar una copia de los datos generados durante la ejecución del programa.

2. **Reubicación de la Opción de Salida**:  
   La opción de salida del programa fue asignada a la opción 6 en el menú, mejorando la organización y claridad del menú de opciones.

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

**Análisis de Complejidad de los Algoritmos de Ordenamiento**

El algoritmo de ordenamiento seleccionado para este proyecto es **Merge Sort**. Después de considerar varias opciones, como **Quick Sort** y **Bubble Sort**, se eligió **Merge Sort** debido a su complejidad temporal de **O(n log n)** en el mejor, promedio y peor caso. Esta eficiencia se logra dividiendo el conjunto en mitades y recombinando los subarreglos ordenados, lo cual hace que sea adecuado incluso para listas grandes. Además, es un algoritmo **estable**, lo cual garantiza que el orden relativo de los elementos con valores iguales se mantenga, lo cual es importante en un contexto como el de los ELOs, donde puede haber valores iguales.

**Análisis Completo de Complejidad de la Estructura de Datos (BST)**

Para almacenar y buscar jugadores por ELO, se eligió implementar un **árbol binario de búsqueda (BST)**. En un BST balanceado, la complejidad promedio de operaciones de inserción, búsqueda y eliminación es **O(log n)**, lo que proporciona una eficiencia superior en comparación con una búsqueda lineal **O(n)**. Sin embargo, en el peor caso (si el árbol no está equilibrado y se asemeja a una lista enlazada), la complejidad puede degradarse a **O(n)**.

La elección del BST permite realizar búsquedas rápidas basadas en el ELO, lo cual es crucial en el programa para encontrar jugadores específicos de forma eficiente. Esta estructura es ideal para este proyecto, ya que garantiza un acceso rápido a los datos en la mayoría de los casos, y podría optimizarse aún más utilizando variantes como el **AVL** o **Splay Trees** si se requiere un rendimiento de búsqueda consistente y balanceado.

**Complejidad General del Programa**

El programa está dominado por dos operaciones principales: la simulación del torneo y el ordenamiento de jugadores. La simulación tiene una complejidad de **O(n^2)**, ya que cada jugador se enfrenta a todos los demás una vez. Al combinar esto con el **Merge Sort** para ordenar la lista de jugadores después de actualizar sus ELOs, la complejidad general del programa se mantiene en **O(n^2)**, que es aceptable dado el tamaño esperado de los datos (un número moderado de jugadores). En situaciones de gran escala, podrían considerarse técnicas adicionales de optimización o paralelización para mejorar el rendimiento.

---

### SICT0302: Toma Decisiones

**Selección del Algoritmo de Ordenamiento**

Para el ordenamiento de los jugadores por ELO, se consideraron los algoritmos **Merge Sort**, **Quick Sort**, y **Bubble Sort**. Después de analizar sus complejidades y características, se eligió **Merge Sort** porque es **estable** (mantiene el orden relativo de elementos iguales) y tiene una complejidad consistente de **O(n log n)**, independientemente del estado inicial de la lista (mejor, promedio y peor caso). Esta característica es crítica para listas que pueden tener valores repetidos y que necesitan ordenarse de manera confiable.

Aunque **Quick Sort** tiene un mejor rendimiento promedio en muchos casos, su peor caso es **O(n^2)**, lo cual puede ser problemático si se enfrenta a listas ya ordenadas o casi ordenadas. **Bubble Sort**, con una complejidad de **O(n^2)** en promedio, fue descartado por su ineficiencia en listas grandes.

En conclusión, **Merge Sort** es más eficaz en este contexto debido a su estabilidad y eficiencia en todos los casos, lo que asegura un rendimiento predecible y evita problemas de degradación de complejidad.

**Selección de la Estructura de Datos**

Para la búsqueda y almacenamiento de jugadores por ELO, se consideraron las estructuras de datos **árbol binario de búsqueda (BST)** y **tablas hash**. La elección final fue el **BST**, principalmente porque permite realizar búsquedas, inserciones y eliminaciones en tiempo promedio **O(log n)** si el árbol está equilibrado. Esto es más adecuado que una tabla hash en este caso, ya que el BST mantiene el orden natural de los datos, lo cual es útil si se desea realizar recorridos en orden o búsquedas de rangos de ELO.

La decisión de usar un BST en lugar de una tabla hash se debe a que el BST proporciona un acceso ordenado, lo cual es fundamental para este proyecto, ya que permite almacenar y consultar eficientemente los jugadores por ELO y mostrarlos en un orden específico si es necesario. Además, el BST ofrece una eficiencia consistente para búsquedas y modificaciones, lo cual es ventajoso para las operaciones de consulta de jugadores.
