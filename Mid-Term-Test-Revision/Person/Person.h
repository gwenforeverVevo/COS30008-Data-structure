#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
private:
    std::string fName;
    std::string fID;
    int fAge;

public:
    // Constructor that initializes a person with their ID, name, and age
    Person(const std::string &id, const std::string &name, int age);

    // Accessor methods
    const std::string &getID() const;
    const std::string &getName() const;
    int getAge() const;

    // Method to display the details of the person
    void display() const;
};

#endif // PERSON_H
