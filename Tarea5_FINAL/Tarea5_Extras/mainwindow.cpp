/*
 * Sebastian Gonzalo Vives Faus - A01025211
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "poligono.h"
#include "arco.h"

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

void MainWindow::on_pushButton_clicked()
{
    Poligono poligono;
    poligono.setModal(true);
    poligono.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    Arco arco;
    arco.setModal(true);
    arco.exec();
}
