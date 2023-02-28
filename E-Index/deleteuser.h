#ifndef DELETEUSER_H
#define DELETEUSER_H

#include <QWidget>

namespace Ui {
class DeleteUser;
}

class DeleteUser : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteUser(QWidget *parent = nullptr);
    ~DeleteUser();

private:
    Ui::DeleteUser *ui;
};

#endif // DELETEUSER_H
