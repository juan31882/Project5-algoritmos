#include <stdio.h>    // Proporciona funciones para entrada y salida est�ndar, como printf() y scanf().
#include <stdlib.h>   // Proporciona funciones para gesti�n de memoria din�mica, como malloc() y free().
#include <time.h>     // Proporciona funciones para manejar el tiempo y generar n�meros aleatorios, como time().
#include <vector>     // Proporciona la clase vector, que es un contenedor din�mico de la biblioteca est�ndar de C++.
#include <algorithm>  // Proporciona algoritmos para manipular elementos en contenedores, como sort() y find().
#include <math.h>     // Proporciona funciones matem�ticas
#include <locale.h>
#define MAX_SIZE 5000 // Esta l�nea define una macro llamada MAX_SIZE con un valor de 5000. Las macros se utilizan para definir 
//constantes que se pueden usar en todo el programa. En este caso, MAX_SIZE se puede usar como un tama�o m�ximo para alg�n arreglo o estructura de datos.

int iterations;// se declara una variable llamada iterations. Esta variable es de tipo entero y 
//se utiliza para almacenar el n�mero de iteraciones en alg�n bucle o algoritmo dentro del programa.


void swap(int *a, int *b) { //define una funci�n llamada swap que intercambia los valores de dos variables enteras. La funci�n toma dos punteros a enteros como argumentos.
    int temp = *a; //e declara una variable temporal llamada temp y se le asigna el valor al que apunta el puntero a.
    *a = *b; //Se asigna el valor al que apunta b a la direcci�n de memoria a la que apunta a.
    *b = temp; //Se asigna el valor almacenado en la variable temporal a la direcci�n de memoria a la que apunta b, es decir, el valor original de a se guarda en b.
}

void printArray(int arr[], int size) { //define una funci�n llamada printArray que imprime los elementos de un arreglo de enteros. 
//La funci�n toma dos argumentos: arr, que es un arreglo de enteros, y size, que es el tama�o del arreglo.
    for (int i = 0; i < size; i++) {
// Inicia un bucle 'for' para iterar sobre los elementos del arreglo.
// Se inicializa una variable 'i' en 0, que servir� como contador de �ndice.
// El bucle continuar� mientras 'i' sea menor que el tama�o del arreglo 'size'.
// En cada iteraci�n, 'i' se incrementar� en 1.
        printf("%d ", arr[i]);
        // Imprime el valor del elemento del arreglo en el �ndice 'i'.
// 'arr[i]' accede al elemento en la posici�n 'i' del arreglo 'arr'.
// Se imprime seguido de un espacio para separar los elementos en la salida.

    }
    printf("\n"); // Despu�s del bucle, se imprime una nueva l�nea para que la pr�xima salida se imprima en la l�nea siguiente.
}

int readNumbersFromFile(int arr[], char filename[]) {
	// Funci�n que lee n�meros de un archivo y los almacena en un arreglo.
// Toma como argumentos un arreglo 'arr' donde se guardar�n los n�meros le�dos,y el nombre del archivo 'filename' del que se leer�n los n�meros.
// Devuelve el n�mero de elementos le�dos y almacenados en el arreglo.

    FILE *file = fopen(filename, "r");
    // Abre un archivo en modo de lectura ("r"). 'filename' es el nombre del archivo a abrir.
// fopen' devuelve un puntero al tipo FILE que apunta al archivo abierto. Si el archivo no se puede abrir, devuelve NULL.
// La variable 'file' almacenar� este puntero.
    if (file == NULL) {// Comprueba si 'file' es NULL, lo cual indicar�a un fallo al abrir el archivo.
// Si 'file' es NULL, significa que el archivo no se pudo abrir.

    perror("Error al abrir el archivo para lectura"); // La funci�n perror() imprime un mensaje de error basado en el valor actual de errno.'errno' es una variable global que almacena el c�digo de error m�s reciente generado por una funci�n del sistema.
// Si fopen() devuelve NULL (indicando que no se pudo abrir el archivo), perror() proporciona una descripci�n detallada del error que ocurri� durante la apertura del archivo.

    return 0;
    } // Si se produce un error al abrir el archivo, la funci�n devuelve 0 para indicar un fallo.No se pudo leer ning�n n�mero del archivo, as� que se retorna 0. La funci�n termina aqu� y no contin�a con la lectura del archivo.


    int count = 0;
    printf("Contenido del archivo:\n");
    while (fscanf(file, "%d", &arr[count]) != EOF && count < MAX_SIZE) {
        printf("%d ", arr[count]);
        count++;
    } 
    printf("\n"); // Inicializa un contador 'count' para seguir la cantidad de n�meros le�dos.Imprime un mensaje para indicar que se mostrar� el contenido del archivo.
// Lee los n�meros del archivo mientras no se llegue al final del archivo (EOF) y no se exceda el tama�o m�ximo del arreglo (MAX_SIZE).
// En cada iteraci�n, se guarda el n�mero le�do en 'arr[count]'.Se imprime el n�mero le�do seguido de un espacio.Finalmente, se imprime una nueva l�nea para separar la salida.


    fclose(file);
    return count;
} // Cierra el archivo despu�s de haber terminado de leer.y Devuelve el n�mero total de elementos le�dos y almacenados en el arreglo.

// Funci�n para guardar una lista de n�meros en un archivo.Toma como argumentos un arreglo de n�meros 'arr' y su tama�o 'n',y el nombre del archivo 'filename' donde se guardar�n los n�meros.
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
// Utiliza fprintf() para imprimir cada elemento en el archivo. Se imprime cada n�mero seguido de un salto de l�nea ('\n')

    fclose(file);
    printf("Lista de n�meros guardada en %s\n", filename);
}// Cierra el archivo despu�s de haber terminado de escribir.
// Muestra un mensaje indicando que la lista de n�meros se ha guardado en el archivo especificado.


