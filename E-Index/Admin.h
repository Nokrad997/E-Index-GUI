#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <vector>
#include "AdminRepository.h"

using namespace std;

/**
 * @brief Klasa Admin
 * zawiera metody, które są wykorzystywane przez klasę Admin
 */
class Admin : public AdminRepository
{
public:
    /**
     * @brief konsturktor obiektu admin
     * 
     */
    Admin(){};

    /**
     * @brief destruktor obiektu admin
     * 
     */
    ~Admin(){};

    /**
     * @brief znajduje wszystkich użytkowników
     * 
     * @return vector<Person>  wektor z danymi użytkowników 
     */
    vector<Person> getAllUsers() override;

    /**
     * @brief znajduje wszystkich uczniów z danej klasy
     * 
     * @param classNumber 
     * @return vector<vector<string>>  wektor z danymi użytkowników
     */
    vector<vector<string>> getAllUsersFromClass(int classNumber) override;

    /**
     * @brief usuwa użytkownika z bazy danych
     * 
     * @param userId  id użytkownika
     */
    void deleteUser(int userId = 0) override;

    /**
     * @brief edytuje dane użytkownika
     * 
     * @param user  obiekt klasy Person zawierający podstawowe dane użytkownika
     * @param previousClassNumber  poprzedni numer klasy
     * @param wasStudent  czy był studentem
     * @param classChanged  czy zmieniono klasę
     */
    void editUser(Person user, int previousClassNumber, bool wasStudent, bool classChanged) override;
};

#endif // ADMIN_H
