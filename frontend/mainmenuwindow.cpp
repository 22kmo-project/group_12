#include "mainmenuwindow.h"
#include "ui_mainmenuwindow.h"

Mainmenuwindow::Mainmenuwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mainmenuwindow)
{
    ui->setupUi(this);
}

Mainmenuwindow::~Mainmenuwindow()
{
    delete ui;
    delete objectWithdrawal;
    objectWithdrawal = nullptr;
}

void Mainmenuwindow::on_btnWithdrawal_clicked()
{
    objectWithdrawal = new withdrawalwindow;
    objectWithdrawal->show();
}


void Mainmenuwindow::on_btnTransferFunds_clicked()
{
    objectTransferFunds = new transferfundswindow;
    objectTransferFunds->show();
}


void Mainmenuwindow::on_btnCheckBalance_clicked()
{
    //Näytetään saldo tekstiboksissa
}


void Mainmenuwindow::on_btnTransactions_clicked()
{
    //tilin omistajan tiedot, 10 viimeistä tilitapahtumaa
}


void Mainmenuwindow::on_btnLogOut_clicked()
{
    this->close();
}

