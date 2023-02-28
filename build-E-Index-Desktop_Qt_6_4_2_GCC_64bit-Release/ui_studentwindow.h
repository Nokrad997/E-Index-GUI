/********************************************************************************
** Form generated from reading UI file 'studentwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTWINDOW_H
#define UI_STUDENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QComboBox *comboBox_Grades;
    QPushButton *pushButton_Grades;
    QTableWidget *tableWidget_Grades;
    QGroupBox *groupBox_2;
    QComboBox *comboBox_Absences;
    QPushButton *pushButton_Absences;
    QTableWidget *tableWidget_Absences;
    QCalendarWidget *calendarWidget;
    QGroupBox *groupBox_3;
    QTableWidget *tableWidget_Average;
    QPushButton *pushButton_CalculateAverage;
    QLabel *label;
    QLabel *label_Name;
    QLabel *label_Surname;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StudentWindow)
    {
        if (StudentWindow->objectName().isEmpty())
            StudentWindow->setObjectName("StudentWindow");
        StudentWindow->resize(1150, 600);
        StudentWindow->setMinimumSize(QSize(1150, 600));
        StudentWindow->setMaximumSize(QSize(1150, 600));
        centralwidget = new QWidget(StudentWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 260, 361, 281));
        QFont font;
        font.setBold(true);
        groupBox->setFont(font);
        comboBox_Grades = new QComboBox(groupBox);
        comboBox_Grades->setObjectName("comboBox_Grades");
        comboBox_Grades->setGeometry(QRect(150, 30, 200, 25));
        pushButton_Grades = new QPushButton(groupBox);
        pushButton_Grades->setObjectName("pushButton_Grades");
        pushButton_Grades->setGeometry(QRect(20, 30, 100, 25));
        tableWidget_Grades = new QTableWidget(groupBox);
        tableWidget_Grades->setObjectName("tableWidget_Grades");
        tableWidget_Grades->setGeometry(QRect(10, 70, 341, 201));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(390, 260, 361, 281));
        groupBox_2->setFont(font);
        comboBox_Absences = new QComboBox(groupBox_2);
        comboBox_Absences->setObjectName("comboBox_Absences");
        comboBox_Absences->setGeometry(QRect(150, 30, 200, 25));
        pushButton_Absences = new QPushButton(groupBox_2);
        pushButton_Absences->setObjectName("pushButton_Absences");
        pushButton_Absences->setGeometry(QRect(20, 30, 100, 25));
        tableWidget_Absences = new QTableWidget(groupBox_2);
        tableWidget_Absences->setObjectName("tableWidget_Absences");
        tableWidget_Absences->setGeometry(QRect(10, 70, 341, 201));
        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(390, 0, 741, 251));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(770, 260, 361, 281));
        groupBox_3->setFont(font);
        tableWidget_Average = new QTableWidget(groupBox_3);
        tableWidget_Average->setObjectName("tableWidget_Average");
        tableWidget_Average->setGeometry(QRect(10, 70, 341, 201));
        pushButton_CalculateAverage = new QPushButton(groupBox_3);
        pushButton_CalculateAverage->setObjectName("pushButton_CalculateAverage");
        pushButton_CalculateAverage->setGeometry(QRect(10, 30, 100, 25));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 50, 251, 81));
        QFont font1;
        font1.setPointSize(25);
        font1.setBold(true);
        label->setFont(font1);
        label_Name = new QLabel(centralwidget);
        label_Name->setObjectName("label_Name");
        label_Name->setGeometry(QRect(10, 120, 251, 81));
        label_Name->setFont(font1);
        label_Surname = new QLabel(centralwidget);
        label_Surname->setObjectName("label_Surname");
        label_Surname->setGeometry(QRect(10, 180, 251, 81));
        label_Surname->setFont(font1);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 10, 111, 31));
        QFont font2;
        font2.setPointSize(13);
        font2.setBold(true);
        pushButton->setFont(font2);
        StudentWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StudentWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1150, 22));
        StudentWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(StudentWindow);
        statusbar->setObjectName("statusbar");
        StudentWindow->setStatusBar(statusbar);

        retranslateUi(StudentWindow);

        QMetaObject::connectSlotsByName(StudentWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StudentWindow)
    {
        StudentWindow->setWindowTitle(QCoreApplication::translate("StudentWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("StudentWindow", "Show Grades", nullptr));
        pushButton_Grades->setText(QCoreApplication::translate("StudentWindow", "Show", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("StudentWindow", "Show Absences", nullptr));
        pushButton_Absences->setText(QCoreApplication::translate("StudentWindow", "Show", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("StudentWindow", "Calculate Average from every subject", nullptr));
        pushButton_CalculateAverage->setText(QCoreApplication::translate("StudentWindow", "Calculate", nullptr));
        label->setText(QCoreApplication::translate("StudentWindow", "Welcome", nullptr));
        label_Name->setText(QCoreApplication::translate("StudentWindow", "Welcome", nullptr));
        label_Surname->setText(QCoreApplication::translate("StudentWindow", "Welcome", nullptr));
        pushButton->setText(QCoreApplication::translate("StudentWindow", "Logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentWindow: public Ui_StudentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTWINDOW_H
