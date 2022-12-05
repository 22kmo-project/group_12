#include "mainmenuwindow.h"
#include "ui_mainmenuwindow.h"

Mainmenuwindow::Mainmenuwindow(QString card_number, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mainmenuwindow)
{
    ui->setupUi(this);
    ui->lineEdit->setText(card_number);  //tulostetaan card_number mainmenussa näkyviin
}

Mainmenuwindow::Mainmenuwindow(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Mainmenuwindow)
{
    ui->setupUi(this);
}

Mainmenuwindow::~Mainmenuwindow()
{
    delete ui;
//    delete objectWithdrawal;
//    objectWithdrawal = nullptr;
}

//const QString &Mainmenuwindow::getWebToken() const
//{

//}

void Mainmenuwindow::setWebToken(QByteArray &newWebToken)
{
    webToken = newWebToken;
}

void Mainmenuwindow::on_btnWithdrawal_clicked()
{

    emit withdrawalClicked();
}


void Mainmenuwindow::on_btnTransferFunds_clicked()
{

    emit transferFundsClicked();
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

    emit logOutClicked();

}


