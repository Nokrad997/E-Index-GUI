#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <vector>
#include "StudentRepository.h"

using namespace std;

class Student1 : public StudentRepository
{
public:
    Student1(){};
    ~Student1(){};

    void studentMenu() override;
    void getGrades() override;
    void getGrades(std::string subject) override;
    void getDatesOfAbsences() override;
    void getDatesOfAbsences(std::string subject) override;
    void getDatesOfUpcomingTests() override;
    void calculateAverageFromEverySubject() override;
};

#endif // STUDENT_H
