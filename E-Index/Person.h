#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/**
 * @brief Klasa Person
 * bazowa klasa dla wszystkich użytkowników
 */

class Person
{
protected:
    /**
     * @brief id użytkownika
     */
    int id;

    /**
     * @brief numer klasy
     */
    int classNumber;

    /**
     * @brief imię użytkownika i jego rozmiar
     */
    size_t nameSize;
    string name;

    /**
     * @brief nazwisko użytkownika i jego rozmiar
     */
    size_t surnameSize;
    string surname;

    /**
     * @brief email użytkownika i jego rozmiar
     */
    size_t emailSize;
    string email;

    /**
     * @brief rola użytkownika i jego rozmiar
     */
    size_t roleSize;
    string role;

    /**
     * @brief hasło użytkownika i jego rozmiar
     */
    size_t passwordSize;
    string password;

public:
    /**
     * @brief konstruktor parametryczny obiektu Person
     * 
     * @param classNumber   numer klasy
     * @param name  imię
     * @param surname  nazwisko
     * @param email  email
     * @param role  rola
     * @param password  hasło
     */
    Person(int classNumber, string name, string surname, string email, string role, string password);

    /**
     * @brief konstruktor domyślny obiektu Person
     * 
     */
    Person();

    /**
     * @brief destruktor obiektu Person
     * 
     */
    virtual ~Person(){};

    /**
     * @brief zapisuje dane użytkownika do pliku klasy
     * 
     * @param file  plik klasy
     */
    void writeToClass(ofstream &file);

    /**
     * @brief zapisuje dane użytkownika do pliku
     * 
     * @param file  plik głowny
     */
    void write(ofstream &file);

    /**
     * @brief wczytuje dane użytkownika z pliku
     * 
     * @param file  plik głowny
     */
    void read(ifstream &file);

    /**
     * @brief zwraca id uzytkownika
     * 
     * @return int id uzytkownika
     */
    virtual int getId();

    /**
     * @brief zwraca numer klasy
     * 
     * @return int numer klasy
     */
    virtual int getClassNumber();

    /**
     * @brief zwraca imię użytkownika
     * 
     * @return string imię użytkownika
     */
    virtual string getName();

    /**
     * @brief zwraca nazwisko użytkownika
     * 
     * @return string nazwisko użytkownika
     */
    virtual string getSurname();

    /**
     * @brief zwraca email użytkownika
     * 
     * @return string email użytkownika
     */
    virtual string getEmail();

    /**
     * @brief zwraca role użytkownika
     * 
     * @return string rola użytkownika
     */
    virtual string getRole();

    /**
     * @brief zwraca hasło użytkownika
     * 
     * @return string hasło użytkownika
     */
    virtual string getPassword();

    /**
     * @brief ustawia id użytkownika
     * 
     * @param id  id użytkownika
     */
    virtual void setId(int id);

    /**
     * @brief ustawia numer klasy
     * 
     * @param classNumber  numer klasy
     */
    virtual void setClassNumber(int classNumber);

    /**
     * @brief ustawia imię użytkownika
     * 
     * @param name  imię użytkownika
     */
    virtual void setName(string name);

    /**
     * @brief ustawia nazwisko użytkownika
     * 
     * @param surname  nazwisko użytkownika
     */
    virtual void setSurname(string surname);

    /**
     * @brief ustawia email użytkownika
     * 
     * @param email  email użytkownika
     */
    virtual void setEmail(string email);

    /**
     * @brief ustawia role użytkownika
     * 
     * @param role  rola użytkownika
     */
    virtual void setRole(string role);

    /**
     * @brief ustawia hasło użytkownika
     * 
     * @param password  hasło użytkownika
     */
    virtual void setPassword(string password);

    /**
     * @brief przeciążony operator strumieniowy <<
     * 
     * @param out  strumień wyjściowy
     * @param p1  obiekt Person
     * @return ostream&  strumień wyjściowy
     */
    friend ostream &operator<<(ostream &out, Person &p1)
    {
        out << "ID: " << p1.getId() << endl;
        out << "Name: " << p1.getName() << endl;
        out << "Surname: " << p1.getSurname() << endl;
        out << "Email: " << p1.getEmail() << endl;
        out << "Role: " << p1.getRole() << endl;
        return out;
    }
};

#endif // PERSON_H
