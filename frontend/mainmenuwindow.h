#ifndef MAINMENUWINDOW_H
#define MAINMENUWINDOW_H

#include "withdrawalwindow.h"
#include "transferfundswindow.h"

#include <QWidget>

namespace Ui {
class Mainmenuwindow;
}

class Mainmenuwindow : public QWidget
{
    Q_OBJECT

public:
    explicit Mainmenuwindow(QString card_number, QWidget *parent = nullptr);  //tuodaan card_number mainWindowista
    ~Mainmenuwindow();

private slots:
    void on_btnWithdrawal_clicked();

    void on_btnTransferFunds_clicked();

    void on_btnCheckBalance_clicked();

    void on_btnTransactions_clicked();

    void on_btnLogOut_clicked();

private:
    Ui::Mainmenuwindow *ui;
    withdrawalwindow *objectWithdrawal;
    transferfundswindow *objectTransferFunds;

};

#endif // MAINMENUWINDOW_H
