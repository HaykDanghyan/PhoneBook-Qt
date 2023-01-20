#ifndef DELETEWINDOW_H
#define DELETEWINDOW_H

#include <QMainWindow>

namespace Ui {
class DeleteWindow;
}

class DeleteWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeleteWindow(QWidget *parent = nullptr);
    ~DeleteWindow();

signals:
    void row_transfer(int);

private slots:
    void on_deletebutton_clicked();

private:
    Ui::DeleteWindow *ui;
};

#endif // DELETEWINDOW_H
