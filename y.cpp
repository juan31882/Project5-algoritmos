#include <stdio.h>    // Proporciona funciones para entrada y salida estándar, como printf() y scanf().
#include <stdlib.h>   // Proporciona funciones para gestión de memoria dinámica, como malloc() y free().
#include <time.h>     // Proporciona funciones para manejar el tiempo y generar números aleatorios, como time().
#include <vector>     // Proporciona la clase vector, que es un contenedor dinámico de la biblioteca estándar de C++.
#include <algorithm>  // Proporciona algoritmos para manipular elementos en contenedores, como sort() y find().
#include <math.h>     // Proporciona funciones matemáticas
#include <locale.h>
#define MAX_SIZE 5000 // Esta línea define una macro llamada MAX_SIZE con un valor de 5000. Las macros se utilizan para definir 
//constantes que se pueden usar en todo el programa. En este caso, MAX_SIZE se puede usar como un tamaño máximo para algún arreglo o estructura de datos.

int iterations;// se declara una variable llamada iterations. Esta variable es de tipo entero y 
//se utiliza para almacenar el número de iteraciones en algún bucle o algoritmo dentro del programa.


void swap(int *a, int *b) { //define una función llamada swap que intercambia los valores de dos variables enteras. La función toma dos punteros a enteros como argumentos.
    int temp = *a; //e declara una variable temporal llamada temp y se le asigna el valor al que apunta el puntero a.
    *a = *b; //Se asigna el valor al que apunta b a la dirección de memoria a la que apunta a.
    *b = temp; //Se asigna el valor almacenado en la variable temporal a la dirección de memoria a la que apunta b, es decir, el valor original de a se guarda en b.
}

void printArray(int arr[], int size) { //define una función llamada printArray que imprime los elementos de un arreglo de enteros. 
//La función toma dos argumentos: arr, que es un arreglo de enteros, y size, que es el tamaño del arreglo.
    for (int i = 0; i < size; i++) {
// Inicia un bucle 'for' para iterar sobre los elementos del arreglo.
// Se inicializa una variable 'i' en 0, que servirá como contador de índice.
// El bucle continuará mientras 'i' sea menor que el tamaño del arreglo 'size'.
// En cada iteración, 'i' se incrementará en 1.
        printf("%d ", arr[i]);
        // Imprime el valor del elemento del arreglo en el índice 'i'.
// 'arr[i]' accede al elemento en la posición 'i' del arreglo 'arr'.
// Se imprime seguido de un espacio para separar los elementos en la salida.

    }
    printf("\n"); // Después del bucle, se imprime una nueva línea para que la próxima salida se imprima en la línea siguiente.
}

int readNumbersFromFile(int arr[], char filename[]) {
	// Función que lee números de un archivo y los almacena en un arreglo.
// Toma como argumentos un arreglo 'arr' donde se guardarán los números leídos,y el nombre del archivo 'filename' del que se leerán los números.
// Devuelve el número de elementos leídos y almacenados en el arreglo.

    FILE *file = fopen(filename, "r");
    // Abre un archivo en modo de lectura ("r"). 'filename' es el nombre del archivo a abrir.
// fopen' devuelve un puntero al tipo FILE que apunta al archivo abierto. Si el archivo no se puede abrir, devuelve NULL.
// La variable 'file' almacenará este puntero.
    if (file == NULL) {// Comprueba si 'file' es NULL, lo cual indicaría un fallo al abrir el archivo.
// Si 'file' es NULL, significa que el archivo no se pudo abrir.

    perror("Error al abrir el archivo para lectura"); // La función perror() imprime un mensaje de error basado en el valor actual de errno.'errno' es una variable global que almacena el código de error más reciente generado por una función del sistema.
// Si fopen() devuelve NULL (indicando que no se pudo abrir el archivo), perror() proporciona una descripción detallada del error que ocurrió durante la apertura del archivo.

    return 0;
    } // Si se produce un error al abrir el archivo, la función devuelve 0 para indicar un fallo.No se pudo leer ningún número del archivo, así que se retorna 0. La función termina aquí y no continúa con la lectura del archivo.


    int count = 0;
    printf("Contenido del archivo:\n");
    while (fscanf(file, "%d", &arr[count]) != EOF && count < MAX_SIZE) {
        printf("%d ", arr[count]);
        count++;
    } 
    printf("\n"); // Inicializa un contador 'count' para seguir la cantidad de números leídos.Imprime un mensaje para indicar que se mostrará el contenido del archivo.
// Lee los números del archivo mientras no se llegue al final del archivo (EOF) y no se exceda el tamaño máximo del arreglo (MAX_SIZE).
// En cada iteración, se guarda el número leído en 'arr[count]'.Se imprime el número leído seguido de un espacio.Finalmente, se imprime una nueva línea para separar la salida.


    fclose(file);
    return count;
} // Cierra el archivo después de haber terminado de leer.y Devuelve el número total de elementos leídos y almacenados en el arreglo.

// Función para guardar una lista de números en un archivo.Toma como argumentos un arreglo de números 'arr' y su tamaño 'n',y el nombre del archivo 'filename' donde se guardarán los números.
void saveToFile(int arr[], int n, char filename[]) {

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error al abrir el archivo para escritura.\n");
        return;
    } // Abre el archivo especificado en modo de escritura ("w").
// 'filename' es el nombre del archivo a abrir.
// Si el archivo no se puede abrir, muestra un mensaje de error y retorna sin hacer nada.


    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", arr[i]);
    } // Recorre el arreglo 'arr' e imprime cada elemento en el archivo.
// Utiliza fprintf() para imprimir cada elemento en el archivo. Se imprime cada número seguido de un salto de línea ('\n')

    fclose(file);
    printf("Lista de números guardada en %s\n", filename);
}// Cierra el archivo después de haber terminado de escribir.
// Muestra un mensaje indicando que la lista de números se ha guardado en el archivo especificado.


// Función para mostrar la lista actual de números en la consola.toma como argumentos un arreglo de números 'arr' y su tamaño 'n'.
void showList(int arr[], int n) {
    printf("Lista actual de números:\n"); // Imprime un mensaje indicando que se mostrará la lista de números.Este mensaje sirve como encabezado antes de imprimir la lista.

    printArray(arr, n);// Utiliza la función printArray() para imprimir la lista de números.'arr' es el arreglo que contiene los números a imprimir.
// 'n' es el tamaño del arreglo.La función printArray() se encarga de imprimir cada número en el arreglo.

}

