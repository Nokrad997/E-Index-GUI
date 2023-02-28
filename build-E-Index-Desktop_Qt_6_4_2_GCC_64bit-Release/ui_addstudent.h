/********************************************************************************
** Form generated from reading UI file 'addstudent.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTUDENT_H
#define UI_ADDSTUDENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddStudent
{
public:
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_Name;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_Surname;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_Email;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QSpinBox *spinBox_ClassNumber;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_Password;
    QLineEdit *lineEdit_Password;
    QRadioButton *radioButton;
    QVBoxLayout *verticalLayout_7;
    QPushButton *pushButton;

    void setupUi(QWidget *AddStudent)
    {
        if (AddStudent->objectName().isEmpty())
            AddStudent->setObjectName("AddStudent");
        AddStudent->resize(400, 800);
        AddStudent->setMinimumSize(QSize(400, 800));
        AddStudent->setMaximumSize(QSize(400, 800));
        verticalLayout_8 = new QVBoxLayout(AddStudent);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(AddStudent);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        verticalLayout_8->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(90, 20, -1, 20);
        label_2 = new QLabel(AddStudent);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(200, 16777215));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        lineEdit_Name = new QLineEdit(AddStudent);
        lineEdit_Name->setObjectName("lineEdit_Name");
        lineEdit_Name->setMaximumSize(QSize(200, 16777215));

        verticalLayout_2->addWidget(lineEdit_Name);


        verticalLayout_8->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(90, 20, -1, 20);
        label_3 = new QLabel(AddStudent);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(200, 16777215));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        lineEdit_Surname = new QLineEdit(AddStudent);
        lineEdit_Surname->setObjectName("lineEdit_Surname");
        lineEdit_Surname->setMaximumSize(QSize(200, 16777215));

        verticalLayout_3->addWidget(lineEdit_Surname);


        verticalLayout_8->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(90, 20, -1, 20);
        label_4 = new QLabel(AddStudent);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(200, 16777215));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_4);

        lineEdit_Email = new QLineEdit(AddStudent);
        lineEdit_Email->setObjectName("lineEdit_Email");
        lineEdit_Email->setMaximumSize(QSize(200, 16777215));
        QFont font2;
        font2.setBold(false);
        lineEdit_Email->setFont(font2);

        verticalLayout_4->addWidget(lineEdit_Email);


        verticalLayout_8->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(90, 20, -1, 20);
        label_5 = new QLabel(AddStudent);
        label_5->setObjectName("label_5");
        label_5->setMaximumSize(QSize(200, 16777215));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_5);

        spinBox_ClassNumber = new QSpinBox(AddStudent);
        spinBox_ClassNumber->setObjectName("spinBox_ClassNumber");
        spinBox_ClassNumber->setMaximumSize(QSize(200, 16777215));
        spinBox_ClassNumber->setMinimum(1);
        spinBox_ClassNumber->setMaximum(6);

        verticalLayout_5->addWidget(spinBox_ClassNumber);


        verticalLayout_8->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(90, 20, -1, 20);
        label_Password = new QLabel(AddStudent);
        label_Password->setObjectName("label_Password");
        label_Password->setMaximumSize(QSize(200, 16777215));
        label_Password->setFont(font1);
        label_Password->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_Password);

        lineEdit_Password = new QLineEdit(AddStudent);
        lineEdit_Password->setObjectName("lineEdit_Password");
        lineEdit_Password->setMaximumSize(QSize(200, 16777215));
        lineEdit_Password->setEchoMode(QLineEdit::Password);

        verticalLayout_6->addWidget(lineEdit_Password);

        radioButton = new QRadioButton(AddStudent);
        radioButton->setObjectName("radioButton");
        QFont font3;
        font3.setBold(true);
        radioButton->setFont(font3);

        verticalLayout_6->addWidget(radioButton);


        verticalLayout_8->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(90, 20, -1, 20);
        pushButton = new QPushButton(AddStudent);
        pushButton->setObjectName("pushButton");
        pushButton->setMaximumSize(QSize(200, 16777215));
        pushButton->setFont(font3);

        verticalLayout_7->addWidget(pushButton);


        verticalLayout_8->addLayout(verticalLayout_7);


        retranslateUi(AddStudent);

        QMetaObject::connectSlotsByName(AddStudent);
    } // setupUi

    void retranslateUi(QWidget *AddStudent)
    {
        AddStudent->setWindowTitle(QCoreApplication::translate("AddStudent", "Form", nullptr));
        label->setText(QCoreApplication::translate("AddStudent", "Add Student", nullptr));
        label_2->setText(QCoreApplication::translate("AddStudent", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("AddStudent", "Surname", nullptr));
        label_4->setText(QCoreApplication::translate("AddStudent", "Email", nullptr));
        label_5->setText(QCoreApplication::translate("AddStudent", "Class ", nullptr));
        label_Password->setText(QCoreApplication::translate("AddStudent", "Password", nullptr));
        radioButton->setText(QCoreApplication::translate("AddStudent", "Show Password", nullptr));
        pushButton->setText(QCoreApplication::translate("AddStudent", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddStudent: public Ui_AddStudent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTUDENT_H
