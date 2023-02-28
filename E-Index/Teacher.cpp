#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

#include "Teacher.h"

using namespace std;

void Teacher::addTest(string date, string path, int classNumber, string topic)
{

    try
    {
        string teacherName = getSurname();
        size_t dateSize, teacherNameSize, topicSize;

        teacherNameSize = teacherName.size();
        dateSize = date.size();
        topicSize = topic.size();

        ofstream subjectFile(path, ios::binary | ios::app);

        if(subjectFile.good() && subjectFile.is_open())
        {
//            if(!subjectFile.good())
//            {
//                throw
//            }

            subjectFile.write((char *)&classNumber, sizeof(int));

            subjectFile.write((char *)&dateSize, sizeof(size_t));
            subjectFile.write((char *)&date[0], dateSize);

            subjectFile.write((char *)&topicSize, sizeof(size_t));
            subjectFile.write((char *)&topic[0], topicSize);

            subjectFile.write((char *)&teacherNameSize, sizeof(size_t));
            subjectFile.write((char *)&teacherName[0], teacherNameSize);
        }
        else
        {
            throw runtime_error("couldnt open a file");
        }
        subjectFile.close();
    }
    catch(exception &e)
    {
        cerr << e.what() << endl;
    }
}

void Teacher::addGrades(string name, string surname, string topic, string subject, int id, int grade, int classNumber)
{
    size_t nameSize, surnameSize, subjectSize, topicSize, teacherNameSize;
    string teacherName = getSurname();
    string path = subject + "-grades.bin";

    nameSize = name.size();
    surnameSize = surname.size();
    teacherNameSize = teacherName.size();
    topicSize = topic.size();

    try
    {
        ofstream classFile(path, ios::binary | ios::app);
        if(classFile.good() && classFile.is_open())
        {
            classFile.write((char *)&id, sizeof(int));

            classFile.write((char *)&classNumber, sizeof(int));

            classFile.write((char *)&grade, sizeof(int));

            classFile.write((char *)&topicSize, sizeof(size_t));
            classFile.write((char *)&topic[0], topicSize);

            classFile.write((char *)&teacherNameSize, sizeof(size_t));
            classFile.write((char *)&teacherName[0], teacherNameSize);

            classFile.write((char *)&nameSize, sizeof(size_t));
            classFile.write((char *)&name[0], nameSize);

            classFile.write((char *)&surnameSize, sizeof(size_t));
            classFile.write((char *)&surname[0], surnameSize);
        }
        else
        {
            throw runtime_error("couldnt open a file");
        }
        classFile.close();
    }
    catch(std::exception &e)
    {
        cerr << e.what() << endl;
        return ;
    }
}

vector<vector<string>> Teacher::getStudents(int classNumber)
{
    string path = to_string(classNumber) + "-class" + ".bin";
    ifstream classFile(path, ios::binary);
    vector<vector<string>> students;

    try
    {
        if(!classFile.good())
        {
            throw std::runtime_error("file not found");
        }
        int studentId;
        string name, surname;
        size_t nameSize, surnameSize;

        classFile.seekg(0, classFile.end);
        int length = classFile.tellg();
        classFile.seekg(0, classFile.beg);

        if(classFile.is_open() && length > 0 && classFile.good())
        {
            while(classFile)
            {
                classFile.read((char *)&studentId, sizeof(int));

                classFile.read((char *)&nameSize, sizeof(size_t));
                name.resize(nameSize);
                classFile.read((char *)&name[0], nameSize);

                classFile.read((char *)&surnameSize, sizeof(size_t));
                surname.resize(surnameSize);
                classFile.read((char *)&surname[0], surnameSize);

                students.push_back({to_string(studentId), name, surname});
            }
            students.pop_back();
        }
        else
        {
            throw runtime_error("couldnt open a file");
        }
    }
    catch(std::exception &e)
    {
        cout << "error: " << e.what() << endl;
    }

    classFile.close();
    return students;
}

void Teacher::saveAbsence(int classNumber, string teacherName, string date, string subject, vector<string> student)
{
    try
    {
        ofstream absencesFile(to_string(classNumber) + "-absences.bin", ios::binary | ios::app);
        int id = 0;
        string name, surname;
        size_t teacherNameSize, dateSize, subjectSize, nameSize, surnameSize;

        if(absencesFile.good() && absencesFile.is_open())
        {
            id = stoi(student[0]);
            name = student[1];
            surname = student[2];

            nameSize = name.size();
            surnameSize = surname.size();
            dateSize = date.size();
            subjectSize = subject.size();
            teacherNameSize = teacherName.size();

            absencesFile.write((char *)&dateSize, sizeof(size_t));
            absencesFile.write((char *)&date[0], dateSize);

            absencesFile.write((char *)&subjectSize, sizeof(size_t));
            absencesFile.write((char *)&subject[0], subjectSize);

            absencesFile.write((char *)&teacherNameSize, sizeof(size_t));
            absencesFile.write((char *)&teacherName[0], teacherNameSize);

            absencesFile.write((char *)&id, sizeof(int));

            absencesFile.write((char *)&nameSize, sizeof(size_t));
            absencesFile.write((char *)&name[0], nameSize);

            absencesFile.write((char *)&surnameSize, sizeof(size_t));
            absencesFile.write((char *)&surname[0], surnameSize);

            absencesFile.close();
        }
        else
        {
            throw runtime_error("problems with opening a file");
        }
    }
    catch(std::exception &e)
    {
        cout << "error: " << e.what() << endl;
    }

}

void Teacher::searchForTeacherSubject()
{
    string path = "Teachers.bin";
    ifstream file(path, ios::binary);

    try
    {
        file.seekg(0, file.end);
        int length = file.tellg();
        file.seekg(0, file.beg);

        if(file.good() && length > 0 && file.is_open())
        {
            while(file)
            {
                int id = 0;
                string subject, name, surname;
                size_t subjectSize, nameSize, surnameSize;

                file.read((char *)&id, sizeof(int));

                file.read((char *)&subjectSize, sizeof(size_t));
                subject.resize(subjectSize);
                file.read((char *)&subject[0], subjectSize);

                file.read((char *)&nameSize, sizeof(size_t));
                name.resize(nameSize);
                file.read((char *)&name[0], nameSize);

                file.read((char *)&surnameSize, sizeof(size_t));
                surname.resize(surnameSize);
                file.read((char *)&surname[0], surnameSize);

                if(id == getId())
                {
                    setSubject(subject);
                    break;
                }
            }
        }
        else
        {
            throw runtime_error("Couldnt open teachers file");
        }
    }
    catch(exception &e)
    {
        cerr << e.what() << endl;
    }
}

void Teacher::setSubject(string subject)
{
    this->subject = subject;
}

string Teacher::getSubject()
{
    return subject;
}

