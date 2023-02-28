#ifndef STUDENTREPOSITORY_H
#define STUDENTREPOSITORY_H

#include <iostream>
#include <vector>
#include "Person.h"

/**
 * @brief Klasa StudentRepository
 * zawiera metody, które są wykorzystywane przez klasę Student
 */
class StudentRepository : public Person
{
public:
    /**
     * @brief konsturktor obiektu studentRepository
     * 
     */
    StudentRepository(){};
    
    /**
     * @brief destruktor obiektu studentRepository
     * 
     */
    virtual ~StudentRepository() = default;

    /**
     * @brief znajduje wszystkie oceny ucznia
     * 
     * @return vector<string>  wektor z danymi użytkownika
     */
    virtual vector<vector<string>> getGrades() = 0;
    
    /**
     * @brief znajduje wszystkie oceny ucznia z danego przedmiotu
     * 
     * @param subject przedmiot
     * @return vector<string> wektor z danymi użytkownika
     */
    virtual vector<vector<string>> getGrades(string subject) = 0;
    
    /**
     * @brief znajduje wszystkie nieobecności ucznia z danego przedmiotu
     * 
     * @param classNumber  numer klasy
     * @return vector<vector<string>>  wektor z danymi użytkownika
     */
    virtual vector<vector<string>> getDatesOfAbsences(int classNumber) = 0;
    
    /**
     * @brief znajduje wszystkie nieobecności ucznia z danego przedmiotu
     * 
     * @param classNumber  numer klasy
     * @param subject  przedmiot
     * @return vector<vector<string>>  wektor z danymi użytkownika
     */
    virtual vector<vector<string>> getDatesOfAbsences(int classNumber, string subject) = 0;
    
    /**
     * @brief znajduje wszystkie daty testów ucznia z danego przedmiotu
     * 
     * @param classNumber  numer klasy
     * @return vector<vector<string>>  wektor z danymi użytkownika
     */
    virtual vector<vector<string>> getDatesOfUpcomingTests() = 0;
    
    /**
     * @brief znajduje wszystkie daty testów ucznia z danego przedmiotu
     * 
     * @param classNumber  numer klasy
     * @param subject  przedmiot
     * @return vector<vector<string>>  wektor z danymi użytkownika
     */
    virtual vector<vector<string>> calculateAverageFromEverySubject() = 0;
};

#endif // STUDENTREPOSITORY_H
