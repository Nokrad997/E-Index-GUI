#include "deleteuser.h"
#include "ui_deleteuser.h"

DeleteUser::DeleteUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeleteUser)
{
    ui->setupUi(this);
}

DeleteUser::~DeleteUser()
{
    delete ui;
}
