/********************************************************************************
** Form generated from reading UI file 'addteacher.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTEACHER_H
#define UI_ADDTEACHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddTeacher
{
public:
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_Name;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_Surname;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_Email;
    QLineEdit *lineEdit_Email;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEdit_Password;
    QRadioButton *radioButton_Password;
    QVBoxLayout *verticalLayout_6;
    QPushButton *pushButton;

    void setupUi(QWidget *AddTeacher)
    {
        if (AddTeacher->objectName().isEmpty())
            AddTeacher->setObjectName("AddTeacher");
        AddTeacher->resize(400, 800);
        AddTeacher->setMinimumSize(QSize(400, 800));
        AddTeacher->setMaximumSize(QSize(400, 800));
        verticalLayout_7 = new QVBoxLayout(AddTeacher);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_2 = new QLabel(AddTeacher);
        label_2->setObjectName("label_2");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);


        verticalLayout_7->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(90, 20, -1, 20);
        label = new QLabel(AddTeacher);
        label->setObjectName("label");
        label->setMaximumSize(QSize(200, 16777215));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        lineEdit_Name = new QLineEdit(AddTeacher);
        lineEdit_Name->setObjectName("lineEdit_Name");
        lineEdit_Name->setMaximumSize(QSize(200, 16777215));

        verticalLayout_2->addWidget(lineEdit_Name);


        verticalLayout_7->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(90, 20, -1, 20);
        label_3 = new QLabel(AddTeacher);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(200, 16777215));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        lineEdit_Surname = new QLineEdit(AddTeacher);
        lineEdit_Surname->setObjectName("lineEdit_Surname");
        lineEdit_Surname->setMaximumSize(QSize(200, 16777215));

        verticalLayout_3->addWidget(lineEdit_Surname);


        verticalLayout_7->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(90, 20, -1, 20);
        label_Email = new QLabel(AddTeacher);
        label_Email->setObjectName("label_Email");
        label_Email->setMaximumSize(QSize(200, 16777215));
        label_Email->setFont(font1);
        label_Email->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_Email);

        lineEdit_Email = new QLineEdit(AddTeacher);
        lineEdit_Email->setObjectName("lineEdit_Email");
        lineEdit_Email->setMaximumSize(QSize(200, 16777215));

        verticalLayout_4->addWidget(lineEdit_Email);


        verticalLayout_7->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(90, 20, -1, 20);
        label_5 = new QLabel(AddTeacher);
        label_5->setObjectName("label_5");
        label_5->setMaximumSize(QSize(200, 16777215));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_5);

        lineEdit_Password = new QLineEdit(AddTeacher);
        lineEdit_Password->setObjectName("lineEdit_Password");
        lineEdit_Password->setMaximumSize(QSize(200, 16777215));
        lineEdit_Password->setEchoMode(QLineEdit::Password);

        verticalLayout_5->addWidget(lineEdit_Password);

        radioButton_Password = new QRadioButton(AddTeacher);
        radioButton_Password->setObjectName("radioButton_Password");
        radioButton_Password->setMaximumSize(QSize(200, 16777215));

        verticalLayout_5->addWidget(radioButton_Password);


        verticalLayout_7->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(90, 20, -1, 20);
        pushButton = new QPushButton(AddTeacher);
        pushButton->setObjectName("pushButton");
        pushButton->setMaximumSize(QSize(200, 16777215));
        QFont font2;
        font2.setBold(true);
        pushButton->setFont(font2);

        verticalLayout_6->addWidget(pushButton);


        verticalLayout_7->addLayout(verticalLayout_6);


        retranslateUi(AddTeacher);

        QMetaObject::connectSlotsByName(AddTeacher);
    } // setupUi

    void retranslateUi(QWidget *AddTeacher)
    {
        AddTeacher->setWindowTitle(QCoreApplication::translate("AddTeacher", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("AddTeacher", "Add New Teacher", nullptr));
        label->setText(QCoreApplication::translate("AddTeacher", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("AddTeacher", "Surname", nullptr));
        label_Email->setText(QCoreApplication::translate("AddTeacher", "Email", nullptr));
        label_5->setText(QCoreApplication::translate("AddTeacher", "Password", nullptr));
        radioButton_Password->setText(QCoreApplication::translate("AddTeacher", "Show Password", nullptr));
        pushButton->setText(QCoreApplication::translate("AddTeacher", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddTeacher: public Ui_AddTeacher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTEACHER_H
