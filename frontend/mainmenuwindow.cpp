#include "mainmenuwindow.h"
#include "ui_mainmenuwindow.h"

Mainmenuwindow::Mainmenuwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mainmenuwindow)
{
    ui->setupUi(this);
    ui->label->setText("Choose your action:");
}


Mainmenuwindow::~Mainmenuwindow()
{
    delete ui;    
}


void Mainmenuwindow::setWebToken(QByteArray &newWebToken)
{
    webToken = newWebToken;
}


QByteArray Mainmenuwindow::getWebToken()
{
    return webToken;
}


void Mainmenuwindow::on_btnWithdrawal_clicked()
{
    ui->text_infobox->clear();
    emit withdrawalClicked();
}


void Mainmenuwindow::on_btnTransferFunds_clicked()
{
    emit transferFundsClicked();
    ui->btnTransferFunds->setEnabled(false);
    ui->text_infobox->clear();
}


void Mainmenuwindow::on_btnCheckBalance_clicked()
{
    //Näytetään saldo tekstiboksissa
}


void Mainmenuwindow::on_btnTransactions_clicked()  //Täällä haetaan tilitapahtumat, vastaus getTransactionsSlottiin
{    
    qDebug() << accountID;
    QString site_url="http://localhost:3000/tentransactions/" +accountID;
    QNetworkRequest request((site_url));

    transactionsManager = new QNetworkAccessManager(this);

    connect(transactionsManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getTransactionsSlot(QNetworkReply*)));

    reply = transactionsManager->get(request);
}


void Mainmenuwindow::on_btnLogOut_clicked()
{
    ui->text_infobox->clear();
    emit logOutClicked();
}


void Mainmenuwindow::getTransactionsSlot(QNetworkReply *reply) //Tänne tilitapahtumien vastaus
{
    QByteArray response_data=reply->readAll();

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString transactions;
    foreach (const QJsonValue &value, json_array) {
            QJsonObject json_obj = value.toObject();
            transactions+=json_obj["Description"].toString()+",  "+QString::number(json_obj["Account number"].toInt())
            +",  "+QString::number(json_obj["Amount"].toInt())+",  "+(json_obj["Date"].toString())+"\r";
        }

    ui->text_infobox->setText(transactions);
    reply->deleteLater();
    transactionsManager->deleteLater();
}

void Mainmenuwindow::cardAndAccountSlot(QString accId, QString cardId)
{
    accountID = accId;
    cardID = cardId;
}


