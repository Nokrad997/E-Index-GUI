#include "mainwindow.h"
#include "adminwindow.h"
#include <QApplication>

bool checkIfAdmin(int argc, char *argv[]);

int main(int argc, char *argv[])
{

    if(checkIfAdmin(argc, argv))
    {
        QApplication a(argc, argv);

        AdminWindow admin;
        admin.show();

        return a.exec();
    }
    else
    {
        QApplication a(argc, argv);

        MainWindow w;
        w.show();

        return a.exec();
    }
}

bool checkIfAdmin(int argc, char *argv[])
{
    for(int i = 0; i < argc; i++)
    {
        std::cout << argv[i] << std::endl;
        if(QString(argv[i]) == "admin")
        {
            return true;
        }
    }
    return false;
}
