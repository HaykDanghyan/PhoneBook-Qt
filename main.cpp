#include "phonebook.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    PhoneBook w;
    w.show();
    w.setFixedSize(w.size());
    w.setWindowTitle("Phone Book");
    return app.exec();
}
