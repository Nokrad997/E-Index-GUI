#ifndef EDITUSERDATA_H
#define EDITUSERDATA_H

#include <QWidget>
#include <QMessageBox>
#include "Person.h"
#include "AdminRepository.h"

namespace Ui {
class EditUserData;
}

class EditUserData : public QWidget
{
    Q_OBJECT

public:
    explicit EditUserData(AdminRepository *_a, Person userData, QWidget *parent = nullptr,  Qt::WindowType type = Qt::Dialog);
    ~EditUserData();

private slots:
    void on_pushButton_clicked();

private:
    Ui::EditUserData *ui;
    AdminRepository *admin;
    Person user;
};

#endif // EDITUSERDATA_H
