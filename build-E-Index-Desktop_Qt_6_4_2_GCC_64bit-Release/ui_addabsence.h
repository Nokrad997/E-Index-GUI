/********************************************************************************
** Form generated from reading UI file 'addabsence.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDABSENCE_H
#define UI_ADDABSENCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddAbsence
{
public:
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QSpinBox *spinBox_ClassNumber;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QSpinBox *spinBox_StudentId;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QComboBox *comboBox_Subject;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton;

    void setupUi(QWidget *AddAbsence)
    {
        if (AddAbsence->objectName().isEmpty())
            AddAbsence->setObjectName("AddAbsence");
        AddAbsence->resize(400, 600);
        AddAbsence->setMinimumSize(QSize(400, 600));
        AddAbsence->setMaximumSize(QSize(400, 600));
        verticalLayout_6 = new QVBoxLayout(AddAbsence);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(AddAbsence);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        verticalLayout_6->addLayout(verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(90, 20, -1, 20);
        label_2 = new QLabel(AddAbsence);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(200, 16777215));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_2);

        spinBox_ClassNumber = new QSpinBox(AddAbsence);
        spinBox_ClassNumber->setObjectName("spinBox_ClassNumber");
        spinBox_ClassNumber->setMaximumSize(QSize(200, 16777215));
        spinBox_ClassNumber->setMaximum(6);

        verticalLayout_4->addWidget(spinBox_ClassNumber);


        verticalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(90, 20, -1, 20);
        label_3 = new QLabel(AddAbsence);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(200, 16777215));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_3);

        spinBox_StudentId = new QSpinBox(AddAbsence);
        spinBox_StudentId->setObjectName("spinBox_StudentId");
        spinBox_StudentId->setMaximumSize(QSize(200, 16777215));

        verticalLayout_2->addWidget(spinBox_StudentId);


        verticalLayout_6->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(90, 20, -1, 20);
        label_4 = new QLabel(AddAbsence);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(200, 16777215));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_4);

        comboBox_Subject = new QComboBox(AddAbsence);
        comboBox_Subject->setObjectName("comboBox_Subject");
        comboBox_Subject->setMaximumSize(QSize(200, 16777215));
        comboBox_Subject->setMaxVisibleItems(5);
        comboBox_Subject->setMaxCount(5);

        verticalLayout_3->addWidget(comboBox_Subject);


        verticalLayout_6->addLayout(verticalLayout_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(90, 20, -1, 20);
        pushButton = new QPushButton(AddAbsence);
        pushButton->setObjectName("pushButton");
        pushButton->setMaximumSize(QSize(200, 16777215));
        QFont font2;
        font2.setBold(true);
        pushButton->setFont(font2);

        verticalLayout_5->addWidget(pushButton);


        verticalLayout_6->addLayout(verticalLayout_5);

        verticalLayout_6->setStretch(0, 1);
        verticalLayout_6->setStretch(1, 2);
        verticalLayout_6->setStretch(2, 2);
        verticalLayout_6->setStretch(3, 2);
        verticalLayout_6->setStretch(4, 2);

        retranslateUi(AddAbsence);

        QMetaObject::connectSlotsByName(AddAbsence);
    } // setupUi

    void retranslateUi(QWidget *AddAbsence)
    {
        AddAbsence->setWindowTitle(QCoreApplication::translate("AddAbsence", "Form", nullptr));
        label->setText(QCoreApplication::translate("AddAbsence", "Add absence", nullptr));
        label_2->setText(QCoreApplication::translate("AddAbsence", "Class number", nullptr));
        label_3->setText(QCoreApplication::translate("AddAbsence", "Student Id", nullptr));
        label_4->setText(QCoreApplication::translate("AddAbsence", "Subject", nullptr));
        pushButton->setText(QCoreApplication::translate("AddAbsence", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddAbsence: public Ui_AddAbsence {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDABSENCE_H
