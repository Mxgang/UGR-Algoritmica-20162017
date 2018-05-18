/**
   @file Ordenación por inserción
*/

   
#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>






/* ************************************************************ */ 
/*  Método de ordenación por inserción  */

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
   inicial y final - 1de forma que los dispone en sentido creciente
   de menor a mayor.
   Aplica el algoritmo de inserción.
*/
static void insercion_lims(int T[], int inicial, int final);



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


void sintaxis() {
  cerr << "Sintaxis:" << endl;
  cerr << " TAM: Tamaño del vector (>0)" << endl;
  cerr << " VMAX: Valor máximo (>0)" << endl;
  cerr << "Genera un vector de TAM números aleatorios en [0,VMAX[" << endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char * argv[]) {
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
  
  clock_t tini; // Anotamos el tiempo de inicio
  tini=clock();
  
  insercion(v,tam); 

  clock_t tfin; // Anotamos el tiempo de finalización
  tfin=clock();
  
  
  cout << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl; // Mostramos resultados (Tamaño del vector y tiempo de ejecución en seg.)

  delete [] v;  // Liberamos memoria dinámica

}