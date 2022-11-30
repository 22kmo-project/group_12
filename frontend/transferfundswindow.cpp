#include "transferfundswindow.h"
#include "ui_transferfundswindow.h"

transferfundswindow::transferfundswindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::transferfundswindow)
{
    ui->setupUi(this);
}

transferfundswindow::~transferfundswindow()
{
    delete ui;
}
void transferfundswindow::on_btnTransferOK_clicked()
{

}
void transferfundswindow::on_btnCloseTransfer_clicked()
{
    this->close();
}
