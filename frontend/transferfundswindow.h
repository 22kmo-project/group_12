#ifndef TRANSFERFUNDSWINDOW_H
#define TRANSFERFUNDSWINDOW_H

#include <QWidget>

namespace Ui {
class transferfundswindow;
}

class transferfundswindow : public QWidget
{
    Q_OBJECT

public:
    explicit transferfundswindow(QWidget *parent = nullptr);
    ~transferfundswindow();

private slots:
    void on_btnCloseTransfer_clicked();

    void on_btnTransferOK_clicked();

private:
    Ui::transferfundswindow *ui;

signals:
    void closeClicked();
    void buttonPressed();
};

#endif // TRANSFERFUNDSWINDOW_H
