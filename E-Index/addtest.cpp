#include "addtest.h"
#include "ui_addtest.h"

AddTest::AddTest(TeacherRepository *_t, QWidget *parent, Qt::WindowType type) :
    QWidget(parent, type),
    ui(new Ui::AddTest)
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
    ui->dateEdit_TestDate->setMinimumDate(QDate::currentDate());

    delete [] subjects;
}

AddTest::~AddTest()
{
    delete teacher;
    delete ui;
}

void AddTest::on_pushButton_Submit_clicked()
{
    if(ui->spinBox_ClassNumber == 0 || ui->lineEdit_Topic->text() == "")
    {
        QMessageBox::warning(this, "Test", "All fields must be filled");
        return ;
    }

    if(ui->lineEdit_Topic->text().length() > 30)
    {
        QMessageBox::warning(this, "Test", "Topic length must be less than 30 characters");
        return ;
    }

    QDate qdate;
    qdate = ui->dateEdit_TestDate->date();

    if(qdate.dayOfWeek() == 0 || qdate.dayOfWeek() == 6)
    {
        QMessageBox::warning(this, "Błąd", "You can't assign test on weekend");
        return ;
    }

    string path = to_string(ui->spinBox_ClassNumber->value())+ "-class" + ".bin";

    ifstream classFile(path, ios::binary);

    if(classFile.good() && classFile.is_open())
    {
        classFile.close();

        string date, topic, path;
        int classNumber = 0;

        string subject = ui->comboBox_Subject->currentText().toStdString();
        path = subject + "-tests.bin";
        QDate qdate = ui->dateEdit_TestDate->date();
        date = qdate.toString("MM-dd-yyyy").toStdString();
        topic = ui->lineEdit_Topic->text().toStdString();
        classNumber = ui->spinBox_ClassNumber->value();

        teacher->addTest(date, path, classNumber, topic);
    }
    else
    {
        QMessageBox::warning(this, "Test", "This class has no members yet");
        return ;
    }

    QMessageBox::information(this, "Test", "Test added");
    this->close();
}