// Funci�n para mostrar la lista actual de n�meros en la consola.toma como argumentos un arreglo de n�meros 'arr' y su tama�o 'n'.
void showList(int arr[], int n) {
    printf("Lista actual de n�meros:\n"); // Imprime un mensaje indicando que se mostrar� la lista de n�meros.Este mensaje sirve como encabezado antes de imprimir la lista.

    printArray(arr, n);// Utiliza la funci�n printArray() para imprimir la lista de n�meros.'arr' es el arreglo que contiene los n�meros a imprimir.
// 'n' es el tama�o del arreglo.La funci�n printArray() se encarga de imprimir cada n�mero en el arreglo.

}

// Funci�n para ordenar un arreglo de n�meros utilizando el algoritmo Bubble Sort.Toma como argumentos un arreglo de n�meros 'arr' y su tama�o 'n'.
void bubbleSort(int arr[], int n) {
    int iterations = 0;// Se inicializa una variable 'iterations' para contar el n�mero de iteraciones del algoritmo.
    clock_t start, end;// Se declara 'start' y 'end' como variables del tipo clock_t para medir el tiempo de ejecuci�n.
    start = clock();// Se guarda el tiempo de inicio de la ejecuci�n del algoritmo en 'start'.

    for (int i = 0; i < n - 1; i++) {// Bucle externo para iterar sobre todos los elementos del arreglo, excepto el �ltimo. Este bucle se ejecuta n - 1 veces, donde 'n' es el tama�o del arreglo.
// Cada iteraci�n de este bucle representa una pasada completa a trav�s del arreglo.

        bool swapped = false;// Se declara una variable booleana llamada 'swapped'.Esta variable se utiliza para indicar si se realiz� alg�n intercambio durante una pasada del algoritmo Bubble Sort.

        for (int j = 0; j < n - i - 1; j++) {
            iterations++;// Bucle interno para comparar elementos y realizar intercambios.Este bucle se ejecuta n - i - 1 veces en cada pasada, donde 'i' es el n�mero de pasadas completadas.
// Cada iteraci�n compara un elemento con el siguiente y realiza un intercambio si es necesario.'iterations' se incrementa en cada comparaci�n.

            if (arr[j] > arr[j + 1]) {// Si el elemento actual es mayor que el siguiente, se intercambian.
                swap(&arr[j], &arr[j + 1]);// Se llama a la funci�n 'swap' para intercambiar los elementos.
                swapped = true;// Se establece 'swapped' en verdadero si se realiza alg�n intercambio en la pasada actual.

            }
        }
        if (!swapped) {// Si no se realiz� ning�n intercambio en la pasada actual, el arreglo ya est� ordenado.
            break;// Por lo tanto, se sale del bucle externo antes de completar todas las pasadas.
        }
    }
    end = clock();// Se guarda el tiempo de finalizaci�n de la ejecuci�n del algoritmo en 'end'.
    printf("Bubble Sort: ");// Se imprime el arreglo ordenado despu�s de aplicar Bubble Sort.
    printArray(arr, n);// Llama a la funci�n printArray() para imprimir los elementos del arreglo 'arr'.'arr' es el arreglo que contiene los n�meros que se imprimir�n.
//'n' es el n�mero de elementos en el arreglo.Esta funci�n se encarga de imprimir cada elemento del arreglo, separados por un espacio.

    printf("N�mero de iteraciones: %d\n", iterations);// Se imprime el n�mero total de iteraciones realizadas por el algoritmo.
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;// Calcula el tiempo total de ejecuci�n del algoritmo en segundos.'end - start' calcula la diferencia de tiempo entre el momento en que se guarda 'start' y 'end'.
// Se convierte la diferencia de tiempo a tipo 'double' para obtener una precisi�n decimal adecuada.Se divide por 'CLOCKS_PER_SEC' para convertir los ciclos del reloj a segundos.
// El resultado se almacena en 'time_taken'.
    printf("Tiempo de ejecuci�n: %.6f segundos\n", time_taken);// Imprime el tiempo de ejecuci�n del algoritmo en segundos con una precisi�n de 6 decimales.
// Utiliza el formato "%.6f" para imprimir el valor de 'time_taken'.'time_taken' es el tiempo total de ejecuci�n del algoritmo en segundos.

    time_taken *= 1000; // Convertir a milisegundos
    printf("Tiempo de ejecuci�n: %.3f milisegundos\n", time_taken); // Imprimir el tiempo en milisegundos
}


