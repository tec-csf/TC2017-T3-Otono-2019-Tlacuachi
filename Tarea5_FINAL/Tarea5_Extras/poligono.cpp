/*
 * Sebastian Gonzalo Vives Faus - A01025211
 */

#include "poligono.h"
#include "ui_poligono.h"
#include <QPolygonF>
#include <QGraphicsScene>
#include <math.h>
#include <iostream>
#include <QTransform>
#include <vector>

using namespace std;
#define _USE_MATH_DEFINES

int n; QPolygonF poly;
vector<float> X,Y;
double angle;
int counterX = 0, counterY = 0;

Poligono::Poligono(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Poligono)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
}

Poligono::~Poligono()
{
    delete ui;
}

void Poligono::on_pushButton_clicked()
{
    qDeleteAll(scene ->items());
    float x[n], y[n], pi = M_PI;
    int radio = 50;
    for(int i = 0; i<n; i++){
      x[i] = radio * cos(2*pi*i/n);
      y[i] = radio * sin(2*pi*i/n);

      X.push_back(x[i]);
      Y.push_back(y[i]);
      cout<<"X: "<<X[i]<<" Y: "<<Y[i]<<endl;
    }

    QPolygonF polyy;
    for(int i = 0; i< n; i++){
    polyy << QPointF(x[i], y[i]);
    }
    poly = polyy;
    scene->addPolygon(polyy);
    ui ->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

void Poligono::on_spinBox_valueChanged(int arg1)
{
    n = arg1;
}

void Poligono::on_doubleSpinBox_valueChanged(double arg1)
{
    angle = arg1;
}

//Trasladar X
void Poligono::on_spinBox_2_valueChanged(int arg1)
{
    TX = arg1;
    counterX = counterX + TX;
}

//Trasladar Y
void Poligono::on_spinBox_3_valueChanged(int arg1)
{
    TY = arg1;
    counterY = counterY + TY;
}

void Poligono::on_pushButton_3_clicked()
{
    //Trasladar Poligono
    //poly.translate(TX,TY);
    QPolygonF polyy;
    for(int i = 0; i< n; i++){
        X[i] = X[i] + TX;
        Y[i] = Y[i] + TY;
        polyy << QPointF(X[i], Y[i]);
    }
    poly = polyy;
    scene->addPolygon(poly);
    ui ->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

//Rotacion
void Poligono::on_pushButton_2_clicked()
{
    //QPolygonF pol = poly;
    //pol.translate(-counterX,-counterY);
    //QGraphicsItemGroup *group = scene->createItemGroup(scene->addPolygon(poly));
    QTransform t;
    t.translate(-counterX,-counterY);
    t.rotate(angle);
    t.translate(counterX,counterY);
    poly = t.map(poly);
    //polyy->setTransform(t);
    //polyy.translate(counterX,counterY);


    /*
    float anguloR = angle * M_PI / 180;
    float Xr[n], Yr[n], Xt[n], Yt[n];
    QPolygonF polyy;
    for(int i = 0; i<n; i++){
        Xt[i] = X[i] - counterX;
        Yt[i] = Y[i] - counterY;
        cout<<"X: "<<X[i]<<" Y: "<<Y[i]<<endl;
        Xr[i] = Xt[i] * cos(anguloR) - Yt[i]*sin(anguloR);
        Yr[i] = Xt[i] * sin(anguloR) + Yt[i]*cos(anguloR);
        cout<<"X: "<<Xr[i]<<" Y: "<<Yr[i]<<endl;
        X[i] = Xr[i] + counterX;
        Y[i] = Yr[i] + counterY;
        polyy << QPointF(X[i], Y[i]);
    }
    */
    scene->addPolygon(poly);
    ui ->graphicsView->setScene(scene);
    ui->graphicsView->show();
    //poly = polyy;
}
