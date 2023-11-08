/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MainWindow.cpp
 * Author: otluix
 * 
 * Created on 20 de Outubro de 2019, 17:40
 */

#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow() {
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

