#include "addteacher.h"
#include "ui_addteacher.h"

AddTeacher::AddTeacher(QWidget *parent, Qt::WindowType type) :
    QWidget(parent, type),
    ui(new Ui::AddTeacher)
{
    ui->setupUi(this);

    string *subjects = new string[5];

    subjects[0] = "Math";
    subjects[1] = "English";
    subjects[2] = "Biology";
    subjects[3] = "Physics";
    subjects[4] = "Chemistry";

    delete [] subjects;
}

AddTeacher::~AddTeacher()
{
    delete ui;
}

void AddTeacher::on_pushButton_clicked()
{
    if(ui->lineEdit_Email->text() == "" || ui->lineEdit_Name->text() == ""
            || ui->lineEdit_Password->text() == "" || ui->lineEdit_Surname->text() == "")
    {
        QMessageBox::warning(this, "Registration", "All fields must be filled");
        return ;
    }

    ifstream file = ifstream("users.bin", ios::binary);
    int id = 0;
    Person p1;

    if(!checkData())
    {
        return;
    }

    string check = ui->lineEdit_Email->text().toStdString();
    try
    {
        if(file.good() && file.is_open())
        {
            while (file)
            {
                p1.read(file);
                if(check == p1.getEmail())
                {
                    QMessageBox::warning(this, "Błąd", "Account with this email already exists");
                    return ;
                }
            }
        }
        else
        {
            throw runtime_error("couldnt open a file");
        }

        file.close();
    }
    catch(std::exception &e)
    {
        QMessageBox::warning(this, "Błąd", e.what());
        return ;
    }
    id = p1.getId() + 1;




    p1.setId(id);
    p1.setName(ui->lineEdit_Name->text().toStdString());
    p1.setSurname(ui->lineEdit_Surname->text().toStdString());
    p1.setRole("Teacher");
    p1.setClassNumber(0);
    p1.setEmail(ui->lineEdit_Email->text().toStdString());
    p1.setPassword(ui->lineEdit_Password->text().toStdString());

    ofstream file2("users.bin", ios::binary | ios::app);

    try
    {
        p1.write(file2);
        file2.close();
        //writeTeacher(file3, p1.getName(), p1.getSurname(), subject, p1.getId());

    }
    catch(std::exception &e)
    {
        QMessageBox::warning(this, "Błąd", e.what());
        return ;
    }

    QMessageBox::information(this, "Registration", "Registration succesful");
    this->close();
}

void AddTeacher::writeTeacher(ofstream &file, string name, string surname, string subject, int id)
{
    try
    {
        if(file.good() && file.is_open())
        {
            size_t nameSize, surnameSize, subjectSize;
            nameSize = name.size();
            surnameSize = surname.size();
            subjectSize = subject.size();

            file.write((char *)&id, sizeof(int));

            file.write((char *)&subjectSize, sizeof(size_t));
            file.write((char *)&subject[0], subjectSize);

            file.write((char *)&nameSize, sizeof(size_t));
            file.write((char *)&name[0], nameSize);

            file.write((char *)&surnameSize, sizeof(size_t));
            file.write((char *)&surname[0], surnameSize);

            file.close();
        }
        else
        {
            throw runtime_error("error opening a file");
        }
    }
    catch(exception &e)
    {
        QMessageBox::warning(this, "Add Teacher", e.what());
        return;
    }
}

bool AddTeacher::checkData()
{
    if(ui->lineEdit_Name->text().toStdString().length() < 1 || ui->lineEdit_Name->text().toStdString().length() > 25)
    {
        QMessageBox::warning(this, "Błąd", "Name must be between 1 and 25 characters");
        return false;
    }
    if(ui->lineEdit_Surname->text().toStdString().length() < 1 || ui->lineEdit_Surname->text().toStdString().length() > 25)
    {
        QMessageBox::warning(this, "Błąd", "Surname must be between 1 and 25 characters");
        return false;
    }
    if(ui->lineEdit_Email->text().toStdString().length() < 1 || ui->lineEdit_Email->text().toStdString().length() > 25)
    {
        QMessageBox::warning(this, "Błąd", "Email must be between 1 and 25 characters");
        return false;
    }
    if(ui->lineEdit_Password->text().toStdString().length() < 8 || ui->lineEdit_Password->text().toStdString().length() > 16)
    {
        QMessageBox::warning(this, "Błąd", "Password must be between 8 and 16 characters");
        return false;
    }

    return true;
}


void AddTeacher::on_radioButton_Password_toggled(bool checked)
{
    if(checked)
    {
        ui->lineEdit_Password->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->lineEdit_Password->setEchoMode(QLineEdit::Password);
    }
}

