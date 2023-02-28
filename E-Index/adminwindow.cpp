#include "adminwindow.h"
#include "ui_adminwindow.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    admin = new Admin();

    QStringList list;
    list << QString::fromStdString("Student") << QString::fromStdString("Teacher");

    ui->comboBox_Roles->addItems(list);

   // setWindowFlag(Qt::WindowCloseButtonHint, false);
}

AdminWindow::~AdminWindow()
{
    delete admin;
    delete addT;
    delete addS;
    delete edit;
    delete ui;
}

void AdminWindow::on_pushButton_ShowAllUsers_clicked()
{
    vector<Person> students;
    students = admin->getAllUsers();
    if(students.size() != 0)
    {
        ui->tableWidget_ShowAll->setRowCount(students.size());
        ui->tableWidget_ShowAll->setColumnCount(6);

        QStringList headers;
        headers << "Id" << "Name" << "Surname" << "Email" << "Role" << "Password";
        ui->tableWidget_ShowAll->setHorizontalHeaderLabels(headers);

        for(int i = 0; i < students.size(); i++)
        {
            ui->tableWidget_ShowAll->setItem(i, 0, new QTableWidgetItem(QString::number(students[i].getId())));
            ui->tableWidget_ShowAll->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(students[i].getName())));
            ui->tableWidget_ShowAll->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(students[i].getSurname())));
            ui->tableWidget_ShowAll->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(students[i].getEmail())));
            ui->tableWidget_ShowAll->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(students[i].getRole())));
            ui->tableWidget_ShowAll->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(students[i].getRole())));
        }
        ui->tableWidget_ShowAll->sortByColumn(0, Qt::AscendingOrder);
    }
}


void AdminWindow::on_pushButton_SearchById_clicked()
{
    int id = ui->spinBox_UserId->value();

    vector<Person> students;
    students = admin->getAllUsers();
    bool found = false;

    ui->tableWidget_ShowBy->setRowCount(1);
    ui->tableWidget_ShowBy->setColumnCount(5);

    QStringList headers;
    headers << "Id" << "Name" << "Surname" << "Email" << "Role";
    ui->tableWidget_ShowBy->setHorizontalHeaderLabels(headers);

    for(int i = 0; i < students.size(); i++)
    {
        if(students[i].getId() == id)
        {
            found =true;

            ui->tableWidget_ShowBy->setItem(0, 0, new QTableWidgetItem(QString::number(students[i].getId())));
            ui->tableWidget_ShowBy->setItem(0, 1, new QTableWidgetItem(QString::fromStdString(students[i].getName())));
            ui->tableWidget_ShowBy->setItem(0, 2, new QTableWidgetItem(QString::fromStdString(students[i].getSurname())));
            ui->tableWidget_ShowBy->setItem(0, 3, new QTableWidgetItem(QString::fromStdString(students[i].getEmail())));
            ui->tableWidget_ShowBy->setItem(0, 4, new QTableWidgetItem(QString::fromStdString(students[i].getRole())));

            break;
        }
    }

    if(!found)
    {
        QMessageBox::warning(this, "SearchBy", "Couldnt find user with given id");
    }
}


void AdminWindow::on_pushButton_SearchByClass_clicked()
{
    int classNumber = ui->spinBox_ClassNumber->value();

    vector<vector<string>> students;
    students = admin->getAllUsersFromClass(classNumber);

    ui->tableWidget_ShowBy->setRowCount(students.size());
    ui->tableWidget_ShowBy->setColumnCount(3);

    QStringList headers;
    headers << "Id" << "Name" << "Surname";
    ui->tableWidget_ShowBy->setHorizontalHeaderLabels(headers);

    try
    {
        if(students.size() == 0)
        {
            throw runtime_error("This class has no students yet");
        }

        for(int i = 0; i < students.size(); i++)
        {
            ui->tableWidget_ShowBy->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(students[i][0])));
            ui->tableWidget_ShowBy->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(students[i][1])));
            ui->tableWidget_ShowBy->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(students[i][2])));
        }
        ui->tableWidget_ShowBy->sortByColumn(1, Qt::DescendingOrder);
    }
    catch(exception &e)
    {
        QMessageBox::warning(this, "SearchBy", e.what());
        return;
    }
}


void AdminWindow::on_pushButton_SearchByRole_clicked()
{
    string role = ui->comboBox_Roles->currentText().toStdString();
    bool found = false;
    vector<Person> students;
    students = admin->getAllUsers();

    students.erase(remove_if(students.begin(), students.end(), [role](Person &person)
                            { return person.getRole() != role; }),
                    students.end());

    ui->tableWidget_ShowBy->setRowCount(students.size());
    ui->tableWidget_ShowBy->setColumnCount(5);

    QStringList headers;
    headers << "Id" << "Name" << "Surname" << "Email" << "Role";
    ui->tableWidget_ShowBy->setHorizontalHeaderLabels(headers);

    try
    {
        for(int i = 0; i < students.size(); i++)
        {
            if(students[i].getRole() == role)
            {
                found = true;

                ui->tableWidget_ShowBy->setItem(i, 0, new QTableWidgetItem(QString::number(students[i].getId())));
                ui->tableWidget_ShowBy->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(students[i].getName())));
                ui->tableWidget_ShowBy->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(students[i].getSurname())));
                ui->tableWidget_ShowBy->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(students[i].getEmail())));
                ui->tableWidget_ShowBy->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(students[i].getRole())));
            }
        }
        if(!found)
        {
            throw runtime_error("There are no users with given role");
        }
    }
    catch(exception &e)
    {
        QMessageBox::warning(this, "SearchBy", e.what());
        return;
    }
}


void AdminWindow::on_pushButton_AddStudent_clicked()
{
    addS = new AddStudent(this, Qt::Window);
    addS->show();
}


void AdminWindow::on_pushButton_AddTeacher_clicked()
{
    addT = new AddTeacher(this, Qt::Window);
    addT->show();
}


void AdminWindow::on_pushButton_EditUser_clicked()
{
    int id = QInputDialog::getInt(this, tr("Enter User id"), tr("id:"));
    bool found = false;

    vector<Person> users;
    users = admin->getAllUsers();
    int idx = 0;

    for(int i = 0; i < users.size(); i++)
    {
        if(users[i].getId() == id)
        {
            idx = i;
            found = true;
            break;
        }
    }

    if(!found)
    {
        QMessageBox::warning(this, "Edit", "Couldnt find user with given id");
        return ;
    }

    edit = new EditUserData(admin, users[idx], this, Qt::Window);
    edit->show();
}


void AdminWindow::on_pushButton_DeleteUser_clicked()
{
    int id = QInputDialog::getInt(this, tr("Enter User id"), tr("id:"));
    bool found = false;

    vector<Person> users;
    users = admin->getAllUsers();

    for(int i = 0; i < users.size(); i++)
    {
        if(users[i].getId() == id)
        {
            found = true;
            break;
        }
    }

    if(!found)
    {
        QMessageBox::warning(this, "Delete", "Couldnt find user with given id");
        return ;
    }

    admin->deleteUser(id);

    QMessageBox::information(this, "DeleteUser", "User deletion complete");
}


void AdminWindow::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Quit", "Are you sure you wont to quit?", QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes)
    {
        QApplication::quit();
    }
}

