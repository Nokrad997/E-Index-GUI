#ifndef TEACHER_H
#define TEACHER_H

#include "TeacherRepository.h"
#include <QMessageBox>

/**
 * @brief Klasa Teacher
 * zawiera metody, które są wykorzystywane przez klasę Teacher
 * 
 */
class Teacher : public TeacherRepository
{
private:
    /**
     * @brief przedmiot nauczyciela
     * 
     */
    string subject;
public:
    /**
     * @brief konsturktor obiektu nauczyciel
     * 
     */
    Teacher(){};

    /**
     * @brief destruktor obiektu nauczyciel
     * 
     */
    virtual ~Teacher(){};

    /**
     * @brief dodaje test do bazy danych
     * 
     */
    void addTest(string date, string path, int classNumber, string topic) override;

    /**
     * @brief dodaje ocenę do bazy danych
     * 
     */
    void addGrades(string name, string surname, string topic, string subject, int id, int grade, int classNumber) override;
    
    /**
     * @brief znajduej wszystkich uczniow z danej klasy
     * 
     * @return vector<string>  wektor z danymi użytkownika
     */
    vector<vector<string>> getStudents(int classNumber) override;

    /**
     * @brief zapisuje nieobecnosci do bazy danych
     * 
     */
    void saveAbsence(int classNumber, string teacherName, string date, string subject, vector<string> student) override;

    /**
     * @brief znajduje i przypisuje przedmiot nauczyciela
     * 
     */
    void searchForTeacherSubject() override;

    /**
     * @brief ustawia przedmiot nauczyciela
     * 
     * @param subject przedmiot
     */
    void setSubject(string subject) override;

    /**
     * @brief zwraca przedmiot nauczyciela
     * 
     * @return string przedmiot
     */
    string getSubject() override;
};

#endif // TEACHER_H
