#ifndef ARCO_H
#define ARCO_H

#include <QDialog>
#include "arco.h"

namespace Ui {
class Arco;
}

class Arco : public QDialog
{
    Q_OBJECT

public:
    explicit Arco(QWidget *parent = 0);
    ~Arco();

protected:
    //void paintEvent(QPaintEvent *event);

private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_clicked();

private:
    Ui::Arco *ui;
};

#endif // ARCO_H
