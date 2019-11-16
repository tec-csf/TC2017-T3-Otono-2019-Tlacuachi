
/*
 * Sebastian Gonzalo Vives Faus - A01025211
 Este es el archivo de libgraph par ahacer poligonos y sus transformaciones
 */

#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#include<iostream>
#include<array>

using namespace std;
#define _USE_MATH_DEFINES

int* Reflect(float xx[], float yy[], int n){
  int* arr = new int[n*2+2];
  int lineay = 320;
  int lineax = 380;
  int dist, option;

  float x[n], y[n];
  for(int i = 0; i<n; i++){
    x[i] = xx[i];
    y[i] = yy[i];
  }

  cout<<"Reflejar en X [0] o Y[1]?";
  cin>>option;
  if(option == 0){
    for(int i = 0; i<n; i++){
      dist = abs(x[i]-lineax);
      x[i] = x[i]+dist*2;
        //cout<<"X: "<<x[i]<<endl;
    }
  }
  else{
    for(int i = 0; i<n; i++){
      dist = abs(y[i]-lineay);
      y[i] = y[i]+dist*2;
        //cout<<"X: "<<x[i]<<endl;
    }
  }

  int j = 0;
  for(int i =0; i<n*2; i = i+2){
    arr[i] = x[j];
    j++;
  }
  j=0;
  for(int i =1; i<n*2; i = i+2){
    arr[i] = y[j];
    j++;
  }

  arr[n*2] = x[0];
  arr[n*2+1] = y[0];

  return arr;

}

int* Translate(float xx[], float yy[], int n){

  float x[n], y[n];
  for(int i = 0; i<n; i++){
    x[i] = xx[i];
    y[i] = yy[i];
  }

  for(int i = 0; i< n; i++){
    x[i] = x[i] + 210;
    y[i] = y[i] - 180;
  }

  int* arr = new int[n*2+2];
  int j = 0;
  for(int i =0; i<n*2; i = i+2){
    arr[i] = x[j];
    j++;
  }
  j=0;
  for(int i =1; i<n*2; i = i+2){
    arr[i] = y[j];
    j++;
  }

  arr[n*2] = x[0];
  arr[n*2+1] = y[0];

  return arr;

}

int* Rotate(float xx[], float yy[], int n, int centrox, int centroy){

  float x[n], y[n];
  for(int i = 0; i<n; i++){
    x[i] = xx[i];
    y[i] = yy[i];
  }

  //Vamos a rotar la figura en un angulo de 90 grados
  cout<<"Ingresar el angulo de rotacion:";
  int r;
  cin>>r;
  float angle = r * M_PI / 180;
  cout<<"Angle: "<<angle<<endl;

  //Guardadmos la rotacion en un nuevo arreglo.
  float xr[n], yr[n];
  for(int i=0; i<n; i++){
    xr[i] = cos(angle)*(x[i]-centrox) - sin(angle)*(y[i]-centroy) + centrox;
    yr[i] = sin(angle)*(x[i]-centrox) + cos(angle)*(y[i]-centroy) + centroy;

    xr[i] = xr[i] - 200;
    yr[i] = yr[i] + 100;
  }

  int* arr = new int[n*2+2];
  int j = 0;
  for(int i =0; i<n*2; i = i+2){
    arr[i] = xr[j];
    j++;
  }
  j=0;
  for(int i =1; i<n*2; i = i+2){
    arr[i] = yr[j];
    j++;
  }

  arr[n*2] = xr[0];
  arr[n*2+1] = yr[0];

  return arr;

}

int* Scale(float xx[], float yy[], int n){
  float x[n], y[n];
  float r;
  cout<<"Ingrese el zoom de escala para la figura: ";
  cin>>r;
  for(int i = 0; i<n; i++){
    x[i] = xx[i] - 200;
    y[i] = yy[i] - 130;

    x[i] = x[i] * r;
    y[i] = y[i] * r;
  }

  int* arr = new int[n*2+2];
  int j = 0;
  for(int i =0; i<n*2; i = i+2){
    arr[i] = x[j];
    j++;
  }
  j=0;
  for(int i =1; i<n*2; i = i+2){
    arr[i] = y[j];
    j++;
  }

  arr[n*2] = x[0];
  arr[n*2+1] = y[0];

  return arr;
}


//driver code
int main()
{
  int n;
  cout<<("Numero de lados del poligono: ");
  cin>>n;

  int centrox = 300, centroy = 250, radio = 50;
  float x[n];
  float y[n];
  float pi = M_PI;

  cout<<pi<<endl;

  for(int i = 0; i<n; i++){
    x[i] = radio * cos(2*pi*i/n) + centrox;
    y[i] = radio * sin(2*pi*i/n) + centroy;
    cout<<"X: "<<x[i]<<" Y: "<<y[i]<<endl;
  }

  int arr[n*2+2];
  int j = 0;
  for(int i =0; i<n*2; i = i+2){
    arr[i] = x[j];
    j++;
  }
  j=0;
  for(int i =1; i<n*2; i = i+2){
    arr[i] = y[j];
    j++;
  }

  arr[n*2] = x[0];
  arr[n*2+1] = y[0];

  int gd = DETECT, gm;
  initgraph(&gd, &gm, "");
  //initGraphics(500,500);

  drawpoly(n+1,arr);
  drawpoly(n+1,Reflect(x,y,n));
  drawpoly(n+1, Translate(x,y,n));
  drawpoly(n+1,Rotate(x,y,n, centrox, centroy));
  drawpoly(n+1, Scale(x,y,n));
  //line(400,100,400,300);

  int maxX = getmaxx();
  int maxY = getmaxy();

  cout<<"Max X and Y are: "<<maxX<<" "<<maxY<<endl;

  getch();

  closegraph();
  return 0;
}