// Función para ordenar un arreglo de números utilizando el algoritmo Bubble Sort.Toma como argumentos un arreglo de números 'arr' y su tamaño 'n'.
void bubbleSort(int arr[], int n) {
    int iterations = 0;// Se inicializa una variable 'iterations' para contar el número de iteraciones del algoritmo.
    clock_t start, end;// Se declara 'start' y 'end' como variables del tipo clock_t para medir el tiempo de ejecución.
    start = clock();// Se guarda el tiempo de inicio de la ejecución del algoritmo en 'start'.

    for (int i = 0; i < n - 1; i++) {// Bucle externo para iterar sobre todos los elementos del arreglo, excepto el último. Este bucle se ejecuta n - 1 veces, donde 'n' es el tamaño del arreglo.
// Cada iteración de este bucle representa una pasada completa a través del arreglo.

        bool swapped = false;// Se declara una variable booleana llamada 'swapped'.Esta variable se utiliza para indicar si se realizó algún intercambio durante una pasada del algoritmo Bubble Sort.

        for (int j = 0; j < n - i - 1; j++) {
            iterations++;// Bucle interno para comparar elementos y realizar intercambios.Este bucle se ejecuta n - i - 1 veces en cada pasada, donde 'i' es el número de pasadas completadas.
// Cada iteración compara un elemento con el siguiente y realiza un intercambio si es necesario.'iterations' se incrementa en cada comparación.

            if (arr[j] > arr[j + 1]) {// Si el elemento actual es mayor que el siguiente, se intercambian.
                swap(&arr[j], &arr[j + 1]);// Se llama a la función 'swap' para intercambiar los elementos.
                swapped = true;// Se establece 'swapped' en verdadero si se realiza algún intercambio en la pasada actual.

            }
        }
        if (!swapped) {// Si no se realizó ningún intercambio en la pasada actual, el arreglo ya está ordenado.
            break;// Por lo tanto, se sale del bucle externo antes de completar todas las pasadas.
        }
    }
    end = clock();// Se guarda el tiempo de finalización de la ejecución del algoritmo en 'end'.
    printf("Bubble Sort: ");// Se imprime el arreglo ordenado después de aplicar Bubble Sort.
    printArray(arr, n);// Llama a la función printArray() para imprimir los elementos del arreglo 'arr'.'arr' es el arreglo que contiene los números que se imprimirán.
//'n' es el número de elementos en el arreglo.Esta función se encarga de imprimir cada elemento del arreglo, separados por un espacio.

    printf("Número de iteraciones: %d\n", iterations);// Se imprime el número total de iteraciones realizadas por el algoritmo.
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;// Calcula el tiempo total de ejecución del algoritmo en segundos.'end - start' calcula la diferencia de tiempo entre el momento en que se guarda 'start' y 'end'.
// Se convierte la diferencia de tiempo a tipo 'double' para obtener una precisión decimal adecuada.Se divide por 'CLOCKS_PER_SEC' para convertir los ciclos del reloj a segundos.
// El resultado se almacena en 'time_taken'.
    printf("Tiempo de ejecución: %.6f segundos\n", time_taken);// Imprime el tiempo de ejecución del algoritmo en segundos con una precisión de 6 decimales.
// Utiliza el formato "%.6f" para imprimir el valor de 'time_taken'.'time_taken' es el tiempo total de ejecución del algoritmo en segundos.

    time_taken *= 1000; // Convertir a milisegundos
    printf("Tiempo de ejecución: %.3f milisegundos\n", time_taken); // Imprimir el tiempo en milisegundos
}