// Funci�n para ordenar un arreglo utilizando el algoritmo Bucket Sort.
void bucketSort(int arr[], int n) {//Toma como argumentos un arreglo de enteros 'arr' y su tama�o 'n'.
    int max_val = arr[0];// Se inicializa una variable para almacenar el valor m�ximo del arreglo.
    // Se declara una variable 'max_val' y se inicializa con el primer elemento del arreglo 'arr'.
// Esta variable se utilizar� para encontrar el valor m�ximo en el arreglo.

// Bucle para encontrar el valor m�ximo en el arreglo.
    for (int i = 1; i < n; i++) {// Se inicia un bucle 'for' para recorrer el arreglo desde el segundo elemento hasta el �ltimo.Se excluye el primer elemento del arreglo ya que ya se ha asignado a 'max_val'.
        if (arr[i] > max_val) {// Comprueba si el elemento actual es mayor que el valor m�ximo encontrado hasta ahora.
        // Se compara el elemento actual del arreglo con el valor m�ximo encontrado hasta el momento.Si el elemento actual es mayor que 'max_val', se actualizar� 'max_val' con el valor del elemento actual.
            max_val = arr[i];// Si es as�, actualiza el valor m�ximo
            // Si el elemento actual es mayor que 'max_val', se actualiza 'max_val' con el valor del elemento actual.
        }
    }

    int buckets = n / 10 + 1; // Ajustar el n�mero de cubos,Se calcula el n�mero de cubos que se utilizar�n en el algoritmo Bucket Sort.
// Se divide el n�mero total de elementos 'n' por 10 y se suma 1 para ajustar el n�mero de cubos.Esto asegura que cada cubo tenga un tama�o adecuado para manejar los elementos del arreglo.

    int **bucket = (int **)malloc(buckets * sizeof(int *)); // Crear un arreglo de punteros para almacenar los cubos
    // Se utiliza 'malloc' para asignar memoria din�mica para 'buckets' punteros.Cada puntero en 'bucket' apuntar� a un arreglo din�mico que contendr� los elementos de un cubo.

    // Inicializar cada cubo como un arreglo din�mico
    for (int i = 0; i < buckets; i++) {
    	// Bucle para inicializar cada cubo del arreglo 'bucket'.
// 'i' representa el �ndice de cada cubo en el arreglo 'bucket'.
// El bucle se ejecuta desde 0 hasta 'buckets - 1' para inicializar cada cubo.
        bucket[i] = (int *)malloc(n * sizeof(int));
        // Se utiliza 'malloc' para asignar memoria din�mica para el arreglo de enteros dentro de cada cubo.
// 'n * sizeof(int)' calcula el tama�o necesario para almacenar 'n' enteros en cada cubo.
// 'int *' se utiliza para convertir el puntero devuelto por 'malloc' en un puntero a un arreglo de enteros.
// Se asigna la memoria reci�n asignada al 'i-�simo' cubo del arreglo 'bucket'.

    }

    // Inicializar el contador de elementos en cada cubo
    int bucket_count[buckets] = {0};// Se crea un arreglo para contar cu�ntos elementos hay en cada cubo.
// 'bucket_count' es un arreglo de enteros donde cada elemento representa el n�mero de elementos en el cubo correspondiente.
// Se inicializa con todos los elementos en 0.


    // Asignar cada elemento al cubo correspondiente
    for (int i = 0; i < n; i++) {
        int bucket_index = (arr[i] * buckets) / (max_val + 1); 
        bucket[bucket_index][bucket_count[bucket_index]++] = arr[i]; // Agregar el elemento al cubo correspondiente
        // Se asigna cada elemento del arreglo original al cubo correspondiente.
// Se utiliza la f�rmula (arr[i] * buckets) / (max_val + 1) para calcular el �ndice del cubo.
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
// Despu�s de ordenar cada cubo, se copian los elementos ordenados de vuelta al arreglo original.
// 'index' se utiliza para rastrear la posici�n en el arreglo original.
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
    // Finalmente, se libera la memoria asignada para el arreglo de punteros 'bucket' en s�.
// Esto libera la memoria asignada para los punteros de los cubos.


    printf("Lista ordenada: ");
    printArray(arr, n);
    // Se imprime el encabezado "Lista ordenada:" en la consola.
// Se utiliza la funci�n printArray() para imprimir el arreglo 'arr' ordenado.
// 'arr' es el arreglo original que ahora contiene los elementos ordenados.
// 'n' es el n�mero total de elementos en el arreglo.


    // Calcular el n�mero de iteraciones (es la suma del tama�o de cada cubo)
    int iterations = 0;// Se declara una variable 'iterations' para almacenar el n�mero total de iteraciones.
// 'iterations' se inicializa en 0 y luego se incrementa agregando el tama�o de cada cubo.
// El n�mero total de iteraciones es la suma del tama�o de todos los cubos, es decir, la cantidad total de elementos.

    for (int i = 0; i < buckets; i++) {
        iterations += bucket_count[i];
        // Se utiliza un bucle para sumar el tama�o de cada cubo al total de iteraciones.
// Se recorren todos los cubos y se suma el n�mero de elementos en cada uno de ellos.
// 'bucket_count[i]' contiene el tama�o del 'i-�simo' cubo.

    }
    

    clock_t start = clock();// Se registra el tiempo de inicio utilizando la funci�n 'clock()'.
// La funci�n 'clock()' devuelve el n�mero de 'ciclos de reloj' (t�picamente en segundos) desde el inicio del programa.
// 'start' almacenar� el tiempo de inicio antes de ejecutar la parte principal del algoritmo.

    for (int i = 0; i < 1000000; i++) {} // Se ejecuta un ciclo vac�o con un mill�n de iteraciones.
// Esto se hace solo para gastar algo de tiempo y obtener una medici�n m�s precisa del tiempo de ejecuci�n.
// Este ciclo no tiene ninguna funcionalidad real y se utiliza solo para prop�sitos de medici�n.

    clock_t end = clock();// Se registra el tiempo de finalizaci�n utilizando la funci�n 'clock()'.
// 'end' almacenar� el tiempo de finalizaci�n despu�s de ejecutar la parte principal del algoritmo.


    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("N�mero de iteraciones: %d\n", iterations);
    printf("Tiempo de ejecuci�n: %.6f segundos\n", time_taken);
// Se calcula el tiempo total de ejecuci�n restando el tiempo de inicio del tiempo de finalizaci�n.
// El resultado se convierte a segundos dividi�ndolo por la constante 'CLOCKS_PER_SEC'.
// Se imprime el n�mero total de iteraciones y el tiempo de ejecuci�n en segundos con 6 decimales.

    // Calcular milisegundos
    double milliseconds = time_taken * 1000; // Convertir a milisegundos
    printf("Tiempo de ejecuci�n: %.3f milisegundos\n", milliseconds);
    // El tiempo de ejecuci�n tambi�n se muestra en milisegundos para mayor comprensi�n.
// Se multiplica el tiempo de ejecuci�n en segundos por 1000 para convertirlo a milisegundos.
// Se imprime el tiempo de ejecuci�n en milisegundos con 3 decimales.

}


// Funci�n para ordenar un arreglo utilizando el algoritmo de Selection Sort.
void selectionSort(int arr[], int n) {// Toma como argumentos un arreglo de enteros 'arr' y su tama�o 'n'.
    int iterations = 0; // Reiniciar el contador de iteraciones
    // Se reinicia el contador de iteraciones para este algoritmo de ordenamiento.
// 'iterations' se utiliza para contar el n�mero total de iteraciones realizadas durante el proceso de ordenamiento.

    printf("Selection Sort:\n");
    clock_t start = clock(); // Iniciar el reloj
    // Se registra el tiempo de inicio utilizando la funci�n 'clock()'.
// 'start' almacenar� el tiempo de inicio antes de ejecutar el algoritmo de Selection Sort.


    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
            iterations++; // Incrementar el contador en cada comparaci�n
        }
        swap(&arr[min_idx], &arr[i]);
        // Este bucle recorre el arreglo y en cada iteraci�n busca el elemento m�s peque�o en el subarreglo no ordenado.
// 'i' indica el �ndice del primer elemento del subarreglo no ordenado.
// Se inicializa 'min_idx' como el �ndice del primer elemento del subarreglo no ordenado.
// Se itera sobre el subarreglo no ordenado (desde 'i+1' hasta el final del arreglo).
// Si se encuentra un elemento m�s peque�o que el elemento en 'min_idx', se actualiza 'min_idx' con el �ndice de ese elemento.
// 'iterations' se incrementa en cada comparaci�n para contar el n�mero total de comparaciones realizadas durante el proceso de ordenamiento.
// Al final de cada iteraci�n del bucle exterior, el elemento en 'min_idx' se intercambia con el elemento en 'i',
// lo que coloca el elemento m�s peque�o en su posici�n correcta en el arreglo ordenado.

    }

    clock_t end = clock(); // Detener el reloj
    // Se registra el tiempo de finalizaci�n utilizando la funci�n 'clock()'.
