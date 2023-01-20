#ifndef DELETECONTACT_H
#define DELETECONTACT_H

#include <QWidget>

namespace Ui {
class DeleteContact;
}

class DeleteContact : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteContact(QWidget *parent = nullptr);
    ~DeleteContact();

private:
    Ui::DeleteContact *ui;
};

#endif // DELETECONTACT_H
