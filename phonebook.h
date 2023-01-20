#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QLineEdit>

#include <iostream>
#include <fstream>
#include <tuple>

#include "newcontact.h"
#include "deletewindow.h"

#define PROPERTY_COUNT 3

QT_BEGIN_NAMESPACE
namespace Ui { class PhoneBook; }
QT_END_NAMESPACE

class PhoneBook : public QMainWindow
{
    Q_OBJECT

public:
    PhoneBook(QWidget *parent = nullptr);
    ~PhoneBook();

private:
    void load_to_file();
    void load_from_file();

private:
    std::vector<std::string> split(const std::string&, const std::string&);

public slots:
    void receive_contact(const std::vector<std::string>&);
    void row_delete(int);

private slots:
    void on_add_contact_clicked();

    void on_delete_contact_clicked();

private:
    Ui::PhoneBook *ui;

};
#endif // PHONEBOOK_H
