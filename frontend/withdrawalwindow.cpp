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
    withdrawal();
    ui->lineEdit->setText("20");
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



void withdrawalwindow::withdrawal()
{
    //qDebug()<< "numero on: "+cardNumber;
    QString site_url="http://localhost:3000/card_access/"+cardNumber;
    QNetworkRequest request((site_url));
    qDebug() << "Kortin numero on"+ cardNumber;

    cardAccessManager = new QNetworkAccessManager(this);

    connect(cardAccessManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getWithdrawal(QNetworkReply*)));

    reply = cardAccessManager->get(request);
    //tänne toiminto joka hakee card_numberin perusteella accessin, tallennetaan muuttujaan ja sitten nostetaan annettu
    //summa tililtä johon kortti liitettynnä
}


void withdrawalwindow::getWithdrawal(QNetworkReply *reply) {
    qDebug() << "Hello world";
    QString id = this->getCardAccessSlot(reply);
    qDebug() << "tilinumero:" + id;
    qDebug() << "HERE ******";
    reply->deleteLater();
    cardAccessManager->deleteLater();
}

QString withdrawalwindow::getCardAccessSlot(QNetworkReply *reply)
{
    account_number=reply->readAll();
    qDebug() << "Tilin numero on:"+account_number;
    QJsonDocument json_doc = QJsonDocument::fromJson(account_number);
        QJsonObject json_obj = json_doc.object();
        QString tili;
        tili=QString::number(json_obj["account_number"].toInt());

        qDebug()<<"Tälle tilille on pääsy:" +tili;

        return tili;
}


void withdrawalwindow::on_btnCloseWithdrawal_clicked()
{
    emit closeClicked();
}
