#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <assert.h>

using namespace std;

typedef vector<vector<float> > Mat;

void leerArchivo( string path ,Mat &dist, Mat &flujo);
float greedyQAP(Mat &dist, Mat &flujo, vector<int> &S);

int main(){

	Mat dist, flujo;
	vector<int> S;
	leerArchivo(string("data"), dist, flujo);

	cout << "\n\tCoste total: " << greedyQAP(dist, flujo, S) << endl;

	for(int i=0; i < S.size(); i++)
		cout << "\n\tOficinista " << i+1 << " en Habitacion " << S[i]+1;
	cout << "\n\n";

}


float greedyQAP(Mat &dist, Mat &flujo, vector<int> &S){

	assert(dist.size() == flujo.size());
	int tam = dist.size();

	//Calculo de potenciales
		vector<float> pd;
		vector<float> pf;

		float sumF=0, sumD=0;
		for(int i=0; i < tam; i++){
			for(int j=0; j < tam; j++){
				sumF+=flujo[i][j];
				sumD+=dist[i][j];
			}
			pf.push_back(sumF);
			pd.push_back(sumD);
			sumF = sumD = 0;
		}

		cout << endl;



	vector<int> solucion(tam);

	//Nucleo del greddy
		for(int i = 0; i < tam; i++){

			//Obtener maximo en pf
			int indexF=0;
			float max = 0;
			for(int f_i = 0; f_i < pf.size(); f_i++){
				if (pf[f_i] > max && pf[f_i] >= 0){
					max = pf[f_i];
					indexF = f_i;
				}
			}
			//cout << "max: " << pf[indexF] << endl;
			pf[indexF] *= -1;

			//Obtener minimo en pd
			int indexD;
			float min=999999;
			for(int d_i = 0; d_i < pd.size(); d_i++){
				if (pd[d_i] < min && pd[d_i] >= 0){
					min = pd[d_i];
					indexD = d_i;
				}
			}
			//cout << "min: " << pd[indexD] << endl;
			pd[indexD] *= -1;




			assert(indexF <= tam && indexD <= tam);

		 	solucion[indexF] = indexD;

		}



	//Calcular el resultado
	float resultado = 0;
	for(int i = 0; i < tam; i++)
		for(int j = 0; j < tam; j++)
			resultado += flujo[i][j] * dist[solucion[i]][solucion[j]];

	S = solucion;

	return resultado;

}


void leerArchivo( string path ,Mat &dist, Mat &flujo){

	ifstream imput(path.c_str());

	assert(imput.good());

	int tam;
	imput >> tam;

	vector<float> aux;
	float v;
	for(int i=0; i < tam; i++){
		for(int j=0; j < tam; j++){
			imput >> v;
			aux.push_back(v);
		}
		dist.push_back(aux);
		aux.clear();
	}

	aux.clear();
	for(int i=0; i < tam; i++){
		for(int j=0; j < tam; j++){
			imput >> v;
			aux.push_back(v);
		}
		flujo.push_back(aux);
		aux.clear();

	}

}