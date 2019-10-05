/*
    Sebastian Gonzalo Vives Faus | A01025211
    Tarea 3| Algoritmo Avido

Dada una secuencia de palabras p1, p2, ..., pn de longitudes l1, l2, ..., ln se desea agruparlas en líneas de longitud L. 
Las palabras están separadas por espacios cuya amplitud ideal (en milímetros) es b, pero los espacios pueden reducirse o 
ampliarse si es necesario (aunque sin solapamiento de palabras), de tal forma que una línea pi, pi+1, ..., pj tenga exactamente longitud L. 
Sin embargo, existe una penalización por reducción o ampliación en el número total de espacios que aparecen o desaparecen. El costo de fijar la 
línea pi, pi+1, ..., pj es (j – i)|b’ – b|, siendo b’ el ancho real de los espacios, es decir (L – li – li+1 – ... – lj)/(j – i). No obstante, si j = n 
(la última palabra) el costo será cero a menos que b’ < b (ya que no es necesario ampliar la última línea).

Diseñe un algoritmo para resolver el problema.
Con la ayuda del libro http://www.lcc.uma.es/~av/Libro/CAP4.pdf Cap4
La complejidad del algoritmo es de O(n).

*/
#include <iostream>
#include <stdlib.h>
#include <time.h>

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
    cout<<"(";
	for(int i = 0; i<n; i++){
        if(i<n-1){
		    cout<<arr[i]<<" , ";
        }
        else{
            cout<<arr[i];
        }
	}
    cout<<")"<<endl;
}


float calcularCosto(int L, int b, int tpalabras, int nlfalta){
    float bprima = (L - tpalabras)/nlfalta;//Calcular el valor de b'
    //cout<<"L("<<L<<") - tpalabras("<<tpalabras<<") / nlfalta("<<nlfalta<<")"<<endl;
    //cout<<"Valor de b' = "<<bprima<<endl;
    if(bprima>b){
        return (nlfalta)*(bprima-b);
    }//end if
    else{
        return (nlfalta)*(b-bprima);
    }
}

int Parrafo(int L, int* palabras, int npalabras, int b){//Devuelve el numero de lineas que necesito.

    int nlllevo=0, nlfalta=L; //Tamano de la linea que llevo y el tamano que me falta.
    int tpalabras=0; // Tama;o de palabras que llevo
    int sol=1;//Contador de lineas que llevamos.
    int pcurso=0; //Numero de la palabra en curso;

    //Peor caso
    if(L <=0 || npalabras<=0){
        cout<<"No hay palabras o la longitud de linea es 0."<<endl;
        return 0;
    }
    else{

        while(pcurso<npalabras){//Mientras que haya palabras...

            if((nlllevo+palabras[pcurso]+b)<=L){//Si la palabra cabe sin problemas, con todo y b
                cout<<"Cupo sin problemas "<<nlllevo<<"+"<<palabras[pcurso]<<"+"<<b<<" <= "<<L<<endl;
                nlllevo = nlllevo+ palabras[pcurso]+b;
                tpalabras = tpalabras+palabras[pcurso];
                nlfalta = abs(nlllevo - L);
                cout<<"La palabra de tamano "<<palabras[pcurso]<<" cupo sin problemas en la linea "<<sol<<endl;
            }//end if
            
            else{//No cabe de forma optima, pero aun puede caber
                if((tpalabras+palabras[pcurso])>L){//No cabe de ninguna forma en la linea actual, incluso sin los espacios entre palabras.
                    cout<<"La palabra de tamano "<<palabras[pcurso]<<" no cabe de ninguna forma en la linea "<<sol<<", por lo que se movera a una nueva linea."<<endl;
                    cout<<"No cupo de ninguna forma "<<tpalabras<<"+"<<palabras[pcurso]<<" > "<<L<<endl;
                    //Nueva Linea
                    nlllevo = 0; 
                    tpalabras = 0; 
                    sol = sol+1; 
                    nlfalta = L;
                    //Lo meto a la nueva linea
                    cout<<"La palabra de tamano "<<palabras[pcurso]<<" fue agregado a la nueva linea "<<sol<<endl;
                    tpalabras = tpalabras+palabras[pcurso];
                    nlllevo= nlllevo+ palabras[pcurso];
                    nlfalta = abs(nlllevo - L);
                }//endif2

                else{//La palabra puede caber, pero hay que tomar una decision basandonos en el costo.
                    if(calcularCosto(L,b,tpalabras,nlfalta)>=calcularCosto(L,b,tpalabras+palabras[pcurso],nlfalta+1)){
                        tpalabras = tpalabras+palabras[pcurso];
                        nlllevo= nlllevo+ palabras[pcurso];
                        nlfalta = abs(nlllevo - L);
                        cout<<"La palabra de tamano "<<palabras[pcurso]<<" cupo obteniendo en la linea "<<sol<<" por el costo "<<calcularCosto(L,b,tpalabras,nlfalta)<<" >= "<<calcularCosto(L,b,tpalabras+palabras[pcurso],nlfalta+1)<<endl;
                    }

                    else{//No cupo por el costo, lo pasamos a la siguiente linea.
                        cout<<"La palabra de tamano "<<palabras[pcurso]<<" no cupo en la linea "<<sol<<" por el costo "<<calcularCosto(L,b,tpalabras,nlfalta)<<"  NO ES >= "<<calcularCosto(L,b,tpalabras+palabras[pcurso],nlfalta+1)<<endl;
                        //Nueva Linea
                        nlllevo = 0; 
                        tpalabras = 0; 
                        sol = sol+1; 
                        nlfalta = L;
                        //Lo meto a la nueva linea
                        cout<<"La palabra de tamano "<<palabras[pcurso]<<" fue agregado a la nueva linea "<<sol<<endl;
                        tpalabras = tpalabras+palabras[pcurso];
                        nlllevo= nlllevo+ palabras[pcurso];
                        nlfalta = abs(nlllevo - L);
                    }
                }

            }//end else

            pcurso++;//Nos movemos a la siguiente palabra.


        }//end while

    }//end if

    return sol;

}

int main(){

    int Longitud, npalabras, b;

    cout<<"Inserte la Longitud maxima de cada linea, el numero de palabras y el espacio maximo (mm) entre las palabras: "<<endl;
    cin>>Longitud>>npalabras>>b;

    int palabras[npalabras];
    scramble(npalabras, palabras, Longitud);
    print(npalabras, palabras);
    int sol = Parrafo(Longitud, palabras, npalabras, b);
    cout<<"Se utilizaron: "<<sol<<" lineas"<<endl;




}