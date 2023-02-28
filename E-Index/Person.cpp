#pragma once

#include <iostream>
#include "Person.h"
#include <fstream>
#include <cstring>

using namespace std;


Person::Person()
{
    id = 0;

    classNumber = 0;

    this->nameSize = 0;
    this->name = "";

    this->surnameSize = 0;
    this->surname = "";

    this->emailSize = 0;
    this->email = "";

    this->roleSize = 0;
    this->role = "";

    this->passwordSize = 0;
    this->password = "";
}

Person::Person(int classNumber, string name, string surname, string email, string role, string password)
{
    Person p1;
    ifstream file = ifstream("Database/users.bin", ios::binary);

    file.seekg(0, file.end);
    int length = file.tellg();
    file.seekg(0, file.beg);
    try
    {
        if(file.good() && length > 0 && file.is_open())
        {
            while (file)
            {
                p1.read(file);
            }
        }
        file.close();
    }
    catch(exception &e)
    {
        throw runtime_error("couldnt open a file");
    }

    id = p1.getId() + 1;

    this->classNumber = classNumber;

    this->nameSize = name.size();
    this->name = name;

    this->surnameSize = surname.size();
    this->surname = surname;

    this->emailSize = email.size();
    this->email = email;

    this->roleSize = role.size();
    this->role = role;

    this->passwordSize = password.size();
    this->password = password;
}

void Person::writeToClass(ofstream &file)
{
    try
    {
        if (file.good() && file.is_open())
        {
            file.write((char *)&id, sizeof(id));

            nameSize = name.size();
            file.write((char *)&nameSize, sizeof(nameSize));
            file.write((char *)&name[0], nameSize);

            surnameSize = surname.size();
            file.write((char *)&surnameSize, sizeof(surnameSize));
            file.write((char *)&surname[0], surnameSize);
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

void Person::write(ofstream &file)
{
    try
    {
        if (file.good() && file.is_open())
        {
            file.write((char *)&id, sizeof(id));

            file.write((char *)&classNumber, sizeof(classNumber));

            nameSize = name.size();
            file.write((char *)&nameSize, sizeof(nameSize));
            file.write((char *)&name[0], nameSize);

            surnameSize = surname.size();
            file.write((char *)&surnameSize, sizeof(surnameSize));
            file.write((char *)&surname[0], surnameSize);

            emailSize = email.size();
            file.write((char *)&emailSize, sizeof(emailSize));
            file.write((char *)&email[0], emailSize);

            roleSize = role.size();
            file.write((char *)&roleSize, sizeof(roleSize));
            file.write((char *)&role[0], roleSize);

            passwordSize = password.size();
            file.write((char *)&passwordSize, sizeof(passwordSize));
            file.write((char *)&password[0], passwordSize);
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

void Person::read(ifstream &file)
{
    try
    {
        if (file.good() && file.is_open())
        {
            file.read((char *)&id, sizeof(id));

            file.read((char *)&classNumber, sizeof(classNumber));

            file.read((char *)&nameSize, sizeof(nameSize));
            name.resize(nameSize);
            file.read((char *)&name[0], nameSize);

            file.read((char *)&surnameSize, sizeof(surnameSize));
            surname.resize(surnameSize);
            file.read((char *)&surname[0], surnameSize);

            file.read((char *)&emailSize, sizeof(emailSize));
            email.resize(emailSize);
            file.read((char *)&email[0], emailSize);

            file.read((char *)&roleSize, sizeof(roleSize));
            role.resize(roleSize);
            file.read((char *)&role[0], roleSize);

            file.read((char *)&passwordSize, sizeof(passwordSize));
            password.resize(passwordSize);
            file.read((char *)&password[0], passwordSize);
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

int Person::getId()
{
    return id;
}

int Person::getClassNumber()
{
    return classNumber;
}

string Person::getName()
{
    return name;
}

string Person::getSurname()
{
    return surname;
}

string Person::getEmail()
{
    return email;
}

string Person::getRole()
{
    return role;
}

string Person::getPassword()
{
    return password;
}

void Person::setId(int id)
{
    this->id = id;
}

void Person::setClassNumber(int classNumber)
{
    this->classNumber = classNumber;
}

void Person::setName(string name)
{
    this->name = name;
}

void Person::setSurname(string surname)
{
    this->surname = surname;
}

void Person::setEmail(string email)
{
    this->email = email;
}

void Person::setRole(string role)
{
    this->role = role;
}

void Person::setPassword(string password)
{
    this->password = password;
}

