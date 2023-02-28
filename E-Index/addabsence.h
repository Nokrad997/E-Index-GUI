#ifndef ADDABSENCE_H
#define ADDABSENCE_H

#include <QWidget>
#include <QMessageBox>
#include <QDate>
#include "Teacher.h"
#include <vector>

using namespace std;

namespace Ui {
class AddAbsence;
}

class AddAbsence : public QWidget
{
    Q_OBJECT

public:
    explicit AddAbsence(TeacherRepository *_t, QWidget *parent = nullptr, Qt::WindowType type = Qt::Dialog);
    ~AddAbsence();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddAbsence *ui;
    TeacherRepository *teacher;
};

#endif // ADDABSENCE_H
