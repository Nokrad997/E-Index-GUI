/********************************************************************************
** Form generated from reading UI file 'addtest.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTEST_H
#define UI_ADDTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddTest
{
public:
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QSpinBox *spinBox_ClassNumber;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QDateEdit *dateEdit_TestDate;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_5;
    QLineEdit *lineEdit_Topic;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QComboBox *comboBox_Subject;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_Submit;

    void setupUi(QWidget *AddTest)
    {
        if (AddTest->objectName().isEmpty())
            AddTest->setObjectName("AddTest");
        AddTest->resize(400, 600);
        AddTest->setMinimumSize(QSize(400, 600));
        AddTest->setMaximumSize(QSize(400, 600));
        verticalLayout_6 = new QVBoxLayout(AddTest);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label = new QLabel(AddTest);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label);


        verticalLayout_6->addLayout(verticalLayout_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(90, 20, -1, 20);
        label_2 = new QLabel(AddTest);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(200, 16777215));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        spinBox_ClassNumber = new QSpinBox(AddTest);
        spinBox_ClassNumber->setObjectName("spinBox_ClassNumber");
        spinBox_ClassNumber->setMaximumSize(QSize(200, 16777215));
        spinBox_ClassNumber->setMaximum(6);

        verticalLayout->addWidget(spinBox_ClassNumber);


        verticalLayout_6->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(90, 20, -1, 20);
        label_3 = new QLabel(AddTest);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(200, 16777215));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_3);

        dateEdit_TestDate = new QDateEdit(AddTest);
        dateEdit_TestDate->setObjectName("dateEdit_TestDate");
        dateEdit_TestDate->setMaximumSize(QSize(200, 16777215));
        dateEdit_TestDate->setCalendarPopup(false);

        verticalLayout_2->addWidget(dateEdit_TestDate);


        verticalLayout_6->addLayout(verticalLayout_2);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(90, 20, -1, 20);
        label_5 = new QLabel(AddTest);
        label_5->setObjectName("label_5");
        label_5->setMaximumSize(QSize(200, 16777215));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_5);

        lineEdit_Topic = new QLineEdit(AddTest);
        lineEdit_Topic->setObjectName("lineEdit_Topic");
        lineEdit_Topic->setMaximumSize(QSize(200, 16777215));

        verticalLayout_7->addWidget(lineEdit_Topic);


        verticalLayout_6->addLayout(verticalLayout_7);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(90, 20, -1, 20);
        label_4 = new QLabel(AddTest);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(200, 16777215));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_4);

        comboBox_Subject = new QComboBox(AddTest);
        comboBox_Subject->setObjectName("comboBox_Subject");
        comboBox_Subject->setMaximumSize(QSize(200, 16777215));
        comboBox_Subject->setMaxVisibleItems(5);
        comboBox_Subject->setMaxCount(5);

        verticalLayout_3->addWidget(comboBox_Subject);


        verticalLayout_6->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(90, 20, -1, 20);
        pushButton_Submit = new QPushButton(AddTest);
        pushButton_Submit->setObjectName("pushButton_Submit");
        pushButton_Submit->setMaximumSize(QSize(200, 16777215));

        verticalLayout_4->addWidget(pushButton_Submit);


        verticalLayout_6->addLayout(verticalLayout_4);


        retranslateUi(AddTest);

        QMetaObject::connectSlotsByName(AddTest);
    } // setupUi

    void retranslateUi(QWidget *AddTest)
    {
        AddTest->setWindowTitle(QCoreApplication::translate("AddTest", "Form", nullptr));
        label->setText(QCoreApplication::translate("AddTest", "Add new test", nullptr));
        label_2->setText(QCoreApplication::translate("AddTest", "Class Number", nullptr));
        label_3->setText(QCoreApplication::translate("AddTest", "Date of test", nullptr));
        dateEdit_TestDate->setDisplayFormat(QCoreApplication::translate("AddTest", "MM.dd.yyyy", nullptr));
        label_5->setText(QCoreApplication::translate("AddTest", "Test Topic", nullptr));
        label_4->setText(QCoreApplication::translate("AddTest", "Subject", nullptr));
        pushButton_Submit->setText(QCoreApplication::translate("AddTest", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddTest: public Ui_AddTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTEST_H
