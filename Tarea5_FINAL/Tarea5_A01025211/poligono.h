#ifndef POLIGONO_H
#define POLIGONO_H

#include "transformaciones.h"
#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class Poligono;
}

class Poligono : public QDialog
{
    Q_OBJECT

public:
    explicit Poligono(QWidget *parent = 0);
    ~Poligono();
    int n;
    double angulo;

private:
    Ui::Poligono *ui;
    bool dibuja = false;

    double xCentro;
    double yCentro;

    QVector<QTransform> vecTrans;
    Transformaciones trans;

protected:
    void paintEvent(QPaintEvent *e);
private slots:
    void on_spinBox_valueChanged(int arg1);
    void on_pushButton_clicked();
    void on_doubleSpinBox_valueChanged(double arg1);
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
};

#endif // POLIGONO_H
