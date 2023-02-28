#include "mainwindow.h"
#include "ui_mainwindow.h"

vector<Person> users;

void getUsers();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlag(Qt::WindowCloseButtonHint, false);
}

MainWindow::~MainWindow()
{
    delete studentUI;
    delete userUI;
    delete regUI;
    delete ui;
}

template <class T, class T2>
void copyData(T *p1, T2 *p2)
{
    p1->setId(p2->getId());
    p1->setName(p2->getName());
    p1->setSurname(p2->getSurname());
    p1->setClassNumber(p2->getClassNumber());
    p1->setEmail(p2->getEmail());
    p1->setRole(p2->getRole());
    p1->setPassword(p2->getPassword());
}

void MainWindow::on_pushButton_Register_clicked()
{
    Person *p1 = new Person();
    regUI = new Registration(p1, this, Qt::Window);
    regUI->show();

}


void MainWindow::on_pushButton_Login_clicked()
{
    getUsers();
    QString userName = ui->lineEdit_UserName->text();
    QString password = ui->lineEdit_Password->text();
    bool loginFailed = true;
    std::string email, pass;

    if(ui->lineEdit_UserName->text() == "" || ui->lineEdit_Password->text() == "")
    {
        QMessageBox::warning(this, "Login", "both fields must be filled");
        return ;
    }

    for(int i = 0; i < users.size(); i++)
    {
        email = users[i].getEmail();
        pass = users[i].getPassword();

        if(userName.toStdString() == email && password.toStdString() == pass)
        {
            loginFailed = false;
            QMessageBox::information(this, "Login", "Login succesful");
            if(users[i].getRole() == "Teacher")
            {
                TeacherRepository *t1 = new Teacher();

                copyData(t1, &users[i]);

                close();
                userUI = new UserWindow(t1, this);
                userUI->show();
                break;
            }
            else if(users[i].getRole() == "Student")
            {
                StudentRepository *s1 = new Student();
                copyData(s1, &users[i]);

                this->close();
                studentUI = new StudentWindow(s1, this);
                studentUI->show();
                break;
            }
        }
    }

    if(loginFailed)
    {
        QMessageBox::warning(this, "Login", "Login failed");
    }

    ui->lineEdit_UserName->clear();
    ui->lineEdit_Password->clear();
}


void MainWindow::on_radioButton_ShowPassword_toggled(bool checked)
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


void MainWindow::on_pushButton_Quit_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Quit", "Are you sure you wont to quit?", QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes)
    {
        QApplication::quit();
    }
}

void getUsers()
{
    users.clear();
    string path = "users.bin";
    ifstream userFile(path, ios::binary);

    try
    {
        userFile.seekg(0, userFile.end);
        int length = userFile.tellg();
        userFile.seekg(0, userFile.beg);

        if(userFile.good() && length > 0 && userFile.is_open())
        {
            Person p1;
            while(userFile)
            {
                p1.read(userFile);
                users.push_back(p1);
            }
        }
        else
        {
            throw runtime_error("couldnt open a file");
        }

        users.pop_back();
        userFile.close();
    }
    catch(std::ios_base::failure &e)
    {
        std::cout << "error opening file: " << e.what() << std::endl;
    }
}


