#ifndef ARCO_H
#define ARCO_H

#include "transformaciones.h"
#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class arco;
}

class arco : public QDialog
{
    Q_OBJECT

public:
    explicit arco(QWidget *parent = 0);
    ~arco();
    int n;
    double angulo;

private:
    Ui::arco *ui;
    bool dibuja = false;

    double xCentro;
    double yCentro;

    QVector<QTransform> vecTrans;
    Transformaciones trans;


protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
};

#endif // ARCO_H
