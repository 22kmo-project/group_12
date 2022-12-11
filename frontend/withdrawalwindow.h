#ifndef WITHDRAWALWINDOW_H
#define WITHDRAWALWINDOW_H

#include <QWidget>

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class withdrawalwindow;
}

class withdrawalwindow : public QWidget
{
    Q_OBJECT

public:
    explicit withdrawalwindow(QWidget *parent = nullptr);
    ~withdrawalwindow();

    QString cardNumber;

private slots:
    void on_btn20_clicked();
    void on_btn40_clicked();
    void on_btn60_clicked();
    void on_btn100_clicked();
    void on_btn200_clicked();
    void on_btn500_clicked();
    void on_btnCloseWithdrawal_clicked();
    void on_btnAmountOK_clicked();

    void withdrawal_status(QNetworkReply *reply);
    void getWithdrawal(QNetworkReply *reply);

private:
    Ui::withdrawalwindow *ui;
    void withdrawal();

    QString getCardAccess(QNetworkReply *reply);

    QNetworkAccessManager *cardAccessManager;
    QNetworkReply *reply;
    QString account_number;

signals:
    void closeClicked();  //tämä voi olla mikä funktio vaan??
};

#endif // WITHDRAWALWINDOW_H
