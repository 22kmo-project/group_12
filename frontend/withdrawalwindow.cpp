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
    emit buttonPressed();
}

void withdrawalwindow::on_btn40_clicked()
{
    ui->lbl_amount->setText("40");
    emit buttonPressed();
}

void withdrawalwindow::on_btn60_clicked()
{
    ui->lbl_amount->setText("60");
    emit buttonPressed();
}

void withdrawalwindow::on_btn100_clicked()
{
    ui->lbl_amount->setText("100");
    emit buttonPressed();
}

void withdrawalwindow::on_btn200_clicked()
{
    ui->lbl_amount->setText("200");
    emit buttonPressed();
}

void withdrawalwindow::on_btn500_clicked()
{
    ui->lbl_amount->setText("500");
    emit buttonPressed();
}
void withdrawalwindow::on_btnAmountOK_clicked()
{
    ui->lbl_withdrawal_status->clear();
    withdrawal();
    emit buttonPressed();
}


void withdrawalwindow::withdrawal()
{
    QString site_url="http://localhost:3000/card_access/"+cardNumber;  //haetaan korttiin liitetyn tilin numero
    QNetworkRequest request((site_url));
    qDebug() << "Number of the card in use is: "+ cardNumber;

    cardAccessManager = new QNetworkAccessManager(this);
    connect(cardAccessManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getWithdrawalSlot(QNetworkReply*)));
    reply = cardAccessManager->get(request);
}


void withdrawalwindow::getWithdrawalSlot(QNetworkReply *reply) {  //tehdään nosto, HTTP POST, ja proseduuri tekee tietokantaan tilitapahtuman taustalla

    QString id = this->getCardAccess(reply);  //tallennetaan korttiin liitetyn tilin numero muuttujaan

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


void withdrawalwindow::withdrawal_status(QNetworkReply* reply)  //vastauksen perusteella annetaan käyttäjälle virheilmoitukset
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject status = json_doc.object();
    qDebug() << status;   //tulostetaan POST-pyynnön vastauksen data
    QString text;

    if (status["status"] != 200) {
        ui->lbl_withdrawal_status->setText("<font color='red'>No response from server</font>");
    }
    else if (status["result"].toObject()["affectedRows"] == 0) {
        ui->lbl_withdrawal_status->setText("<font color='red'>Insufficient funds</font>");
    }
    else {
        ui->lbl_withdrawal_status->setText("<font color='green'>Withdrawal executed successfully</font>");
        }
}


QString withdrawalwindow::getCardAccess(QNetworkReply *reply) //tällä funktiolla palautetaan tilinumero getWithdrawalSlottiin
{
    QByteArray response=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response);
    QJsonObject json_obj = json_doc.object();
    account_number=QString::number(json_obj["account_number"].toInt());
    qDebug()<<"This card has access to account: " +account_number;
    return account_number;
}


void withdrawalwindow::on_btnCloseWithdrawal_clicked()
{
    emit closeClicked();
    emit buttonPressed();
}

void withdrawalwindow::on_lbl_amount_textEdited(const QString &arg1)
{
    emit buttonPressed();
}

