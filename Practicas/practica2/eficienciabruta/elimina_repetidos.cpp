#include <iostream>

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <assert.h> 
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>

using namespace std;

void removeRepSimple(vector<int> v );

void removeRepDV(vector<int> v);
void removeRepDV_rec(vector<int> v);

double uniforme();

void sintaix();



void sintaxis() {
  cerr << "Sintaxis:" << endl;
  cerr << " TAM: Tamaño del vector (>0)" << endl;
  cerr << " VMAX: Valor máximo (>0)" << endl;
  cerr << "Genera un vector de TAM números aleatorios en [0,VMAX[" << endl;
  exit(EXIT_FAILURE);
}

void removeRepSimple(vector<int> v ){

	for(auto i:v)
		for(int j=i; j < v.size(); j++)
			if(i == v[j])
				v.erase(v.begin() + j);


}

/*void removeRepDV(vector<int> v){

	heapsort(v.data(), v.size());

	removeRepDV_rec(v);

}*/

void removeRepDV_rec(vector<int> v){



}

//generador de ejemplos para el problema de eliminar elementos repetidos. Simplemente, para rellenar el vector de tamaño n genera n enteros aleatorios entre 0 y n-1

double uniforme() //Genera un número uniformemente distribuido en el
                  //intervalo [0,1) a partir de uno de los generadores
                  //disponibles en C.
{
	int t = rand();
	double f = ((double)RAND_MAX+1.0);
	return (double)t/f;
}


int main(int argc, char* argv[]){

	if (argc!=3)// Lectura de parámetros
    sintaxis();

  int tam=atoi(argv[1]);// Tamaño del vector
  int vmax=atoi(argv[2]);// Valor máximo
  
  if (tam<=0 || vmax<=0) // Generación del vector aleatorio
    sintaxis();
  
  	vector<int> v(tam);
  
  srand(time(0)); // Inicialización generador números pseudoaleatorios
  
  //para generar un vector que pueda tener elementos repetidos
	for (int j=0; j<tam; j++) {
		double u=uniforme();
		int k=(int)(tam*u);
		v[j]=k;
	}

  
  clock_t tini; // Anotamos el tiempo de inicio
  tini=clock();
  
  removeRepSimple(v); 

  clock_t tfin; // Anotamos el tiempo de finalización
  tfin=clock();
  
  
  cout << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl; // Mostramos resultados (Tamaño del vector y tiempo de ejecución en seg.)



	return 0;
}