// Función para ordenar un arreglo utilizando el algoritmo Bucket Sort.
void bucketSort(int arr[], int n) {//Toma como argumentos un arreglo de enteros 'arr' y su tamaño 'n'.
    int max_val = arr[0];// Se inicializa una variable para almacenar el valor máximo del arreglo.
    // Se declara una variable 'max_val' y se inicializa con el primer elemento del arreglo 'arr'.
// Esta variable se utilizará para encontrar el valor máximo en el arreglo.

// Bucle para encontrar el valor máximo en el arreglo.
    for (int i = 1; i < n; i++) {// Se inicia un bucle 'for' para recorrer el arreglo desde el segundo elemento hasta el último.Se excluye el primer elemento del arreglo ya que ya se ha asignado a 'max_val'.
        if (arr[i] > max_val) {// Comprueba si el elemento actual es mayor que el valor máximo encontrado hasta ahora.
        // Se compara el elemento actual del arreglo con el valor máximo encontrado hasta el momento.Si el elemento actual es mayor que 'max_val', se actualizará 'max_val' con el valor del elemento actual.
            max_val = arr[i];// Si es así, actualiza el valor máximo
            // Si el elemento actual es mayor que 'max_val', se actualiza 'max_val' con el valor del elemento actual.
        }
    }

    int buckets = n / 10 + 1; // Ajustar el número de cubos,Se calcula el número de cubos que se utilizarán en el algoritmo Bucket Sort.
// Se divide el número total de elementos 'n' por 10 y se suma 1 para ajustar el número de cubos.Esto asegura que cada cubo tenga un tamaño adecuado para manejar los elementos del arreglo.

    int **bucket = (int **)malloc(buckets * sizeof(int *)); // Crear un arreglo de punteros para almacenar los cubos
    // Se utiliza 'malloc' para asignar memoria dinámica para 'buckets' punteros.Cada puntero en 'bucket' apuntará a un arreglo dinámico que contendrá los elementos de un cubo.

    // Inicializar cada cubo como un arreglo dinámico
    for (int i = 0; i < buckets; i++) {
    	// Bucle para inicializar cada cubo del arreglo 'bucket'.
// 'i' representa el índice de cada cubo en el arreglo 'bucket'.
// El bucle se ejecuta desde 0 hasta 'buckets - 1' para inicializar cada cubo.
        bucket[i] = (int *)malloc(n * sizeof(int));
        // Se utiliza 'malloc' para asignar memoria dinámica para el arreglo de enteros dentro de cada cubo.
// 'n * sizeof(int)' calcula el tamaño necesario para almacenar 'n' enteros en cada cubo.
// 'int *' se utiliza para convertir el puntero devuelto por 'malloc' en un puntero a un arreglo de enteros.
// Se asigna la memoria recién asignada al 'i-ésimo' cubo del arreglo 'bucket'.

    }

    // Inicializar el contador de elementos en cada cubo
    int bucket_count[buckets] = {0};// Se crea un arreglo para contar cuántos elementos hay en cada cubo.
// 'bucket_count' es un arreglo de enteros donde cada elemento representa el número de elementos en el cubo correspondiente.
// Se inicializa con todos los elementos en 0.


    // Asignar cada elemento al cubo correspondiente
    for (int i = 0; i < n; i++) {
        int bucket_index = (arr[i] * buckets) / (max_val + 1); 
        bucket[bucket_index][bucket_count[bucket_index]++] = arr[i]; // Agregar el elemento al cubo correspondiente
        // Se asigna cada elemento del arreglo original al cubo correspondiente.
// Se utiliza la fórmula (arr[i] * buckets) / (max_val + 1) para calcular el índice del cubo.
// Se incrementa el contador de elementos en el cubo correspondiente.
// Cada elemento se agrega al cubo y se incrementa el contador de elementos de ese cubo.
    }

    // Ordenar cada cubo y copiar los elementos ordenados al arreglo original
    int index = 0;
    for (int i = 0; i < buckets; i++) {
        for (int j = 0; j < bucket_count[i]; j++) {
            for (int k = j + 1; k < bucket_count[i]; k++) {
                if (bucket[i][j] > bucket[i][k]) {
                    swap(&bucket[i][j], &bucket[i][k]);
                }
            }
            arr[index++] = bucket[i][j]; 
            // Se ordenan los elementos de cada cubo utilizando el algoritmo de ordenamiento de burbuja.
// Se recorren todos los cubos y sus elementos respectivos.
// Para cada cubo:
//     - Se utiliza un bucle anidado para comparar cada par de elementos adyacentes.
//     - Si un elemento es mayor que el siguiente, se intercambian.
//     - Esto coloca los elementos en orden ascendente dentro de cada cubo.
// Después de ordenar cada cubo, se copian los elementos ordenados de vuelta al arreglo original.
// 'index' se utiliza para rastrear la posición en el arreglo original.
// Los elementos ordenados de cada cubo se copian secuencialmente en el arreglo original 'arr'.

        }
    }

    // Liberar la memoria asignada para cada cubo
    for (int i = 0; i < buckets; i++) {
        free(bucket[i]);
        // Se libera la memoria asignada para cada cubo del arreglo 'bucket'.
// Se utiliza un bucle para recorrer todos los cubos.
// Dentro del bucle, 'free' libera la memoria asignada para cada arreglo de enteros dentro de 'bucket'.

    }
    free(bucket);
    // Finalmente, se libera la memoria asignada para el arreglo de punteros 'bucket' en sí.
// Esto libera la memoria asignada para los punteros de los cubos.


    printf("Lista ordenada: ");
    printArray(arr, n);
    // Se imprime el encabezado "Lista ordenada:" en la consola.
// Se utiliza la función printArray() para imprimir el arreglo 'arr' ordenado.
// 'arr' es el arreglo original que ahora contiene los elementos ordenados.
// 'n' es el número total de elementos en el arreglo.


    // Calcular el número de iteraciones (es la suma del tamaño de cada cubo)
    int iterations = 0;// Se declara una variable 'iterations' para almacenar el número total de iteraciones.
// 'iterations' se inicializa en 0 y luego se incrementa agregando el tamaño de cada cubo.
// El número total de iteraciones es la suma del tamaño de todos los cubos, es decir, la cantidad total de elementos.

    for (int i = 0; i < buckets; i++) {
        iterations += bucket_count[i];
        // Se utiliza un bucle para sumar el tamaño de cada cubo al total de iteraciones.
// Se recorren todos los cubos y se suma el número de elementos en cada uno de ellos.
// 'bucket_count[i]' contiene el tamaño del 'i-ésimo' cubo.

    }
    

    clock_t start = clock();// Se registra el tiempo de inicio utilizando la función 'clock()'.
// La función 'clock()' devuelve el número de 'ciclos de reloj' (típicamente en segundos) desde el inicio del programa.
// 'start' almacenará el tiempo de inicio antes de ejecutar la parte principal del algoritmo.

    for (int i = 0; i < 1000000; i++) {} // Se ejecuta un ciclo vacío con un millón de iteraciones.
// Esto se hace solo para gastar algo de tiempo y obtener una medición más precisa del tiempo de ejecución.
// Este ciclo no tiene ninguna funcionalidad real y se utiliza solo para propósitos de medición.

    clock_t end = clock();// Se registra el tiempo de finalización utilizando la función 'clock()'.
// 'end' almacenará el tiempo de finalización después de ejecutar la parte principal del algoritmo.


    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Número de iteraciones: %d\n", iterations);
    printf("Tiempo de ejecución: %.6f segundos\n", time_taken);
// Se calcula el tiempo total de ejecución restando el tiempo de inicio del tiempo de finalización.
// El resultado se convierte a segundos dividiéndolo por la constante 'CLOCKS_PER_SEC'.
// Se imprime el número total de iteraciones y el tiempo de ejecución en segundos con 6 decimales.

    // Calcular milisegundos
    double milliseconds = time_taken * 1000; // Convertir a milisegundos
    printf("Tiempo de ejecución: %.3f milisegundos\n", milliseconds);
    // El tiempo de ejecución también se muestra en milisegundos para mayor comprensión.
// Se multiplica el tiempo de ejecución en segundos por 1000 para convertirlo a milisegundos.
// Se imprime el tiempo de ejecución en milisegundos con 3 decimales.

}


