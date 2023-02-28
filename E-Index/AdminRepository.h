#ifndef ADMINREPOSITORY_H
#define ADMINREPOSITORY_H

#include <iostream>
#include <vector>

#include "Person.h"

/**
 * @brief Klasa AdminRepository
 * zawiera metody, które są wykorzystywane przez klasę Admin
 */

class AdminRepository : public Person
{
public:
    
    /**
     * @brief konstruktor obiektu AdminRepository
     * 
     */
    AdminRepository(){};
    
    /**
     * @brief destruktor obiektu AdminRepository
     * 
     */
    virtual ~AdminRepository(){};

    /**
     * @brief metoda znajduje wszystkich użytkowników
     * w bazie danych
     * 
     * @return vector<Person> wektor z danymi użytkowników 
     */
    virtual vector<Person> getAllUsers() = 0;

    /**
     * @brief metoda znajduje wszystkich użytkowników
     * z danej klasy
     * 
     * @param classNumber numer klasy
     * @return vector<vector<string>> wektor z danymi użytkowników 
     */
    virtual vector<vector<string>> getAllUsersFromClass(int classNumber) = 0;

    /**
     * @brief metoda usuwa użytkownika z bazy danych
     * 
     * @param userId id użytkownika
     */
    virtual void deleteUser(int userId) = 0;

    /**
     * @brief metoda edytuje dane użytkownika
     * 
     * @param user obiekt klasy Person zawierający podstawowe dane użytkownika
     * @param previousClassNumber poprzedni numer klasy
     * @param wasStudent czy był studentem
     * @param classChanged czy zmieniono klasę
     */
    virtual void editUser(Person user, int previousClassNumber, bool wasStudent, bool classChanged) = 0;
};

#endif // ADMINREPOSITORY_H
