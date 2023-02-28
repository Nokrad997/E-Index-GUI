#pragma once

#include <iostream>
#include "student1.h"
#include <fstream>

using namespace std;

vector<vector<string>> getGradesData();
vector<vector<string>> getAbsencesData();
vector<vector<string>> getTestsData();
int getClassData(int id);

void Student1::studentMenu()
{
    bool logout = false;

    while (!logout)
    {
        char option;

        cout << endl;
        cout << "[1]. show grades" << endl;
        cout << "[2]. show absences" << endl;
        cout << "[3]. show all upcoming tests" << endl;
        cout << "[4]. calculate average grade for every subject" << endl;
        cout << "[5]. logout" << endl;

        cin >> option;

        switch (option)
        {
        case '1':
        {
            int option = 0;
            string *subjects = new string[5];
            subjects[0] = "Math";
            subjects[1] = "English";
            subjects[2] = "Biology";
            subjects[3] = "Physics";
            subjects[4] = "Chemistry";

            cout << endl;
            for (int i = 0; i < 5; i++)
            {
                cout << i + 1 << ". " << subjects[i] << endl;
            }
            cout << "Type 0 to show all grades or type subject number to show grades for specific subject" << endl;
            cin >> option;
            cout << endl;

            if (option == 0)
            {
                getGrades();
            }
            else if (option > 0 && option < 6)
            {
                getGrades(subjects[option - 1]);
            }
            else
            {
                cout << "Invalid option!" << endl;
            }

            delete[] subjects;
            break;
        }

        case '2':
        {
            int option = 0;
            string *subjects = new string[5];
            subjects[0] = "Math";
            subjects[1] = "English";
            subjects[2] = "Biology";
            subjects[3] = "Physics";
            subjects[4] = "Chemistry";

            cout << endl;
            for (int i = 0; i < 5; i++)
            {
                cout << i + 1 << ". " << subjects[i] << endl;
            }
            cout << "Type 0 to show all absences or type subject number to show absences for specific subject" << endl;
            cin >> option;
            cout << endl;

            if (option == 0)
            {
                getDatesOfAbsences();
            }
            else if (option > 0 && option < 6)
            {
                getDatesOfAbsences(subjects[option - 1]);
            }
            else
            {
                cout << "Invalid option!" << endl;
            }

            delete[] subjects;
            break;
        }

        case '3':
        {
            getDatesOfUpcomingTests();
            break;
        }

        case '4':
        {
            calculateAverageFromEverySubject();
            break;
        }

        case '5':
        {
            logout = true;
            break;
        }

        default:
            cout << "Invalid option!" << endl;
            break;
        }
    }
}

void Student1::getGrades()
{
    int studentId = getId();

    vector<vector<string>> grades;

    grades = getGradesData();

    for (int i = 0; i < grades.size(); i++)
    {
        if (grades[i][1] == to_string(studentId))
        {
            cout << "---------------------------- " << endl;
            cout << "Subject: " << grades[i][0] << endl;
            cout << "Topic: " << grades[i][3] << endl;
            cout << "Grade: " << grades[i][2] << endl;
            cout << "---------------------------- " << endl;
        }
    }
}

void Student1::getGrades(string subject)
{
    int studentId = getId();
    vector<vector<string>> grades;

    grades = getGradesData();

    for (int i = 0; i < grades.size(); i++)
    {
        if (grades[i][1] == to_string(studentId))
        {
            if (grades[i][0] == subject)
            {
                cout << "---------------------------- " << endl;
                cout << "Subject: " << grades[i][0] << endl;
                cout << "Topic: " << grades[i][3] << endl;
                cout << "Grade: " << grades[i][2] << endl;
                cout << "---------------------------- " << endl;
            }
        }
    }
}

void Student1::getDatesOfAbsences()
{
    int id = getId();
    vector<vector<string>> absences;

    absences = getAbsencesData();

    for (int i = 0; i < absences.size(); i++)
    {
        if (absences[i][3] == to_string(id))
        {
            cout << "---------------------------- " << endl;
            cout << "Date: " << absences[i][0] << endl;
            cout << "Subject: " << absences[i][1] << endl;
            cout << "---------------------------- " << endl;
        }
    }
}

void Student1::getDatesOfAbsences(string subject)
{
    int id = getId();
    vector<vector<string>> absences;

    absences = getAbsencesData();

    for (int i = 0; i < absences.size(); i++)
    {
        if (absences[i][3] == to_string(id))
        {
            if (absences[i][1] == subject)
            {
                cout << "---------------------------- " << endl;
                cout << "Date: " << absences[i][0] << endl;
                cout << "Subject: " << absences[i][1] << endl;
                cout << "---------------------------- " << endl;
            }
        }
    }
}

