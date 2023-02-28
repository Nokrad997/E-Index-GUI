#include "studentwindow.h"
#include "ui_studentwindow.h"

StudentWindow::StudentWindow(StudentRepository *_s, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentWindow)
{
    ui->setupUi(this);
    setWindowFlag(Qt::WindowCloseButtonHint, false);

    student = _s;

    string *subjects = new string[5];
    subjects[0] = "Math";
    subjects[1] = "English";
    subjects[2] = "Biology";
    subjects[3] = "Physics";
    subjects[4] = "Chemistry";

    QStringList list;
    list << "" << QString::fromStdString(subjects[0]) << QString::fromStdString(subjects[1])
            << QString::fromStdString(subjects[2]) << QString::fromStdString(subjects[3])
            << QString::fromStdString(subjects[4]);

    ui->comboBox_Grades->addItems(list);
    ui->comboBox_Absences->addItems(list);
    ui->label_Name->setText(QString::fromStdString(student->getName()));
    ui->label_Surname->setText(QString::fromStdString(student->getSurname()));

    vector<vector<string>> dates;
    dates = student->getDatesOfUpcomingTests();

    time_t now = time(0);
    tm *ltm = localtime(&now);

    int tmpDate[3] = {1 + ltm->tm_mon, ltm->tm_mday, 1900 + ltm->tm_year};

    for (int i = 0; i < dates.size(); i++)
    {
        QDateTime dateTime = QDateTime::fromString(QString::fromStdString(dates[i][1]), "MM-dd-yyyy");
        QDate eventDate = dateTime.date();

        if (tmpDate[2] < stoi(dates[i][1].substr(6, 4)))
        {
            QDateTime dateTime = QDateTime::fromString(QString::fromStdString(dates[i][1]), "MM-dd-yyyy");
                QDate eventDate = dateTime.date();
                QTextCharFormat eventFormat;
                eventFormat.setToolTip("Topic: " + QString::fromStdString(dates[i][2]) + "\n"
                                        + "Subject: " + QString::fromStdString(dates[i][3]) + "\n"
                                        + "Teacher: " + QString::fromStdString(dates[i][4]));
                eventFormat.setForeground(Qt::yellow);
                ui->calendarWidget->setDateTextFormat(eventDate, eventFormat);
        }
        else if (tmpDate[2] == stoi(dates[i][1].substr(6, 4)))
        {
            if (tmpDate[0] < stoi(dates[i][1].substr(0, 2)))
            {
                QTextCharFormat eventFormat;
                eventFormat.setToolTip("Topic: " + QString::fromStdString(dates[i][2]) + "\n"
                                                    + "Subject: " + QString::fromStdString(dates[i][3]) + "\n"
                                                    + "Teacher: " + QString::fromStdString(dates[i][4]));
                eventFormat.setForeground(Qt::yellow);
                ui->calendarWidget->setDateTextFormat(eventDate, eventFormat);
            }
            else if (tmpDate[0] == stoi(dates[i][1].substr(0, 2)))
            {
                if (tmpDate[1] < stoi(dates[i][1].substr(3, 2)))
                {
                    QTextCharFormat eventFormat;
                    eventFormat.setToolTip("Topic: " + QString::fromStdString(dates[i][2]) + "\n"
                                                        + "Subject: " + QString::fromStdString(dates[i][3]) + "\n"
                                                        + "Teacher: " + QString::fromStdString(dates[i][4]));
                    eventFormat.setForeground(Qt::yellow);
                    ui->calendarWidget->setDateTextFormat(eventDate, eventFormat);
                }
            }
        }
    }
    connect(ui->calendarWidget, &QCalendarWidget::clicked, [this, dates] (const QDate &clickedDate) {
        showEventInfo(clickedDate, dates);
    });

    delete [] subjects;
}

StudentWindow::~StudentWindow()
{
    delete student;
    delete ui;
}

