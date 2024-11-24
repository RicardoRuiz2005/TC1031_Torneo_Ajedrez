# Proyecto: Torneo de Ajedrez - Simulación y Ordenamiento por ELO

**Autor**: Ricardo Ruiz Cano  
**Matrícula**: A01707233

---

## Resumen General del Proyecto

Este proyecto simula un torneo de ajedrez en el cual los jugadores están registrados con sus nombres y valores de ELO, reflejando su nivel de habilidad en el juego. Los jugadores se organizan de mayor a menor según su ELO utilizando el algoritmo `std::sort`, una función estándar de la biblioteca de C++ optimizada para manejar eficientemente el ordenamiento en listas de datos. En el torneo, los jugadores compiten entre sí y sus ELOs se actualizan en función de los resultados de cada partida.

---

## Descripción del Avance 1

En el primer avance del proyecto, se implementaron las funcionalidades principales del programa:

- Registro de jugadores con sus nombres y valores de ELO.
- Visualización de la lista de jugadores con sus ELOs.
- Ordenamiento de los jugadores usando `std::sort` para organizar de mayor a menor ELO.
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
   Se añadió la opción de buscar jugadores por su ELO usando un árbol binario de búsqueda (BST), permitiendo a los usuarios encontrar jugadores específicos de manera más eficiente. El BST también se utiliza para almacenar y organizar los jugadores, con la posibilidad de imprimirlos en orden por su ELO.

---

## Descripción del Avance 3

En este avance, se agregaron nuevas funcionalidades y mejoras al programa.

### Cambios sobre el Segundo Avance

1. **Opción para Imprimir en Archivo**  
   Se añadió la opción de imprimir la lista de jugadores en un archivo de texto (`jugadores.txt`), lo cual permite conservar una copia de los datos generados durante la ejecución del programa.

2. **Reubicación de la Opción de Salida**  
   La opción de salida del programa fue asignada a la opción 7 en el menú, mejorando la organización y claridad del menú de opciones.

3. **Implementación de Carga de Jugadores desde Archivo**  
   Se añadió una función que permite cargar jugadores desde un archivo jugadores.txt . Este archivo contiene el nombre y ELO de cada jugador, y el programa los añade automáticamente al BST o a la lista de jugadores.

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
   Durante la simulación, se muestran los resultados de cada partida y cómo se ajustan los ELOs de los jugadores. La simulación incluye condiciones simplificadas para empates basadas en un valor aleatorio y la diferencia de ELO.

3. **Lista de jugadores después del torneo**  
   Muestra los jugadores ordenados por su ELO actualizado.

4. **Archivo de jugadores**  
   Al seleccionar la opción correspondiente, se genera un archivo `jugadores.txt` con la lista de jugadores y sus ELOs.

---

## Desarrollo de Competencias

### SICT0301: Evalúa los Componentes

**Análisis de Complejidad Completo**

1. **Simulación del Torneo**:  
   La simulación de un torneo entre `n` jugadores requiere que cada jugador se enfrente a todos los demás, resultando en una complejidad de **O(n²)**, ya que cada partida involucra una actualización del ELO. En el mejor caso, la complejidad sigue siendo **O(n²)**, pues cada jugador debe participar en las mismas comparaciones independientemente de los resultados. Esta es la operación dominante en el programa.

2. **Uso de `std::sort` para Ordenamiento**:  
   Utilizado para ordenar los jugadores por ELO después del torneo, `std::sort` tiene una complejidad de **O(n log n)** en promedio y en el mejor caso, aunque en el peor caso puede llegar a **O(n²)**.

   - **Caso Promedio**: `std::sort` realiza ordenamiento en **O(n log n)** en promedio debido a la estructura de Quick Sort, que divide la lista en subconjuntos y ordena cada subconjunto de manera recursiva. Esta eficiencia es particularmente útil para listas grandes, ya que reduce el número de comparaciones y particiones necesarias.

   - **Mejor Caso**: En el mejor escenario, **O(n log n)**, ocurre cuando la lista está en un estado cercano al orden requerido, permitiendo que el algoritmo aproveche su eficiencia al evitar divisiones innecesarias.

   - **Peor Caso**: **O(n²)**. Esto sucede si los elementos están en un orden que causa particiones desequilibradas, como si la lista ya está casi completamente ordenada o inversamente ordenada. Sin embargo, `std::sort` implementa técnicas para minimizar la probabilidad de este caso, como usar un algoritmo híbrido (incluso combinando Quick Sort con Heap Sort o Insertion Sort para manejar listas pequeñas o parcialmente ordenadas).

