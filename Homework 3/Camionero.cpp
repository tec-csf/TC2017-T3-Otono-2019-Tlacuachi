/*
    Sebastian Gonzalo Vives Faus | A01025211
    Tarea 3| Algoritmo Avido

Un camionero conduce desde DF a Acapulco siguiendo una ruta dada y llevando un camión que le permite, 
con el tanque de gasolina lleno, recorrer n kilómetros sin parar. El camionero dispone de un mapa de carreteras 
que le indica las distancias entre las gasolineras que hay en su ruta. Como va con prisa, el camionero desea detenerse a 
abastecer gasolina el menor número de veces posible.

Diseñe un algoritmo eficiente que determine en qué gasolineras tiene que parar el camionero.

Este lo hice solito!
Complejidad del algoritmo: O(n)

*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

//Inserta valores aleatorios al arreglo
void scramble(int n, int *arr, int maxD){
	srand (time(NULL));//Semilla aleatorio
	for(int i = 0; i<n; i++){
		arr[i] = rand() % maxD;
	}

}

//Imprime el arreglo
void print(int n, int *arr){
	for(int i = 0; i<n; i++){
		cout<<"Gasolineria "<<i+1<<" se encuentra a "<<arr[i]<<" KM del punto B"<<endl;
	}
}

//Bucket Sort, ordena el arreglo
void BucketSort(int* data, int count) {
	int minValue = data[0];
	int maxValue = data[0];

	for (int i = 1; i < count; i++)
	{
		if (data[i] > maxValue)
			maxValue = data[i];
		if (data[i] < minValue)
			minValue = data[i];
	}

	int bucketLength = maxValue - minValue + 1;
	vector<int>* bucket = new vector<int>[bucketLength];

	for (int i = 0; i < bucketLength; i++)
	{
		bucket[i] = vector<int>();
	}

	for (int i = 0; i < count; i++)
	{
		bucket[data[i] - minValue].push_back(data[i]);
	}

	int k = 0;
	for (int i = 0; i < bucketLength; i++)
	{
		int bucketSize = bucket[i].size();

		if (bucketSize > 0)
		{
			for (int j = 0; j < bucketSize; j++)
			{
				data[k] = bucket[i][j];
				k++;
			}
		}
	}
}

void viaje(int *arr, int *paradas, int maxF, int n, int maxD){
	bool destino = true;
	int distancia=0, counter = 0, pcounter=0, d=0;
	distancia = maxF;
	while(destino){
		
		if(counter<n-1){ //Tomamos hasta la penultima gasolineria
				distancia = maxF - (arr[counter]-d);
			if(distancia-(arr[counter+1]-arr[counter])>0){//Alcanzo a llegar a la siguiente gasolineria? SI, entonces sigo.
				
				cout<<"KM que me quedan de gasolina "<<distancia<<endl;
				counter++;
				
			}//end if2
			else {//No alcanzo a llegar a la siguiente gasolineria, entonces pongo.
				paradas[pcounter] = counter+1;
				d = arr[counter];
				counter++; pcounter++;
				cout<<"Puse gasolina en la gasolineria "<<counter<<" | d = "<<d<<endl;
				distancia = maxF;
				cout<<"KM que me quedan de gasolina "<<distancia<<endl;
				
				
			}//end else2

		}//end if1
		else{
			cout<<"Ultima!"<<endl;
			distancia = maxF - (arr[counter]-d);
			if(distancia-(maxD-arr[counter])>0){ //Alcanzo a llegar al destino sin poner gasolina? SI
				cout<<"Alcance a llegar sin poner gasolina!"<<endl;
				cout<<"KM que me quedan de gasolina "<<distancia<<endl;
				destino = false;
			}//end if2

			else{//No llego al destino sin poner gasolina
				paradas[pcounter] = counter+1;
				d = arr[counter];
				counter++;
				cout<<"Puse gasolina en la gasolineria "<<counter<<" | d = "<<d<<endl;
				distancia = maxF;
				cout<<"KM que me quedan de gasolina "<<distancia<<endl;
				destino = false;
			}
		}//end else

	}//while
}


int main() {
	int ngas, maxD, maxF;
	bool error = true;

	cout<<"Ingrese la distancia entre punto A y punto B, al igual que la gasolina maxima ";
	cin>>maxD>>maxF;
	cout<<"Ingrese el numero de gasolinerias entre punto A y punto B: ";
	cin>>ngas;
	int gasolinerias[ngas];
	int paradas [ngas];
	for(int i = 0; i<ngas; i++){
		paradas[i] = 0;
	}

	while(error){//La primer gasolineria no puede estar mas lejos que el tanque de gasolina.
	scramble(ngas, gasolinerias, maxD);
	BucketSort(gasolinerias, ngas);

		if(gasolinerias[0]<=maxF){
		error = false;
		}	
	}

	print(ngas, gasolinerias);

	viaje(gasolinerias, paradas, maxF, ngas, maxD);
	cout<<"El camion paro en las siguientes gasolinerias:"<<endl;
	for(int i = 0; i<ngas; i++){
		if(paradas[i]!=0){
			cout<<"Gasolineria "<<paradas[i]<<endl;
		}
		
	}
	return 0;
}