// Función para ordenar un arreglo utilizando el algoritmo de Selection Sort.
void selectionSort(int arr[], int n) {// Toma como argumentos un arreglo de enteros 'arr' y su tamaño 'n'.
    int iterations = 0; // Reiniciar el contador de iteraciones
    // Se reinicia el contador de iteraciones para este algoritmo de ordenamiento.
// 'iterations' se utiliza para contar el número total de iteraciones realizadas durante el proceso de ordenamiento.

    printf("Selection Sort:\n");
    clock_t start = clock(); // Iniciar el reloj
    // Se registra el tiempo de inicio utilizando la función 'clock()'.
// 'start' almacenará el tiempo de inicio antes de ejecutar el algoritmo de Selection Sort.


    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
            iterations++; // Incrementar el contador en cada comparación
        }
        swap(&arr[min_idx], &arr[i]);
        // Este bucle recorre el arreglo y en cada iteración busca el elemento más pequeño en el subarreglo no ordenado.
// 'i' indica el índice del primer elemento del subarreglo no ordenado.
// Se inicializa 'min_idx' como el índice del primer elemento del subarreglo no ordenado.
// Se itera sobre el subarreglo no ordenado (desde 'i+1' hasta el final del arreglo).
// Si se encuentra un elemento más pequeño que el elemento en 'min_idx', se actualiza 'min_idx' con el índice de ese elemento.
// 'iterations' se incrementa en cada comparación para contar el número total de comparaciones realizadas durante el proceso de ordenamiento.
// Al final de cada iteración del bucle exterior, el elemento en 'min_idx' se intercambia con el elemento en 'i',
// lo que coloca el elemento más pequeño en su posición correcta en el arreglo ordenado.

    }

    clock_t end = clock(); // Detener el reloj
    // Se registra el tiempo de finalización utilizando la función 'clock()'.
// 'end' almacenará el tiempo de finalización después de ejecutar el algoritmo de Selection Sort.

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Calcular tiempo en segundos
    // Se calcula el tiempo total de ejecución del algoritmo restando el tiempo de inicio del tiempo de finalización.
// El resultado se convierte a segundos dividiéndolo por la constante 'CLOCKS_PER_SEC'.
// 'time_taken' contendrá el tiempo de ejecución del algoritmo en segundos.


    printf("Lista ordenada: ");
    printArray(arr, n);
    printf("Número de iteraciones: %d\n", iterations);
    printf("Tiempo de ejecución: %.6f segundos\n", time_taken);
    // Se imprime la lista ordenada en la consola utilizando la función printArray().
// Se imprime el número total de iteraciones y el tiempo de ejecución del algoritmo en segundos con 6 decimales.


    double milliseconds = time_taken * 1000; 
    printf("Tiempo de ejecución: %.3f milisegundos\n", milliseconds); 
    // Se convierte el tiempo de ejecución del algoritmo a milisegundos multiplicándolo por 1000.
// Se imprime el tiempo de ejecución en milisegundos con una precisión de tres decimales.

}


// Función para ordenar un arreglo utilizando el algoritmo de Insertion Sort.
void insertionSort(int arr[], int n) {// Toma como argumentos un arreglo de enteros 'arr' y su tamaño 'n'.
    int iterations = 0; 
    printf("Insertion Sort:\n");
    clock_t start = clock(); 
    // Se inicializa el contador de iteraciones y se imprime un mensaje indicando que se está utilizando el algoritmo de Insertion Sort.
// Se inicia el reloj para registrar el tiempo de inicio de la ejecución del algoritmo.

    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            iterations++; // Incrementar el contador en cada comparación
        }
        arr[j + 1] = key;
        // Este bucle recorre el arreglo a partir del segundo elemento hasta el último.
// En cada iteración, se selecciona un elemento 'key' y se compara con los elementos anteriores a él.
// Mientras el elemento 'key' sea menor que el elemento en la posición 'j', se desplaza el elemento 'j' una posición hacia adelante.
// Se incrementa 'iterations' en cada comparación realizada.
// Una vez que se encuentra la posición correcta para 'key', se inserta en esa posición.

    }

    clock_t end = clock(); 
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; 
    // Se detiene el reloj para registrar el tiempo de finalización de la ejecución del algoritmo.
// Se calcula el tiempo total de ejecución del algoritmo en segundos.


    printf("Lista ordenada: ");
    printArray(arr, n);
    printf("Número de iteraciones: %d\n", iterations);
    printf("Tiempo de ejecución: %.6f segundos\n", time_taken);
    // Se imprime la lista ordenada en la consola.
// Se imprime el número total de iteraciones realizadas durante el proceso de ordenamiento.
// Se imprime el tiempo de ejecución del algoritmo en segundos con 6 decimales.


    time_taken *= 1000; // Convertir a milisegundos
    printf("Tiempo de ejecución: %.3f milisegundos\n", time_taken); // Imprimir el tiempo en milisegundos
    // Se convierte el tiempo de ejecución del algoritmo a milisegundos y se imprime con una precisión de tres decimales.
// Esto se hace para proporcionar una medida de tiempo más comprensible.

}


// Función para fusionar dos subarreglos ordenados en uno solo.
void merge(int arr[], int left[], int left_size, int right[], int right_size) {// Toma como argumentos el arreglo original 'arr', dos subarreglos ordenados 'left' y 'right',
// y sus respectivos tamaños 'left_size' y 'right_size'.
    int i = 0, j = 0, k = 0;// Se inicializan los índices 'i', 'j' y 'k' para los subarreglos 'left', 'right' y el arreglo fusionado 'arr' respectivamente.
// 'i' y 'j' son los índices que rastrean la posición actual en 'left' y 'right' respectivamente.
// 'k' es el índice que rastrea la posición actual en el arreglo fusionado 'arr'.

    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
        iterations++; // Incrementar el contador de iteraciones
        // Se compara los elementos de 'left' y 'right' en sus posiciones actuales ('i' y 'j') respectivamente.
// El menor de los dos se copia en el arreglo fusionado 'arr' y se avanza en el subarreglo correspondiente.
// Se incrementa 'k' para apuntar al siguiente espacio en 'arr'.
// Se incrementa 'iterations' en cada comparación realizada.

    }

    while (i < left_size) {
        arr[k++] = left[i++];
        iterations++; // Incrementar el contador de iteraciones
        
        // Se copian los elementos restantes de 'left' al arreglo fusionado 'arr' si todavía hay elementos en 'left'.
// Se incrementa 'k' para apuntar al siguiente espacio en 'arr'.
// Se incrementa 'iterations' en cada copia realizada.

    }

    while (j < right_size) {
        arr[k++] = right[j++];
        iterations++; // Incrementar el contador de iteraciones
        
        // Se copian los elementos restantes de 'right' al arreglo fusionado 'arr' si todavía hay elementos en 'right'.
// Se incrementa 'k' para apuntar al siguiente espacio en 'arr'.
// Se incrementa 'iterations' en cada copia realizada.

    }
}