// 'end' almacenar� el tiempo de finalizaci�n despu�s de ejecutar el algoritmo de Selection Sort.

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Calcular tiempo en segundos
    // Se calcula el tiempo total de ejecuci�n del algoritmo restando el tiempo de inicio del tiempo de finalizaci�n.
// El resultado se convierte a segundos dividi�ndolo por la constante 'CLOCKS_PER_SEC'.
// 'time_taken' contendr� el tiempo de ejecuci�n del algoritmo en segundos.


    printf("Lista ordenada: ");
    printArray(arr, n);
    printf("N�mero de iteraciones: %d\n", iterations);
    printf("Tiempo de ejecuci�n: %.6f segundos\n", time_taken);
    // Se imprime la lista ordenada en la consola utilizando la funci�n printArray().
// Se imprime el n�mero total de iteraciones y el tiempo de ejecuci�n del algoritmo en segundos con 6 decimales.


    double milliseconds = time_taken * 1000; 
    printf("Tiempo de ejecuci�n: %.3f milisegundos\n", milliseconds); 
    // Se convierte el tiempo de ejecuci�n del algoritmo a milisegundos multiplic�ndolo por 1000.
// Se imprime el tiempo de ejecuci�n en milisegundos con una precisi�n de tres decimales.

}


// Funci�n para ordenar un arreglo utilizando el algoritmo de Insertion Sort.
void insertionSort(int arr[], int n) {// Toma como argumentos un arreglo de enteros 'arr' y su tama�o 'n'.
    int iterations = 0; 
    printf("Insertion Sort:\n");
    clock_t start = clock(); 
    // Se inicializa el contador de iteraciones y se imprime un mensaje indicando que se est� utilizando el algoritmo de Insertion Sort.
// Se inicia el reloj para registrar el tiempo de inicio de la ejecuci�n del algoritmo.

    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            iterations++; // Incrementar el contador en cada comparaci�n
        }
        arr[j + 1] = key;
        // Este bucle recorre el arreglo a partir del segundo elemento hasta el �ltimo.
// En cada iteraci�n, se selecciona un elemento 'key' y se compara con los elementos anteriores a �l.
// Mientras el elemento 'key' sea menor que el elemento en la posici�n 'j', se desplaza el elemento 'j' una posici�n hacia adelante.
// Se incrementa 'iterations' en cada comparaci�n realizada.
// Una vez que se encuentra la posici�n correcta para 'key', se inserta en esa posici�n.

    }

    clock_t end = clock(); 
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; 
    // Se detiene el reloj para registrar el tiempo de finalizaci�n de la ejecuci�n del algoritmo.
// Se calcula el tiempo total de ejecuci�n del algoritmo en segundos.


    printf("Lista ordenada: ");
    printArray(arr, n);
    printf("N�mero de iteraciones: %d\n", iterations);
    printf("Tiempo de ejecuci�n: %.6f segundos\n", time_taken);
    // Se imprime la lista ordenada en la consola.
// Se imprime el n�mero total de iteraciones realizadas durante el proceso de ordenamiento.
// Se imprime el tiempo de ejecuci�n del algoritmo en segundos con 6 decimales.


    time_taken *= 1000; // Convertir a milisegundos
    printf("Tiempo de ejecuci�n: %.3f milisegundos\n", time_taken); // Imprimir el tiempo en milisegundos
    // Se convierte el tiempo de ejecuci�n del algoritmo a milisegundos y se imprime con una precisi�n de tres decimales.
// Esto se hace para proporcionar una medida de tiempo m�s comprensible.

}


