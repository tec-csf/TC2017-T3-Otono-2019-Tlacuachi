/*
 * Sebastian Gonzalo Vives Faus - A01025211
 * Partes del codigo obtenidos del autor: yocoHM, 2015: "Geometria Computacional", https://github.com/yocoHM/GeometriaComputacional.git
 */
#include "prisma_rectangular.h"
#include "ui_prisma_rectangular.h"
#include <math.h>

QPen pointP(Qt::black);

Prisma_Rectangular::Prisma_Rectangular(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Prisma_Rectangular)
{
    //this->setFixedSize(900,600);
    ui->setupUi(this);
    xCentro = 325.0;
    yCentro = 205.0;
    QTransform center;
    center.translate(xCentro,yCentro);
    vecTrans.push_back(center);
}

Prisma_Rectangular::~Prisma_Rectangular()
{
    delete ui;
}

void dibujaPrismaRec(QPainter & painter){

    int medida = 50;
    int medida2 = 100;
    int medida3 = 30;

    int x0 = 0;
    int y0 = medida;
    int x1 = medida;
    int y1 = medida;
    int x2 = 0;
    int y2 = -medida2;
    int x3 = medida;
    int y3 = -medida2;

    //Cuadrado 3
    int x4 = x0 + medida3;
    int y4 = y0 - medida;
    int x5 = x1 + medida3;
    int y5 = y1 - medida;
    int x6 = x2 + medida3;
    int y6 = y2 - medida;
    int x7 = x3 + medida3;
    int y7 = y3 - medida;

    painter.drawLine(x0,y0,x1,y1);
    painter.drawLine(x2,y2,x3,y3);
    painter.drawLine(x2,y2,x0,y0);
    painter.drawLine(x3,y3,x1,y1);

    painter.drawLine(x4,y4,x5,y5);
    painter.drawLine(x6,y6,x7,y7);
    painter.drawLine(x6,y6,x4,y4);
    painter.drawLine(x7,y7,x5,y5);

    painter.drawLine(x0,y0,x4,y4);
    painter.drawLine(x1,y1,x5,y5);
    painter.drawLine(x2,y2,x6,y6);
    painter.drawLine(x3,y3,x7,y7);

}//cierre de dibujarPrisma

void Prisma_Rectangular::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    //QPen pointPen(Qt::black);
    pointP.setWidth(2);
    painter.setPen(pointP);

    if(dibuja) {

        for(int i=0; i<vecTrans.size(); ++i) {
            painter.setTransform(vecTrans[i],true);
            dibujaPrismaRec(painter);
        }//cierre del for

    }//cierre del if que checa  dibuja

}//cierre de paintEvent

void Prisma_Rectangular::on_pushButton_clicked()
{
    trans.crearFig(dibuja,vecTrans,xCentro,yCentro);
    pointP.setBrush(Qt::black);
    update();
}

void Prisma_Rectangular::on_pushButton_3_clicked()
{
    QString xStr = ui->BoxX->cleanText();
    QString yStr = ui->BoxY->cleanText();

    trans.trasladar(xStr, yStr, vecTrans);
    pointP.setBrush(Qt::red);
    update();
}

void Prisma_Rectangular::on_pushButton_2_clicked()
{
    QString anguloString = ui->ValorAngulo->cleanText();
    trans.rotar(anguloString, vecTrans);
    pointP.setBrush(Qt::green);
    update();
}

void Prisma_Rectangular::on_pushButton_5_clicked()
{
    QString EscalaStr = ui->escalaBox->cleanText();
    double escala = EscalaStr.toDouble();
    trans.zoomIn(vecTrans, escala);
    pointP.setBrush(Qt::blue);
    update();
}

void Prisma_Rectangular::on_pushButton_6_clicked()
{
    trans.reflexHorizontal(vecTrans);
    pointP.setBrush(Qt::gray);
    update();
}

void Prisma_Rectangular::on_pushButton_7_clicked()
{
    trans.reflexVertical(vecTrans);
    pointP.setBrush(Qt::gray);
    update();
}
