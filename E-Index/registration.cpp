#include "registration.h"
#include "ui_registration.h"

Registration::Registration(Person *_p, QWidget *parent, Qt::WindowType type ) :
    QWidget(parent, type),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    person = _p;
}

Registration::~Registration()
{
    delete person;
    delete ui;
}

void Registration::on_radioButton_toggled(bool checked)
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


void Registration::on_pushButton_clicked()
{
    if(ui->lineEdit_Email->text() == "" || ui->lineEdit_Name->text() == ""
            || ui->lineEdit_Password->text() == "" || ui->lineEdit_Surname->text() == ""
            || ui->spinBox_ClassNumber->value() == 0)
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
    p1.setRole("Student");
    p1.setClassNumber(ui->spinBox_ClassNumber->value());
    p1.setEmail(ui->lineEdit_Email->text().toStdString());
    p1.setPassword(ui->lineEdit_Password->text().toStdString());

    ofstream file2("users.bin", ios::binary | ios::app);
    string classPath = to_string(ui->spinBox_ClassNumber->value()) + "-class" + ".bin";
    ofstream file3(classPath, ios::binary | ios::app);

    try
    {
        p1.write(file2);
        file2.close();
        p1.writeToClass(file3);
        file3.close();
    }
    catch(std::exception &e)
    {
        QMessageBox::warning(this, "Błąd", e.what());
        return ;
    }

    QMessageBox::information(this, "Registration", "Registration succesful");
    this->close();
}

bool Registration::checkData()
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
    if(ui->spinBox_ClassNumber->value() == 0)
    {
        QMessageBox::warning(this, "Błąd", "You need to choose class number");
        return false;
    }

    return true;
}
