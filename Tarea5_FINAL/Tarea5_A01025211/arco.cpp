/*
 * Sebastian Gonzalo Vives Faus - A01025211
 * Partes del codigo obtenidos del autor: yocoHM, 2015: "Geometria Computacional", https://github.com/yocoHM/GeometriaComputacional.git
 */
#include "arco.h"
#include "ui_arco.h"
#include <QMessageBox>
#include <math.h>

#define PI 3.14159265

QPen pointPenn(Qt::black);

arco::arco(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::arco)
{
    //this->setFixedSize(900,600);
    ui->setupUi(this);
    xCentro = 325.0;
    yCentro = 205.0;
    QTransform center;
    center.translate(xCentro,yCentro);
    vecTrans.push_back(center);
}

arco::~arco()
{
    delete ui;
}

void puntosCirculo(int & x, int & y, int & angulo, QPainter & painter) {

    int oct = (angulo - (angulo % 45)) / 45;
    double limit1 = tan((90.0 - (angulo % 90)) * PI / 180.0) * x;
    double limit2 = tan((45.0 + (angulo % 45)) * PI / 180.0) * x;

    if (oct > 0 || (oct == 0 && y > limit1))
        painter.drawPoint(x,-y);
    if (oct > 1 || (oct == 1 && y <= limit2))
        painter.drawPoint(y,-x);
    if (oct > 2 || (oct == 2 && y > limit1))
        painter.drawPoint(y,x);
    if (oct > 3 || (oct == 3 && y <= limit2))
        painter.drawPoint(x,y);
    if (oct > 4 || (oct == 4 && y > limit1))
        painter.drawPoint(-x,y);
    if (oct > 5 || (oct == 5 && y <= limit2))
        painter.drawPoint(-y,x);
    if (oct > 6 || (oct == 6 && y > limit1))
        painter.drawPoint(-y,-x);
    if (oct > 7 || (oct == 7 && y <= limit2))
        painter.drawPoint(-x,-y);

}//cierre de puntosCirculo

void dibujarArco(int angulo, int radio, QPainter & painter) {

    //---Dibuja por simetría en todos los octantes---
    int x = 0;
    int y = radio;
    double p = 5.0/4.0-y;

    puntosCirculo(x, y, angulo, painter);

    while(y > x) {
        if(p < 0) {
            p += 2.0 * x + 3.0;
        }
        else {
            p += 2.0 * (x - y) + 5.0;
            y--;
        }

        x++;

        puntosCirculo(x, y, angulo, painter);

    }//cierre del while

}//cierre de diubjarArco

void arco::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    //QPen pointPen(Qt::black);
    pointPenn.setWidth(2);
    painter.setPen(pointPenn);

    if (dibuja) {

        QString radioStr = ui->spinBoxRadio->cleanText();
        QString anguloStr = ui->spinBoxAngulo->cleanText();

        int angulo = anguloStr.toInt();
        int radio = radioStr.toInt();

        if (!radioStr.isEmpty() && !anguloStr.isEmpty()) {

            for(int i=0; i<vecTrans.size(); ++i) {
                painter.setTransform(vecTrans[i],true);
                dibujarArco(angulo, radio,  painter);

            }//cierre del for

        }//cierre del if

    }//cierre del if para checar dibuja

}//cierre de paintEvent

void arco::on_pushButton_clicked()
{
    trans.crearFig(dibuja,vecTrans,xCentro,yCentro);
    pointPenn.setBrush(Qt::black);
    update();
}

void arco::on_pushButton_3_clicked()
{
    QString xStr = ui->BoxX->cleanText();
    QString yStr = ui->BoxY->cleanText();

    trans.trasladar(xStr, yStr, vecTrans);
    pointPenn.setBrush(Qt::red);
    update();
}

void arco::on_pushButton_2_clicked()
{
    QString anguloString = ui->ValorAngulo->cleanText();
    trans.rotar(anguloString, vecTrans);
    pointPenn.setBrush(Qt::green);
    update();
}

void arco::on_pushButton_5_clicked()
{
    QString EscalaStr = ui->escalaBox->cleanText();
    double escala = EscalaStr.toDouble();
    trans.zoomIn(vecTrans, escala);
    pointPenn.setBrush(Qt::blue);
    update();
}

void arco::on_pushButton_6_clicked()
{
    trans.reflexHorizontal(vecTrans);
    pointPenn.setBrush(Qt::gray);
    update();
}

void arco::on_pushButton_7_clicked()
{
    trans.reflexVertical(vecTrans);
    pointPenn.setBrush(Qt::gray);
    update();
}
