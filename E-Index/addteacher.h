#ifndef ADDTEACHER_H
#define ADDTEACHER_H

#include <QWidget>
#include <QMessageBox>
#include <Person.h>

namespace Ui {
class AddTeacher;
}

class AddTeacher : public QWidget
{
    Q_OBJECT

public:
    explicit AddTeacher(QWidget *parent = nullptr, Qt::WindowType type = Qt::Dialog);
    ~AddTeacher();
    bool checkData();
    void writeTeacher(ofstream &file, string name, string surname, string subject, int id);

private slots:
    void on_pushButton_clicked();

    void on_radioButton_Password_toggled(bool checked);

private:
    Ui::AddTeacher *ui;
};

#endif // ADDTEACHER_H