void StudentWindow::on_pushButton_Grades_clicked()
{
    vector<vector<string>> grades;


    if(ui->comboBox_Grades->currentText() == "")
    {
        grades = student->getGrades();
    }
    else
    {
        grades = student->getGrades(ui->comboBox_Grades->currentText().toStdString());
    }

    ui->tableWidget_Grades->setStyleSheet("alignment: center;");
    ui->tableWidget_Grades->setRowCount(grades.size());
    ui->tableWidget_Grades->setColumnCount(4);

    QStringList headers;
    headers << "Subject" << "Grade" << "Topic" << "Teacher";
    ui->tableWidget_Grades->setHorizontalHeaderLabels(headers);

    if(grades.size() == 0)
    {
        QMessageBox::information(this, "Grades", "Student has no grades yet");
        return ;
    }

    for(int i = 0; i < grades.size(); i++)
    {
        ui->tableWidget_Grades->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(grades[i][0])));
        ui->tableWidget_Grades->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(grades[i][2])));
        ui->tableWidget_Grades->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(grades[i][3])));
        ui->tableWidget_Grades->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(grades[i][4])));
    }
    ui->tableWidget_Grades->sortByColumn(1, Qt::DescendingOrder);
}


void StudentWindow::on_pushButton_Absences_clicked()
{
    vector<vector<string>> absences;

    if(ui->comboBox_Absences->currentText() == "")
    {
        absences = student->getDatesOfAbsences(student->getClassNumber());
    }
    else
    {
        absences = student->getDatesOfAbsences(student->getClassNumber(), ui->comboBox_Absences->currentText().toStdString());
    }

    ui->tableWidget_Absences->setStyleSheet("alignment: center;");
    ui->tableWidget_Absences->setRowCount(absences.size());
    ui->tableWidget_Absences->setColumnCount(3);

    QStringList headers;
    headers << "Date" << "Subject" << "Teacher";
    ui->tableWidget_Absences->setHorizontalHeaderLabels(headers);

    if(absences.size() == 0)
    {
        QMessageBox::information(this, "Absences", "Student has no absences yet");
        return ;
    }

    for(int i = 0; i < absences.size(); i++)
    {
        ui->tableWidget_Absences->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(absences[i][0])));
        ui->tableWidget_Absences->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(absences[i][1])));
        ui->tableWidget_Absences->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(absences[i][2])));
    }
    ui->tableWidget_Absences->sortByColumn(1, Qt::DescendingOrder);

}


void StudentWindow::on_pushButton_CalculateAverage_clicked()
{
    vector<vector<string>> average;

    average = student->calculateAverageFromEverySubject();

    if(average.size() == 0)
    {
        QMessageBox::information(this, "Average", "This student has no grades yet");
        return;
    }

    ui->tableWidget_Average->setStyleSheet("alignment: center;");
    ui->tableWidget_Average->setRowCount(average.size());
    ui->tableWidget_Average->setColumnCount(2);

    QStringList headers;
    headers << "Subject" << "Average";
    ui->tableWidget_Average->setHorizontalHeaderLabels(headers);

    for(int i = 0; i < average.size(); i++)
    {
        ui->tableWidget_Average->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(average[i][0])));
        ui->tableWidget_Average->setItem(i, 1, new QTableWidgetItem(QString::number(stod(average[i][1]), 'f', 2)));
    }
    ui->tableWidget_Average->sortByColumn(1, Qt::DescendingOrder);

}


void StudentWindow::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Quit", "Are you sure you wont to logout?", QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes)
    {
        this->close();
        QWidget *parent = this->parentWidget();
        parent->show();
    }

    return ;
}

void StudentWindow::showEventInfo(QDate clickedDate, vector<vector<string>> dates)
{
    bool found = false;
    for (int i = 0; i < dates.size(); i++)
    {
        QDateTime dateTime = QDateTime::fromString(QString::fromStdString(dates[i][1]), "MM-dd-yyyy");
        QDate tmpEventDate = dateTime.date();
        if (tmpEventDate == clickedDate)
        {
            found = true;
            QMessageBox::information(this, "Test", "Topic: " + QString::fromStdString(dates[i][2]) + "\n"
                    + "Subject: " + QString::fromStdString(dates[i][3]) + "\n"
                    + "Teacher: " + QString::fromStdString(dates[i][4]));
        }
    }
    if(!found)
    {
        QMessageBox::information(this, "Test", "There are no test on this day");
    }
}
