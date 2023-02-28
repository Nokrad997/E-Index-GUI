#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QInputDialog>
#include "edituserdata.h"
#include "addstudent.h"
#include "addteacher.h"
#include "Admin.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

private slots:
    void on_pushButton_ShowAllUsers_clicked();

    void on_pushButton_SearchById_clicked();

    void on_pushButton_SearchByClass_clicked();

    void on_pushButton_SearchByRole_clicked();

    void on_pushButton_AddStudent_clicked();

    void on_pushButton_AddTeacher_clicked();

    void on_pushButton_EditUser_clicked();

    void on_pushButton_DeleteUser_clicked();

    void on_pushButton_clicked();

private:
    Ui::AdminWindow *ui;
    AdminRepository *admin;

    AddTeacher *addT;
    AddStudent *addS;
    EditUserData *edit;
};

#endif // ADMINWINDOW_H
