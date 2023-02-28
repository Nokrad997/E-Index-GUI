#include "addabsence.h"
#include "ui_addabsence.h"

AddAbsence::AddAbsence(TeacherRepository *_t, QWidget *parent,  Qt::WindowType type) :
    QWidget(parent, type),
    ui(new Ui::AddAbsence)
{
    ui->setupUi(this);
    teacher = _t;

    string *subjects = new string[5];
    subjects[0] = "Math";
    subjects[1] = "English";
    subjects[2] = "Biology";
    subjects[3] = "Physics";
    subjects[4] = "Chemistry";

    QStringList list;
    list << QString::fromStdString(subjects[0]) << QString::fromStdString(subjects[1])
            << QString::fromStdString(subjects[2]) << QString::fromStdString(subjects[3])
            << QString::fromStdString(subjects[4]);

    ui->comboBox_Subject->addItems(list);

    delete [] subjects;
}

AddAbsence::~AddAbsence()
{
    delete teacher;
    delete ui;
}

void AddAbsence::on_pushButton_clicked()
{
    if(ui->spinBox_ClassNumber->value() == 0 || ui->spinBox_StudentId->value() == 0)
    {
        QMessageBox::warning(this, "Błąd", "All fields must be filled");
        return ;
    }

    if(QDate::currentDate().dayOfWeek() == 1 || QDate::currentDate().dayOfWeek() == 7)
    {
        QMessageBox::warning(this, "Błąd", "You can't assign absence on weekend");
        return ;
    }

    ifstream classFile(to_string(ui->spinBox_ClassNumber->value()) + "-class.bin", ios::binary);

    if(classFile.good() && classFile.is_open())
    {
        int idx = 0;
        vector<vector<string>> students;
        students = teacher->getStudents(ui->spinBox_ClassNumber->value());
        bool found = false;

        for(int i = 0; i < students.size(); i++)
        {
            if(students[i][0] == ui->spinBox_StudentId->text().toStdString())
            {
                idx = i;
                found = true;
                break;
            }
        }

        if(!found)
        {
            QMessageBox::warning(this, "Błąd", "couldnt find student with given id");
            return ;
        }

        int classNumber = ui->spinBox_ClassNumber->value();
        string teacherName = teacher->getSurname();
        string subject = ui->comboBox_Subject->currentText().toStdString();
        string date = QDate::currentDate().toString("MM-dd-yyyy").toStdString();
        teacher->saveAbsence(classNumber, teacherName, date, subject, students[idx]);
    }
    else
    {
        QMessageBox::warning(this, "Błąd", "Class has no members yet");
        return ;
    }
    QMessageBox::information(this, "Absence", "Absence added");
    this->close();
}


