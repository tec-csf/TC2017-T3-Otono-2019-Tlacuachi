#ifndef PRISMA_RECTANGULAR_H
#define PRISMA_RECTANGULAR_H

#include "transformaciones.h"
#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class Prisma_Rectangular;
}

class Prisma_Rectangular : public QDialog
{
    Q_OBJECT

public:
    explicit Prisma_Rectangular(QWidget *parent = 0);
    ~Prisma_Rectangular();

private:
    Ui::Prisma_Rectangular *ui;
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

#endif // PRISMA_RECTANGULAR_H
