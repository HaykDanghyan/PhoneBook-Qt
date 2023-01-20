#ifndef NEWCONTACT_H
#define NEWCONTACT_H

#include <QMainWindow>
#include <QDialog>
#include <iostream>

namespace Ui {
class NewContact;
}

class NewContact : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewContact(QWidget *parent = nullptr);
    ~NewContact();

signals:
    void contact_transfer(const std::vector<std::string>&);

private slots:
    void on_add_clicked();

private:
    Ui::NewContact *ui;
};

#endif // NEWCONTACT_H
