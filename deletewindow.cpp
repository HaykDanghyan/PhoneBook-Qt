#include "deletewindow.h"
#include "ui_deletewindow.h"

DeleteWindow::DeleteWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::DeleteWindow) {
    ui->setupUi(this);
    QPixmap pix("../PhoneBook/Pictures/academy.png");
    auto w = ui->picture->width();
    auto h = ui->picture->height();
    ui->picture->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    ui->rowNumber->setPlaceholderText("Enter the row number of contact");
}

DeleteWindow::~DeleteWindow() {
    delete ui;
    ui = nullptr;
}

void DeleteWindow::on_deletebutton_clicked() {
    int row_number = ui->rowNumber->text().toInt();
    emit row_transfer(row_number);
    this->close();
}
