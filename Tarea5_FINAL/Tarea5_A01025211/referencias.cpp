/*
 * Sebastian Gonzalo Vives Faus - A01025211
 * Partes del codigo obtenidos del autor: yocoHM, 2015: "Geometria Computacional", https://github.com/yocoHM/GeometriaComputacional.git
 */
#include "referencias.h"
#include "ui_referencias.h"

Referencias::Referencias(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Referencias)
{
    ui->setupUi(this);
}

Referencias::~Referencias()
{
    delete ui;
}
