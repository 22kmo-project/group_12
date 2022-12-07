#ifndef MAINMENUWINDOW_H
#define MAINMENUWINDOW_H

#include "qbitarray.h"


#include <QWidget>
#include <QDebug>   //??????

namespace Ui {
class Mainmenuwindow;
}

class Mainmenuwindow : public QWidget
{
    Q_OBJECT

public:
    explicit Mainmenuwindow(QString card_number, QWidget *parent = nullptr);  //tuodaan card_number mainWindowista
    Mainmenuwindow(QWidget *parent = nullptr);
    ~Mainmenuwindow();

//    const QString &getWebToken() const;
    void setWebToken(QByteArray &newWebToken);
    QByteArray getWebToken();

private slots:
    void on_btnWithdrawal_clicked();
    void on_btnTransferFunds_clicked();
    void on_btnCheckBalance_clicked();
    void on_btnTransactions_clicked();
    void on_btnLogOut_clicked();

private:
    Ui::Mainmenuwindow *ui;

    QByteArray webToken;

signals:
    void logOutClicked();
    void withdrawalClicked();
    void transferFundsClicked();


};

#endif // MAINMENUWINDOW_H
