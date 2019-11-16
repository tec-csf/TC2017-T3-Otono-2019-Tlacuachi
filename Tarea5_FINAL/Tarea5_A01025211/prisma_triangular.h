#ifndef PRISMA_TRIANGULAR_H
#define PRISMA_TRIANGULAR_H

#include "transformaciones.h"
#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class Prisma_Triangular;
}

class Prisma_Triangular : public QDialog
{
    Q_OBJECT

public:
    explicit Prisma_Triangular(QWidget *parent = 0);
    ~Prisma_Triangular();
    int n;
    double angulo;

private:
    Ui::Prisma_Triangular *ui;
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

#endif // PRISMA_TRIANGULAR_H
