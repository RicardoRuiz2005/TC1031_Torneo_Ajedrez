# Proyecto: Torneo de Ajedrez - Simulación y Ordenamiento por ELO

Este proyecto simula un torneo de ajedrez donde los jugadores son registrados con sus nombres y valores de ELO, lo que refleja su nivel de habilidad en el juego. Los jugadores se ordenan de mayor a menor según su ELO usando el algoritmo **Merge Sort**. El objetivo es organizar a los jugadores de manera eficiente y simular sus enfrentamientos, mostrando cómo varía su ELO después de cada partida.

---

## Descripción del avance 1

En este primer avance del proyecto, se implementan las funcionalidades principales del programa:
- Registro de jugadores con sus nombres y valores de ELO.
- Visualización de la lista de jugadores con sus ELOs.
- Ordenamiento de los jugadores usando **Merge Sort**, ordenando de mayor a menor ELO.
- Simulación de un torneo, donde se enfrentan los jugadores y sus ELOs se actualizan en función de los resultados de los partidos.
- Al finalizar, se muestra la lista de jugadores ordenados por su ELO actualizado tras el torneo.

---

## Instrucciones para compilar el avance de proyecto

Para compilar el programa, ejecuta el siguiente comando en la terminal:

```bash
g++ mainAjedrez.cpp -o mainAjedrez
Instrucciones para ejecutar el avance de proyecto
Después de compilar, ejecuta el programa con este comando:

bash
Copiar código
./mainAjedrez
Descripción de las entradas del avance de proyecto
El programa no requiere archivos externos para las entradas. Se inicializa con una lista de jugadores predefinidos, pero también permite agregar nuevos jugadores durante la ejecución.

Ejemplo de jugadores predefinidos:

text
Copiar código
1. Magnus Carlsen, ELO: 2852
2. Ian Nepomniachtchi, ELO: 2793
3. Ding Liren, ELO: 2811
4. Fabiano Caruana, ELO: 2786
5. Anish Giri, ELO: 2779
El usuario puede agregar jugadores adicionales proporcionando el nombre y el ELO en el programa.

Descripción de las salidas del avance de proyecto
Al ejecutar el programa, obtendrás los siguientes resultados:

Lista de jugadores antes del torneo: Se imprime la lista de jugadores con sus nombres y ELO en el orden en que fueron registrados.

Resultados del torneo: El programa simula los enfrentamientos entre los jugadores, mostrando quién ganó o si hubo un empate. Luego, actualiza los ELOs de los jugadores en función de los resultados.

Lista de jugadores después del torneo: Una vez que el torneo ha concluido, se imprime la lista de jugadores ordenada por su ELO de mayor a menor.

Desarrollo de competencias
SICT0301: Evalúa los componentes
En este avance, se realizó un análisis de la complejidad de los componentes clave del programa. El algoritmo principal, Merge Sort, tiene una complejidad de O(n log n), lo que es eficiente para ordenar listas grandes de jugadores.

Análisis de complejidad:

Inserción de jugadores en el vector: La inserción de jugadores tiene una complejidad O(1) amortiguada. El redimensionamiento del vector en caso de que se quede sin espacio puede ser O(n), pero eso ocurre de forma ocasional.
Búsqueda e impresión de jugadores: Se recorre la lista de jugadores para mostrarlos, lo que tiene una complejidad O(n).
Ordenamiento de jugadores (Merge Sort): La ordenación tiene una complejidad O(n log n), garantizando un rendimiento eficiente para listas grandes de jugadores.
Este análisis demuestra que se ha evaluado correctamente la complejidad de los algoritmos implementados en el programa.

SICT0302: Toma decisiones
Se eligió el algoritmo Merge Sort para ordenar los jugadores por ELO debido a su eficiencia y estabilidad. Merge Sort garantiza una complejidad O(n log n) en todos los casos, lo que lo hace ideal para ordenar los jugadores independientemente del tamaño de la lista.

Justificación:

Merge Sort se seleccionó porque siempre tiene un rendimiento consistente, sin importar si la lista ya está parcialmente ordenada





Tú dijiste:
vuelve a mandar, por favor
ChatGPT Plus
ChatGPT
Aquí tienes el texto completo en formato Markdown, listo para que lo copies y pegues directamente en GitHub:

markdown
Copiar código
# Proyecto: Torneo de Ajedrez - Simulación y Ordenamiento por ELO

Este proyecto simula un torneo de ajedrez donde los jugadores son registrados con sus nombres y valores de ELO, lo que refleja su nivel de habilidad en el juego. Los jugadores se ordenan de mayor a menor según su ELO usando el algoritmo **Merge Sort**. El objetivo es organizar a los jugadores de manera eficiente y simular sus enfrentamientos, mostrando cómo varía su ELO después de cada partida.

---

## Descripción del avance 1

En este primer avance del proyecto, se implementan las funcionalidades principales del programa:
- Registro de jugadores con sus nombres y valores de ELO.
- Visualización de la lista de jugadores con sus ELOs.
- Ordenamiento de los jugadores usando **Merge Sort**, ordenando de mayor a menor ELO.
- Simulación de un torneo, donde se enfrentan los jugadores y sus ELOs se actualizan en función de los resultados de los partidos.
- Al finalizar, se muestra la lista de jugadores ordenados por su ELO actualizado tras el torneo.

---

## Instrucciones para compilar el avance de proyecto

Para compilar el programa, ejecuta el siguiente comando en la terminal:

```bash
g++ mainAjedrez.cpp -o mainAjedrez
Instrucciones para ejecutar el avance de proyecto
Después de compilar, ejecuta el programa con este comando:

bash
Copiar código
./mainAjedrez
Descripción de las entradas del avance de proyecto
El programa no requiere archivos externos para las entradas. Se inicializa con una lista de jugadores predefinidos, pero también permite agregar nuevos jugadores durante la ejecución.

Ejemplo de jugadores predefinidos:

text
Copiar código
1. Magnus Carlsen, ELO: 2852
2. Ian Nepomniachtchi, ELO: 2793
3. Ding Liren, ELO: 2811
4. Fabiano Caruana, ELO: 2786
5. Anish Giri, ELO: 2779
El usuario puede agregar jugadores adicionales proporcionando el nombre y el ELO en el programa.

Descripción de las salidas del avance de proyecto
Al ejecutar el programa, obtendrás los siguientes resultados:

Lista de jugadores antes del torneo: Se imprime la lista de jugadores con sus nombres y ELO en el orden en que fueron registrados.

Resultados del torneo: El programa simula los enfrentamientos entre los jugadores, mostrando quién ganó o si hubo un empate. Luego, actualiza los ELOs de los jugadores en función de los resultados.

Lista de jugadores después del torneo: Una vez que el torneo ha concluido, se imprime la lista de jugadores ordenada por su ELO de mayor a menor.

Desarrollo de competencias
SICT0301: Evalúa los componentes
En este avance, se realizó un análisis de la complejidad de los componentes clave del programa. El algoritmo principal, Merge Sort, tiene una complejidad de O(n log n), lo que es eficiente para ordenar listas grandes de jugadores.

Análisis de complejidad:

Inserción de jugadores en el vector: La inserción de jugadores tiene una complejidad O(1) amortiguada. El redimensionamiento del vector en caso de que se quede sin espacio puede ser O(n), pero eso ocurre de forma ocasional.
Búsqueda e impresión de jugadores: Se recorre la lista de jugadores para mostrarlos, lo que tiene una complejidad O(n).
Ordenamiento de jugadores (Merge Sort): La ordenación tiene una complejidad O(n log n), garantizando un rendimiento eficiente para listas grandes de jugadores.
Este análisis demuestra que se ha evaluado correctamente la complejidad de los algoritmos implementados en el programa.

SICT0302: Toma decisiones
Se eligió el algoritmo Merge Sort para ordenar los jugadores por ELO debido a su eficiencia y estabilidad. Merge Sort garantiza una complejidad O(n log n) en todos los casos, lo que lo hace ideal para ordenar los jugadores independientemente del tamaño de la lista.

Justificación:

Merge Sort se seleccionó porque siempre tiene un rendimiento consistente, sin importar si la lista ya está parcialmente ordenada o desordenada.
Además, es un algoritmo estable, lo que significa que los jugadores con el mismo ELO mantendrán su orden relativo de inserción, lo cual puede ser útil si se registran jugadores con el mismo nivel de habilidad.
Al usar este algoritmo correctamente en el contexto del problema, se ha demostrado una toma de decisiones basada en la necesidad de eficiencia y estabilidad en la ordenación de datos.