// Función para ordenar un arreglo utilizando el algoritmo de Merge Sort.
void mergeSort(int arr[], int n) {// Toma como argumentos un arreglo de enteros 'arr' y su tamaño 'n'.
    if (n < 2) {
        return;
        // Se verifica si el tamaño del arreglo es menor que 2.
// Si es así, significa que el arreglo ya está ordenado (tiene 0 o 1 elemento), por lo que no se hace nada y se retorna.

    }

    int mid = n / 2;
    int left[mid];
    int right[n - mid];
    // Se calcula el índice medio del arreglo.
// Se crean dos arreglos, 'left' y 'right', para almacenar la mitad izquierda y la mitad derecha del arreglo 'arr' respectivamente.
// 'left' tendrá 'mid' elementos y 'right' tendrá 'n - mid' elementos.


    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
        
    }

    for (int i = mid; i < n; i++) {
        right[i - mid] = arr[i];
    }// Se copian los elementos de la mitad izquierda de 'arr' al arreglo 'left'.
// Se copian los elementos de la mitad derecha de 'arr' al arreglo 'right'.


    mergeSort(left, mid);
    mergeSort(right, n - mid);
    // Se llama recursivamente a 'mergeSort' para ordenar las mitades izquierda y derecha del arreglo.
// Se divide el problema en subproblemas más pequeños hasta que se llega a arreglos de tamaño 1.
    merge(arr, left, mid, right, n - mid);
   // Se llama a la función 'merge' para fusionar las mitades izquierda y derecha ya ordenadas.
// 'mid' es el tamaño de la mitad izquierda y 'n - mid' es el tamaño de la mitad derecha.
// 'arr' contiene los elementos ordenados fusionados de 'left' y 'right'.


}


// Función envoltorio para ordenar un arreglo utilizando el algoritmo de Merge Sort.
void mergeSortWrapper(int arr[], int n) {// Toma como argumentos un arreglo de enteros 'arr' y su tamaño 'n'.
    iterations = 0; 
    printf("Merge Sort:\n");
    clock_t start = clock(); 
    // Se reinicia el contador de iteraciones para este algoritmo de ordenamiento.
// Se imprime un mensaje indicando que se está utilizando el algoritmo de Merge Sort.
// Se inicia el reloj para registrar el tiempo de inicio de la ejecución del algoritmo.


    mergeSort(arr, n);// Se llama a la función 'mergeSort' para ordenar el arreglo 'arr' utilizando el algoritmo de Merge Sort.


    clock_t end = clock(); 
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; 
    // Se detiene el reloj para registrar el tiempo de finalización de la ejecución del algoritmo.
// Se calcula el tiempo total de ejecución del algoritmo en segundos.


    printf("Lista ordenada: ");
    printArray(arr, n);
    printf("Número de iteraciones: %d\n", iterations);
    printf("Tiempo de ejecución: %.6f segundos\n", time_taken);
    // Se imprime la lista ordenada en la consola.
// Se imprime el número total de iteraciones realizadas durante el proceso de ordenamiento.
// Se imprime el tiempo de ejecución del algoritmo en segundos con 6 decimales.


    double milliseconds = time_taken * 1000; // Convertir a milisegundos
    printf("Tiempo de ejecución: %.3f milisegundos\n", milliseconds); // Imprimir el tiempo en milisegundos
}

// Función para particionar un arreglo en torno a un elemento pivote.
int partition(int arr[], int low, int high) {// Toma como argumentos un arreglo de enteros 'arr', y los índices 'low' y 'high' que indican el rango del arreglo a considerar.
// Se utilizará el elemento en 'high' como pivote.
    
	int pivot = arr[high];
    int i = low - 1;
    // Se selecciona el pivote como el elemento en la posición 'high'.
// Se inicializa 'i' como el índice del elemento más pequeño (o del último elemento del subarreglo que contiene los elementos menores o iguales al pivote).


    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
            // Se recorre el arreglo desde 'low' hasta 'high - 1' para comparar cada elemento con el pivote.
// Si el elemento actual es menor o igual al pivote, se incrementa 'i' y se intercambia el elemento en 'i' con el elemento en 'j'.
// Esto asegura que los elementos menores o iguales al pivote queden a la izquierda de 'i', mientras que los elementos mayores al pivote queden a la derecha.

        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
    // Finalmente, se intercambia el pivote con el elemento en la posición 'i + 1' para colocar el pivote en su posición final en el arreglo ordenado.
// Se devuelve el índice de la posición final del pivote.

}

// Función para ordenar un arreglo utilizando el algoritmo de Quick Sort de manera recursiva.
void quickSort(int arr[], int low, int high, int *iterations, double *time_taken) {
	// Toma como argumentos un arreglo de enteros 'arr', y los índices 'low' y 'high' que indican el rango del arreglo a considerar.
// También toma como argumentos un puntero a 'iterations' y un puntero a 'time_taken' para actualizar el número de iteraciones y el tiempo de ejecución respectivamente.

    if (low < high) {// Se verifica si el rango es válido, es decir, si 'low' es menor que 'high'.Si es válido, continúa con la ordenación.

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1, iterations, time_taken);
        quickSort(arr, pi + 1, high, iterations, time_taken);
        (*iterations)++;
        // Se llama a la función 'partition' para obtener el índice del pivote y particionar el arreglo en torno a él.
// Luego, se llama recursivamente a 'quickSort' para ordenar las subarreglos a la izquierda y a la derecha del pivote.
// Se incrementa el contador de iteraciones después de cada llamada recursiva, ya que cada llamada representa un paso en el algoritmo de Quick Sort.

    }
}

