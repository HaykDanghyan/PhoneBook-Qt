#include "newcontact.h"
#include "ui_newcontact.h"

NewContact::NewContact(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::NewContact) {
    ui->setupUi(this);
    QPixmap pix("../PhoneBook/Pictures/academy.png");
    auto w = ui->picture->width();
    auto h = ui->picture->height();
    ui->picture->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    ui->email->setPlaceholderText("Email");
    ui->phonenumber->setPlaceholderText("Phone Number");
    ui->name->setPlaceholderText("Name");
}

NewContact::~NewContact() {
    delete ui;
    ui = nullptr;
}

void NewContact::on_add_clicked() {
    std::vector<std::string> vec;
    const QString name = ui->name->text();
    const QString email = ui->email->text();
    bool valid = true;
    QRegExp reg("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    if (!reg.exactMatch(email)) {
        ui->email->setStyleSheet("QLineEdit {"
                                 "border-radius: 30px;"
                                 "border: 3px solid red;"
                                 "}");
        ui->email->clear();
        ui->email->setPlaceholderText("Wrong email");
        valid = false;
        return;
    }
    const QString phone_number = ui->phonenumber->text();
    reg = QRegExp("^[0-9]+$");
    if (!reg.exactMatch(phone_number)) {
        ui->phonenumber->setStyleSheet("QLineEdit {"
                                 "border-radius: 30px;"
                                 "border: 3px solid red;"
                                 "}");
        ui->phonenumber->clear();
        ui->phonenumber->setPlaceholderText("Wrong phone number");
        valid = false;
        return;
    }
    if (valid) {
        vec.push_back(name.toStdString());
        vec.push_back(email.toStdString());
        vec.push_back(phone_number.toStdString());
        emit contact_transfer(vec);
        this->close();
    }
}