// Funci�n para fusionar dos subarreglos ordenados en uno solo.
void merge(int arr[], int left[], int left_size, int right[], int right_size) {// Toma como argumentos el arreglo original 'arr', dos subarreglos ordenados 'left' y 'right',
// y sus respectivos tama�os 'left_size' y 'right_size'.
    int i = 0, j = 0, k = 0;// Se inicializan los �ndices 'i', 'j' y 'k' para los subarreglos 'left', 'right' y el arreglo fusionado 'arr' respectivamente.
// 'i' y 'j' son los �ndices que rastrean la posici�n actual en 'left' y 'right' respectivamente.
// 'k' es el �ndice que rastrea la posici�n actual en el arreglo fusionado 'arr'.

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
// Se incrementa 'iterations' en cada comparaci�n realizada.

    }

    while (i < left_size) {
        arr[k++] = left[i++];
        iterations++; // Incrementar el contador de iteraciones
        
        // Se copian los elementos restantes de 'left' al arreglo fusionado 'arr' si todav�a hay elementos en 'left'.
// Se incrementa 'k' para apuntar al siguiente espacio en 'arr'.
// Se incrementa 'iterations' en cada copia realizada.

    }

    while (j < right_size) {
        arr[k++] = right[j++];
        iterations++; // Incrementar el contador de iteraciones
        
        // Se copian los elementos restantes de 'right' al arreglo fusionado 'arr' si todav�a hay elementos en 'right'.
// Se incrementa 'k' para apuntar al siguiente espacio en 'arr'.
// Se incrementa 'iterations' en cada copia realizada.

    }
}

// Funci�n para ordenar un arreglo utilizando el algoritmo de Merge Sort.
void mergeSort(int arr[], int n) {// Toma como argumentos un arreglo de enteros 'arr' y su tama�o 'n'.
    if (n < 2) {
        return;
        // Se verifica si el tama�o del arreglo es menor que 2.
// Si es as�, significa que el arreglo ya est� ordenado (tiene 0 o 1 elemento), por lo que no se hace nada y se retorna.

    }

    int mid = n / 2;
    int left[mid];
    int right[n - mid];
    // Se calcula el �ndice medio del arreglo.
// Se crean dos arreglos, 'left' y 'right', para almacenar la mitad izquierda y la mitad derecha del arreglo 'arr' respectivamente.
// 'left' tendr� 'mid' elementos y 'right' tendr� 'n - mid' elementos.


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
// Se divide el problema en subproblemas m�s peque�os hasta que se llega a arreglos de tama�o 1.
    merge(arr, left, mid, right, n - mid);
   // Se llama a la funci�n 'merge' para fusionar las mitades izquierda y derecha ya ordenadas.
// 'mid' es el tama�o de la mitad izquierda y 'n - mid' es el tama�o de la mitad derecha.
// 'arr' contiene los elementos ordenados fusionados de 'left' y 'right'.


}


// Funci�n envoltorio para ordenar un arreglo utilizando el algoritmo de Merge Sort.
void mergeSortWrapper(int arr[], int n) {// Toma como argumentos un arreglo de enteros 'arr' y su tama�o 'n'.
    iterations = 0; 
    printf("Merge Sort:\n");
    clock_t start = clock(); 
    // Se reinicia el contador de iteraciones para este algoritmo de ordenamiento.
// Se imprime un mensaje indicando que se est� utilizando el algoritmo de Merge Sort.
// Se inicia el reloj para registrar el tiempo de inicio de la ejecuci�n del algoritmo.


    mergeSort(arr, n);// Se llama a la funci�n 'mergeSort' para ordenar el arreglo 'arr' utilizando el algoritmo de Merge Sort.


    clock_t end = clock(); 
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; 
    // Se detiene el reloj para registrar el tiempo de finalizaci�n de la ejecuci�n del algoritmo.
// Se calcula el tiempo total de ejecuci�n del algoritmo en segundos.


    printf("Lista ordenada: ");
    printArray(arr, n);
    printf("N�mero de iteraciones: %d\n", iterations);
    printf("Tiempo de ejecuci�n: %.6f segundos\n", time_taken);
    // Se imprime la lista ordenada en la consola.
// Se imprime el n�mero total de iteraciones realizadas durante el proceso de ordenamiento.
// Se imprime el tiempo de ejecuci�n del algoritmo en segundos con 6 decimales.


    double milliseconds = time_taken * 1000; // Convertir a milisegundos
    printf("Tiempo de ejecuci�n: %.3f milisegundos\n", milliseconds); // Imprimir el tiempo en milisegundos
}

// Funci�n para particionar un arreglo en torno a un elemento pivote.
int partition(int arr[], int low, int high) {// Toma como argumentos un arreglo de enteros 'arr', y los �ndices 'low' y 'high' que indican el rango del arreglo a considerar.
// Se utilizar� el elemento en 'high' como pivote.
    
	int pivot = arr[high];
    int i = low - 1;
    // Se selecciona el pivote como el elemento en la posici�n 'high'.
// Se inicializa 'i' como el �ndice del elemento m�s peque�o (o del �ltimo elemento del subarreglo que contiene los elementos menores o iguales al pivote).


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
    // Finalmente, se intercambia el pivote con el elemento en la posici�n 'i + 1' para colocar el pivote en su posici�n final en el arreglo ordenado.
// Se devuelve el �ndice de la posici�n final del pivote.

}

