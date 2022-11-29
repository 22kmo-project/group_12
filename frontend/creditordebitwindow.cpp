#include "creditordebitwindow.h"
#include "ui_creditordebitwindow.h"

creditOrDebitWindow::creditOrDebitWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::creditOrDebitWindow)
{
    ui->setupUi(this);
}

creditOrDebitWindow::~creditOrDebitWindow()
{
    delete ui;
}

void creditOrDebitWindow::on_btnCredit_clicked()
{

}


void creditOrDebitWindow::on_btnDebit_clicked()
{

}