void Student1::getDatesOfUpcomingTests()
{
    int classNumber, id = getId();
    vector<vector<string>> tests;

    classNumber = getClassData(id);
    tests = getTestsData();

    time_t now = time(0);
    tm *ltm = localtime(&now);

    int tmpDate[3] = {1 + ltm->tm_mon, ltm->tm_mday, 1900 + ltm->tm_year};

    for (int i = 0; i < tests.size(); i++)
    {
        if (tests[i][0] == to_string(classNumber))
        {
            if (tmpDate[2] < stoi(tests[i][1].substr(6, 4)))
            {
                cout << "---------------------------- " << endl;
                cout << "Date: " << tests[i][1] << endl;
                cout << "Subject: " << tests[i][2] << endl;
                cout << "Teacher: " << tests[i][3] << endl;
                cout << "---------------------------- " << endl;
            }
            else if (tmpDate[2] == stoi(tests[i][1].substr(6, 4)))
            {
                if (tmpDate[0] < stoi(tests[i][1].substr(0, 2)))
                {
                    cout << "---------------------------- " << endl;
                    cout << "Date: " << tests[i][1] << endl;
                    cout << "Subject: " << tests[i][2] << endl;
                    cout << "Teacher: " << tests[i][3] << endl;
                    cout << "---------------------------- " << endl;
                }
                else if (tmpDate[0] == stoi(tests[i][1].substr(0, 2)))
                {
                    if (tmpDate[1] < stoi(tests[i][1].substr(3, 2)))
                    {
                        cout << "---------------------------- " << endl;
                        cout << "Date: " << tests[i][1] << endl;
                        cout << "Subject: " << tests[i][2] << endl;
                        cout << "Teacher: " << tests[i][3] << endl;
                        cout << "---------------------------- " << endl;
                    }
                }
            }
        }
    }
}

