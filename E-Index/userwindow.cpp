#include "userwindow.h"
#include "ui_userwindow.h"

UserWindow::UserWindow(TeacherRepository *_t, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserWindow)
    {
    ui->setupUi(this);
    teacher = _t;

    QString name = QString::fromStdString(_t->getName());
    QString surname = QString::fromStdString(_t->getSurname());
    ui->label_Welcome_2->setText(name);
    ui->label_Welcome_3->setText(surname);

    setWindowFlag(Qt::WindowCloseButtonHint, false);
}

UserWindow::~UserWindow()
{
    delete teacher;
    delete absence;
    delete test;
    delete Grade;
    delete ui;
}

void UserWindow::on_pushButton_searchForMembers_clicked()
{
    int classNumber = ui->spinBox_ClassNumber->value();
    vector<vector<string>> students;
    students = teacher->getStudents(classNumber);
    if(students.size() != 0)
    {
        ui->tableWidget_ClassMembers->setStyleSheet("alignment: center;");
        ui->tableWidget_ClassMembers->setRowCount(students.size());
        ui->tableWidget_ClassMembers->setColumnCount(students[0].size());

        QStringList headers;
        headers << "Id" << "Name" << "Surname";
        ui->tableWidget_ClassMembers->setHorizontalHeaderLabels(headers);

        for(int i = 0; i < students.size(); i++)
        {
            for(int ii = 0; ii < students[0].size(); ii++)
            {
                QTableWidgetItem* item = new QTableWidgetItem(QString::fromStdString(students[i][ii]));
                ui->tableWidget_ClassMembers->setItem(i, ii, item);
            }
        }
        ui->tableWidget_ClassMembers->sortByColumn(1, Qt::DescendingOrder);
    }
    else
    {
        QMessageBox::warning(this, "eror", "This class has no students yet");
    }
}


void UserWindow::on_pushButton_AddNewTest_clicked()
{
    test = new AddTest(teacher, this, Qt::Window);
    test->show();
}


void UserWindow::on_pushButton_AddNewGrade_clicked()
{
    Grade = new AddGrades(teacher, this, Qt::Window);
    Grade->show();
}


void UserWindow::on_pushButton_AddAbsence_clicked()
{
    absence = new AddAbsence(teacher, this, Qt::Window);
    absence->show();
}


void UserWindow::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Quit", "Are you sure you wont to logout?", QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes)
    {
        this->close();
        QWidget *parent = this->parentWidget();
        parent->show();
    }

    return ;
}

