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

void withdrawalwindow::withdrawal_status(QNetworkReply* reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject status = json_doc.object();

    QString text;
    qDebug() << status;

    if (status["status"] != 200) {
        ui->lbl_withdrawal_status->setText("<font color='red'>Error</font>");
    }
    else if (status["result"].toObject()["affectedRows"] == 0) {
        ui->lbl_withdrawal_status->setText("<font color='red'>Insufficient funds</font>");
    }
    else {
        ui->lbl_withdrawal_status->setText("<font color='green'>Withdrawal executed successfully</font>");
        }
    //ui->lbl_withdrawal_status->setText("<font color='red'>'text'</font>");
    //ui->lbl_withdrawal_status->setText(text);

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
    QString site_url="http://localhost:3000/card_access/"+cardNumber;
    QNetworkRequest request((site_url));
    qDebug() << "Number of the card in use is: "+ cardNumber;

    cardAccessManager = new QNetworkAccessManager(this);
    connect(cardAccessManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getWithdrawal(QNetworkReply*)));
    reply = cardAccessManager->get(request);
}


void withdrawalwindow::getWithdrawal(QNetworkReply *reply) {

    QString id = this->getCardAccessSlot(reply);

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
    account_number=reply->readAll();        //Haetaan korttiin liitetyn tilin numero
    QJsonDocument json_doc = QJsonDocument::fromJson(account_number);
        QJsonObject json_obj = json_doc.object();
        QString tili;
        tili=QString::number(json_obj["account_number"].toInt());

        qDebug()<<"This card has access to account: " +tili;

        return tili;
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

