#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <vector>
#include <fstream>

#include "registration.h"
#include "userwindow.h"
#include "studentwindow.h"
#include "Teacher.h"
#include "Student.h"
#include "Admin.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Register_clicked();

    void on_pushButton_Login_clicked();

    void on_radioButton_ShowPassword_toggled(bool checked);

    void on_pushButton_Quit_clicked();

private:
    Ui::MainWindow *ui;
    StudentWindow *studentUI;
    UserWindow *userUI;
    Registration *regUI;
};
#endif // MAINWINDOW_H
