#include "mainmenuwindow.h"
#include "ui_mainmenuwindow.h"

Mainmenuwindow::Mainmenuwindow(QString card_number,  QWidget *parent) :
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

    emit withdrawalClicked();

}


void Mainmenuwindow::on_btnTransferFunds_clicked()
{

    emit transferFundsClicked();
    ui->btnTransferFunds->setEnabled(false);
}


void Mainmenuwindow::on_btnCheckBalance_clicked()
{

    //Näytetään saldo tekstiboksissa
}


void Mainmenuwindow::on_btnTransactions_clicked()  //Täällä haetaan tilitapahtumat
{    
    qDebug() << accountID; //täälläpä korttinumero
    QString site_url="http://localhost:3000/tentransactions/" +accountID;
    QNetworkRequest request((site_url));

    transactionsManager = new QNetworkAccessManager(this);

    connect(transactionsManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getTransactions(QNetworkReply*)));

    reply = transactionsManager->get(request);

}


void Mainmenuwindow::on_btnLogOut_clicked()
{

    emit logOutClicked();

}

void Mainmenuwindow::getTransactions(QNetworkReply *reply) //Tänne tilitapahtumien vastaus
{
    QByteArray response_data=reply->readAll();
    qDebug()<<"Last ten transactions : "+response_data;

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString transactions;
    foreach (const QJsonValue &value, json_array) {
            QJsonObject json_obj = value.toObject();
            transactions+=json_obj["Description"].toString()+","+QString::number(json_obj["Account number"].toInt())+","+QString::number(json_obj["amount"].toInt())+","+(json_obj["Date"].toString())+"\r";
        }

    qDebug()<<transactions;

    ui->text_infobox->setText(transactions);

    reply->deleteLater();
    transactionsManager->deleteLater();
}

void Mainmenuwindow::tilinumero(QString id)
{
    accountID = id;
}


