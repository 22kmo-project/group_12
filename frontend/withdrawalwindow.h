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

    void clearFields();


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
    void getWithdrawalSlot(QNetworkReply *reply);

    void on_lbl_amount_textEdited(const QString &arg1);

private:
    Ui::withdrawalwindow *ui;
    void withdrawal();
    QString getCardAccess(QNetworkReply *reply);
    QNetworkAccessManager *cardAccessManager;
    QNetworkReply *reply;
    QString account_number;

signals:
    void closeClicked();
    void buttonPressed();

};

#endif // WITHDRAWALWINDOW_H
