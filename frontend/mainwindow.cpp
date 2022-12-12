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


    // Ajastimet
    timer1 = new QTimer(this);

    connect(timer1, SIGNAL(timeout()), this, SLOT(timerTriggered()));
    // Ajastimen resetointi kun jotain nappia painetaan
    connect(&objectWithdrawMenu, SIGNAL(buttonPressed()), this, SLOT(timerReset()));
    connect(&objectTransferMenu, SIGNAL(buttonPressed()), this, SLOT(timerReset()));

    connect(this, SIGNAL(cardAndAccount(QString,QString)), &objectMainMenu, SLOT(cardAndAccountSlot(QString, QString)));

}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_btn_login_clicked()
{
    ui->label_infobox->clear();
    card_number = ui->text_id->text(); //otetaan käyttäjän syötteet vastaan, ja tallennetaan muuttujiin
    QString pincode = ui->text_PIN->text();

    QJsonObject jsonObj;
    jsonObj.insert("card_number", card_number);
    jsonObj.insert("pincode", pincode);

    QString site_url="http://localhost:3000/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    netManager = new QNetworkAccessManager(this);
    connect(netManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = netManager->post(request, QJsonDocument(jsonObj).toJson());
}

void MainWindow::loginSlot(QNetworkReply *reply)  //tämä käsittelee vastauksen, saadaan tuo *reply
{

    response_data = reply->readAll();
    qDebug() << response_data;

    int test=QString::compare(response_data, "false");
    qDebug() << test;

    if(test == -1 && response_data.length() > 0){
        getAccountId();
        moveToMenu();
        clearFields();

    }else if(test == 0){
        clearFields();
        ui->label_infobox->setText("<font color='red'>Wrong password or username</font");
    }
    else{
        ui->label_infobox->setText("<font color='red'>No response from server</font");
    }

}

void MainWindow::logOut()
{
    // Login screeniin siirtyminen
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::moveToMenu()
{

    if(ui->stackedWidget->currentIndex() > 0){
        timerReset();
    }

    // Päänäkymään/menuun siirtyminen
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::moveToWithdrawal()
{
    objectWithdrawMenu.cardNumber = card_number; //viedään card_number withdraw-ikkunaan, public/private??
    objectWithdrawMenu.cardNumber = card_number; //viedään card_number withdraw-ikkunaan
    ui->stackedWidget->setCurrentIndex(3); // Withdrawal-ikkunaan siirtyminen
    timerReset();
}

void MainWindow::moveToTransferFunds()
{
    // transferfunds näkymään siirtyminen
    ui->stackedWidget->setCurrentIndex(2);
    timerReset();
}

void MainWindow::clearFields()
{
    // Käyttäjä ja salasana kentän tyhjennys
    ui->label_infobox->clear();
    ui->text_id->clear();
    ui->text_PIN->clear();

}

void MainWindow::netRequest(QString siteurl)
{
    // WebToken alku
    QNetworkRequest request((siteurl));
    request.setRawHeader(QByteArray("Authorization"),("Bearer "+objectMainMenu.getWebToken()));
    // WebToken loppu
    netManager = new QNetworkAccessManager(this);
    connect(netManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getBookSlot(QNetworkReply*)));

    reply = netManager->get(request);
}


void MainWindow::timerReset()
{
    if(ui->stackedWidget->currentIndex() == 1){
         timer1->stop();
         timer1->start(30000);
    }else{
         timer1->stop();
         timer1->start(10000);
        }
}

void MainWindow::timerTriggered()
{
    if(ui->stackedWidget->currentIndex() > 1){
        ui->stackedWidget->setCurrentIndex(1);
        timer1->start(30000);
    }
    else if(ui->stackedWidget->currentIndex() == 1){
        logOut();
    }
    objectMainMenu.clearFields();
    objectWithdrawMenu.clearFields();
}


void MainWindow::getAccountId()  //haetaan tilin numero Main Windowiin
{
    QString site_url="http://localhost:3000/card_access/"+card_number;
    QNetworkRequest request((site_url));
    qDebug() << "Number of the card in use is: "+ card_number;
        netManager = new QNetworkAccessManager(this);
    connect(netManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(accountIdSlot(QNetworkReply*)));
    reply = netManager->get(request);

}

void MainWindow::accountIdSlot(QNetworkReply *reply) //Tilinumerohaun vastaus tulee tänne
{
    QByteArray response=reply->readAll();        //Haetaan korttiin liitetyn tilin numero
    QJsonDocument json_doc = QJsonDocument::fromJson(response);
    QJsonObject json_obj = json_doc.object();

    account_number=QString::number(json_obj["account_number"].toInt());

    emit cardAndAccount(account_number, card_number);  //EI lähde korttinumero täältä?????????

    qDebug()<<"ja MainWindowissa tilin numero on: " +account_number;

    reply->deleteLater();
    netManager->deleteLater();
}

