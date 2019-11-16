/*
 * Sebastian Gonzalo Vives Faus - A01025211
 * Partes del codigo obtenidos del autor: yocoHM, 2015: "Geometria Computacional", https://github.com/yocoHM/GeometriaComputacional.git
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "poligono.h"
#include "arco.h"
#include "cubo.h"
#include "cono.h"
#include "prisma_triangular.h"
#include "prisma_rectangular.h"
#include "referencias.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Cuando se presiona el boton de "Poligono"
void MainWindow::on_pushButton_clicked()
{
    Poligono poligono;
    poligono.setModal(true);
    poligono.exec();
}

//Cuando se presiona el boton de "Arco"
void MainWindow::on_pushButton_2_clicked()
{
    arco arc;
    arc.setModal(true);
    arc.exec();
}

//Cuando se presiona el boton de "Cubo"

void MainWindow::on_pushButton_3_clicked()
{
    Cubo cubo;
    cubo.setModal(true);
    cubo.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    Cono cono;
    cono.setModal(true);
    cono.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    Prisma_Triangular pt;
    pt.setModal(true);
    pt.exec();
}

void MainWindow::on_pushButton_6_clicked()
{
    Prisma_Rectangular pr;
    pr.setModal(true);
    pr.exec();
}

void MainWindow::on_pushButton_7_clicked()
{
    Referencias r;
    r.setModal(true);
    r.exec();
}
