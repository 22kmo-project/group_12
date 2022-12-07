#ifndef WITHDRAWALWINDOW_H
#define WITHDRAWALWINDOW_H

#include <QWidget>

namespace Ui {
class withdrawalwindow;
}

class withdrawalwindow : public QWidget
{
    Q_OBJECT

public:
    explicit withdrawalwindow(QWidget *parent = nullptr);
    ~withdrawalwindow();


private slots:
    void on_btn20_clicked();

    void on_btn40_clicked();

    void on_btn60_clicked();

    void on_btn100_clicked();

    void on_btn200_clicked();

    void on_btn500_clicked();

    void on_btnCloseWithdrawal_clicked();

    void on_btnAmountOK_clicked();

private:
    Ui::withdrawalwindow *ui;
    int nostettava = 0;


signals:
    void closeClicked();
};

#endif // WITHDRAWALWINDOW_H
