#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include "Admin.h"

using namespace std;

bool checkMail(string email);
vector<vector<string>> getClassMembers(int classId);
void removeFromClass(int classId, int userId);
void removeFromGrades(int userId);
void removeFromAbsences(int classId, int userId);
void editClass(int edClassId, int edStudentId, string edName, string edSurname);
void editGrades(int previousClassId, int edClassId, int edStudentId, string edName, string edSurname);
void editAbsences(int previousClassId, int edClassId, int edStudentId, string edName, string edSurname, bool classChanged);

vector<Person> Admin::getAllUsers()
{
    ifstream file("users.bin", ios::binary);
    Person p1;
    vector<Person> users;

    file.seekg(0, file.end);
    int length = file.tellg();
    file.seekg(0, file.beg);
    try
    {
        if (file.good() && length > 0 && file.is_open())
        {
            while (file)
            {
                p1.read(file);
                users.push_back(p1);
                cout <<p1;
            }
            users.pop_back();
            file.close();

            return users;
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

vector<vector<string>> Admin::getAllUsersFromClass(int classNumber)
{
    ifstream file(to_string(classNumber) + "-class.bin", ios::binary);
    int id;
    string name, surname;
    size_t nameSize, surnameSize;

    vector<vector<string>> users;
    vector<string> data;

    file.seekg(0, file.end);
    int length = file.tellg();
    file.seekg(0, file.beg);

    try
    {
        if (file.good() && length > 0 && file.is_open())
        {
            while (file)
            {
                data.clear();

                file.read((char*)&id, sizeof(int));

                file.read((char *)&nameSize, sizeof(size_t));
                name.resize(nameSize);
                file.read((char *)&name[0], nameSize);

                file.read((char *)&surnameSize, sizeof(size_t));
                surname.resize(surnameSize);
                file.read((char *)&surname[0], surnameSize);

                data.push_back(to_string(id));
                data.push_back(name);
                data.push_back(surname);

                users.push_back(data);
            }
            users.pop_back();

            file.close();

            return users;
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

void Admin::deleteUser(int userId)
{
    int index = 0;
    vector<Person> users;
    bool found = false;

    users = getAllUsers();

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getId() == userId)
        {
            index = i;
            found = true;

            break;
        }
    }

    if (!found)
    {
        cout << "couldn't find user by given id" << endl;
        return;
    }

    if (users[index].getRole() == "Student")
    {
        int classNumber = users[index].getClassNumber();

        removeFromClass(classNumber, userId);
        removeFromGrades(userId);
        removeFromAbsences(classNumber, userId);
    }

    users.erase(users.begin() + index);

    ofstream file("users.bin", ios::binary);

    try
    {
        if (file.good() && file.is_open())
        {
            users.shrink_to_fit();
            for (int i = 0; i < users.size(); i++)
            {
                users[i].write(file);
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



void Admin::editUser(Person user, int previousClassNumber, bool wasStudent, bool classChanged)
{
    vector<Person> users;

    users = getAllUsers();

    ifstream file("users.bin", ios::binary);
    if (file.good() && file.is_open())
    {
        remove("users.bin");
        file.close();
    }
    else
    {
        cout << "File not found" << endl;
        return;
    }

    for(int i = 0; i < users.size(); i++)
    {
        if(users[i].getId() == user.getId())
        {
            users[i] = user;
            break;
        }
    }

    ofstream file2("users.bin", ios::binary | ios::app);

    if (!wasStudent && user.getRole() == "Student")
    {
        ofstream file3(to_string(user.getClassNumber()) + "-class.bin", ios::binary | ios::app);
        user.writeToClass(file3);
        file3.close();
    }
    else if (wasStudent && user.getRole() == "Teacher")
    {
        removeFromClass(previousClassNumber, user.getId());
        removeFromGrades(user.getId());
        removeFromAbsences(previousClassNumber, user.getId());
    }
    else if (wasStudent && user.getRole() == "Student")
    {
        editClass(user.getClassNumber(), user.getId(), user.getName(), user.getSurname());
        editGrades(previousClassNumber, user.getClassNumber(), user.getId(), user.getName(), user.getSurname());
        editAbsences(previousClassNumber, user.getClassNumber(), user.getId(), user.getName(), user.getSurname(), classChanged);

        if (previousClassNumber != user.getClassNumber())
        {
            removeFromClass(previousClassNumber, user.getId());
            removeFromAbsences(previousClassNumber, user.getId());
        }

        if (classChanged)
        {
            ofstream file3(to_string(user.getClassNumber()) + "-class.bin", ios::binary | ios::app);
            if (file3.good())
            {
                user.writeToClass(file3);
            }
            file3.close();
        }
    }

    for (int i = 0; i < users.size(); i++)
    {
        users[i].write(file2);
    }

    file2.close();
}



bool checkMail(string email)
{
    ifstream file = ifstream("Database/users.bin", ios::binary);

    file.seekg(0, file.end);
    int length = file.tellg();
    file.seekg(0, file.beg);

    if (file.good() && length > 0 && file.is_open())
    {
        Person p1;

        while (file)
        {
            p1.read(file);
            if (p1.getEmail() == email)
            {
                cout << "Email already exists!" << endl;
                return true;
            }
        }
        file.close();

        return false;
    }
}

vector<vector<string>> getClassMembers(int classId)
{
    vector<vector<string>> classData;
    vector<string> data;

    ifstream file = ifstream(to_string(classId) + "-class.bin", ios::binary);

    int length = 0;

    file.seekg(0, file.end);
    length = file.tellg();
    file.seekg(0, file.beg);

    try
    {
        if (file.good() && length > 0 && file.is_open())
        {
            int id;
            string name, surname;
            size_t nameSize, surnameSize;

            while (file)
            {
                data.clear();

                file.read((char *)&id, sizeof(int));

                file.read((char *)&nameSize, sizeof(size_t));
                name.resize(nameSize);
                file.read((char *)&name[0], nameSize);

                file.read((char *)&surnameSize, sizeof(size_t));
                surname.resize(surnameSize);
                file.read((char *)&surname[0], surnameSize);

                data.push_back(to_string(id));
                data.push_back(name);
                data.push_back(surname);

                classData.push_back(data);
            }
            classData.pop_back();
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

    file.close();

    return classData;
}

void removeFromClass(int classId, int userId)
{
    vector<vector<string>> classes;
    classes = getClassMembers(classId);
    string path = to_string(classId) + "-class.bin";

    ofstream classesFile(path, ios::binary);

    for (int i = 0; i < classes.size(); i++)
    {
        if (classes[i][0] == to_string(userId))
        {
            classes.erase(classes.begin() + i);
            break;
        }
    }

    try
    {
        if (classesFile.good() && classesFile.is_open())
        {
            string name, surname;
            size_t nameSize, surnameSize;
            int cId;

            classes.shrink_to_fit();

            for (int i = 0; i < classes.size(); i++)
            {
                cId = stoi(classes[i][0]);
                name = classes[i][1];
                surname = classes[i][2];
                nameSize = name.size();
                surnameSize = surname.size();

                classesFile.write((char *)&cId, sizeof(int));

                classesFile.write((char *)&nameSize, sizeof(size_t));
                classesFile.write(&name[0], nameSize);

                classesFile.write((char *)&surnameSize, sizeof(size_t));
                classesFile.write(&surname[0], surnameSize);
            }
        }
        else
        {
            throw runtime_error("couldnt open a file");
        }

        classesFile.close();
    }
    catch(exception &e)
    {
        cerr << e.what() << endl;
    }

}

void removeFromGrades(int userId)
{
    vector<vector<string>> grades;
    vector<string> data;
    string *subjects = new string[5];

    subjects[0] = "Math";
    subjects[1] = "English";
    subjects[2] = "Biology";
    subjects[3] = "Physics";
    subjects[4] = "Chemistry";

    for (int i = 0; i < 5; i++)
    {
        ifstream file(subjects[i] + "-grades.bin", ios::binary);

        int length = 0;

        file.seekg(0, file.end);
        length = file.tellg();
        file.seekg(0, file.beg);

        try
        {
            if (file.good() && length > 0 && file.is_open())
            {
                int fileId, grade, classId;
                string topic, teacherName, surname, name;
                size_t topicSize, teacherNameSize, nameSize, surnameSize;

                while (file)
                {

                    data.clear();

                    file.read((char *)&fileId, sizeof(int));

                    file.read((char *)&classId, sizeof(int));

                    file.read((char *)&grade, sizeof(int));

                    file.read((char *)&topicSize, sizeof(size_t));
                    topic.resize(topicSize);
                    file.read((char *)&topic[0], topicSize);

                    file.read((char *)&teacherNameSize, sizeof(size_t));
                    teacherName.resize(teacherNameSize);
                    file.read((char *)&teacherName[0], teacherNameSize);

                    file.read((char *)&nameSize, sizeof(size_t));
                    name.resize(nameSize);
                    file.read((char *)&name[0], nameSize);

                    file.read((char *)&surnameSize, sizeof(size_t));
                    surname.resize(surnameSize);
                    file.read((char *)&surname[0], surnameSize);

                    data.push_back(to_string(fileId));
                    data.push_back(to_string(classId));
                    data.push_back(to_string(grade));
                    data.push_back(topic);
                    data.push_back(teacherName);
                    data.push_back(name);
                    data.push_back(surname);

                    grades.push_back(data);
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

        file.close();

        string path = subjects[i] + "-grades.bin";
        remove(path.c_str());
        ofstream gradesFile(path, ios::binary);

        grades.erase(remove_if(grades.begin(), grades.end(), [userId](vector<string> &v)
                               { return v[0] == to_string(userId); }),
                     grades.end());

        grades.shrink_to_fit();

        try
        {
            if (gradesFile.good() && gradesFile.is_open())
            {
                int fileId, grade, classId;
                string topic, teacherName, surname, name;
                size_t topicSize, teacherNameSize, nameSize, surnameSize;

                for (int ii = 0; ii < grades.size(); ii++)
                {
                    fileId = stoi(grades[ii][0]);
                    classId = stoi(grades[ii][1]);
                    grade = stoi(grades[ii][2]);
                    topic = grades[ii][3];
                    teacherName = grades[ii][4];
                    name = grades[ii][5];
                    surname = grades[ii][6];

                    topicSize = topic.size();
                    teacherNameSize = teacherName.size();
                    nameSize = name.size();
                    surnameSize = surname.size();

                    gradesFile.write((char *)&fileId, sizeof(int));

                    gradesFile.write((char *)&classId, sizeof(int));

                    gradesFile.write((char *)&grade, sizeof(int));

                    gradesFile.write((char *)&topicSize, sizeof(size_t));
                    gradesFile.write(&topic[0], topicSize);

                    gradesFile.write((char *)&teacherNameSize, sizeof(size_t));
                    gradesFile.write(&teacherName[0], teacherNameSize);

                    gradesFile.write((char *)&nameSize, sizeof(size_t));
                    gradesFile.write(&name[0], nameSize);

                    gradesFile.write((char *)&surnameSize, sizeof(size_t));
                    gradesFile.write(&surname[0], surnameSize);
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

        gradesFile.close();
        grades.clear();
    }
}

void removeFromAbsences(int classId, int userId)
{
    vector<vector<string>> absences;
    vector<string> data;

    ifstream file(to_string(classId) + "-absences.bin", ios::binary);
    int length = 0;

    file.seekg(0, file.end);
    length = file.tellg();
    file.seekg(0, file.beg);
    cout << length << endl;

    try
    {
        if (file.good() && length > 0 && file.is_open())
        {
            int id;
            string date, subject, teacherName, name, surname;
            size_t dateSize, subjectSize, teacherNameSize, nameSize, surnameSize;

            while (file)
            {
                data.clear();

                file.read((char *)&dateSize, sizeof(size_t));
                date.resize(dateSize);
                file.read((char *)&date[0], dateSize);

                file.read((char *)&subjectSize, sizeof(size_t));
                subject.resize(subjectSize);
                file.read((char *)&subject[0], subjectSize);

                file.read((char *)&teacherNameSize, sizeof(size_t));
                teacherName.resize(teacherNameSize);
                file.read((char *)&teacherName[0], teacherNameSize);

                file.read((char *)&id, sizeof(int));

                file.read((char *)&nameSize, sizeof(size_t));
                name.resize(nameSize);
                file.read((char *)&name[0], nameSize);

                file.read((char *)&surnameSize, sizeof(size_t));
                surname.resize(surnameSize);
                file.read((char *)&surname[0], surnameSize);

                data.push_back(date);
                data.push_back(subject);
                data.push_back(teacherName);
                data.push_back(to_string(id));
                data.push_back(name);
                data.push_back(surname);

                absences.push_back(data);
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

    file.close();

    string path = to_string(classId) + "-absences.bin";
    remove(path.c_str());
    ofstream absencesFile(path, ios::binary);

    absences.erase(remove_if(absences.begin(), absences.end(), [userId](vector<string> v)
                             { return stoi(v[3]) == userId; }),
                   absences.end());

    absences.shrink_to_fit();

    try
    {
        if (absencesFile.good() && absencesFile.is_open())
        {
            int id;
            string date, subject, teacherName, name, surname;
            size_t dateSize, subjectSize, teacherNameSize, nameSize, surnameSize;

            for (int i = 0; i < absences.size(); i++)
            {
                date = absences[i][0];
                subject = absences[i][1];
                teacherName = absences[i][2];
                id = stoi(absences[i][3]);
                name = absences[i][4];
                surname = absences[i][5];

                dateSize = date.size();
                subjectSize = subject.size();
                teacherNameSize = teacherName.size();
                nameSize = name.size();
                surnameSize = surname.size();

                absencesFile.write((char *)&dateSize, sizeof(size_t));
                absencesFile.write(&date[0], dateSize);

                absencesFile.write((char *)&subjectSize, sizeof(size_t));
                absencesFile.write(&subject[0], subjectSize);

                absencesFile.write((char *)&teacherNameSize, sizeof(size_t));
                absencesFile.write(&teacherName[0], teacherNameSize);

                absencesFile.write((char *)&id, sizeof(int));

                absencesFile.write((char *)&nameSize, sizeof(size_t));
                absencesFile.write(&name[0], nameSize);

                absencesFile.write((char *)&surnameSize, sizeof(size_t));
                absencesFile.write(&surname[0], surnameSize);
            }
        }
        else
        {
            throw runtime_error("couldnt open a file");
        }
        absencesFile.close();
    }
    catch(exception &e)
    {
        cerr << e.what() << endl;
    }
}

void editClass(int edClassId, int edStudentId, string edName, string edSurname)
{
    vector<vector<string>> classes;
    classes = getClassMembers(edClassId);
    string path = to_string(edClassId) + "-class.bin";

    ofstream classesFile(path, ios::binary);

    for (int i = 0; i < classes.size(); i++)
    {
        if (classes[i][0] == to_string(edStudentId))
        {
            classes[i][1] = edName;
            classes[i][2] = edSurname;

            break;
        }
    }

    try
    {
        if (classesFile.good() && classesFile.is_open())
        {
            string name, surname;
            size_t nameSize, surnameSize;
            int cId;

            classes.shrink_to_fit();

            for (int i = 0; i < classes.size(); i++)
            {
                cId = stoi(classes[i][0]);
                name = classes[i][1];
                surname = classes[i][2];
                nameSize = name.size();
                surnameSize = surname.size();

                classesFile.write((char *)&cId, sizeof(int));

                classesFile.write((char *)&nameSize, sizeof(size_t));
                classesFile.write(&name[0], nameSize);

                classesFile.write((char *)&surnameSize, sizeof(size_t));
                classesFile.write(&surname[0], surnameSize);
            }
        }
        else
        {
            throw runtime_error("couldnt open a file");
        }

        classesFile.close();
    }
    catch(exception &e)
    {
        cerr << e.what() << endl;
    }
}

void editGrades(int previousClassId, int edClassId, int edStudentId, string edName, string edSurname)
{
    vector<vector<string>> grades;
    vector<string> data;
    string *subjects = new string[5];

    subjects[0] = "Math";
    subjects[1] = "English";
    subjects[2] = "Biology";
    subjects[3] = "Physics";
    subjects[4] = "Chemistry";

    for (int i = 0; i < 5; i++)
    {
        ifstream file(subjects[i] + "-grades.bin", ios::binary);

        int length = 0;

        file.seekg(0, file.end);
        length = file.tellg();
        file.seekg(0, file.beg);

        try
        {
            if (file.good() && length > 0 && file.is_open())
            {
                int fileId, grade, classId;
                string topic, teacherName, surname, name;
                size_t topicSize, teacherNameSize, nameSize, surnameSize;

                while (file)
                {

                    data.clear();

                    file.read((char *)&fileId, sizeof(int));

                    file.read((char *)&classId, sizeof(int));

                    file.read((char *)&grade, sizeof(int));

                    file.read((char *)&topicSize, sizeof(size_t));
                    topic.resize(topicSize);
                    file.read((char *)&topic[0], topicSize);

                    file.read((char *)&teacherNameSize, sizeof(size_t));
                    teacherName.resize(teacherNameSize);
                    file.read((char *)&teacherName[0], teacherNameSize);

                    file.read((char *)&nameSize, sizeof(size_t));
                    name.resize(nameSize);
                    file.read((char *)&name[0], nameSize);

                    file.read((char *)&surnameSize, sizeof(size_t));
                    surname.resize(surnameSize);
                    file.read((char *)&surname[0], surnameSize);

                    data.push_back(to_string(fileId));
                    data.push_back(to_string(classId));
                    data.push_back(to_string(grade));
                    data.push_back(topic);
                    data.push_back(teacherName);
                    data.push_back(name);
                    data.push_back(surname);

                    grades.push_back(data);
                }
                grades.pop_back();
            }
            else
            {
                throw runtime_error("couldnt open a file");
            }
            file.close();
        }
        catch(exception &e)
        {
            cerr << e.what() << endl;
        }

        string path = subjects[i] + "-grades.bin";
        ofstream gradesFile(path, ios::binary);

        for (int ii = 0; ii < grades.size(); ii++)
        {

            if (grades[ii][0] == to_string(edStudentId))
            {
                grades[ii][1] = to_string(edClassId);
                grades[ii][5] = edName;
                grades[ii][6] = edSurname;
            }
        }

        grades.shrink_to_fit();

        try
        {
            if (gradesFile.good() && gradesFile.is_open())
            {
                int fileId, grade, classId;
                string topic, teacherName, surname, name;
                size_t topicSize, teacherNameSize, nameSize, surnameSize;

                for (int ii = 0; ii < grades.size(); ii++)
                {
                    fileId = stoi(grades[ii][0]);
                    classId = stoi(grades[ii][1]);
                    grade = stoi(grades[ii][2]);
                    topic = grades[ii][3];
                    teacherName = grades[ii][4];
                    name = grades[ii][5];
                    surname = grades[ii][6];

                    topicSize = topic.size();
                    teacherNameSize = teacherName.size();
                    nameSize = name.size();
                    surnameSize = surname.size();

                    gradesFile.write((char *)&fileId, sizeof(int));

                    gradesFile.write((char *)&classId, sizeof(int));

                    gradesFile.write((char *)&grade, sizeof(int));

                    gradesFile.write((char *)&topicSize, sizeof(size_t));
                    gradesFile.write(&topic[0], topicSize);

                    gradesFile.write((char *)&teacherNameSize, sizeof(size_t));
                    gradesFile.write(&teacherName[0], teacherNameSize);

                    gradesFile.write((char *)&nameSize, sizeof(size_t));
                    gradesFile.write(&name[0], nameSize);

                    gradesFile.write((char *)&surnameSize, sizeof(size_t));
                    gradesFile.write(&surname[0], surnameSize);
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


        try
        {
            gradesFile.close();
            grades.clear();
        }
        catch(exception &e)
        {
            cerr << e.what() << endl;
        }
    }
}

void editAbsences(int previousClassId, int edClassId, int edStudentId, string edName, string edSurname, bool classChanged)
{
    vector<vector<string>> absences;
    vector<string> data;

    ifstream file(to_string(previousClassId) + "-absences.bin", ios::binary);
    int length = 0;

    file.seekg(0, file.end);
    length = file.tellg();
    file.seekg(0, file.beg);

    try
    {
        if (file.good() && length > 0 && file.is_open())
        {
            int id;
            string date, subject, teacherName, name, surname;
            size_t dateSize, subjectSize, teacherNameSize, nameSize, surnameSize;

            while (file)
            {
                data.clear();

                file.read((char *)&dateSize, sizeof(size_t));
                date.resize(dateSize);
                file.read((char *)&date[0], dateSize);

                file.read((char *)&subjectSize, sizeof(size_t));
                subject.resize(subjectSize);
                file.read((char *)&subject[0], subjectSize);

                file.read((char *)&teacherNameSize, sizeof(size_t));
                teacherName.resize(teacherNameSize);
                file.read((char *)&teacherName[0], teacherNameSize);

                file.read((char *)&id, sizeof(int));

                file.read((char *)&nameSize, sizeof(size_t));
                name.resize(nameSize);
                file.read((char *)&name[0], nameSize);

                file.read((char *)&surnameSize, sizeof(size_t));
                surname.resize(surnameSize);
                file.read((char *)&surname[0], surnameSize);

                data.push_back(date);
                data.push_back(subject);
                data.push_back(teacherName);
                data.push_back(to_string(id));
                data.push_back(name);
                data.push_back(surname);

                absences.push_back(data);
            }
            absences.pop_back();
        }
        else
        {
            throw runtime_error("couldnt open a file");
        }

        file.close();
    }
    catch(exception &e)
    {
        cerr << e.what() << endl;
    }

    ofstream absencesFile;
    string path = to_string(edClassId) + "-absences.bin";

    if (classChanged)
    {
        absencesFile = ofstream(path, ios::binary | ios::app);
    }
    else
    {
        remove(path.c_str());
        absencesFile = ofstream(path, ios::binary);
    }

    for (int i = 0; i < absences.size(); i++)
    {
        if (absences[i][3] == to_string(edStudentId))
        {
            absences[i][4] = edName;
            absences[i][5] = edSurname;
        }
    }

    absences.erase(remove_if(absences.begin(), absences.end(), [edStudentId, classChanged](vector<string> &v)
                             { return v[3] != to_string(edStudentId) && classChanged; }),
                   absences.end());

    absences.shrink_to_fit();
    
    try
    {
        if (absencesFile.good() && absencesFile.is_open())
        {
            int id;
            string date, subject, teacherName, name, surname;
            size_t dateSize, subjectSize, teacherNameSize, nameSize, surnameSize;

            for (int i = 0; i < absences.size(); i++)
            {
                date = absences[i][0];
                subject = absences[i][1];
                teacherName = absences[i][2];
                id = stoi(absences[i][3]);
                name = absences[i][4];
                surname = absences[i][5];

                dateSize = date.size();
                subjectSize = subject.size();
                teacherNameSize = teacherName.size();
                nameSize = name.size();
                surnameSize = surname.size();

                absencesFile.write((char *)&dateSize, sizeof(size_t));
                absencesFile.write(&date[0], dateSize);

                absencesFile.write((char *)&subjectSize, sizeof(size_t));
                absencesFile.write(&subject[0], subjectSize);

                absencesFile.write((char *)&teacherNameSize, sizeof(size_t));
                absencesFile.write(&teacherName[0], teacherNameSize);

                absencesFile.write((char *)&id, sizeof(int));

                absencesFile.write((char *)&nameSize, sizeof(size_t));
                absencesFile.write(&name[0], nameSize);

                absencesFile.write((char *)&surnameSize, sizeof(size_t));
                absencesFile.write(&surname[0], surnameSize);
            }
        }
        else
        {
            throw runtime_error("couldnt open a file");
        }
        absencesFile.close();
    }
    catch(exception &e)
    {
        cerr << e.what() << endl;
    }
}
