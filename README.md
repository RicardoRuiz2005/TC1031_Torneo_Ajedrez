# Proyecto: Torneo de Ajedrez - Simulación y Ordenamiento por ELO

**Autor**: Ricardo Ruiz Cano  
**Matrícula**: A01707233

---

## Overview General del Proyecto

Este proyecto simula un torneo de ajedrez en el cual los jugadores están registrados con sus nombres y valores de ELO, reflejando su nivel de habilidad en el juego. Los jugadores se organizan de mayor a menor según su ELO utilizando el algoritmo **Merge Sort** y compiten en un torneo simulado, donde se enfrentan y sus ELOs se actualizan en función de los resultados de cada partida.

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

1. **Unificación de Datos en una Clase**  
   Se integró la información de los jugadores (nombre y ELO) en una única clase `Jugador`. Esto mejora la organización y el manejo de los datos, haciendo que el código sea más limpio y formal, además de prevenir posibles fallos.

2. **Reestructuración de la Salida**  
   Se mejoró la presentación de los resultados al mostrar la lista de jugadores después del torneo, incluyendo su posición en la lista, lo cual facilita la lectura y comprensión de los resultados.

3. **Mejora en la Simulación del Torneo**  
   La simulación de partidas y ajuste de ELOs se optimizó, haciéndolo más representativo de la competencia real y proporcionando una experiencia más realista al usuario.

4. **Actualización del README**  
   Se modificó el README para describir más claramente las funcionalidades y avances del proyecto, haciendo la documentación más formal y accesible.

5. **Implementación de Búsqueda por ELO**  
   Se añadió la opción de buscar jugadores por su ELO usando un árbol binario de búsqueda (BST), permitiendo a los usuarios encontrar jugadores específicos de manera más eficiente.

---

## Descripción del Avance 3

En este avance, se agregaron nuevas funcionalidades y mejoras al programa.

### Cambios sobre el Segundo Avance

1. **Opción para Imprimir en Archivo**  
   Se añadió la opción de imprimir la lista de jugadores en un archivo de texto (`jugadores.txt`), lo cual permite conservar una copia de los datos generados durante la ejecución del programa.

2. **Reubicación de la Opción de Salida**  
   La opción de salida del programa fue asignada a la opción 6 en el menú, mejorando la organización y claridad del menú de opciones.

3. **Implementación de Carga de Jugadores desde Archivo**  
   Se añadió una función que permite cargar jugadores desde un archivo CSV. Este archivo contiene el nombre y ELO de cada jugador, y el programa los añade automáticamente al BST o a la lista de jugadores.

---

## Instrucciones para Compilar el Proyecto

Para compilar el proyecto, ejecuta el siguiente comando en la terminal:

    g++ main.cpp -o torneo_ajedrez

## Instrucciones para Ejecutar el Proyecto

Para ejecutar el proyecto, utiliza el siguiente comando en la terminal:

    ./torneo_ajedrez

---

## Descripción de las Entradas del Proyecto

El programa no requiere archivos externos para las entradas. Se inicializa con una lista de jugadores predefinidos, pero permite agregar nuevos jugadores durante la ejecución o cargar una lista desde un archivo CSV. Al agregar un jugador, se solicita:

- **Nombre del jugador**: Una cadena de texto.
- **ELO del jugador**: Un número entero entre 1 y 4000.

**Ejemplo de jugadores predefinidos**:

- Magnus Carlsen, ELO: 2852
- Ian Nepomniachtchi, ELO: 2793
- Ding Liren, ELO: 2811
- Fabiano Caruana, ELO: 2786
- Anish Giri, ELO: 2779

---

## Descripción de las Salidas del Proyecto

El programa genera las siguientes salidas:

1. **Lista de jugadores antes del torneo**  
   Muestra los jugadores con sus nombres y ELO iniciales.

2. **Resultados del torneo**  
   Durante la simulación, se muestran los resultados de cada partida y cómo se ajustan los ELOs de los jugadores.

3. **Lista de jugadores después del torneo**  
   Muestra los jugadores ordenados por su ELO actualizado.

4. **Archivo de jugadores**  
   Al seleccionar la opción correspondiente, se genera un archivo `jugadores.txt` con la lista de jugadores y sus ELOs.

---

## Desarrollo de Competencias

### SICT0301: Evalúa los Componentes

**Análisis de Complejidad de los Algoritmos de Ordenamiento**

El algoritmo de ordenamiento seleccionado para este proyecto es **Merge Sort**, una opción adecuada cuando se necesita estabilidad y una complejidad **O(n log n)** en el mejor, promedio y peor caso. **Merge Sort** es un algoritmo de división y conquista que divide la lista en sublistas, las ordena recursivamente y luego las combina. Su estabilidad es clave aquí, ya que mantiene el orden relativo de jugadores con ELO iguales, lo cual es importante en competiciones donde los jugadores pueden tener un rendimiento similar.

