#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

#include <QWidget>
#include <QMessageBox>
#include "Person.h"

namespace Ui {
class AddStudent;
}

class AddStudent : public QWidget
{
    Q_OBJECT

public:
    explicit AddStudent(QWidget *parent = nullptr, Qt::WindowType type = Qt::Dialog);
    ~AddStudent();
    bool checkData();

private slots:
    void on_pushButton_clicked();

    void on_radioButton_toggled(bool checked);

private:
    Ui::AddStudent *ui;
};

#endif // ADDSTUDENT_H