// Funci�n para ordenar un arreglo utilizando el algoritmo de Quick Sort de manera recursiva.
void quickSort(int arr[], int low, int high, int *iterations, double *time_taken) {
	// Toma como argumentos un arreglo de enteros 'arr', y los �ndices 'low' y 'high' que indican el rango del arreglo a considerar.
// Tambi�n toma como argumentos un puntero a 'iterations' y un puntero a 'time_taken' para actualizar el n�mero de iteraciones y el tiempo de ejecuci�n respectivamente.

    if (low < high) {// Se verifica si el rango es v�lido, es decir, si 'low' es menor que 'high'.Si es v�lido, contin�a con la ordenaci�n.

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1, iterations, time_taken);
        quickSort(arr, pi + 1, high, iterations, time_taken);
        (*iterations)++;
        // Se llama a la funci�n 'partition' para obtener el �ndice del pivote y particionar el arreglo en torno a �l.
// Luego, se llama recursivamente a 'quickSort' para ordenar las subarreglos a la izquierda y a la derecha del pivote.
// Se incrementa el contador de iteraciones despu�s de cada llamada recursiva, ya que cada llamada representa un paso en el algoritmo de Quick Sort.

    }
}

// Funci�n para llamar al algoritmo de Quick Sort y mostrar los resultados.
void callQuickSort(int arr[], int n) {// Toma como argumentos un arreglo de enteros 'arr' y su tama�o 'n'.
    int iterations = 0;
    clock_t start, end;// Variables para medir el tiempo de ejecuci�n
    double time_taken;// Variable para almacenar el tiempo de ejecuci�n
   printf("Quick Sort:\n");
   // Se inicializa el contador de iteraciones.
// Se declaran las variables para medir el tiempo de ejecuci�n del algoritmo.
// Se imprime un mensaje indicando que se est� utilizando el algoritmo de Quick Sort.


    start = clock();//arrancar reloj
    quickSort(arr, 0, n - 1, &iterations, &time_taken);//Llamar al algoritmo de Quick Sort
    end = clock();
    // Se inicia el reloj antes de llamar al algoritmo de Quick Sort.
// Se llama a la funci�n 'quickSort' para ordenar el arreglo 'arr' de manera recursiva.
// Se pasan punteros a 'iterations' y 'time_taken' para actualizar el n�mero de iteraciones y el tiempo de ejecuci�n.
// Se detiene el reloj despu�s de que Quick Sort ha finalizado su ejecuci�n.


    printArray(arr, n);
    printf("N�mero de iteraciones: %d\n", iterations);
    // Se imprime el arreglo ordenado.
// Se imprime el n�mero total de iteraciones realizadas durante la ejecuci�n de Quick Sort.


}


// Funci�n para ordenar un arreglo utilizando el algoritmo de Shell Sort.
void shellSort(int arr[], int n) {// Toma como argumentos un arreglo de enteros 'arr' y su tama�o 'n'.
    int iterations = 0;
    clock_t start, end;
    start = clock(); 
    // Se inicializa el contador de iteraciones.
// Se declaran las variables para medir el tiempo de ejecuci�n del algoritmo.
// Se inicia el reloj para registrar el tiempo de inicio de la ejecuci�n del algoritmo.


    for (int gap = n / 2; gap > 0; gap /= 2) {// Se establece el tama�o inicial del espacio de separaci�n 'gap' como la mitad del tama�o del arreglo.
// 'gap' determina el tama�o del paso entre los elementos que se comparan y se intercambian en cada iteraci�n.
// El algoritmo de Shell Sort utiliza diferentes valores de 'gap' para ordenar subgrupos de elementos del arreglo.

        for (int i = gap; i < n; i++) {
        	// Se inicia un bucle que recorre el arreglo desde el �ndice 'gap' hasta el final.
// 'i' representa la posici�n actual en el arreglo.
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
// 'j' representa la posici�n actual en el arreglo dentro del grupo definido por 'gap'.
// El bucle se ejecuta mientras 'j' sea mayor o igual que 'gap' y el elemento anterior dentro del grupo sea mayor que 'temp'.
// Si se cumple la condici�n, se mueve el elemento anterior hacia adelante en el grupo.
// Se incrementa el contador de iteraciones en cada comparaci�n.
// Despu�s de que el bucle interno termine, se coloca el valor de 'temp' en la posici�n correcta dentro del grupo.

        }
    }

    end = clock(); // Detener el reloj
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; 
    // Se detiene el reloj para registrar el tiempo de finalizaci�n de la ejecuci�n del algoritmo.
// Se calcula el tiempo total de ejecuci�n del algoritmo en segundos.


    printf("Shell Sort:\n");
    printf("Lista ordenada: ");
    printArray(arr, n);
    printf("N�mero de iteraciones: %d\n", iterations);
    
    // Se imprime un mensaje indicando que se est� utilizando el algoritmo de Shell Sort.
// Se imprime el arreglo ordenado.
// Se imprime el n�mero total de iteraciones realizadas durante la ejecuci�n del algoritmo.

}


// Funci�n de Counting Sort
void countingSort(int arr[], int n) {// Toma como argumentos un arreglo de enteros 'arr' y su tama�o 'n'.
    int max_val = arr[0];// Inicializar el valor m�ximo como el primer elemento del arreglo
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];// Actualizar el valor m�ximo si se encuentra un valor mayor
        }
    }
    // Se busca el valor m�ximo en el arreglo para determinar el rango de los elementos.
// El valor m�ximo es necesario para crear un arreglo de conteo de tama�o suficiente.


        int *count = (int *)calloc(max_val + 1, sizeof(int)); // Crear un arreglo de conteo
    int iterations = 0; // Inicializar el contador de iteraciones

    for (int i = 0; i < n; i++) {
        count[arr[i]]++; // Contar la frecuencia de cada elemento
        iterations++; // Incrementar el contador de iteraciones
    }
    // Se crea un arreglo de conteo de tama�o (max_val + 1) e inicializado con ceros.
