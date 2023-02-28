#include "addgrades.h"
#include "ui_addgrades.h"

AddGrades::AddGrades(TeacherRepository *_t, QWidget *parent, Qt::WindowType type) :
    QWidget(parent, type),
    ui(new Ui::AddGrades)
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

AddGrades::~AddGrades()
{
    delete teacher;
    delete ui;
}

void AddGrades::on_pushButton_SubmitGrade_clicked()
{
    if(ui->lineEdit_Topic->text() == "" || ui->spinBox_ClassId->value() == 0
            || ui->spinBox_Grade->value() == 0 || ui->spinBox_StudentId->value() == 0)
    {
        QMessageBox::warning(this, "Grade", "All fields must be filled");
        return ;
    }

    int classNumber = ui->spinBox_ClassId->value();
    vector<vector<string>> students = teacher->getStudents(classNumber);
    int grade = 0;
    int studentId = ui->spinBox_StudentId->value();
    int idx = 0;

    if(students.size() != 0)
    {
        for(int i = 0; i < students.size(); i++)
        {
            if(students[i][0] == to_string(studentId))
            {
                idx = i;
                grade = ui->spinBox_Grade->value();
                break;
            }
        }
    }

    if(grade != 0)
    {
        string name, surname, subject, topic, teacherName;


        teacherName = teacher->getName();
        topic = ui->lineEdit_Topic->text().toStdString();
        subject = ui->comboBox_Subject->currentText().toStdString();
        string path = subject + "-grades" + ".bin";
        name = students[idx][1];
        surname = students[idx][2];

        teacher->addGrades(name, surname, topic, subject, studentId, grade, classNumber);

        QMessageBox::information(this, "Grade", "Grade added");
    }
    else
    {
        QMessageBox::warning(this, "Grade", "Student not found");
        return ;
    }
    this->close();
}

