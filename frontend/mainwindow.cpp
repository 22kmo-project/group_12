#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;    
}


void MainWindow::on_btn_login_clicked()
{
    card_number = ui->text_id->text(); //otetaan käyttäjän syötteet vastaan, ja tallennetaan muuttujiin
    QString pincode = ui->text_PIN->text();

    QJsonObject jsonObj;
    jsonObj.insert("card_number", card_number);
    jsonObj.insert("pincode", pincode);

    QString site_url="http://localhost:3000/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());
}

void MainWindow::loginSlot(QNetworkReply *reply)  //tämä käsittelee vastauksen, saadaan tuo *reply
{
    response_data = reply->readAll();
    qDebug() << response_data;

    int test=QString::compare(response_data, "false");
    qDebug() << test;

    if(test==0){
        ui->text_id->clear();
        ui->text_PIN->clear();
        ui->label_infobox->setText("Ei natsannut");
        }
    else{
        objectMainMenu = new Mainmenuwindow(card_number);
        objectMainMenu->setWebToken(response_data); //käytetään setteriä ja getteriä tallentamaan webtoken ja viedään uuteen ikkunaan
        objectMainMenu->show();
    }

}

