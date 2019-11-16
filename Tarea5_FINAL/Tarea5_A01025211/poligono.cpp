/*
 * Sebastian Gonzalo Vives Faus - A01025211
 * Partes del codigo obtenidos del autor: yocoHM, 2015: "Geometria Computacional", https://github.com/yocoHM/GeometriaComputacional.git
 */
#include "poligono.h"
#include "ui_poligono.h"
#include <QMessageBox>
#include <QPainter>
#include <math.h>

QPen pointPen(Qt::black);

Poligono::Poligono(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Poligono)
{
    //this->setFixedSize(900,600);
    ui->setupUi(this);
    xCentro = 325;
    yCentro = 205;
    QTransform centro;
    centro.translate(xCentro,yCentro);
    vecTrans.push_back(centro);


}

Poligono::~Poligono()
{
    delete ui;
}

void dibujarPoligono(int lados, QPainter & painter) {

    double radio = 50;
    double angulo = (double)360.0/(double)lados;

    int xi,yi,xf,yf;
    double val = M_PI / 180;
    angulo *= val;
    int a = 0;
    painter.setPen(pointPen);

    for(a = 1; a <= lados; a++) {
        xi = (radio * cos(angulo*a));
        yi = (radio * sin(angulo*a));

        xf = (radio * cos(angulo*(a+1)));
        yf = (radio * sin(angulo*(a+1)));

        painter.drawLine(xi, yi, xf, yf);
    }//cierre del for

}//cierre de dibujarPoligono

void Poligono::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
  //QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    painter.setPen(pointPen);

    if (dibuja) {
            int lados = n;
            if(n>=3){ //Checar si el numero de lados es mayor a 3.
                for(int i=0; i<vecTrans.size(); ++i) {
                    painter.setTransform(vecTrans[i],true);
                    dibujarPoligono(lados, painter);
                }
            }

    }

}

//Obtener valor de los lados
void Poligono::on_spinBox_valueChanged(int arg1)
{
    n = arg1;
}
//Cuando se presiona el boton donde metes los lados, dibuja el poligono correspondiente.
void Poligono::on_pushButton_clicked()
{
    trans.crearFig(dibuja,vecTrans,xCentro,yCentro);
    pointPen.setBrush(Qt::black);
    update();
}

//Obtener el valor del angulo
void Poligono::on_doubleSpinBox_valueChanged(double arg1)
{
    angulo = arg1;
}

//Rotar el poligono
void Poligono::on_pushButton_2_clicked(){
    QString anguloString = ui->ValorAngulo->cleanText();
    trans.rotar(anguloString, vecTrans);
    pointPen.setBrush(Qt::green);
    update();
}

//Trasladar el poligono
void Poligono::on_pushButton_3_clicked()
{
    QString xStr = ui->BoxX->cleanText();
    QString yStr = ui->BoxY->cleanText();

    trans.trasladar(xStr, yStr, vecTrans);
    pointPen.setBrush(Qt::red);
    update();

}

//Escalar poligono positivamente
void Poligono::on_pushButton_4_clicked()
{
    QString EscalaStr = ui->escalaBox->cleanText();
    double escala = EscalaStr.toDouble();
    trans.zoomOut(vecTrans, escala);
    pointPen.setBrush(Qt::blue);
    update();
}

//Escalar poligono
void Poligono::on_pushButton_5_clicked()
{
    QString EscalaStr = ui->escalaBox->cleanText();
    double escala = EscalaStr.toDouble();
    trans.zoomIn(vecTrans, escala);
    pointPen.setBrush(Qt::blue);
    update();
}

//Reflejar poligono en base al eje X
void Poligono::on_pushButton_6_clicked()
{
    trans.reflexHorizontal(vecTrans);
    pointPen.setBrush(Qt::gray);
    update();
}

void Poligono::on_pushButton_7_clicked()
{
    trans.reflexVertical(vecTrans);
    pointPen.setBrush(Qt::gray);
    update();
}
