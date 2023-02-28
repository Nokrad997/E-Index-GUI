#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include "StudentRepository.h"
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * @brief Klasa Student
 * zawiera metody, które są wykorzystywane przez klasę Student
 */
class Student : public StudentRepository
{
public:
    /**
     * @brief konsturktor obiektu student
     * 
     */
    Student(){};

    /**
     * @brief destruktor obiektu student
     * 
     */
    ~Student(){};

    /**
     * @brief znajduje wszystkie oceny ucznia
     * 
     * @return vector<string>  wektor z danymi użytkownika
     */
    vector<vector<string>> getGrades() override;

    /**
     * @brief znajduje wszystkie oceny ucznia z danego przedmiotu
     * 
     * @param subject przedmiot
     * @return vector<string> wektor z danymi użytkownika
     */
    vector<vector<string>> getGrades(std::string subject) override;

    /**
     * @brief znajduje wszystkie nieobecności ucznia z danego przedmiotu
     * 
     * @param classNumber  numer klasy
     * @return vector<vector<string>>  wektor z danymi użytkownika
     */
    vector<vector<string>> getDatesOfAbsences(int classNumber) override;
    
    /**
     * @brief znajduje wszystkie nieobecności ucznia z danego przedmiotu
     * 
     * @param classNumber  numer klasy
     * @param subject  przedmiot
     * @return vector<vector<string>>  wektor z danymi użytkownika
     */
    vector<vector<string>> getDatesOfAbsences(int classNumber, string subject) override;
    
    /**
     * @brief znajduje wszystkie daty nadchodzących testow
     * 
     * @return vector<vector<string>> wektor z danymi testow
     */
    vector<vector<string>> getDatesOfUpcomingTests() override;

    /**
     * @brief oblicza srednia z kazdego przedmiotu
     * 
     * @return vector<vector<string>> zwraca wektor z srednimi z kazdego przedmiotu
     */
    vector<vector<string>> calculateAverageFromEverySubject() override;

    /**
     * @brief oblicza srednia z przedmiotu
     * 
     * @param subject  przedmiot
     * @return zwraca srednia z przedmiotu zaokraglona do 2 miejsc po przecinku
     */
    double operator/(int a) {
        double result = 1/a;
        return round(result * 100.0) / 100.0;
    }
};

#endif // STUDENT_H
