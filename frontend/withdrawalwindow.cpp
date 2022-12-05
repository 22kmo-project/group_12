#include "withdrawalwindow.h"
#include "ui_withdrawalwindow.h"

withdrawalwindow::withdrawalwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::withdrawalwindow)
{
    ui->setupUi(this);
}

withdrawalwindow::~withdrawalwindow()
{
    delete ui;
}

void withdrawalwindow::on_btn20_clicked()
{

}


void withdrawalwindow::on_btn40_clicked()
{

}

void withdrawalwindow::on_btn60_clicked()
{

}

void withdrawalwindow::on_btn100_clicked()
{

}

void withdrawalwindow::on_btn200_clicked()
{

}

void withdrawalwindow::on_btn500_clicked()
{

}
void withdrawalwindow::on_btnAmountOK_clicked()
{
 // PUT PUT
}
void withdrawalwindow::on_btnCloseWithdrawal_clicked()
{
    emit closeClicked();
}
