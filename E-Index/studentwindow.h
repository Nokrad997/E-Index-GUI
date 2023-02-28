#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTextCharFormat>
#include "StudentRepository.h"

namespace Ui {
class StudentWindow;
}

class StudentWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentWindow(StudentRepository *_s, QWidget *parent = nullptr);
    ~StudentWindow();
    void showEventInfo(QDate eventDate, vector<vector<string>> dates);

private slots:
    void on_pushButton_Grades_clicked();

    void on_pushButton_Absences_clicked();

    void on_pushButton_CalculateAverage_clicked();

    void on_pushButton_clicked();

private:
    Ui::StudentWindow *ui;

    StudentRepository *student;
};

#endif // STUDENTWINDOW_H
