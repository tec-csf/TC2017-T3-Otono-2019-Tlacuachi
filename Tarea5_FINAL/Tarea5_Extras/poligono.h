#ifndef POLIGONO_H
#define POLIGONO_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

namespace Ui {
class Poligono;
}

class Poligono : public QDialog
{
    Q_OBJECT

public:
    explicit Poligono(QWidget *parent = 0);
    ~Poligono();
    int TX = 0, TY = 0;

protected:
    //void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Poligono *ui;
    QGraphicsScene *scene;
};

#endif // POLIGONO_H
