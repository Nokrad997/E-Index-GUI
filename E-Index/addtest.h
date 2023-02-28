#ifndef ADDTEST_H
#define ADDTEST_H

#include <QWidget>
#include <QMessageBox>
#include "Teacher.h"

namespace Ui {
class AddTest;
}

class AddTest : public QWidget
{
    Q_OBJECT

public:
    explicit AddTest(TeacherRepository *_t, QWidget *parent = nullptr, Qt::WindowType type = Qt::Dialog);
    ~AddTest();

private slots:
    void on_pushButton_Submit_clicked();

private:
    Ui::AddTest *ui;
    TeacherRepository *teacher;
};

#endif // ADDTEST_H