// Se recorre el arreglo original para contar la frecuencia de cada elemento.
// Se incrementa el contador de iteraciones en cada iteraci�n del bucle.



    int index = 0;
    for (int i = 0; i <= max_val; i++) {

        while (count[i]--) {
            arr[index++] = i;// Reconstruir el arreglo ordenado
            iterations++;
            // Se reconstruye el arreglo ordenado a partir del arreglo de conteo.
// Se recorre el arreglo de conteo y para cada elemento se copian 'count[i]' veces el valor 'i' en el arreglo original.
// Se incrementa el contador de iteraciones en cada iteraci�n del bucle.

        }
    }

    free(count);// Liberar la memoria asignada para el arreglo de conteo

    printf("Counting Sort: ");
    printArray(arr, n);
    printf("N�mero de iteraciones: %d\n", iterations);

    clock_t start, end;
    double time_taken;
    start = clock();
    end = clock(); // Detener el reloj
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Calcular tiempo en segundos
    // Se libera la memoria asignada para el arreglo de conteo.
// Se imprime el arreglo ordenado.
// Se imprime el n�mero total de iteraciones realizadas durante la ejecuci�n del algoritmo.
// Se mide el tiempo de ejecuci�n del algoritmo.

}

// Funci�n para obtener el m�ximo valor en un arreglo
int getMax(int arr[], int n) {// Esta funci�n recibe un arreglo de enteros 'arr' y su tama�o 'n'.
// Retorna el valor m�ximo presente en el arreglo.
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
            // Se busca el valor m�ximo en el arreglo para determinar el m�ximo.
// Se inicializa 'max_val' con el primer elemento del arreglo.
// Se recorre el arreglo a partir del segundo elemento.
// Si se encuentra un elemento mayor que 'max_val', se actualiza 'max_val' con este valor.

        }
    }
    return max_val;// Se retorna el valor m�ximo encontrado en el arreglo.

}

// Funci�n de Count Sort para Radix Sort
void countSort(int arr[], int n, int exp) {// Esta funci�n implementa Counting Sort, un algoritmo auxiliar utilizado en Radix Sort.
// Recibe un arreglo de enteros 'arr', su tama�o 'n' y el exponente 'exp'.
// 'exp' determina el d�gito en el que se est� ordenando actualmente el arreglo.

      int *output = (int *)malloc(n * sizeof(int)); // Arreglo de salida para almacenar los elementos ordenados
    int count[10] = {0}; // Arreglo de conteo para contar la frecuencia de cada d�gito (0-9)
// Se reserva memoria para un arreglo de salida del mismo tama�o que el arreglo original.
// Se inicializa un arreglo de conteo para contar la frecuencia de cada d�gito del 0 al 9.


    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;// Contar la frecuencia de cada d�gito
        // Se recorre el arreglo original y se cuenta la frecuencia de cada d�gito en la posici�n correspondiente del arreglo de conteo.
// La f�rmula (arr[i] / exp) % 10 obtiene el d�gito relevante en la posici�n 'exp' del n�mero.

    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];// Actualizar el arreglo de conteo para indicar las posiciones finales de los elementos
    }// Se actualiza el arreglo de conteo para que cada elemento indique la posici�n final de los elementos en el arreglo de salida.


        for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]; // Colocar los elementos en el arreglo de salida en orden
        count[(arr[i] / exp) % 10]--; // Disminuir la cuenta despu�s de colocar un elemento
    }// Se coloca cada elemento del arreglo original en su posici�n correspondiente en el arreglo de salida.
// Se decrementa el conteo de ese d�gito despu�s de colocar un elemento en el arreglo de salida.


        for (int i = 0; i < n; i++) {
        arr[i] = output[i]; // Copiar el arreglo de salida al arreglo original
    }// Se copia el arreglo de salida al arreglo original para reflejar los cambios.



    free(output);// Se libera la memoria asignada para el arreglo de salida.

}

// Funci�n de Radix Sort
void radixSort(int arr[], int n) {
    // Encontrar el valor m�ximo en el arreglo
    int max_val = getMax(arr, n);
    int iterations = 0; // Inicializar el contador de iteraciones

    // Loop para cada posici�n de los d�gitos, comenzando desde el d�gito menos significativo hasta el m�s significativo
    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        // Ordenar el arreglo utilizando el conteo de cada d�gito en la posici�n actual
        countSort(arr, n, exp);
        iterations++; // Incrementar el contador de iteraciones
    }

    // Imprimir la lista ordenada
    printf("Lista ordenada: ");
    printArray(arr, n);

    // Imprimir el n�mero de iteraciones realizadas
    printf("N�mero de iteraciones: %d\n", iterations);

    clock_t start, end; // Variables para medir el tiempo
    double time_taken;
    start = clock(); // Iniciar el reloj
    
    end = clock(); // Detener el reloj
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Calcular tiempo en segundos
}

// funcion para agregar numero ala lista
void agregarNumero(int arr[], int *n, int max_size) {
    // Verifica si el tama�o actual del arreglo es menor que el tama�o m�ximo permitido
    if (*n < max_size) {
        printf("Ingrese el n�mero a agregar: "); // Solicita al usuario ingresar un n�mero
        int num;
        scanf("%d", &num); // Lee el n�mero ingresado por el usuario
        arr[*n] = num; // Agrega el n�mero al final del arreglo
        (*n)++; // Incrementa el tama�o del arreglo
        printf("N�mero agregado.\n"); // Muestra un mensaje de confirmaci�n
    } else {
        printf("�La lista est� llena! No se puede agregar m�s n�meros.\n"); // Muestra un mensaje de error si el arreglo est� lleno
    }
}

