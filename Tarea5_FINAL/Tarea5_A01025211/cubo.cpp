/*
 * Sebastian Gonzalo Vives Faus - A01025211
 * Partes del codigo obtenidos del autor: yocoHM, 2015: "Geometria Computacional", https://github.com/yocoHM/GeometriaComputacional.git
 */
#include "cubo.h"
#include "ui_cubo.h"
#include <math.h>

QPen pointPeen(Qt::black);

Cubo::Cubo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cubo)
{
    //this->setFixedSize(900,600);
    ui->setupUi(this);
    xCentro = 325.0;
    yCentro = 205.0;
    QTransform center;
    center.translate(xCentro,yCentro);
    vecTrans.push_back(center);
}

Cubo::~Cubo()
{
    delete ui;
}

void dibujaCubo(QPainter &painter){
    int medida = 30; //La medida o el volumen (radio) del cubo.

    //Obtenemos las "Coordenadas" del cuadrado de enfrente.
    int x1 = -medida;
    int y1 = medida;
    int x2 = medida;
    int y2 = medida;
    int x3 = -medida;
    int y3 = -medida;
    int x4 = medida;
    int y4 = -medida;

    int distancia = (x2-x1)/2; //Obtenemos la mitad de la linea superior del primer cuadrado, la cual nos ayudara a dibujar el cuadrado de detras.

    //Obtenemos las "Coordenadas" basandonos en la mitad del primer cuadrado para obtener el de atras.
    int _x1 = x1 + distancia;
    int _y1 = y1 - distancia;
    int _x2 = x2 + distancia;
    int _y2 = y2 - distancia;
    int _x3 = x3 + distancia;
    int _y3 = y3 - distancia;
    int _x4 = x4 + distancia;
    int _y4 = y4 - distancia;

    //Cuadrado de enfrente
    painter.drawLine(x1, y1, x2, y2);
    painter.drawLine(x1, y1, x3, y3);
    painter.drawLine(x2, y2, x4, y4);
    painter.drawLine(x3, y3, x4, y4);
    //Cuadrado de atras
    painter.drawLine(_x1, _y1, _x2, _y2);
    painter.drawLine(_x1, _y1, _x3, _y3);
    painter.drawLine(_x2, _y2, _x4, _y4);
    painter.drawLine(_x3, _y3, _x4, _y4);

    //Lineas que interconectan cada esquina de ambos cuadrados para dibujar el cubo.
    painter.drawLine(x1, y1, _x1, _y1);
    painter.drawLine(x2, y2, _x2, _y2);
    painter.drawLine(x3, y3, _x3, _y3);
    painter.drawLine(x4, y4, _x4, _y4);

}//Cierre de dibujaCubo

void Cubo::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    //QPen pointPen(Qt::black);
    pointPeen.setWidth(2);
    painter.setPen(pointPeen);

    if (dibuja) {

        for(int i=0; i<vecTrans.size(); ++i) {
            painter.setTransform(vecTrans[i],true);
            dibujaCubo(painter);

        }//Cierre del for

    }//Cierre del if que checa dibuja

}//cierre de paintEvent


void Cubo::on_pushButton_clicked()
{
    trans.crearFig(dibuja,vecTrans,xCentro,yCentro);
    pointPeen.setBrush(Qt::black);
    update();
}

void Cubo::on_pushButton_3_clicked()
{
    QString xStr = ui->BoxX->cleanText();
    QString yStr = ui->BoxY->cleanText();

    trans.trasladar(xStr, yStr, vecTrans);
    pointPeen.setBrush(Qt::red);
    update();
}

void Cubo::on_pushButton_2_clicked()
{
    QString anguloString = ui->ValorAngulo->cleanText();
    trans.rotar(anguloString, vecTrans);
    pointPeen.setBrush(Qt::green);
    update();
}

void Cubo::on_pushButton_5_clicked()
{
    QString EscalaStr = ui->escalaBox->cleanText();
    double escala = EscalaStr.toDouble();
    trans.zoomIn(vecTrans, escala);
    pointPeen.setBrush(Qt::blue);
    update();
}

void Cubo::on_pushButton_6_clicked()
{
    trans.reflexHorizontal(vecTrans);
    pointPeen.setBrush(Qt::gray);
    update();
}

void Cubo::on_pushButton_7_clicked()
{
    trans.reflexVertical(vecTrans);
    pointPeen.setBrush(Qt::gray);
    update();
}
