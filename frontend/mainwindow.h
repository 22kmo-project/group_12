#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

#include "mainmenuwindow.h"
#include "transferfundswindow.h"
#include "withdrawalwindow.h"
#include "creditordebitwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_login_clicked();
    void loginSlot (QNetworkReply *reply);

    void logOut();
    void moveToMenu();
    void moveToWithdrawal();
    void moveToTransferFunds();

private:
    Ui::MainWindow *ui;
    Mainmenuwindow objectMainMenu;
    transferfundswindow objectTransferMenu;
    withdrawalwindow objectWithdrawMenu;
    creditOrDebitWindow objectCreditDebitMenu;

    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString card_number;

    void clearFields();


};
#endif // MAINWINDOW_H
