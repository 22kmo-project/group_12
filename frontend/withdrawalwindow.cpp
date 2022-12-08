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
    ui->lbl_amount->setText("20");
}

void withdrawalwindow::withdrawal_status(QNetworkReply* reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject status = json_doc.object();

    QString text;
    qDebug() << status;
    if (status["status"] != 200) {
        text = "Virhe nodejs";
        // Virhe tapahtunut nodejs
    } else if (status["result"].toObject()["affectedRows"] == 0) {
        text = "Ei saldoa";
    } else {
        text = "Ok";
    }
    ui->lbl_withdrawal_status->setText(text);

}

void withdrawalwindow::on_btn40_clicked()
{
    ui->lbl_amount->setText("40");
}

void withdrawalwindow::on_btn60_clicked()
{
    ui->lbl_amount->setText("60");
}

void withdrawalwindow::on_btn100_clicked()
{
    ui->lbl_amount->setText("100");
}

void withdrawalwindow::on_btn200_clicked()
{
    ui->lbl_amount->setText("200");
}

void withdrawalwindow::on_btn500_clicked()
{
    ui->lbl_amount->setText("500");
}
void withdrawalwindow::on_btnAmountOK_clicked()
{
    withdrawal();
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
    QString id = this->getCardAccessSlot(reply);
    qDebug() << "tilinumero:" + id;
    reply->deleteLater();
    cardAccessManager->deleteLater();
    int amount = ui->lbl_amount->text().toInt();
    QJsonObject jsonObj;
    jsonObj.insert("account_number",id);
    jsonObj.insert("card_number",cardNumber);
    jsonObj.insert("amount", amount);

    QString site_url="http://localhost:3000/withdrawal";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    cardAccessManager = new QNetworkAccessManager(this);
    connect(cardAccessManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(withdrawal_status(QNetworkReply*)));

    cardAccessManager->post(request, QJsonDocument(jsonObj).toJson());
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
