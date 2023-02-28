/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_Title;
    QGroupBox *groupBox_LoginRegister;
    QLabel *label_UserName;
    QLabel *label_Password;
    QLineEdit *lineEdit_UserName;
    QLineEdit *lineEdit_Password;
    QPushButton *pushButton_Login;
    QPushButton *pushButton_Register;
    QRadioButton *radioButton_ShowPassword;
    QPushButton *pushButton_Quit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_Title = new QLabel(centralwidget);
        label_Title->setObjectName("label_Title");
        label_Title->setGeometry(QRect(190, 50, 421, 141));
        QFont font;
        font.setPointSize(50);
        font.setBold(true);
        label_Title->setFont(font);
        label_Title->setAlignment(Qt::AlignCenter);
        groupBox_LoginRegister = new QGroupBox(centralwidget);
        groupBox_LoginRegister->setObjectName("groupBox_LoginRegister");
        groupBox_LoginRegister->setGeometry(QRect(200, 260, 401, 221));
        label_UserName = new QLabel(groupBox_LoginRegister);
        label_UserName->setObjectName("label_UserName");
        label_UserName->setGeometry(QRect(25, 10, 151, 51));
        QFont font1;
        font1.setPointSize(17);
        font1.setBold(true);
        label_UserName->setFont(font1);
        label_UserName->setAlignment(Qt::AlignCenter);
        label_Password = new QLabel(groupBox_LoginRegister);
        label_Password->setObjectName("label_Password");
        label_Password->setGeometry(QRect(25, 70, 151, 51));
        label_Password->setFont(font1);
        lineEdit_UserName = new QLineEdit(groupBox_LoginRegister);
        lineEdit_UserName->setObjectName("lineEdit_UserName");
        lineEdit_UserName->setGeometry(QRect(160, 15, 200, 40));
        QFont font2;
        font2.setPointSize(16);
        lineEdit_UserName->setFont(font2);
        lineEdit_Password = new QLineEdit(groupBox_LoginRegister);
        lineEdit_Password->setObjectName("lineEdit_Password");
        lineEdit_Password->setGeometry(QRect(160, 75, 200, 40));
        lineEdit_Password->setFont(font2);
        lineEdit_Password->setEchoMode(QLineEdit::Password);
        pushButton_Login = new QPushButton(groupBox_LoginRegister);
        pushButton_Login->setObjectName("pushButton_Login");
        pushButton_Login->setGeometry(QRect(210, 160, 110, 40));
        QFont font3;
        font3.setPointSize(13);
        font3.setBold(true);
        pushButton_Login->setFont(font3);
        pushButton_Register = new QPushButton(groupBox_LoginRegister);
        pushButton_Register->setObjectName("pushButton_Register");
        pushButton_Register->setGeometry(QRect(70, 160, 111, 41));
        pushButton_Register->setFont(font3);
        radioButton_ShowPassword = new QRadioButton(groupBox_LoginRegister);
        radioButton_ShowPassword->setObjectName("radioButton_ShowPassword");
        radioButton_ShowPassword->setGeometry(QRect(160, 120, 131, 23));
        pushButton_Quit = new QPushButton(centralwidget);
        pushButton_Quit->setObjectName("pushButton_Quit");
        pushButton_Quit->setGeometry(QRect(690, 10, 101, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_Title->setText(QCoreApplication::translate("MainWindow", "E-Index", nullptr));
        groupBox_LoginRegister->setTitle(QString());
        label_UserName->setText(QCoreApplication::translate("MainWindow", "Email:", nullptr));
        label_Password->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        pushButton_Login->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        pushButton_Register->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        radioButton_ShowPassword->setText(QCoreApplication::translate("MainWindow", "Show Password", nullptr));
        pushButton_Quit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
