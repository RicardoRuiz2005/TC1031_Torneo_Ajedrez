Proyecto: Torneo de Ajedrez - Simulación y Ordenamiento por ELO
Este proyecto simula un torneo de ajedrez donde los jugadores son registrados con sus nombres y valores de ELO, lo que refleja su nivel de habilidad en el juego. Los jugadores se ordenan de mayor a menor según su ELO usando el algoritmo Merge Sort. El objetivo es organizar a los jugadores de manera eficiente y simular sus enfrentamientos, mostrando cómo varía su ELO después de cada partida.

Descripción del avance 1
En este primer avance del proyecto, se implementan las funcionalidades principales del programa:
Registro de jugadores con sus nombres y valores de ELO.
Visualización de la lista de jugadores con sus ELOs.
Ordenamiento de los jugadores usando Merge Sort, ordenando de mayor a menor ELO.
Simulación de un torneo, donde se enfrentan los jugadores y sus ELOs se actualizan en función de los resultados de los partidos.
Al finalizar, se muestra la lista de jugadores ordenados por su ELO actualizado tras el torneo.

Descripción de las entradas del avance de proyecto
El programa no requiere archivos externos para las entradas. Se inicializa con una lista de jugadores predefinidos, pero también permite agregar nuevos jugadores durante la ejecución.
Ejemplo de jugadores predefinidos:
Magnus Carlsen, ELO: 2852
Ian Nepomniachtchi, ELO: 2793
Ding Liren, ELO: 2811
Fabiano Caruana, ELO: 2786
Anish Giri, ELO: 2779
El usuario puede agregar jugadores adicionales proporcionando el nombre y el ELO en el programa.

Descripción de las salidas del avance de proyecto
Al ejecutar el programa, obtendrás los siguientes resultados:
Lista de jugadores antes del torneo: Se imprime la lista de jugadores con sus nombres y ELO en el orden en que fueron registrados.
Resultados del torneo: El programa simula los enfrentamientos entre los jugadores, mostrando quién ganó o si hubo un empate. Luego, se actualizan los ELOs de los jugadores en función de los resultados.
Lista de jugadores después del torneo: Una vez que el torneo ha concluido, se imprime la lista de jugadores ordenada por su ELO de mayor a menor.

Desarrollo de competencias
SICT0301: Evalúa los componentes
En este avance, se realizó un análisis de la eficiencia de los componentes clave del programa, principalmente el algoritmo Merge Sort, que es utilizado para ordenar los jugadores por ELO.
Análisis de complejidad:
Inserción de jugadores: La inserción de un jugador en la lista tiene una complejidad de O(1), es decir, la operación se realiza de manera instantánea porque solo se agrega al final de la lista. En casos donde la capacidad de la lista se llena y necesita más espacio, podría aumentar temporalmente a O(n), pero esto sucede raramente.
Búsqueda e impresión de jugadores: Para mostrar la lista de jugadores, el programa recorre cada uno de ellos, lo que implica una complejidad de O(n), ya que revisa todos los jugadores uno por uno.
Ordenamiento de jugadores (Merge Sort): El algoritmo Merge Sort utilizado para ordenar la lista tiene una complejidad de O(n log n), lo que lo hace muy eficiente incluso para listas grandes. Esto significa que, si tienes más jugadores, el tiempo de ordenamiento crece de forma moderada.
Análisis del Mejor, Peor y Caso Promedio de Merge Sort:
Mejor caso: El mejor caso para Merge Sort ocurre cuando la lista ya está ordenada. Aún en este caso, Merge Sort siempre divide y combina las listas de manera recursiva, por lo que la complejidad sigue siendo O(n log n). A diferencia de otros algoritmos, como Quick Sort, Merge Sort no tiene un mejor rendimiento si la lista ya está ordenada.
Caso promedio: En la mayoría de las veces, cuando el orden de la lista es aleatorio, el comportamiento de Merge Sort sigue siendo O(n log n). Esto significa que la eficiencia del algoritmo no cambia dependiendo del nivel de desorden en la lista.
Peor caso: Incluso en el peor de los casos (cuando la lista está completamente desordenada), la complejidad sigue siendo O(n log n). Merge Sort es estable y eficiente en el peor escenario, lo que lo hace una elección sólida para ordenar grandes cantidades de datos.
En resumen, Merge Sort es un algoritmo que siempre tiene un comportamiento predecible y eficiente, sin importar el nivel de desorden de los datos. Su estabilidad y eficiencia hacen que sea una excelente opción para este tipo de problemas.

SICT0302: Toma decisiones
Se eligió el algoritmo Merge Sort para ordenar los jugadores por ELO debido a su eficiencia y estabilidad. Merge Sort garantiza una complejidad O(n log n) en todos los casos, lo que lo hace ideal para ordenar los jugadores independientemente del tamaño de la lista.
Justificación:
Merge Sort fue seleccionado porque tiene un rendimiento consistente, sin importar si la lista ya está ordenada o completamente desordenada. Además, es un algoritmo estable, lo que significa que si dos jugadores tienen el mismo ELO, se mantendrá el orden en que fueron registrados inicialmente. Esto puede ser útil en situaciones donde jugadores tienen habilidades similares.
Este algoritmo ha demostrado ser una buena elección para este proyecto, ya que asegura que la ordenación de los jugadores por ELO sea rápida y eficiente, ayudando a que el programa funcione de manera fluida incluso con listas grandes.
