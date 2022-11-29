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

private:
    Ui::transferfundswindow *ui;
};

#endif // TRANSFERFUNDSWINDOW_H
