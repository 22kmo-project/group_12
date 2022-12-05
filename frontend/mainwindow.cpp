#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qstackedwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Widgettien lisäys
    ui->stackedWidget->insertWidget(1, &objectMainMenu);
    ui->stackedWidget->insertWidget(2, &objectTransferMenu);
    ui->stackedWidget->insertWidget(3, &objectWithdrawMenu);
//    ui->stackedWidget->insertWidget(4, &objectCreditDebitMenu);

    // Navigaationappien signaalit
    connect(&objectMainMenu, SIGNAL(logOutClicked()), this, SLOT(logOut()));
    connect(&objectMainMenu, SIGNAL(withdrawalClicked()), this, SLOT(moveToWithdrawal()));
    connect(&objectMainMenu, SIGNAL(transferFundsClicked()), this, SLOT(moveToTransferFunds()));
    connect(&objectWithdrawMenu, SIGNAL(closeClicked()), this, SLOT(moveToMenu()));
    connect(&objectTransferMenu, SIGNAL(closeClicked()), this, SLOT(moveToMenu()));


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
    connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());
}

void MainWindow::loginSlot(QNetworkReply *reply)  //tämä käsittelee vastauksen, saadaan tuo *reply
{

    response_data = reply->readAll();
    qDebug() << response_data;

    int test=QString::compare(response_data, "false");
    qDebug() << test;

    if(response_data.length()==0){
        ui->label_infobox->setText("Palvelin ei vastaa");
    }
    else{
        if(test==0){
            clearFields();
            ui->label_infobox->setText("Tunnus ja salasana eivät täsmää");
            }
        else{
            //objectMainMenu = new Mainmenuwindow(card_number);
            objectMainMenu.setWebToken(response_data);
            //objectMainMenu.show();
            moveToMenu();
        }
        clearFields();
    }



}

void MainWindow::logOut()
{
    // Login screeniin siirtyminen
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::moveToMenu()
{
    // Päänäkymään/menuun siirtyminen
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::moveToWithdrawal()
{
    // Withdrawal-ikkunaan siirtyminen
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::moveToTransferFunds()
{
    // transferfunds näkymään siirtyminen
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::clearFields()
{
    // Käyttäjä ja salasana kentän tyhjennys
    ui->text_id->clear();
    ui->text_PIN->clear();
}

