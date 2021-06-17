/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MainWindow.h
 * Author: otluix
 *
 * Created on 20 de Outubro de 2019, 17:40
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();
    //MainWindow(const MainWindow& orig);
    explicit MainWindow(QWidget *parent = 0);   
    virtual ~MainWindow();
    
private:
    Ui::MainWindow *ui;

};

#endif /* MAINWINDOW_H */