// Función para llamar al algoritmo de Quick Sort y mostrar los resultados.
void callQuickSort(int arr[], int n) {// Toma como argumentos un arreglo de enteros 'arr' y su tamaño 'n'.
    int iterations = 0;
    clock_t start, end;// Variables para medir el tiempo de ejecución
    double time_taken;// Variable para almacenar el tiempo de ejecución
   printf("Quick Sort:\n");
   // Se inicializa el contador de iteraciones.
// Se declaran las variables para medir el tiempo de ejecución del algoritmo.
// Se imprime un mensaje indicando que se está utilizando el algoritmo de Quick Sort.


    start = clock();//arrancar reloj
    quickSort(arr, 0, n - 1, &iterations, &time_taken);//Llamar al algoritmo de Quick Sort
    end = clock();
    // Se inicia el reloj antes de llamar al algoritmo de Quick Sort.
// Se llama a la función 'quickSort' para ordenar el arreglo 'arr' de manera recursiva.
// Se pasan punteros a 'iterations' y 'time_taken' para actualizar el número de iteraciones y el tiempo de ejecución.
// Se detiene el reloj después de que Quick Sort ha finalizado su ejecución.


    printArray(arr, n);
    printf("Número de iteraciones: %d\n", iterations);
    // Se imprime el arreglo ordenado.
// Se imprime el número total de iteraciones realizadas durante la ejecución de Quick Sort.


}


// Función para ordenar un arreglo utilizando el algoritmo de Shell Sort.
void shellSort(int arr[], int n) {// Toma como argumentos un arreglo de enteros 'arr' y su tamaño 'n'.
    int iterations = 0;
    clock_t start, end;
    start = clock(); 
    // Se inicializa el contador de iteraciones.
// Se declaran las variables para medir el tiempo de ejecución del algoritmo.
// Se inicia el reloj para registrar el tiempo de inicio de la ejecución del algoritmo.


    for (int gap = n / 2; gap > 0; gap /= 2) {// Se establece el tamaño inicial del espacio de separación 'gap' como la mitad del tamaño del arreglo.
// 'gap' determina el tamaño del paso entre los elementos que se comparan y se intercambian en cada iteración.
// El algoritmo de Shell Sort utiliza diferentes valores de 'gap' para ordenar subgrupos de elementos del arreglo.

        for (int i = gap; i < n; i++) {
        	// Se inicia un bucle que recorre el arreglo desde el índice 'gap' hasta el final.
// 'i' representa la posición actual en el arreglo.
// Este bucle se utiliza para comparar y mover los elementos dentro de los grupos definidos por 'gap'.

            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
                iterations++;
            }
            arr[j] = temp;
            // Se almacena el valor del elemento actual en 'temp'.
// Se inicia un bucle interno que compara el elemento actual con los elementos en el mismo grupo definido por 'gap'.
// 'j' representa la posición actual en el arreglo dentro del grupo definido por 'gap'.
// El bucle se ejecuta mientras 'j' sea mayor o igual que 'gap' y el elemento anterior dentro del grupo sea mayor que 'temp'.
// Si se cumple la condición, se mueve el elemento anterior hacia adelante en el grupo.
// Se incrementa el contador de iteraciones en cada comparación.
// Después de que el bucle interno termine, se coloca el valor de 'temp' en la posición correcta dentro del grupo.

        }
    }

    end = clock(); // Detener el reloj
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; 
    // Se detiene el reloj para registrar el tiempo de finalización de la ejecución del algoritmo.
// Se calcula el tiempo total de ejecución del algoritmo en segundos.


    printf("Shell Sort:\n");
    printf("Lista ordenada: ");
    printArray(arr, n);
    printf("Número de iteraciones: %d\n", iterations);
    
    // Se imprime un mensaje indicando que se está utilizando el algoritmo de Shell Sort.
// Se imprime el arreglo ordenado.
// Se imprime el número total de iteraciones realizadas durante la ejecución del algoritmo.

}


// Función de Counting Sort
void countingSort(int arr[], int n) {// Toma como argumentos un arreglo de enteros 'arr' y su tamaño 'n'.
    int max_val = arr[0];// Inicializar el valor máximo como el primer elemento del arreglo
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];// Actualizar el valor máximo si se encuentra un valor mayor
        }
    }
    // Se busca el valor máximo en el arreglo para determinar el rango de los elementos.
// El valor máximo es necesario para crear un arreglo de conteo de tamaño suficiente.


        int *count = (int *)calloc(max_val + 1, sizeof(int)); // Crear un arreglo de conteo
    int iterations = 0; // Inicializar el contador de iteraciones

    for (int i = 0; i < n; i++) {
        count[arr[i]]++; // Contar la frecuencia de cada elemento
        iterations++; // Incrementar el contador de iteraciones
    }
    // Se crea un arreglo de conteo de tamaño (max_val + 1) e inicializado con ceros.
// Se recorre el arreglo original para contar la frecuencia de cada elemento.
// Se incrementa el contador de iteraciones en cada iteración del bucle.



    int index = 0;
    for (int i = 0; i <= max_val; i++) {

        while (count[i]--) {
            arr[index++] = i;// Reconstruir el arreglo ordenado
            iterations++;
            // Se reconstruye el arreglo ordenado a partir del arreglo de conteo.
// Se recorre el arreglo de conteo y para cada elemento se copian 'count[i]' veces el valor 'i' en el arreglo original.
// Se incrementa el contador de iteraciones en cada iteración del bucle.

        }
    }

    free(count);// Liberar la memoria asignada para el arreglo de conteo

    printf("Counting Sort: ");
    printArray(arr, n);
    printf("Número de iteraciones: %d\n", iterations);

    clock_t start, end;
    double time_taken;
    start = clock();
    end = clock(); // Detener el reloj
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Calcular tiempo en segundos
    // Se libera la memoria asignada para el arreglo de conteo.
// Se imprime el arreglo ordenado.
// Se imprime el número total de iteraciones realizadas durante la ejecución del algoritmo.
// Se mide el tiempo de ejecución del algoritmo.

}

// Función para obtener el máximo valor en un arreglo
int getMax(int arr[], int n) {// Esta función recibe un arreglo de enteros 'arr' y su tamaño 'n'.
// Retorna el valor máximo presente en el arreglo.
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
            // Se busca el valor máximo en el arreglo para determinar el máximo.
// Se inicializa 'max_val' con el primer elemento del arreglo.
// Se recorre el arreglo a partir del segundo elemento.
// Si se encuentra un elemento mayor que 'max_val', se actualiza 'max_val' con este valor.

        }
    }
    return max_val;// Se retorna el valor máximo encontrado en el arreglo.

}

