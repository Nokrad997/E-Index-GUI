#pragma once

#include <iostream>
#include "Student.h"
#include <fstream>

using namespace std;

vector<vector<string>> getGradesData();
vector<vector<string>> getAbsencesData(int classNumber);
vector<vector<string>> getTestsData();
int getClassData(int id);



vector<vector<string>> Student::getGrades()
{
    int studentId = getId();

    vector<vector<string>> grades;

    grades = getGradesData();

    grades.erase(remove_if(grades.begin(), grades.end(),
                [studentId](const vector<string> &v)
                {
                    return v[1] != to_string(studentId);
                }), grades.end());

    return grades;

}

vector<vector<string>> Student::getGrades(string subject)
{
    int studentId = getId();
    vector<vector<string>> grades;

    grades = getGradesData();

    grades.erase(remove_if(grades.begin(), grades.end(),
                [studentId](const vector<string> &v)
                {
                    return v[1] != to_string(studentId);
                }), grades.end());

    grades.erase(remove_if(grades.begin(), grades.end(),
                [subject](const vector<string> &v)
                {
                    return v[0] != subject;
                }), grades.end());

    return grades;
}

vector<vector<string>> Student::getDatesOfAbsences(int classNumber)
{
    int id = getId();
    vector<vector<string>> absences;

    absences = getAbsencesData(classNumber);

    absences.erase(remove_if(absences.begin(), absences.end(),
                [id](const vector<string> &v)
                {
                    return v[3] != to_string(id);
                }), absences.end());

    return absences;
}

vector<vector<string>> Student::getDatesOfAbsences(int classNumber, string subject)
{
    int id = getId();
    vector<vector<string>> absences;

    absences = getAbsencesData(classNumber);

    absences.erase(remove_if(absences.begin(), absences.end(),
                [id](const vector<string> &v)
                {
                    return v[3] != to_string(id);
                }), absences.end());

    absences.erase(remove_if(absences.begin(), absences.end(),
                [subject](const vector<string> &v)
                {
                    return v[1] != subject;
                }), absences.end());

    return absences;
}

vector<vector<string>> Student::getDatesOfUpcomingTests()
{
    int classNumber, id = getId();
    vector<vector<string>> tests;

    classNumber = getClassData(id);
    tests = getTestsData();

    tests.erase(remove_if(tests.begin(), tests.end(),
            [classNumber](const vector<string> &test)
            {
                return test[0] != to_string(classNumber);
            }), tests.end());

    return tests;


}

vector<vector<string>> Student::calculateAverageFromEverySubject()
{
    int id = getId();
    vector<vector<string>> grades;
    vector<vector<string>> result;
    vector<string> data;
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

    double ave = 0;

    for (int i = 0; i < 5; i++)
    {
        if (average[i] != 0)
        {
            data.clear();
            data.push_back(subjects[i]);
            ave = average[i] / amountOfGrades[i];
            data.push_back(to_string(ave));

            result.push_back(data);
        }
    }

    delete[] subjects;

    return result;
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
        string fileName = subjects[i] + "-grades.bin";
        ifstream file(fileName, ios::binary);

        file.seekg(0, file.end);
        int length = file.tellg();
        file.seekg(0, file.beg);

        try
        {
            if (file.good() && length > 0 && file.is_open())
            {
                while (file)
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
            else
            {
                throw runtime_error("couldnt open a file");
            }
        }
        catch(exception &e)
        {
            cerr << e.what() << endl;
        }
    }

    delete[] subjects;

    return grades;
}

vector<vector<string>> getAbsencesData(int classNumber)
{
    int studentId = 0;
    string date, subject, teacherName, name, surname;
    size_t dateSize, subjectSize, teacherSize, nameSize, surnameSize;

    vector<vector<string>> absences;
    vector<string> absenceInfo;

    string fileName = to_string(classNumber) + "-absences.bin";
    ifstream file(fileName, ios::binary);

    file.seekg(0, file.end);
    int length = file.tellg();
    file.seekg(0, file.beg);

    try
    {
        if (file.good() && length > 0 && file.is_open())
        {
            while (file)
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
        else
        {
            throw runtime_error("couldnt open a file");
        }
    }
    catch(exception &e)
    {
        cerr << e.what() << endl;
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

        string fileName = to_string(i) + "-class.bin";
        ifstream file(fileName, ios::binary);

        try
        {
            file.seekg(0, file.end);
            int length = file.tellg();
            file.seekg(0, file.beg);

            if (file.good() && length > 0 && file.is_open())
            {
                while (file)
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
            else
            {
                throw runtime_error("couldnt open a file");
            }
        }
        catch(exception &e)
        {
            cerr << e.what() << endl;
        }

    }
}

vector<vector<string>> getTestsData()
{
    int studentId, classNumber;
    string teacherName, date, topic;
    size_t teacherSize, dateSize, topicSize;
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
        string fileName = subjects[i] + "-tests.bin";
        ifstream file(fileName, ios::binary | ios::in);

        file.seekg(0, file.end);
        int length = file.tellg();
        file.seekg(0, file.beg);

        try
        {
            if (file.good() && length > 0 && file.is_open())
            {
                while (file)
                {
                    testInfo.clear();

                    file.read((char *)&classNumber, sizeof(int));

                    file.read((char *)&dateSize, sizeof(size_t));
                    date.resize(dateSize);
                    file.read((char *)&date[0], dateSize);

                    file.read((char *)&topicSize, sizeof(topicSize));
                    topic.resize(topicSize);
                    file.read((char *)&topic[0], topicSize);

                    file.read((char *)&teacherSize, sizeof(teacherSize));
                    teacherName.resize(teacherSize);
                    file.read((char *)&teacherName[0], teacherSize);

                    testInfo.push_back(to_string(classNumber));
                    testInfo.push_back(date);
                    testInfo.push_back(topic);
                    testInfo.push_back(subjects[i]);
                    testInfo.push_back(teacherName);

                    tests.push_back(testInfo);
                }
                tests.pop_back();
            }
            else
            {
                throw runtime_error("couldnt open a file");
            }
        }
        catch(exception &e)
        {
            cerr << e.what() << endl;
        }
    }

    delete[] subjects;

    return tests;
}