**Por qué Merge Sort es adecuado**:  
A diferencia de otros algoritmos como **Quick Sort**, que tiene un peor caso de **O(n^2)**, **Merge Sort** es consistente y eficiente para listas grandes. Aunque **Quick Sort** puede ser más rápido en promedio, su inestabilidad y posible peor caso lo hacen menos confiable para listas ordenadas o parcialmente ordenadas, como las que se usan en este proyecto.

**Análisis Completo de Complejidad de la Estructura de Datos (BST)**

El proyecto utiliza un **árbol binario de búsqueda (BST)** para almacenar y buscar jugadores por ELO. La complejidad de operaciones de búsqueda, inserción y eliminación en un BST equilibrado es **O(log n)**, lo cual es eficiente para manejar consultas rápidas. En el peor caso, si el árbol se desequilibra (por ejemplo, se convierte en una lista enlazada), la complejidad puede aumentar a **O(n)**. Sin embargo, este proyecto no requiere un equilibrio dinámico, ya que el BST se reconstruye periódicamente después de cada torneo.

**Por qué el BST es adecuado**:  
El BST es una estructura flexible y eficiente para almacenar datos ordenados como los ELOs de los jugadores. Su orden natural permite búsquedas rápidas y facilita el recorrido en orden, lo cual es esencial para mostrar los jugadores ordenados por ELO después de cada torneo. Aunque una estructura como un **AVL** o **Splay Tree** podría ofrecer mejor rendimiento en términos de equilibrio, el BST es suficiente para este proyecto y cumple con los requerimientos de eficiencia y simplicidad.

**Complejidad General del Programa**

El programa está dominado por dos operaciones principales: la simulación del torneo y el ordenamiento de jugadores. La simulación tiene una complejidad de **O(n^2)**, ya que cada jugador se enfrenta a todos los demás una vez. Al combinar esto con el **Merge Sort** para ordenar la lista de jugadores después de actualizar sus ELOs, la complejidad general del programa se mantiene en **O(n^2)**, lo cual es aceptable para el número de jugadores manejado en este proyecto.

---

### SICT0302: Toma Decisiones

**Selección del Algoritmo de Ordenamiento**

Para el ordenamiento de los jugadores por ELO, se consideraron los algoritmos **Merge Sort**, **Quick Sort**, y **Bubble Sort**. Se eligió **Merge Sort** por su estabilidad y complejidad consistente de **O(n log n)** en todos los casos. La estabilidad de **Merge Sort** asegura que jugadores con el mismo ELO mantengan su orden relativo, lo cual es importante en un contexto de clasificación.

**Por qué Merge Sort es más eficaz**:  
**Quick Sort** tiene un promedio de **O(n log n)**, pero en el peor caso (si la lista ya está ordenada o casi ordenada) su complejidad puede ser **O(n^2)**, lo cual podría generar un impacto negativo en el rendimiento. **Bubble Sort** fue descartado por su ineficiencia en listas grandes con complejidad **O(n^2)**, que resultaría en tiempos de ejecución inaceptables.

**Selección de la Estructura de Datos**

Para almacenar y consultar jugadores por ELO, se consideraron **BST** y **tablas hash**. Se eligió el **BST** porque permite búsquedas, inserciones y eliminaciones en **O(log n)** en promedio, manteniendo el orden natural de los datos. Una tabla hash no sería adecuada aquí porque no mantiene el orden y complicaría la organización de la lista de jugadores.

**Por qué el BST es más adecuado**:  
El BST es especialmente útil en este proyecto porque permite recorrer los datos en orden. Al final del torneo, esta estructura facilita la impresión de los jugadores ordenados sin necesidad de realizar un ordenamiento adicional. Esto, además de la eficiencia de **O(log n)** en promedio para búsquedas y modificaciones, hace que el BST sea ideal para este tipo de consulta de datos.

---

### SICT0303: Implementa Acciones Científicas

**Implementa Mecanismos para Consultar Información de las Estructuras**

Se implementaron métodos específicos para consultar información de los jugadores usando el BST. La función `BuscarJugadorPorELO` permite buscar un jugador específico por su ELO de forma eficiente.

**Implementa Mecanismos de Lectura de Archivos para Cargar Datos**

Aunque en este avance no se implementó la lectura de archivos para cargar datos, el código está estructurado para incluir fácilmente esta funcionalidad en el futuro. La clase `Jugador` y la estructura `BST` pueden adaptarse para recibir datos de archivos en formatos como CSV.

**Implementa Mecanismos de Escritura de Archivos para Guardar los Datos**

Se añadió la opción de exportar la lista de jugadores a un archivo de texto (`jugadores.txt`). Esto permite que los datos sean accesibles fuera del programa, proporcionando una manera organizada de consultar y preservar la información generada durante la ejecución.
