/*
 * Sebastian Gonzalo Vives Faus - A01025211
 */
#include "arco.h"
#include "ui_arco.h"
#include <math.h>
#include <QVector>
#include <QPainter>
#define _USE_MATH_DEFINES

int centroX = 291.5;
int centroY = 252;
QVector<QPoint> points;

Arco::Arco(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Arco)
{
    ui->setupUi(this);
}

Arco::~Arco()
{
    delete ui;
}

void Arco::on_spinBox_valueChanged(int arg1)
{
    int n = arg1;
}

void Arco::on_pushButton_clicked()
{/*
    float x[n], y[n], pi = M_PI;
    int radio = 50;
    QPointF temp;
    for(int i = 0; i<n; i++){
      x[i] = radio * cos(2*pi*i/n) +centroX;
      y[i] = radio * sin(2*pi*i/n) +centroY;

      temp.setX(x[i]);
      temp.setY(y[i]);

      points.append(temp);
      //cout<<"X: "<<X[i]<<" Y: "<<Y[i]<<endl;
    }
    */
}

/*
void Arco::paintEvent(QPaintEvent *event){
    Qpainter painter(this);
    painter.drawConvexPolygon(points,n);

}
*/
