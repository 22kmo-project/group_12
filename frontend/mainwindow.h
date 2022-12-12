#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "QTimer"

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
    void netRequest(QString url);
    void timerReset();
    void timerTriggered();

private:
    Ui::MainWindow *ui;
    Mainmenuwindow objectMainMenu;
    transferfundswindow objectTransferMenu;
    withdrawalwindow objectWithdrawMenu;
    creditOrDebitWindow objectCreditDebitMenu;
    QTimer *timer1;

    QNetworkAccessManager *netManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString card_number;

    void clearFields();


};
#endif // MAINWINDOW_H
