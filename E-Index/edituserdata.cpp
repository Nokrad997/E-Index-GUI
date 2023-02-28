#include "edituserdata.h"
#include "ui_edituserdata.h"

EditUserData::EditUserData(AdminRepository *_a, Person userData, QWidget *parent, Qt::WindowType type) :
    QWidget(parent, type),
    ui(new Ui::EditUserData)
{
    ui->setupUi(this);
    admin = _a;
    user = userData;

    QStringList list;
    list << "Student" << "Teacher";

    ui->comboBox_Role->addItems(list);

    if(user.getRole() == "Student")
        ui->comboBox_Role->setCurrentText("Student");
    else
        ui->comboBox_Role->setCurrentText("Teacher");

    ui->lineEdit_Email->setPlaceholderText(QString::fromStdString(user.getEmail()));
    ui->lineEdit_Name->setPlaceholderText(QString::fromStdString(user.getName()));
    ui->lineEdit_Surname->setPlaceholderText(QString::fromStdString(user.getSurname()));
    ui->lineEdit_Password->setPlaceholderText(QString::fromStdString(user.getPassword()));
    ui->spinBox_ClassNumber->setValue(user.getClassNumber());
}

EditUserData::~EditUserData()
{
    delete admin;
    delete ui;
}

void EditUserData::on_pushButton_clicked()
{
    int previousClassNumber = 0;
    bool wasStudent = false, classChanged = false;

    previousClassNumber = user.getClassNumber();

    if(user.getRole() == "Teacher" && ui->comboBox_Role->currentText().toStdString() == "Teacher")
    {
        QMessageBox::warning(this, "Edit", "Cant change from teacher to teacher");
        return;
    }

    if(ui->lineEdit_Email->text() != "")
    {
        user.setEmail(ui->lineEdit_Email->text().toStdString());
    }

    if(ui->lineEdit_Name->text() != "")
    {
        user.setName(ui->lineEdit_Name->text().toStdString());
    }

    if(ui->lineEdit_Surname->text() != "")
    {
        user.setSurname(ui->lineEdit_Surname->text().toStdString());
    }

    if(ui->lineEdit_Password->text() != "")
    {
        user.setPassword(ui->lineEdit_Password->text().toStdString());
    }

    if(ui->comboBox_Role->currentText().toStdString() == user.getRole() && user.getRole() == "Student")
    {
        wasStudent = true;
        user.setRole(ui->comboBox_Role->currentText().toStdString());
    }
    else if(ui->comboBox_Role->currentText().toStdString() != user.getRole() && user.getRole() == "Student")
    {
        wasStudent = true;
        user.setRole(ui->comboBox_Role->currentText().toStdString());
    }
    else if(ui->comboBox_Role->currentText().toStdString() != user.getRole() && user.getRole() == "Teacher")
    {
        wasStudent = false;
        user.setRole(ui->comboBox_Role->currentText().toStdString());
    }
    else if(ui->comboBox_Role->currentText().toStdString() == user.getRole() && user.getRole() == "Teacher")
    {
        wasStudent = false;
        user.setRole(ui->comboBox_Role->currentText().toStdString());
    }

    if(previousClassNumber != ui->spinBox_ClassNumber->value())
    {
        classChanged = true;
        user.setClassNumber(ui->spinBox_ClassNumber->value());
    }

    admin->editUser(user, previousClassNumber, wasStudent, classChanged);

    QMessageBox::information(this, "Edit", "User data changed");

    this->close();
}

