#ifndef ADDGRADES_H
#define ADDGRADES_H

#include <QWidget>
#include <QMessageBox>
#include <iostream>
#include <vector>
#include <fstream>
#include "Teacher.h"

using namespace std;

namespace Ui {
class AddGrades;
}

class AddGrades : public QWidget
{
    Q_OBJECT

public:
    explicit AddGrades(TeacherRepository *_t, QWidget *parent = nullptr, Qt::WindowType type = Qt::Dialog);
    ~AddGrades();

private slots:
    void on_pushButton_SubmitGrade_clicked();

private:
    Ui::AddGrades *ui;
    TeacherRepository *teacher;
};

#endif // ADDGRADES_H