//funcion para eliminar un numero de la lista
void eliminarNumero(int arr[], int *n) {
    // Verifica si el arreglo no est� vac�o
    if (*n > 0) {
        printf("Ingrese el n�mero a eliminar: "); // Solicita al usuario ingresar el n�mero a eliminar
        int num;
        scanf("%d", &num); // Lee el n�mero ingresado por el usuario
        int found = 0; // Variable para indicar si el n�mero se encontr� en el arreglo
        // Recorre el arreglo para encontrar el n�mero
        for (int i = 0; i < *n; i++) {
            if (arr[i] == num) { // Si el n�mero se encuentra en el arreglo
                found = 1; // Marca que el n�mero fue encontrado
                // Elimina el n�mero moviendo los elementos restantes una posici�n hacia adelante
                for (int j = i; j < *n - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                (*n)--; // Decrementa el tama�o del arreglo
                printf("N�mero eliminado.\n"); // Muestra un mensaje de confirmaci�n
                break; // Sale del bucle una vez que el n�mero se elimina
            }
        }
        // Si el n�mero no se encontr� en el arreglo
        if (!found) {
            printf("El n�mero no existe en la lista.\n"); // Muestra un mensaje de error
        }
    } else {
        printf("�La lista est� vac�a! No se puede eliminar ning�n n�mero.\n"); // Muestra un mensaje de error si el arreglo est� vac�o
    }
}






int main() {
		setlocale(LC_ALL, "");
// Esta l�nea declara un arreglo de enteros llamado numbers con un tama�o m�ximo definido por MAX_SIZE.
// Este arreglo se utilizar� para almacenar los n�meros le�dos desde el archivo.
int numbers[MAX_SIZE];

// Esta l�nea inicializa una variable entera llamada count en 0.
// Probablemente se utilizar� para llevar un recuento del n�mero de elementos en el arreglo numbers.
int count = 0;

// Esta l�nea declara un arreglo de caracteres llamado filename y lo inicializa con la ruta del archivo
// que contiene la lista de n�meros que se leer�.
char filename[] = "C:\\Users\\juana\\OneDrive\\Escritorio\\STRUCT DE DATOS\\lista_de_numeros.txt";

// Esta l�nea declara otro arreglo de caracteres llamado newFilename y lo inicializa con la ruta del archivo
// donde se escribir�n los n�meros.
char newFilename[] = "C:\\Users\\juana\\OneDrive\\Escritorio\\STRUCT DE DATOS\\nueva_lista.txt";

   // Imprime un mensaje de bienvenida
printf("Bienvenido al programa de ordenamiento!\n");

// Lee los n�meros desde el archivo y los almacena en el arreglo numbers
// count contiene la cantidad de n�meros le�dos
count = readNumbersFromFile(numbers, filename);

// Si no se pudo leer ning�n n�mero desde el archivo, muestra un mensaje de error y sale del programa
if (count == 0) {
    printf("No se pudo leer ning�n n�mero desde el archivo.\n");
    return 1;
}

// Muestra la lista de n�meros le�dos desde el archivo
showList(numbers, count);

// Solicita al usuario la cantidad de n�meros que desea ordenar
int numToSort;
printf("Ingrese la cantidad de n�meros que desea ordenar: ");
scanf("%d", &numToSort);

// Si la cantidad de n�meros a ordenar excede la cantidad total de n�meros en el archivo, muestra un mensaje de error y sale del programa
if (numToSort > count) {
    printf("La cantidad de n�meros a ordenar excede la cantidad total de n�meros en el archivo.\n");
    return 1;
}

// Crea un nuevo arreglo numbersToSort con los primeros numToSort n�meros del arreglo numbers
int numbersToSort[numToSort];
for (int i = 0; i < numToSort; i++) {
    numbersToSort[i] = numbers[i];
}

// Muestra los n�meros que se van a ordenar
printf("N�meros a ordenar:\n");
printArray(numbersToSort, numToSort);

// Guarda los n�meros en el nuevo archivo
saveToFile(numbersToSort, numToSort, newFilename);

// Inicia un bucle infinito para mostrar el men� de opciones
char choice;
while (1) {
    printf("\nMen�:\n");
    printf("a. Agregar un n�mero\n");
    printf("b. Eliminar un n�mero\n");
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
    printf("Ingrese su elecci�n: ");
    scanf(" %c", &choice);

    // Realiza la acci�n correspondiente seg�n la opci�n elegida por el usuario
    switch (choice) {
        case 'a': { // Agregar un n�mero
            agregarNumero(numbersToSort, &numToSort, MAX_SIZE);
            printArray(numbersToSort, numToSort);
            break;
        }
        case 'b': { // Eliminar un n�mero
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
            printf("Tiempo de ejecuci�n: %.6f segundos\n", time_taken);
            time_taken *= 1000; // Convertir a milisegundos
            printf("Tiempo de ejecuci�n: %.3f milisegundos\n", time_taken);
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
            printf("Tiempo de ejecuci�n: %.6f segundos\n", time_taken);
            printf("Tiempo de ejecuci�n: %.3f milisegundos\n", milliseconds);
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
            printf("Tiempo de ejecuci�n de Counting Sort: %.6f segundos\n", time_taken);
            printf("Tiempo de ejecuci�n de Counting Sort: %.3f milisegundos\n", milliseconds);
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
            printf("Tiempo de ejecuci�n de Radix Sort: %.6f segundos\n", time_taken);
            printf("Tiempo de ejecuci�n de Radix Sort: %.3f milisegundos\n", milliseconds);
            saveToFile(numbersToSort, numToSort, newFilename);
            break;
        }
        case 'l': // Salir
            printf("�Adi�s!\n");
            exit(0);
            break;
        default: // Opci�n inv�lida
            printf("�Opci�n inv�lida!\n");
            break;
    }
}

// Finaliza el programa
return 0;
}
