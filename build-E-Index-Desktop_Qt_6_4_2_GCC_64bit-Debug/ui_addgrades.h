/********************************************************************************
** Form generated from reading UI file 'addgrades.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDGRADES_H
#define UI_ADDGRADES_H

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

class Ui_AddGrades
{
public:
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_ClassId;
    QSpinBox *spinBox_ClassId;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_StudentId;
    QSpinBox *spinBox_StudentId;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_Subject;
    QComboBox *comboBox_Subject;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_Topic;
    QLineEdit *lineEdit_Topic;
    QVBoxLayout *verticalLayout;
    QLabel *label_Grade;
    QSpinBox *spinBox_Grade;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_SubmitGrade;

    void setupUi(QWidget *AddGrades)
    {
        if (AddGrades->objectName().isEmpty())
            AddGrades->setObjectName("AddGrades");
        AddGrades->resize(400, 700);
        AddGrades->setMinimumSize(QSize(400, 700));
        AddGrades->setMaximumSize(QSize(400, 700));
        verticalLayout_5 = new QVBoxLayout(AddGrades);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label = new QLabel(AddGrades);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);


        verticalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(140, 20, -1, 20);
        label_ClassId = new QLabel(AddGrades);
        label_ClassId->setObjectName("label_ClassId");
        label_ClassId->setMaximumSize(QSize(100, 16777215));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        label_ClassId->setFont(font1);
        label_ClassId->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_ClassId);

        spinBox_ClassId = new QSpinBox(AddGrades);
        spinBox_ClassId->setObjectName("spinBox_ClassId");
        spinBox_ClassId->setMaximumSize(QSize(100, 16777215));
        spinBox_ClassId->setMinimum(0);
        spinBox_ClassId->setMaximum(6);
        spinBox_ClassId->setValue(0);

        verticalLayout_8->addWidget(spinBox_ClassId);


        verticalLayout_5->addLayout(verticalLayout_8);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_10->setContentsMargins(140, 20, -1, 20);
        label_StudentId = new QLabel(AddGrades);
        label_StudentId->setObjectName("label_StudentId");
        label_StudentId->setMaximumSize(QSize(100, 16777215));
        label_StudentId->setFont(font1);
        label_StudentId->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_StudentId);

        spinBox_StudentId = new QSpinBox(AddGrades);
        spinBox_StudentId->setObjectName("spinBox_StudentId");
        spinBox_StudentId->setMaximumSize(QSize(100, 16777215));
        spinBox_StudentId->setMinimum(0);
        spinBox_StudentId->setMaximum(500);
        spinBox_StudentId->setValue(0);

        verticalLayout_10->addWidget(spinBox_StudentId);


        verticalLayout_5->addLayout(verticalLayout_10);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(90, 20, -1, 20);
        label_Subject = new QLabel(AddGrades);
        label_Subject->setObjectName("label_Subject");
        label_Subject->setMaximumSize(QSize(200, 16777215));
        label_Subject->setFont(font1);
        label_Subject->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_Subject);

        comboBox_Subject = new QComboBox(AddGrades);
        comboBox_Subject->setObjectName("comboBox_Subject");
        comboBox_Subject->setMaximumSize(QSize(200, 16777215));
        QFont font2;
        font2.setPointSize(13);
        font2.setBold(false);
        comboBox_Subject->setFont(font2);
        comboBox_Subject->setMaxVisibleItems(5);
        comboBox_Subject->setMaxCount(5);

        verticalLayout_2->addWidget(comboBox_Subject);


        verticalLayout_5->addLayout(verticalLayout_2);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName("verticalLayout_11");
        verticalLayout_11->setContentsMargins(90, 20, -1, 20);
        label_Topic = new QLabel(AddGrades);
        label_Topic->setObjectName("label_Topic");
        label_Topic->setMaximumSize(QSize(200, 16777215));
        label_Topic->setFont(font1);
        label_Topic->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(label_Topic);

        lineEdit_Topic = new QLineEdit(AddGrades);
        lineEdit_Topic->setObjectName("lineEdit_Topic");
        lineEdit_Topic->setMaximumSize(QSize(200, 16777215));

        verticalLayout_11->addWidget(lineEdit_Topic);


        verticalLayout_5->addLayout(verticalLayout_11);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(140, 20, -1, 20);
        label_Grade = new QLabel(AddGrades);
        label_Grade->setObjectName("label_Grade");
        label_Grade->setMaximumSize(QSize(100, 16777215));
        label_Grade->setFont(font1);
        label_Grade->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_Grade);

        spinBox_Grade = new QSpinBox(AddGrades);
        spinBox_Grade->setObjectName("spinBox_Grade");
        spinBox_Grade->setMaximumSize(QSize(100, 16777215));
        spinBox_Grade->setMinimum(0);
        spinBox_Grade->setMaximum(6);
        spinBox_Grade->setValue(0);

        verticalLayout->addWidget(spinBox_Grade);


        verticalLayout_5->addLayout(verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(90, -1, -1, -1);
        pushButton_SubmitGrade = new QPushButton(AddGrades);
        pushButton_SubmitGrade->setObjectName("pushButton_SubmitGrade");
        pushButton_SubmitGrade->setEnabled(true);
        pushButton_SubmitGrade->setMaximumSize(QSize(200, 16777215));

        verticalLayout_4->addWidget(pushButton_SubmitGrade);


        verticalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 1);
        verticalLayout_5->setStretch(2, 1);
        verticalLayout_5->setStretch(3, 1);
        verticalLayout_5->setStretch(4, 1);
        verticalLayout_5->setStretch(5, 1);
        verticalLayout_5->setStretch(6, 1);

        retranslateUi(AddGrades);

        QMetaObject::connectSlotsByName(AddGrades);
    } // setupUi

    void retranslateUi(QWidget *AddGrades)
    {
        AddGrades->setWindowTitle(QCoreApplication::translate("AddGrades", "Form", nullptr));
        label->setText(QCoreApplication::translate("AddGrades", "Add new grade", nullptr));
        label_ClassId->setText(QCoreApplication::translate("AddGrades", "Class Id", nullptr));
        label_StudentId->setText(QCoreApplication::translate("AddGrades", "Student Id", nullptr));
        label_Subject->setText(QCoreApplication::translate("AddGrades", "Subject", nullptr));
        comboBox_Subject->setCurrentText(QString());
        label_Topic->setText(QCoreApplication::translate("AddGrades", "Topic", nullptr));
        label_Grade->setText(QCoreApplication::translate("AddGrades", "Grade", nullptr));
        pushButton_SubmitGrade->setText(QCoreApplication::translate("AddGrades", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddGrades: public Ui_AddGrades {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDGRADES_H
