/********************************************************************************
** Form generated from reading UI file 'edituserdata.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITUSERDATA_H
#define UI_EDITUSERDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditUserData
{
public:
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_2;
    QLineEdit *lineEdit_Name;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_Surname;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_4;
    QLineEdit *lineEdit_Email;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QComboBox *comboBox_Role;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_7;
    QSpinBox *spinBox_ClassNumber;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_6;
    QLineEdit *lineEdit_Password;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton;

    void setupUi(QWidget *EditUserData)
    {
        if (EditUserData->objectName().isEmpty())
            EditUserData->setObjectName("EditUserData");
        EditUserData->resize(400, 800);
        EditUserData->setMinimumSize(QSize(400, 800));
        EditUserData->setMaximumSize(QSize(400, 800));
        verticalLayout_8 = new QVBoxLayout(EditUserData);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(EditUserData);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        verticalLayout_8->addLayout(verticalLayout);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(90, 20, -1, 20);
        label_2 = new QLabel(EditUserData);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(200, 16777215));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_2);

        lineEdit_Name = new QLineEdit(EditUserData);
        lineEdit_Name->setObjectName("lineEdit_Name");
        lineEdit_Name->setMaximumSize(QSize(200, 16777215));

        verticalLayout_6->addWidget(lineEdit_Name);


        verticalLayout_8->addLayout(verticalLayout_6);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(90, 20, -1, 20);
        label_3 = new QLabel(EditUserData);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(200, 16777215));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_3);

        lineEdit_Surname = new QLineEdit(EditUserData);
        lineEdit_Surname->setObjectName("lineEdit_Surname");
        lineEdit_Surname->setMaximumSize(QSize(200, 16777215));

        verticalLayout_2->addWidget(lineEdit_Surname);


        verticalLayout_8->addLayout(verticalLayout_2);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(90, 20, -1, 20);
        label_4 = new QLabel(EditUserData);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(200, 16777215));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_4);

        lineEdit_Email = new QLineEdit(EditUserData);
        lineEdit_Email->setObjectName("lineEdit_Email");
        lineEdit_Email->setMaximumSize(QSize(200, 16777215));

        verticalLayout_7->addWidget(lineEdit_Email);


        verticalLayout_8->addLayout(verticalLayout_7);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(90, 20, -1, 20);
        label_5 = new QLabel(EditUserData);
        label_5->setObjectName("label_5");
        label_5->setMaximumSize(QSize(200, 16777215));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_5);

        comboBox_Role = new QComboBox(EditUserData);
        comboBox_Role->setObjectName("comboBox_Role");
        comboBox_Role->setMaximumSize(QSize(200, 16777215));
        comboBox_Role->setMaxVisibleItems(2);
        comboBox_Role->setMaxCount(2);

        verticalLayout_3->addWidget(comboBox_Role);


        verticalLayout_8->addLayout(verticalLayout_3);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_9->setContentsMargins(90, 20, 0, 20);
        label_7 = new QLabel(EditUserData);
        label_7->setObjectName("label_7");
        label_7->setMaximumSize(QSize(200, 16777215));
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(label_7);

        spinBox_ClassNumber = new QSpinBox(EditUserData);
        spinBox_ClassNumber->setObjectName("spinBox_ClassNumber");
        spinBox_ClassNumber->setMaximumSize(QSize(200, 16777215));
        spinBox_ClassNumber->setMinimum(1);
        spinBox_ClassNumber->setMaximum(6);

        verticalLayout_9->addWidget(spinBox_ClassNumber);


        verticalLayout_8->addLayout(verticalLayout_9);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(90, 20, -1, 20);
        label_6 = new QLabel(EditUserData);
        label_6->setObjectName("label_6");
        label_6->setMaximumSize(QSize(200, 16777215));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_6);

        lineEdit_Password = new QLineEdit(EditUserData);
        lineEdit_Password->setObjectName("lineEdit_Password");
        lineEdit_Password->setMaximumSize(QSize(200, 16777215));

        verticalLayout_4->addWidget(lineEdit_Password);


        verticalLayout_8->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(90, 20, -1, 20);
        pushButton = new QPushButton(EditUserData);
        pushButton->setObjectName("pushButton");
        pushButton->setMaximumSize(QSize(200, 16777215));
        QFont font2;
        font2.setBold(true);
        pushButton->setFont(font2);

        verticalLayout_5->addWidget(pushButton);


        verticalLayout_8->addLayout(verticalLayout_5);


        retranslateUi(EditUserData);

        QMetaObject::connectSlotsByName(EditUserData);
    } // setupUi

    void retranslateUi(QWidget *EditUserData)
    {
        EditUserData->setWindowTitle(QCoreApplication::translate("EditUserData", "Form", nullptr));
        label->setText(QCoreApplication::translate("EditUserData", "Edit User Data", nullptr));
        label_2->setText(QCoreApplication::translate("EditUserData", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("EditUserData", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("EditUserData", "Email", nullptr));
        label_5->setText(QCoreApplication::translate("EditUserData", "Role", nullptr));
        label_7->setText(QCoreApplication::translate("EditUserData", "Class", nullptr));
        label_6->setText(QCoreApplication::translate("EditUserData", "Password", nullptr));
        pushButton->setText(QCoreApplication::translate("EditUserData", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditUserData: public Ui_EditUserData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITUSERDATA_H