**Complejidad General del Programa**:  
La complejidad general está dominada por la simulación de partidas, lo que resulta en **O(n²)**. Combinando esto con el ordenamiento y las operaciones de búsqueda e inserción, el rendimiento es adecuado para el contexto de este proyecto, que no maneja listas extremadamente grandes.

### SICT0302: Toma Decisiones

**Selección del Algoritmo de Ordenamiento**

Se eligió `std::sort` debido a su alta eficiencia promedio y a la optimización inherente de la biblioteca estándar de C++. Aunque **Merge Sort** fue considerado debido a su estabilidad (mantiene el orden relativo en caso de valores iguales), se descartó porque en este contexto la estabilidad no es un requisito estricto, ya que los ELOs son únicos o el orden exacto en empates no afecta al proyecto. Además, `std::sort` reduce el tiempo de ejecución gracias a su enfoque adaptativo de algoritmos híbridos, lo cual es útil en listas de datos moderadas como esta.

**Selección de la Estructura de Datos**

El **BST** fue elegido por su simplicidad y eficiencia en **O(log n)** promedio para inserciones y búsquedas, manteniendo el orden natural de los datos. También se consideraron estructuras como **AVL Tree** y **Splay Tree**, pero fueron descartadas debido a su complejidad de implementación y el sobrecosto de equilibrio en cada inserción.

**Justificación del BST**:  
El BST proporciona una estructura fácil de implementar y eficiente para manejar una cantidad moderada de datos. Aunque un **AVL Tree** o **Splay Tree** podría mejorar el rendimiento en búsquedas intensivas, el BST es suficiente para este proyecto, que no requiere un equilibrio continuo ni una alta frecuencia de consultas.

### SICT0303: Implementa Acciones Científicas

**Cálculo de ELO en la Simulación**

En cada partida, el cálculo del ELO se realiza utilizando el modelo de puntuación ELO, donde la probabilidad de que un jugador gane se calcula en función de la diferencia de ELOs. Después de cada partida, se ajustan los ELOs de los jugadores:

1. **Probabilidad de Victoria**: Calculada con la fórmula:
   \[
   P(A) = \frac{1}{1 + 10^{(ELO_B - ELO_A) / 400}}
   \]

2. **Actualización de ELO**: La puntuación ELO de cada jugador se ajusta según el resultado de la partida, utilizando una constante de ajuste (K-Factor). La simulación actual incluye una lógica simplificada para el empate, condicionada por el valor aleatorio y la diferencia de ELO entre jugadores.

**Implementa Mecanismos de Lectura y Escritura de Archivos**

Se implementó la función de carga de jugadores desde un archivo jugadores.txt, validando el formato de cada línea y el rango de ELO. La opción de exportar la lista de jugadores a un archivo de texto (`jugadores.txt`) también permite conservar los datos generados.

---

## Referencia a la Guía de Estilos

Para mantener la coherencia y legibilidad del código, se utilizó la [Guía de Estilo de Google para C++](https://google.github.io/styleguide/cppguide.html) como referencia. Donde aplique las siguientes prácticas:

- **Nombres descriptivos** para variables y funciones, evitando abreviaturas ambiguas.
- **Comentarios explicativos** en funciones clave, describiendo propósito, parámetros, salida y complejidad.
- **Consistencia en el formato** de indentación, llaves y espacios para mejorar la legibilidad.

Estas prácticas ayudan a garantizar que el código sea claro y mantenible.







LINK DE LOS VIDEOS:

- Problema 1: Algoritmos de ordenamiento

Link: https://leetcode.com/problems/sort-the-jumbled-numbers/

RESUELTO: https://leetcode.com/problems/sort-the-jumbled-numbers/submissions/1443842785

Video: https://drive.google.com/file/d/1LJE8wcIw57dwTy4BpMHYgZBKiSIJetcu/view?usp=sharing

- Problema 2: Estructura de datos lineales

Link: https://leetcode.com/problems/odd-even-linked-list/description/

RESUELTO: https://leetcode.com/problems/odd-even-linked-list/submissions/1443938816

Video:
https://drive.google.com/file/d/1Tjt-yV5Ms2ZviuoETMy_UA968Jomul8y/view?usp=sharing

- Problema 3: Estructura de datos no lineales
  
Link: https://leetcode.com/problems/validate-binary-tree-nodes/

RESUELTO: https://leetcode.com/problems/validate-binary-tree-nodes/description/

Video:
https://drive.google.com/file/d/11fPW95jfds4Nk4v-Vo2xapn9sgaCtTK_/view?usp=sharing
