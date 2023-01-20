#include "phonebook.h"
#include "ui_phonebook.h"

PhoneBook::PhoneBook(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::PhoneBook) {
    ui->setupUi(this);
    QPixmap pa("../PhoneBook/Pictures/academy.png");
    auto w = ui->picture->width();
    auto h = ui->picture->height();
    ui->picture->setPixmap(pa.scaled(w, h, Qt::KeepAspectRatio));
    QPixmap user_plus("../PhoneBook/Pictures/user-plus.svg");
    QIcon user_plus_icon(user_plus);
    ui->add_contact->setIcon(user_plus_icon);
    ui->add_contact->setIconSize(QSize(100, 75));
    QPixmap user_minus("../PhoneBook/Pictures/user-minus.svg");
    QIcon user_minus_icon(user_minus);
    ui->delete_contact->setIcon(user_minus_icon);
    ui->delete_contact->setIconSize(QSize(100, 75));
    for (int i = 0; i < ui->tableWidget->columnCount(); ++i) {
        ui->tableWidget->setColumnWidth(i, 195);
    }
    load_from_file();
}

PhoneBook::~PhoneBook() {
    load_to_file();
    delete ui;
    ui = nullptr;
}

void PhoneBook::receive_contact(const std::vector<std::string>& vec) {
    QTableWidgetItem* name = new QTableWidgetItem(vec[0].c_str());
    QTableWidgetItem* email = new QTableWidgetItem(vec[1].c_str());
    QTableWidgetItem* phone_number = new QTableWidgetItem(vec[2].c_str());
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    ui->tableWidget->setItem(row, 0, name);
    ui->tableWidget->setItem(row, 1, email);
    ui->tableWidget->setItem(row, 2, phone_number);
}


void PhoneBook::on_add_contact_clicked() {
    NewContact* window = new NewContact(this);
    window->setFixedSize(window->size());
    window->setWindowTitle("New Contact");
    window->show();
    connect(window, &NewContact::contact_transfer, this, &PhoneBook::receive_contact);
}

void PhoneBook::load_to_file() {
    std::fstream file;
    file.open("../PhoneBook/contacts.data", std::ios::in | std::ios::app | std::ios::out);
    int row = 0;
    std::vector<std::string> vec;
    int count = 0;
    while (row < ui->tableWidget->rowCount()) {
        int col = 0;
        while (col < PROPERTY_COUNT) {
            auto el = ui->tableWidget->item(row, col)->text().toStdString();
            vec.push_back(el);
            ++col;
        }
        file << "Name - " << vec[count] << " | Email - " << vec[++count] <<
                " | PhoneNumber - " << vec[++count] << "\n";
        ++row;
        vec.clear();
        count = 0;
    }
    file.close();
}

std::vector<std::string> PhoneBook::split(const std::string& line, const std::string& delimiter) {
    std::vector<std::string> res;
    std::string word{};
    for (const auto& el : line) {
        if (delimiter.find(el) == std::string::npos) {
            word += el;
        } else if (!word.empty()) {
            res.push_back(word);
            word.clear();
        }
    }
    if (!word.empty()) {
        res.push_back(word);
    }
    return res;
}

void PhoneBook::load_from_file() {
    std::fstream file;
    file.open("../PhoneBook/contacts.data", std::ios::in | std::ios::app | std::ios::out);
    while (file.peek() != EOF) {
        std::string line{};
        std::getline(file, line);
        auto vec = split(line, " -|");
        vec.erase(std::remove(vec.begin(), vec.end(), "Name"), vec.end());
        vec.erase(std::remove(vec.begin(), vec.end(), "Email"), vec.end());
        vec.erase(std::remove(vec.begin(), vec.end(), "PhoneNumber"), vec.end());
        receive_contact(vec);
    }
}


void PhoneBook::on_delete_contact_clicked() {
    DeleteWindow* window = new DeleteWindow(this);
    window->show();
    window->setFixedSize(window->size());
    window->setWindowTitle("Delete Contact");
    connect(window, &DeleteWindow::row_transfer, this, &PhoneBook::row_delete);
}

void PhoneBook::row_delete(int row) {
    ui->tableWidget->removeRow(row - 1);
    ui->tableWidget->sortItems(0);
}
