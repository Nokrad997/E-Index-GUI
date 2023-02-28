/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

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

class Ui_Registration
{
public:
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_Name;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_Surname;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEdit_Email;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_ClassNumber;
    QSpinBox *spinBox_ClassNumber;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QLineEdit *lineEdit_Password;
    QRadioButton *radioButton;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton;

    void setupUi(QWidget *Registration)
    {
        if (Registration->objectName().isEmpty())
            Registration->setObjectName("Registration");
        Registration->resize(400, 700);
        Registration->setMinimumSize(QSize(400, 700));
        Registration->setMaximumSize(QSize(400, 700));
        verticalLayout_7 = new QVBoxLayout(Registration);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label = new QLabel(Registration);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label);


        verticalLayout_7->addLayout(verticalLayout_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(90, 20, -1, 20);
        label_2 = new QLabel(Registration);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(200, 16777215));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        lineEdit_Name = new QLineEdit(Registration);
        lineEdit_Name->setObjectName("lineEdit_Name");
        lineEdit_Name->setMaximumSize(QSize(200, 16777215));

        verticalLayout->addWidget(lineEdit_Name);


        verticalLayout_7->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(90, 20, -1, 20);
        label_3 = new QLabel(Registration);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(200, 16777215));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_3);

        lineEdit_Surname = new QLineEdit(Registration);
        lineEdit_Surname->setObjectName("lineEdit_Surname");
        lineEdit_Surname->setMaximumSize(QSize(200, 16777215));

        verticalLayout_2->addWidget(lineEdit_Surname);


        verticalLayout_7->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(90, 20, -1, 20);
        label_4 = new QLabel(Registration);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(200, 16777215));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_4);

        lineEdit_Email = new QLineEdit(Registration);
        lineEdit_Email->setObjectName("lineEdit_Email");
        lineEdit_Email->setMinimumSize(QSize(200, 0));
        lineEdit_Email->setMaximumSize(QSize(200, 16777215));

        verticalLayout_3->addWidget(lineEdit_Email);


        verticalLayout_7->addLayout(verticalLayout_3);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(115, 20, 0, 20);
        label_ClassNumber = new QLabel(Registration);
        label_ClassNumber->setObjectName("label_ClassNumber");
        label_ClassNumber->setMaximumSize(QSize(150, 16777215));
        label_ClassNumber->setFont(font1);
        label_ClassNumber->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_ClassNumber);

        spinBox_ClassNumber = new QSpinBox(Registration);
        spinBox_ClassNumber->setObjectName("spinBox_ClassNumber");
        spinBox_ClassNumber->setMaximumSize(QSize(150, 16777215));
        spinBox_ClassNumber->setMaximum(6);

        verticalLayout_8->addWidget(spinBox_ClassNumber);


        verticalLayout_7->addLayout(verticalLayout_8);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(90, 20, -1, 20);
        label_5 = new QLabel(Registration);
        label_5->setObjectName("label_5");
        label_5->setMaximumSize(QSize(200, 16777215));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_5);

        lineEdit_Password = new QLineEdit(Registration);
        lineEdit_Password->setObjectName("lineEdit_Password");
        lineEdit_Password->setMaximumSize(QSize(200, 16777215));
        lineEdit_Password->setEchoMode(QLineEdit::Password);

        verticalLayout_4->addWidget(lineEdit_Password);

        radioButton = new QRadioButton(Registration);
        radioButton->setObjectName("radioButton");
        radioButton->setMaximumSize(QSize(150, 16777215));
        QFont font2;
        font2.setPointSize(11);
        radioButton->setFont(font2);
        radioButton->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_4->addWidget(radioButton);


        verticalLayout_7->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(90, 20, -1, 20);
        pushButton = new QPushButton(Registration);
        pushButton->setObjectName("pushButton");
        pushButton->setMaximumSize(QSize(200, 16777215));
        QFont font3;
        font3.setBold(true);
        pushButton->setFont(font3);

        verticalLayout_5->addWidget(pushButton);


        verticalLayout_7->addLayout(verticalLayout_5);

        verticalLayout_7->setStretch(0, 2);
        verticalLayout_7->setStretch(1, 1);
        verticalLayout_7->setStretch(2, 1);
        verticalLayout_7->setStretch(3, 1);
        verticalLayout_7->setStretch(4, 1);
        verticalLayout_7->setStretch(5, 1);
        verticalLayout_7->setStretch(6, 3);

        retranslateUi(Registration);

        QMetaObject::connectSlotsByName(Registration);
    } // setupUi

    void retranslateUi(QWidget *Registration)
    {
        Registration->setWindowTitle(QCoreApplication::translate("Registration", "Form", nullptr));
        label->setText(QCoreApplication::translate("Registration", "Registration", nullptr));
        label_2->setText(QCoreApplication::translate("Registration", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("Registration", "Surname", nullptr));
        label_4->setText(QCoreApplication::translate("Registration", "Email", nullptr));
        label_ClassNumber->setText(QCoreApplication::translate("Registration", "ClassNumber", nullptr));
        label_5->setText(QCoreApplication::translate("Registration", "Password", nullptr));
        radioButton->setText(QCoreApplication::translate("Registration", "Show password", nullptr));
        pushButton->setText(QCoreApplication::translate("Registration", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Registration: public Ui_Registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
