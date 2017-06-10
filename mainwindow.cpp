#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->clearButton, SIGNAL(clicked(bool)), this, SLOT(clearButtonPressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setArea(Area *area)
{
    this->area = area;
}

void MainWindow::clearButtonPressed()
{
    area->clear();
}
