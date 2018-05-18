/**
   @file Ordenación por mezcla
*/

   
#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>






/* ************************************************************ */ 
/*  Método de ordenación por mezcla  */

/**
   @brief Ordena un vector por el método de mezcla.

   @param T: vector de elementos. Debe tener num_elem elementos.
             Es MODIFICADO.
   @param num_elem: número de elementos. num_elem > 0.

   Cambia el orden de los elementos de T de forma que los dispone
   en sentido creciente de menor a mayor.
   Aplica el algoritmo de mezcla.
*/
inline static 
void mergesort(int T[], int num_elem);



/**
   @brief Ordena parte de un vector por el método de mezcla.

   @param T: vector de elementos. Tiene un número de elementos 
                   mayor o igual a final. Es MODIFICADO.
   @param inicial: Posición que marca el incio de la parte del
                   vector a ordenar.
   @param final: Posición detrás de la última de la parte del
                   vector a ordenar. 
		   inicial < final.

   Cambia el orden de los elementos de T entre las posiciones
   inicial y final - 1 de forma que los dispone en sentido creciente
   de menor a mayor.
   Aplica el algoritmo de la mezcla.
*/
static void mergesort_lims(int T[], int inicial, int final);


/**
   @brief Ordena un vector por el método de inserción.

   @param T: vector de elementos. Debe tener num_elem elementos.
             Es MODIFICADO.
   @param num_elem: número de elementos. num_elem > 0.

   Cambia el orden de los elementos de T de forma que los dispone
   en sentido creciente de menor a mayor.
   Aplica el algoritmo de inserción.
*/
inline static 
void insercion(int T[], int num_elem);


/**
   @brief Ordena parte de un vector por el método de inserción.

   @param T: vector de elementos. Tiene un número de elementos 
                   mayor o igual a final. Es MODIFICADO.
   @param inicial: Posición que marca el incio de la parte del
                   vector a ordenar.
   @param final: Posición detrás de la última de la parte del
                   vector a ordenar. 
		   inicial < final.

   Cambia el orden de los elementos de T entre las posiciones
   inicial y final - 1 de forma que los dispone en sentido creciente
   de menor a mayor.
   Aplica el algoritmo de la inserción.
*/
static void insercion_lims(int T[], int inicial, int final);


/**
   @brief Mezcla dos vectores ordenados sobre otro.

   @param T: vector de elementos. Tiene un número de elementos 
                   mayor o igual a final. Es MODIFICADO.
   @param inicial: Posición que marca el incio de la parte del
                   vector a escribir.
   @param final: Posición detrás de la última de la parte del
                   vector a escribir
		   inicial < final.
   @param U: Vector con los elementos ordenados.
   @param V: Vector con los elementos ordenados.
             El número de elementos de U y V sumados debe coincidir
             con final - inicial.

   En los elementos de T entre las posiciones inicial y final - 1
   pone ordenados en sentido creciente, de menor a mayor, los
   elementos de los vectores U y V.
*/
static void fusion(int T[], int inicial, int final, int U[], int V[]);



/**
   Implementación de las funciones
**/


inline static void insercion(int T[], int num_elem)
{
  insercion_lims(T, 0, num_elem);
}


static void insercion_lims(int T[], int inicial, int final)
{
  int i, j;
  int aux;
  for (i = inicial + 1; i < final; i++) {
    j = i;
    while ((T[j] < T[j-1]) && (j > 0)) {
      aux = T[j];
      T[j] = T[j-1];
      T[j-1] = aux;
      j--;
    };
  };
}


const int UMBRAL_MS = 2;

void mergesort(int T[], int num_elem)
{
  mergesort_lims(T, 0, num_elem);
}

static void mergesort_lims(int T[], int inicial, int final)
{

  if (final - inicial < UMBRAL_MS)
    {
      return;
    } else {
      int k = (final - inicial)/2;

      int * U = new int [k - inicial + 1];
      assert(U);
      int l, l2;
      for (l = 0, l2 = inicial; l < k; l++, l2++)
	    U[l] = T[l2];
      U[l] = INT_MAX;

      int * V = new int [final - k + 1];
      assert(V);
      for (l = 0, l2 = k; l < final - k; l++, l2++)
	    V[l] = T[l2];
      V[l] = INT_MAX;

      mergesort_lims(U, 0, k);
      mergesort_lims(V, 0, final - k);
      fusion(T, inicial, final, U, V);
      delete [] U;
      delete [] V;
    };
}
  

static void fusion(int T[], int inicial, int final, int U[], int V[])
{
  	int j = 0;
  	int k = 0;
  	for (int i = inicial; i < final; i++){
		if (U[j] < V[k]) {
			T[i] = U[j];
			j++;
		} 
		else if(U[j] > V[k]){
			T[i] = V[k];
			k++;
		}
		else{
      T[i] = V[k];
			k++;
      j++;

    }
	}
}



double uniforme() //Genera un número uniformemente distribuido en el
                  //intervalo [0,1) a partir de uno de los generadores
                  //disponibles en C.
{
  int t = rand();
  double f = ((double)RAND_MAX+1.0);
  return (double)t/f;
}

void sintaxis() {
  cerr << "Sintaxis:" << endl;
  cerr << " TAM: Tamaño del vector (>0)" << endl;
  cerr << " VMAX: Valor máximo (>0)" << endl;
  cerr << "Genera un vector de TAM números aleatorios en [0,VMAX[" << endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{

  int contador = 0;
  if (argc!=3)// Lectura de parámetros
    sintaxis();

  int tam=atoi(argv[1]);// Tamaño del vector
  int vmax=atoi(argv[2]);// Valor máximo
  
  if (tam<=0 || vmax<=0) // Generación del vector aleatorio
    sintaxis();
  
  int *v=new int[tam]; // Reserva de memoria
  
  srand(time(0)); // Inicialización generador números pseudoaleatorios
  
  for (int i=0; i<tam; i++) // Recorrer vector
    v[i] = rand() % vmax; // Generar aleatorio [0,vmax[

  ///////////////VECTOR ORIGINAL////////////////

  /*cout << "El vector original es: ";
  for (int j=0; j<tam; j++){
    cout << v[j] << " ";
  }
  cout << endl;*/


  //Buscar el elemento mayor del vector
  int aux = 0;
  for(int j = 0; j < tam; j++){
    if(v[j]>=aux)
      aux = v[j];
  }

  
  clock_t tini; // Anotamos el tiempo de inicio
  tini=clock();
  
  mergesort(v,tam); 

  clock_t tfin; // Anotamos el tiempo de finalización
  tfin=clock();
  
  
  cout << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl; // Mostramos resultados (Tamaño del vector y tiempo de ejecución en seg.)

  int j = 0;
  while(v[j] <= aux){
    contador++;
    j++;
  }
  int vector[contador];

  for(int i = 0; i<contador; i++){
    vector[i] = v[i];
  }

  ////////////////////MOSTRAR VECTOR SIN REPETIROS Y ORDENADO////////////////////////
  /*cout << "El vector resultante sin repetidos y ordenado es: ";
    for (int j=0; j<contador; j++) {
      cout << vector[j] << " ";

  }
    cout << endl;*/

  delete [] v;  // Liberamos memoria dinámica


}