// Función de Count Sort para Radix Sort
void countSort(int arr[], int n, int exp) {// Esta función implementa Counting Sort, un algoritmo auxiliar utilizado en Radix Sort.
// Recibe un arreglo de enteros 'arr', su tamaño 'n' y el exponente 'exp'.
// 'exp' determina el dígito en el que se está ordenando actualmente el arreglo.

      int *output = (int *)malloc(n * sizeof(int)); // Arreglo de salida para almacenar los elementos ordenados
    int count[10] = {0}; // Arreglo de conteo para contar la frecuencia de cada dígito (0-9)
// Se reserva memoria para un arreglo de salida del mismo tamaño que el arreglo original.
// Se inicializa un arreglo de conteo para contar la frecuencia de cada dígito del 0 al 9.


    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;// Contar la frecuencia de cada dígito
        // Se recorre el arreglo original y se cuenta la frecuencia de cada dígito en la posición correspondiente del arreglo de conteo.
// La fórmula (arr[i] / exp) % 10 obtiene el dígito relevante en la posición 'exp' del número.

    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];// Actualizar el arreglo de conteo para indicar las posiciones finales de los elementos
    }// Se actualiza el arreglo de conteo para que cada elemento indique la posición final de los elementos en el arreglo de salida.


        for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]; // Colocar los elementos en el arreglo de salida en orden
        count[(arr[i] / exp) % 10]--; // Disminuir la cuenta después de colocar un elemento
    }// Se coloca cada elemento del arreglo original en su posición correspondiente en el arreglo de salida.
// Se decrementa el conteo de ese dígito después de colocar un elemento en el arreglo de salida.


        for (int i = 0; i < n; i++) {
        arr[i] = output[i]; // Copiar el arreglo de salida al arreglo original
    }// Se copia el arreglo de salida al arreglo original para reflejar los cambios.



    free(output);// Se libera la memoria asignada para el arreglo de salida.

}

// Función de Radix Sort
void radixSort(int arr[], int n) {
    // Encontrar el valor máximo en el arreglo
    int max_val = getMax(arr, n);
    int iterations = 0; // Inicializar el contador de iteraciones

    // Loop para cada posición de los dígitos, comenzando desde el dígito menos significativo hasta el más significativo
    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        // Ordenar el arreglo utilizando el conteo de cada dígito en la posición actual
        countSort(arr, n, exp);
        iterations++; // Incrementar el contador de iteraciones
    }

    // Imprimir la lista ordenada
    printf("Lista ordenada: ");
    printArray(arr, n);

    // Imprimir el número de iteraciones realizadas
    printf("Número de iteraciones: %d\n", iterations);

    clock_t start, end; // Variables para medir el tiempo
    double time_taken;
    start = clock(); // Iniciar el reloj
    
    end = clock(); // Detener el reloj
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Calcular tiempo en segundos
}

// funcion para agregar numero ala lista
void agregarNumero(int arr[], int *n, int max_size) {
    // Verifica si el tamaño actual del arreglo es menor que el tamaño máximo permitido
    if (*n < max_size) {
        printf("Ingrese el número a agregar: "); // Solicita al usuario ingresar un número
        int num;
        scanf("%d", &num); // Lee el número ingresado por el usuario
        arr[*n] = num; // Agrega el número al final del arreglo
        (*n)++; // Incrementa el tamaño del arreglo
        printf("Número agregado.\n"); // Muestra un mensaje de confirmación
    } else {
        printf("¡La lista está llena! No se puede agregar más números.\n"); // Muestra un mensaje de error si el arreglo está lleno
    }
}

