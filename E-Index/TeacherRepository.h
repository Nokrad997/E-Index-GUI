#ifndef TEACHERREPOSITORY_H
#define TEACHERREPOSITORY_H

#include "Person.h"
#include <QMessageBox>

/**
 * @brief Klasa TeacherRepository
 * zawiera metody, które są wykorzystywane przez klasę Teacher
 */
class TeacherRepository : public Person
{
public:

    /**
     * @brief konsturktor obiektu teacherRepository
     * 
     */
    TeacherRepository(){};

    /**
     * @brief destruktor obiektu teacherRepository
     * 
     */
    virtual ~TeacherRepository() = default;

    /**
     * @brief dodaje test do bazy danych
     * 
     */
    virtual void addTest(string date, string path, int classNumber, string topic) = 0;
    
    /**
     * @brief dodaje ocenę do bazy danych
     * 
     */
    virtual void addGrades(string name, string surname, string topic, string subject, int id, int grade, int classNumber) = 0;
    
    /**
     * @brief znajduej wszystkich uczniow z danej klasy
     * 
     * @return vector<string>  wektor z danymi użytkownika
     */
    virtual vector<vector<string>> getStudents(int classNumber) = 0;
    
    /**
     * @brief zapisuje nieobecnosci do bazy danych
     * 
     */
    virtual void saveAbsence(int classNumber, string teacherName, string date, string subject, vector<string> student) = 0;
    
    /**
     * @brief znajduje i przypisuje przedmiot nauczyciela
     * 
     */
    virtual void searchForTeacherSubject() = 0;
    
    /**
     * @brief ustawia przedmiot nauczyciela
     * 
     */
    virtual void setSubject(string subject) = 0;
    
    /**
     * @brief zwraca przedmiot nauczyciela
     * 
     */
    virtual string getSubject() = 0;
};

#endif // TEACHERREPOSITORY_H
