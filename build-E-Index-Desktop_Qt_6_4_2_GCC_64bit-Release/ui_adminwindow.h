/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *groupBox;
    QTableWidget *tableWidget_ShowAll;
    QPushButton *pushButton_ShowAllUsers;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox_2;
    QTableWidget *tableWidget_ShowBy;
    QSpinBox *spinBox_UserId;
    QPushButton *pushButton_SearchById;
    QPushButton *pushButton_SearchByClass;
    QPushButton *pushButton_SearchByRole;
    QSpinBox *spinBox_ClassNumber;
    QComboBox *comboBox_Roles;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_AddStudent;
    QPushButton *pushButton_AddTeacher;
    QPushButton *pushButton_EditUser;
    QPushButton *pushButton_DeleteUser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName("AdminWindow");
        AdminWindow->resize(1000, 800);
        AdminWindow->setMinimumSize(QSize(1000, 800));
        AdminWindow->setMaximumSize(QSize(1000, 800));
        centralwidget = new QWidget(AdminWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setMaximumSize(QSize(100, 16777215));
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        pushButton->setFont(font);

        verticalLayout->addWidget(pushButton);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QFont font1;
        font1.setPointSize(22);
        font1.setBold(true);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        tableWidget_ShowAll = new QTableWidget(groupBox);
        tableWidget_ShowAll->setObjectName("tableWidget_ShowAll");
        tableWidget_ShowAll->setGeometry(QRect(10, 40, 461, 231));
        pushButton_ShowAllUsers = new QPushButton(groupBox);
        pushButton_ShowAllUsers->setObjectName("pushButton_ShowAllUsers");
        pushButton_ShowAllUsers->setGeometry(QRect(15, 300, 141, 25));

        horizontalLayout_7->addWidget(groupBox);


        horizontalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        tableWidget_ShowBy = new QTableWidget(groupBox_2);
        tableWidget_ShowBy->setObjectName("tableWidget_ShowBy");
        tableWidget_ShowBy->setGeometry(QRect(10, 40, 461, 231));
        spinBox_UserId = new QSpinBox(groupBox_2);
        spinBox_UserId->setObjectName("spinBox_UserId");
        spinBox_UserId->setGeometry(QRect(50, 320, 44, 26));
        pushButton_SearchById = new QPushButton(groupBox_2);
        pushButton_SearchById->setObjectName("pushButton_SearchById");
        pushButton_SearchById->setGeometry(QRect(20, 280, 111, 25));
        pushButton_SearchByClass = new QPushButton(groupBox_2);
        pushButton_SearchByClass->setObjectName("pushButton_SearchByClass");
        pushButton_SearchByClass->setGeometry(QRect(170, 280, 111, 25));
        pushButton_SearchByRole = new QPushButton(groupBox_2);
        pushButton_SearchByRole->setObjectName("pushButton_SearchByRole");
        pushButton_SearchByRole->setGeometry(QRect(340, 280, 111, 25));
        spinBox_ClassNumber = new QSpinBox(groupBox_2);
        spinBox_ClassNumber->setObjectName("spinBox_ClassNumber");
        spinBox_ClassNumber->setGeometry(QRect(200, 320, 44, 26));
        spinBox_ClassNumber->setMaximum(6);
        comboBox_Roles = new QComboBox(groupBox_2);
        comboBox_Roles->setObjectName("comboBox_Roles");
        comboBox_Roles->setGeometry(QRect(320, 320, 150, 25));

        horizontalLayout_6->addWidget(groupBox_2);


        horizontalLayout_3->addLayout(horizontalLayout_6);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(50, -1, 50, -1);
        pushButton_AddStudent = new QPushButton(centralwidget);
        pushButton_AddStudent->setObjectName("pushButton_AddStudent");

        horizontalLayout_2->addWidget(pushButton_AddStudent);

        pushButton_AddTeacher = new QPushButton(centralwidget);
        pushButton_AddTeacher->setObjectName("pushButton_AddTeacher");

        horizontalLayout_2->addWidget(pushButton_AddTeacher);

        pushButton_EditUser = new QPushButton(centralwidget);
        pushButton_EditUser->setObjectName("pushButton_EditUser");

        horizontalLayout_2->addWidget(pushButton_EditUser);

        pushButton_DeleteUser = new QPushButton(centralwidget);
        pushButton_DeleteUser->setObjectName("pushButton_DeleteUser");

        horizontalLayout_2->addWidget(pushButton_DeleteUser);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 5);
        AdminWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 22));
        AdminWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminWindow);
        statusbar->setObjectName("statusbar");
        AdminWindow->setStatusBar(statusbar);

        retranslateUi(AdminWindow);

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminWindow)
    {
        AdminWindow->setWindowTitle(QCoreApplication::translate("AdminWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("AdminWindow", "Quit", nullptr));
        label->setText(QCoreApplication::translate("AdminWindow", "Admin Mode", nullptr));
        groupBox->setTitle(QString());
        pushButton_ShowAllUsers->setText(QCoreApplication::translate("AdminWindow", "Show All Users", nullptr));
        groupBox_2->setTitle(QString());
        pushButton_SearchById->setText(QCoreApplication::translate("AdminWindow", "Search by id", nullptr));
        pushButton_SearchByClass->setText(QCoreApplication::translate("AdminWindow", "Search by class", nullptr));
        pushButton_SearchByRole->setText(QCoreApplication::translate("AdminWindow", "Search by role", nullptr));
        pushButton_AddStudent->setText(QCoreApplication::translate("AdminWindow", "Add Student", nullptr));
        pushButton_AddTeacher->setText(QCoreApplication::translate("AdminWindow", "Add Teacher", nullptr));
        pushButton_EditUser->setText(QCoreApplication::translate("AdminWindow", "Edit User Data", nullptr));
        pushButton_DeleteUser->setText(QCoreApplication::translate("AdminWindow", "Delete User", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
