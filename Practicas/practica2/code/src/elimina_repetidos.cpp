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




int main(int argc, char* argv[]){


	if (argc != 2){
		cerr << "Formato " << argv[0] << " <num_elem>" << endl;
		return -1;
    }

	int n = atoi(argv[1]);

	//int * T = new int[n];
	vector<int> v(n);

	srand(time(0));
	//para generar un vector que pueda tener elementos repetidos
	for (int j=0; j<n; j++) {
		double u=uniforme();
		int k=(int)(n*u);
		v[j]=k;
	}
	
	//*****************************************************
	// CALCULO DE TIEMPO DE EJECUION DEL ALGORITMO SIMPLE
	//*****************************************************	

		srand(time(0)); // Inicialización generador números pseudoaleatorios

		clock_t tini; // Anotamos el tiempo de inicio
		tini=clock();
		
		removeRepSimple(v);
		
		clock_t tfin; // Anotamos el tiempo de finalización
		tfin=clock();
		
		
		cout << v.size() << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl; // Mostramos resultados (Tamaño del vector y tiempo de ejecución en seg.)


	//*****************************************************
	// CALCULO DE TIEMPO DE EJECUION DEL ALGORITMO DV
	//*****************************************************

		srand(time(0)); // Inicialización generador números pseudoaleatorios

		clock_t tini_dv; // Anotamos el tiempo de inicio
		tini=clock();
		
		removeRepDV(v);
		
		clock_t tfin_dv; // Anotamos el tiempo de finalización
		tfin=clock();
		
		
		cout << v.size() << "\t" << (tfin_dv-tini_dv)/(double)CLOCKS_PER_SEC << endl; // Mostramos resultados (Tamaño del vector y tiempo de ejecución en seg.)


	return 0;
}


void removeRepSimple(vector<int> v ){

	for(auto i:v)
		for(uint j=i; j < v.size(); j++)
			if(i == v[j])
				v.erase(v.begin() + j);


}

void removeRepDV(vector<int> v){

	heapsort(v.data(), v.size());

	removeRepDV_rec(v);

}

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
