#ifndef CREDITORDEBITWINDOW_H
#define CREDITORDEBITWINDOW_H

#include <QWidget>

namespace Ui {
class creditOrDebitWindow;
}

class creditOrDebitWindow : public QWidget
{
    Q_OBJECT

public:
    explicit creditOrDebitWindow(QWidget *parent = nullptr);
    ~creditOrDebitWindow();

private slots:
    void on_btnCredit_clicked();

    void on_btnDebit_clicked();

private:
    Ui::creditOrDebitWindow *ui;
};

#endif // CREDITORDEBITWINDOW_H
