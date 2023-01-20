#include "deletecontact.h"
#include "ui_deletecontact.h"

DeleteContact::DeleteContact(QWidget *parent) :
    QWidget(parent), ui(new Ui::DeleteContact) {
    ui->setupUi(this);
    auto w = ui->picture->width();
    auto h = ui->picture->height();
    QPixmap pix("../PhoneBook/Pictures/academy.png");
    ui->picture->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

DeleteContact::~DeleteContact() {
    delete ui;
    ui = nullptr;
}
