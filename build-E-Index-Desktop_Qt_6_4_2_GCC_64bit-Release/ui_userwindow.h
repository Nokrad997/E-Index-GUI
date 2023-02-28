/********************************************************************************
** Form generated from reading UI file 'userwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWINDOW_H
#define UI_USERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QTableWidget *tableWidget_ClassMembers;
    QPushButton *pushButton_searchForMembers;
    QSpinBox *spinBox_ClassNumber;
    QLabel *label_Welcome;
    QGroupBox *groupBox_Buttons;
    QPushButton *pushButton_AddNewTest;
    QPushButton *pushButton_AddNewGrade;
    QPushButton *pushButton_AddAbsence;
    QPushButton *pushButton;
    QLabel *label_Welcome_2;
    QLabel *label_Welcome_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UserWindow)
    {
        if (UserWindow->objectName().isEmpty())
            UserWindow->setObjectName("UserWindow");
        UserWindow->resize(800, 600);
        UserWindow->setMinimumSize(QSize(800, 600));
        UserWindow->setMaximumSize(QSize(800, 600));
        centralwidget = new QWidget(UserWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 240, 451, 311));
        tableWidget_ClassMembers = new QTableWidget(groupBox);
        tableWidget_ClassMembers->setObjectName("tableWidget_ClassMembers");
        tableWidget_ClassMembers->setGeometry(QRect(10, 50, 431, 251));
        pushButton_searchForMembers = new QPushButton(groupBox);
        pushButton_searchForMembers->setObjectName("pushButton_searchForMembers");
        pushButton_searchForMembers->setGeometry(QRect(310, 10, 89, 25));
        spinBox_ClassNumber = new QSpinBox(groupBox);
        spinBox_ClassNumber->setObjectName("spinBox_ClassNumber");
        spinBox_ClassNumber->setGeometry(QRect(10, 10, 44, 26));
        spinBox_ClassNumber->setMinimum(1);
        spinBox_ClassNumber->setMaximum(6);
        label_Welcome = new QLabel(centralwidget);
        label_Welcome->setObjectName("label_Welcome");
        label_Welcome->setGeometry(QRect(10, 10, 191, 111));
        QFont font;
        font.setPointSize(30);
        label_Welcome->setFont(font);
        groupBox_Buttons = new QGroupBox(centralwidget);
        groupBox_Buttons->setObjectName("groupBox_Buttons");
        groupBox_Buttons->setGeometry(QRect(470, 0, 321, 551));
        pushButton_AddNewTest = new QPushButton(groupBox_Buttons);
        pushButton_AddNewTest->setObjectName("pushButton_AddNewTest");
        pushButton_AddNewTest->setGeometry(QRect(100, 90, 131, 25));
        pushButton_AddNewGrade = new QPushButton(groupBox_Buttons);
        pushButton_AddNewGrade->setObjectName("pushButton_AddNewGrade");
        pushButton_AddNewGrade->setGeometry(QRect(100, 220, 131, 25));
        pushButton_AddAbsence = new QPushButton(groupBox_Buttons);
        pushButton_AddAbsence->setObjectName("pushButton_AddAbsence");
        pushButton_AddAbsence->setGeometry(QRect(100, 360, 131, 25));
        pushButton = new QPushButton(groupBox_Buttons);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(220, 10, 89, 25));
        label_Welcome_2 = new QLabel(centralwidget);
        label_Welcome_2->setObjectName("label_Welcome_2");
        label_Welcome_2->setGeometry(QRect(10, 90, 191, 111));
        label_Welcome_2->setFont(font);
        label_Welcome_3 = new QLabel(centralwidget);
        label_Welcome_3->setObjectName("label_Welcome_3");
        label_Welcome_3->setGeometry(QRect(240, 90, 191, 111));
        label_Welcome_3->setFont(font);
        UserWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UserWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        UserWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(UserWindow);
        statusbar->setObjectName("statusbar");
        UserWindow->setStatusBar(statusbar);

        retranslateUi(UserWindow);

        QMetaObject::connectSlotsByName(UserWindow);
    } // setupUi

    void retranslateUi(QMainWindow *UserWindow)
    {
        UserWindow->setWindowTitle(QCoreApplication::translate("UserWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        pushButton_searchForMembers->setText(QCoreApplication::translate("UserWindow", "Search", nullptr));
        label_Welcome->setText(QCoreApplication::translate("UserWindow", "Welcome", nullptr));
        groupBox_Buttons->setTitle(QString());
        pushButton_AddNewTest->setText(QCoreApplication::translate("UserWindow", "Add new test", nullptr));
        pushButton_AddNewGrade->setText(QCoreApplication::translate("UserWindow", "Add new grade", nullptr));
        pushButton_AddAbsence->setText(QCoreApplication::translate("UserWindow", "Add new absence", nullptr));
        pushButton->setText(QCoreApplication::translate("UserWindow", "Logout", nullptr));
        label_Welcome_2->setText(QCoreApplication::translate("UserWindow", "Welcome", nullptr));
        label_Welcome_3->setText(QCoreApplication::translate("UserWindow", "Welcome", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWindow: public Ui_UserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
