#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>
#include <QMessageBox>
#include "Person.h"
#include <string>

namespace Ui {
class Registration;
}

class Registration : public QWidget
{
    Q_OBJECT

public:
    explicit Registration(Person *_p, QWidget *parent = nullptr, Qt::WindowType type = Qt::Dialog);
    ~Registration();
    bool checkData();

private slots:
    void on_radioButton_toggled(bool checked);

    void on_pushButton_clicked();

private:
    Ui::Registration *ui;
    Person *person;
};

#endif // REGISTRATION_H