//funcion para eliminar un numero de la lista
void eliminarNumero(int arr[], int *n) {
    // Verifica si el arreglo no está vacío
    if (*n > 0) {
        printf("Ingrese el número a eliminar: "); // Solicita al usuario ingresar el número a eliminar
        int num;
        scanf("%d", &num); // Lee el número ingresado por el usuario
        int found = 0; // Variable para indicar si el número se encontró en el arreglo
        // Recorre el arreglo para encontrar el número
        for (int i = 0; i < *n; i++) {
            if (arr[i] == num) { // Si el número se encuentra en el arreglo
                found = 1; // Marca que el número fue encontrado
                // Elimina el número moviendo los elementos restantes una posición hacia adelante
                for (int j = i; j < *n - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                (*n)--; // Decrementa el tamaño del arreglo
                printf("Número eliminado.\n"); // Muestra un mensaje de confirmación
                break; // Sale del bucle una vez que el número se elimina
            }
        }
        // Si el número no se encontró en el arreglo
        if (!found) {
            printf("El número no existe en la lista.\n"); // Muestra un mensaje de error
        }
    } else {
        printf("¡La lista está vacía! No se puede eliminar ningún número.\n"); // Muestra un mensaje de error si el arreglo está vacío
    }
}






int main() {
		setlocale(LC_ALL, "");
// Esta línea declara un arreglo de enteros llamado numbers con un tamaño máximo definido por MAX_SIZE.
// Este arreglo se utilizará para almacenar los números leídos desde el archivo.
int numbers[MAX_SIZE];

// Esta línea inicializa una variable entera llamada count en 0.
// Probablemente se utilizará para llevar un recuento del número de elementos en el arreglo numbers.
int count = 0;

// Esta línea declara un arreglo de caracteres llamado filename y lo inicializa con la ruta del archivo
// que contiene la lista de números que se leerá.
char filename[] = "C:\\Users\\juana\\OneDrive\\Escritorio\\STRUCT DE DATOS\\lista_de_numeros.txt";

// Esta línea declara otro arreglo de caracteres llamado newFilename y lo inicializa con la ruta del archivo
// donde se escribirán los números.
char newFilename[] = "C:\\Users\\juana\\OneDrive\\Escritorio\\STRUCT DE DATOS\\nueva_lista.txt";

   // Imprime un mensaje de bienvenida
printf("Bienvenido al programa de ordenamiento!\n");

// Lee los números desde el archivo y los almacena en el arreglo numbers
// count contiene la cantidad de números leídos
count = readNumbersFromFile(numbers, filename);

// Si no se pudo leer ningún número desde el archivo, muestra un mensaje de error y sale del programa
if (count == 0) {
    printf("No se pudo leer ningún número desde el archivo.\n");
    return 1;
}

// Muestra la lista de números leídos desde el archivo
showList(numbers, count);

// Solicita al usuario la cantidad de números que desea ordenar
int numToSort;
printf("Ingrese la cantidad de números que desea ordenar: ");
scanf("%d", &numToSort);

// Si la cantidad de números a ordenar excede la cantidad total de números en el archivo, muestra un mensaje de error y sale del programa
if (numToSort > count) {
    printf("La cantidad de números a ordenar excede la cantidad total de números en el archivo.\n");
    return 1;
}

// Crea un nuevo arreglo numbersToSort con los primeros numToSort números del arreglo numbers
int numbersToSort[numToSort];
for (int i = 0; i < numToSort; i++) {
    numbersToSort[i] = numbers[i];
}

// Muestra los números que se van a ordenar
printf("Números a ordenar:\n");
printArray(numbersToSort, numToSort);

// Guarda los números en el nuevo archivo
saveToFile(numbersToSort, numToSort, newFilename);

// Inicia un bucle infinito para mostrar el menú de opciones
char choice;
while (1) {
    printf("\nMenú:\n");
    printf("a. Agregar un número\n");
    printf("b. Eliminar un número\n");
    printf("c. Utilizar Bubble Sort\n");
    printf("d. Utilizar Bucket Sort\n");
    printf("e. Utilizar Selection Sort\n");
    printf("f. Utilizar Insertion Sort\n");
    printf("g. Utilizar Merge Sort\n");
    printf("h. Utilizar Quick Sort\n");
    printf("i. Utilizar Shell Sort\n");
    printf("j. Utilizar Counting Sort\n");
    printf("k. Utilizar Radix Sort\n");
    printf("l. Salir\n");
    printf("Ingrese su elección: ");
    scanf(" %c", &choice);

    // Realiza la acción correspondiente según la opción elegida por el usuario
    switch (choice) {
        case 'a': { // Agregar un número
            agregarNumero(numbersToSort, &numToSort, MAX_SIZE);
            printArray(numbersToSort, numToSort);
            break;
        }
        case 'b': { // Eliminar un número
            eliminarNumero(numbersToSort, &numToSort);
            printArray(numbersToSort, numToSort);
            break;
        }
        case 'c': // Utilizar Bubble Sort
            bubbleSort(numbersToSort, numToSort);
            saveToFile(numbersToSort, numToSort, newFilename);
            break;
        case 'd': // Utilizar Bucket Sort
            bucketSort(numbersToSort, numToSort);
            saveToFile(numbersToSort, numToSort, newFilename);
            break;
        case 'e': // Utilizar Selection Sort
            selectionSort(numbersToSort, numToSort);
            break;
        case 'f': { // Utilizar Insertion Sort
            insertionSort(numbersToSort, numToSort);
            break;
        }
        case 'g': { // Utilizar Merge Sort
            mergeSortWrapper(numbersToSort, numToSort);
            saveToFile(numbersToSort, numToSort, newFilename);
            break;
        }
        case 'h': { // Utilizar Quick Sort
            int originalNumbers[numToSort]; // Copia de la lista original
            for (int i = 0; i < numToSort; i++) {
                originalNumbers[i] = numbersToSort[i];
            }
            clock_t start, end;
            double time_taken;
            start = clock();
            callQuickSort(numbersToSort, numToSort);
            end = clock();
            time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Tiempo en segundos
            printf("Tiempo de ejecución: %.6f segundos\n", time_taken);
            time_taken *= 1000; // Convertir a milisegundos
            printf("Tiempo de ejecución: %.3f milisegundos\n", time_taken);
            for (int i = 0; i < numToSort; i++) {
                numbersToSort[i] = originalNumbers[i];
            }
            saveToFile(numbersToSort, numToSort, newFilename);
            break;
        }
        case 'i': { // Utilizar Shell Sort
            clock_t start, end;
            double milliseconds;
            start = clock(); // Iniciar el reloj
            shellSort(numbersToSort, numToSort); // Llamada a shellSort
            end = clock(); // Detener el reloj
            double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Calcular tiempo en segundos
            milliseconds = time_taken * 1000; // Convertir a milisegundos
            printf("Tiempo de ejecución: %.6f segundos\n", time_taken);
            printf("Tiempo de ejecución: %.3f milisegundos\n", milliseconds);
            saveToFile(numbersToSort, numToSort, newFilename);
            break;
        }
        case 'j': { // Utilizar Counting Sort
            clock_t start, end;
            double milliseconds;
            start = clock(); // Iniciar el reloj
            countingSort(numbersToSort, numToSort); // Llamada a countingSort
            end = clock(); // Detener el reloj
            double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Calcular tiempo en segundos
            milliseconds = time_taken * 1000; // Convertir a milisegundos
            printf("Tiempo de ejecución de Counting Sort: %.6f segundos\n", time_taken);
            printf("Tiempo de ejecución de Counting Sort: %.3f milisegundos\n", milliseconds);
            saveToFile(numbersToSort, numToSort, newFilename);
            break;
        }
        case 'k': { // Utilizar Radix Sort
            clock_t start, end;
            double milliseconds;
            start = clock(); // Iniciar el reloj
            radixSort(numbersToSort, numToSort); // Llamada a radixSort
            end = clock(); // Detener el reloj
            double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Calcular tiempo en segundos
            milliseconds = time_taken * 1000; // Convertir a milisegundos
            printf("Tiempo de ejecución de Radix Sort: %.6f segundos\n", time_taken);
            printf("Tiempo de ejecución de Radix Sort: %.3f milisegundos\n", milliseconds);
            saveToFile(numbersToSort, numToSort, newFilename);
            break;
        }
        case 'l': // Salir
            printf("¡Adiós!\n");
            exit(0);
            break;
        default: // Opción inválida
            printf("¡Opción inválida!\n");
            break;
    }
}

// Finaliza el programa
return 0;
}
