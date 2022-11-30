#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;    
}


void MainWindow::on_btn_login_clicked()
{
    objectMainMenu = new Mainmenuwindow;
    objectMainMenu->show();
    //tänne valinta avataanko main menu-ikkuna vai credit/debit-ikkuna
}

