/*
 * Sebastian Gonzalo Vives Faus - A01025211
 * Partes del codigo obtenidos del autor: yocoHM, 2015: "Geometria Computacional", https://github.com/yocoHM/GeometriaComputacional.git
 */
#include "transformaciones.h"

//Este archivo contiene las funciones de transformacion Rotar, Escalar, Trasladar y REflejar, tomando el vector de puntos de la figura, transformandolo y empuja el resultado al final del vector.

Transformaciones::Transformaciones()
{

}

void Transformaciones::crearFig(bool & dibuja, QVector<QTransform> & vecTrans, double & xCentro, double & yCentro)
{
    dibuja=!dibuja;
    vecTrans.clear();
    QTransform centro;
    centro.translate(xCentro,yCentro);
    vecTrans.push_back(centro);
}

void Transformaciones::trasladar(QString & xStr, QString & yStr, QVector<QTransform> & vecTrans)
{
    if(!xStr.isEmpty() && !yStr.isEmpty()) {
        double x = xStr.toDouble();
        double y = yStr.toDouble();
        QTransform translate;
        translate.translate(x, y);
        vecTrans.push_back(translate);
    }//cierre del if
}

void Transformaciones::rotar(QString & gradosStr, QVector<QTransform> & vecTrans)
{
    if(!gradosStr.isEmpty()){
        double grados = gradosStr.toDouble();
        QTransform rotate;
        rotate.rotate(grados);
        vecTrans.push_back(rotate);
    }
}

void Transformaciones::zoomOut(QVector<QTransform> & vecTrans, double & escala)
{
    QTransform zoomOut;
    zoomOut.scale(escala,escala);
    vecTrans.push_back(zoomOut);
}

void Transformaciones::zoomIn(QVector<QTransform> & vecTrans, double & escala)
{
    QTransform zoomIn;
    zoomIn.scale(escala,escala);
    vecTrans.push_back(zoomIn);
}

void Transformaciones::reflexHorizontal(QVector<QTransform> & vecTrans)
{
    QTransform zoomIn;
    zoomIn.scale(-1,1);
    vecTrans.push_back(zoomIn);
}

void Transformaciones::reflexVertical(QVector<QTransform> & vecTrans)
{
    QTransform zoomIn;
    zoomIn.scale(1,-1);
    vecTrans.push_back(zoomIn);
}
