#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <addgrades.h>
#include "addtest.h"
#include "addabsence.h"
#include "Teacher.h"

namespace Ui {
class UserWindow;
}

class UserWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserWindow(TeacherRepository *_t, QWidget *parent = nullptr);
    ~UserWindow();

private slots:
    void on_pushButton_searchForMembers_clicked();

    void on_pushButton_AddNewTest_clicked();

    void on_pushButton_AddNewGrade_clicked();

    void on_pushButton_AddAbsence_clicked();

    void on_pushButton_clicked();

private:
    Ui::UserWindow *ui;
    TeacherRepository *teacher;
    AddAbsence *absence;
    AddTest *test;
    AddGrades *Grade;
};

#endif // USERWINDOW_H
