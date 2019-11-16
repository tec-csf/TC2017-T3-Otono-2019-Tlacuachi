/*
 * Sebastian Gonzalo Vives Faus - A01025211
 * Partes del codigo obtenidos del autor: yocoHM, 2015: "Geometria Computacional", https://github.com/yocoHM/GeometriaComputacional.git
 */

#include "prisma_triangular.h"
#include "ui_prisma_triangular.h"
#include <math.h>

QPen pointPn(Qt::black);

Prisma_Triangular::Prisma_Triangular(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Prisma_Triangular)
{
    //this->setFixedSize(900,600);
    ui->setupUi(this);
    xCentro = 325.0;
    yCentro = 205.0;
    QTransform center;
    center.translate(xCentro,yCentro);
    vecTrans.push_back(center);
}

Prisma_Triangular::~Prisma_Triangular()
{
    delete ui;
}

void dibujarPrismaTri(QPainter & painter){

    int medida = 25;
    int medida2 = medida*2;
    int medida3 = 70;

    int x1 = 0;
    int y1 = -medida2;
    int x2 = -medida;
    int y2 = -medida3;
    int x3 = medida;
    int y3 = -medida3;
    int _x1 = 0;
    int _y1 = -medida2+medida2;
    int _x2 = -medida;
    int _y2 = -medida3+medida2;
    int _x3 = medida;
    int _y3 = -medida3+medida2;

    painter.drawLine(x1,y1,x2,y2);
    painter.drawLine(x1,y1,x3,y3);
    painter.drawLine(x2,y2,x3,y3);
    painter.drawLine(_x1,_y1,_x2,_y2);
    painter.drawLine(_x1,_y1,_x3,_y3);
    painter.drawLine(_x2,_y2,_x3,_y3);
    painter.drawLine(x1,y1,_x1,_y1);
    painter.drawLine(x2,y2,_x2,_y2);
    painter.drawLine(_x3,_y3,x3,y3);

}//cierre de dibujarPrismaTri

void Prisma_Triangular::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    //QPen pointPen(Qt::black);
    pointPn.setWidth(2);
    painter.setPen(pointPn);


    if(dibuja) {

        for(int i=0; i<vecTrans.size(); ++i) {
            painter.setTransform(vecTrans[i],true);
            dibujarPrismaTri(painter);
        }//cierre del for

    }//cierre del if que checa dibuja

}//cierre de paintEvent

void Prisma_Triangular::on_pushButton_clicked()
{
    trans.crearFig(dibuja,vecTrans,xCentro,yCentro);
    pointPn.setBrush(Qt::black);
    update();
}

void Prisma_Triangular::on_pushButton_3_clicked()
{
    QString xStr = ui->BoxX->cleanText();
    QString yStr = ui->BoxY->cleanText();

    trans.trasladar(xStr, yStr, vecTrans);
    pointPn.setBrush(Qt::red);
    update();
}

void Prisma_Triangular::on_pushButton_2_clicked()
{
    QString anguloString = ui->ValorAngulo->cleanText();
    trans.rotar(anguloString, vecTrans);
    pointPn.setBrush(Qt::green);
    update();
}

void Prisma_Triangular::on_pushButton_5_clicked()
{
    QString EscalaStr = ui->escalaBox->cleanText();
    double escala = EscalaStr.toDouble();
    trans.zoomIn(vecTrans, escala);
    pointPn.setBrush(Qt::blue);
    update();
}

void Prisma_Triangular::on_pushButton_6_clicked()
{
    trans.reflexHorizontal(vecTrans);
    pointPn.setBrush(Qt::gray);
    update();
}

void Prisma_Triangular::on_pushButton_7_clicked()
{
    trans.reflexVertical(vecTrans);
    pointPn.setBrush(Qt::gray);
    update();
}