void Student1::calculateAverageFromEverySubject()
{
    int id = getId();
    vector<vector<string>> grades;
    double average[5] = {0, 0, 0, 0, 0};
    int amountOfGrades[5] = {0, 0, 0, 0, 0};
    string *subjects = new string[5];

    subjects[0] = "Math";
    subjects[1] = "English";
    subjects[2] = "Biology";
    subjects[3] = "Physics";
    subjects[4] = "Chemistry";

    grades = getGradesData();

    for (int i = 0; i < grades.size(); i++)
    {
        if (stoi(grades[i][1]) == id)
        {
            if (grades[i][0] == "Math")
            {
                amountOfGrades[0]++;
                average[0] += (stoi(grades[i][2]) * 1.0);
            }
            else if (grades[i][0] == "English")
            {
                amountOfGrades[1]++;
                average[1] += (stoi(grades[i][2]) * 1.0);
            }
            else if (grades[i][0] == "Biology")
            {
                amountOfGrades[2]++;
                average[2] += (stoi(grades[i][2]) * 1.0);
            }
            else if (grades[i][0] == "Physics")
            {
                amountOfGrades[3]++;
                average[3] += (stoi(grades[i][2]) * 1.0);
            }
            else if (grades[i][0] == "Chemistry")
            {
                amountOfGrades[4]++;
                average[4] += (stoi(grades[i][2]) * 1.0);
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (average[i] != 0)
        {
            cout << "---------------------------- " << endl;
            cout << subjects[i] << ": " << average[i] / amountOfGrades[i] << endl;
            cout << "---------------------------- " << endl
                 << endl;
        }
    }

    delete[] subjects;
}

vector<vector<string>> getGradesData()
{
    vector<vector<string>> grades;
    vector<string> gradeInfo;

    int id = 0, grade = 0, classNumber = 0;
    size_t nameSize, surnameSize, topicSize, teacherSize;
    string name, surname, topic, teacherName;
    string *subjects = new string[5];

    subjects[0] = "Math";
    subjects[1] = "English";
    subjects[2] = "Biology";
    subjects[3] = "Physics";
    subjects[4] = "Chemistry";

    for (int i = 0; i < 5; i++)
    {
        string fileName = "Database/Grades/" + subjects[i] + ".bin";
        ifstream file(fileName, ios::binary | ios::in);

        file.seekg(0, file.end);
        int length = file.tellg();
        file.seekg(0, file.beg);

        if (file.good() && length > 0)
        {
            while (file.good())
            {
                gradeInfo.clear();

                file.read((char *)&id, sizeof(id));

                file.read((char *)&classNumber, sizeof(classNumber));

                file.read((char *)&grade, sizeof(grade));

                file.read((char *)&topicSize, sizeof(topicSize));
                topic.resize(topicSize);
                file.read((char *)&topic[0], topicSize);

                file.read((char *)&teacherSize, sizeof(teacherSize));
                teacherName.resize(teacherSize);
                file.read((char *)&teacherName[0], teacherSize);

                file.read((char *)&nameSize, sizeof(nameSize));
                name.resize(nameSize);
                file.read((char *)&name[0], nameSize);

                file.read((char *)&surnameSize, sizeof(surnameSize));
                surname.resize(surnameSize);
                file.read((char *)&surname[0], surnameSize);

                gradeInfo.push_back(subjects[i]);
                gradeInfo.push_back(to_string(id));
                gradeInfo.push_back(to_string(grade));
                gradeInfo.push_back(topic);
                gradeInfo.push_back(teacherName);

                grades.push_back(gradeInfo);
            }
            grades.pop_back();
        }
    }

    delete[] subjects;

    return grades;
}

vector<vector<string>> getAbsencesData()
{
    int studentId = 0;
    string date, subject, teacherName, name, surname;
    size_t dateSize, subjectSize, teacherSize, nameSize, surnameSize;

    vector<vector<string>> absences;
    vector<string> absenceInfo;

    for (int i = 1; i < 7; i++)
    {
        string fileName = "Database/Absences/" + to_string(i) + ".bin";
        ifstream file(fileName, ios::binary | ios::in);

        file.seekg(0, file.end);
        int length = file.tellg();
        file.seekg(0, file.beg);

        if (file.good() && length > 0)
        {
            while (file.good())
            {
                absenceInfo.clear();

                file.read((char *)&dateSize, sizeof(dateSize));
                date.resize(dateSize);
                file.read((char *)&date[0], dateSize);

                file.read((char *)&subjectSize, sizeof(subjectSize));
                subject.resize(subjectSize);
                file.read((char *)&subject[0], subjectSize);

                file.read((char *)&teacherSize, sizeof(teacherSize));
                teacherName.resize(teacherSize);
                file.read((char *)&teacherName[0], teacherSize);

                file.read((char *)&studentId, sizeof(studentId));

                file.read((char *)&nameSize, sizeof(nameSize));
                name.resize(nameSize);
                file.read((char *)&name[0], nameSize);

                file.read((char *)&surnameSize, sizeof(surnameSize));
                surname.resize(surnameSize);
                file.read((char *)&surname[0], surnameSize);

                absenceInfo.push_back(date);
                absenceInfo.push_back(subject);
                absenceInfo.push_back(teacherName);
                absenceInfo.push_back(to_string(studentId));

                absences.push_back(absenceInfo);
            }
            absences.pop_back();
        }
    }

    return absences;
}

int getClassData(int id)
{
    int studentId = 0, classNumber = 0;
    string name, surname;
    size_t nameSize, surnameSize;

    for (int i = 1; i < 7; i++)
    {

        string fileName = "Database/Classes/" + to_string(i) + ".bin";
        ifstream file(fileName, ios::binary | ios::in);

        file.seekg(0, file.end);
        int length = file.tellg();
        file.seekg(0, file.beg);

        if (file.good() && length > 0)
        {
            while (file.good())
            {
                file.read((char *)&studentId, sizeof(studentId));

                file.read((char *)&nameSize, sizeof(nameSize));
                name.resize(nameSize);
                file.read((char *)&name[0], nameSize);

                file.read((char *)&surnameSize, sizeof(surnameSize));
                surname.resize(surnameSize);
                file.read((char *)&surname[0], surnameSize);

                if (studentId == id)
                {
                    classNumber = i;
                    return classNumber;
                }
            }
        }
    }
}

vector<vector<string>> getTestsData()
{
    int studentId;
    string teacherName, date, fileClassNumber;
    size_t teacherSize;
    string *subjects = new string[5];

    subjects[0] = "Math";
    subjects[1] = "English";
    subjects[2] = "Biology";
    subjects[3] = "Physics";
    subjects[4] = "Chemistry";

    vector<vector<string>> tests;
    vector<string> testInfo;

    for (int i = 0; i < 5; i++)
    {
        string fileName = "Database/Tests/" + subjects[i] + ".bin";
        ifstream file(fileName, ios::binary | ios::in);

        file.seekg(0, file.end);
        int length = file.tellg();
        file.seekg(0, file.beg);

        if (file.good() && length > 0)
        {
            while (file.good())
            {
                testInfo.clear();

                date.resize(11);
                file.read((char *)&date[0], 11);

                file.read((char *)&teacherSize, sizeof(teacherSize));
                teacherName.resize(teacherSize);
                file.read((char *)&teacherName[0], teacherSize);

                fileClassNumber = date[0];
                date = date.substr(1, date.size());

                testInfo.push_back(fileClassNumber);
                testInfo.push_back(date);
                testInfo.push_back(subjects[i]);
                testInfo.push_back(teacherName);

                tests.push_back(testInfo);
            }
            tests.pop_back();
        }
    }

    delete[] subjects;

    return tests;
}
