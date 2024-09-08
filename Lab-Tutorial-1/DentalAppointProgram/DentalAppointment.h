#pragma once
#include "Person.h"
#include "Date.h"
using namespace std;

class DentalAppointment {
private:
    Person patient;
    Date appointmentDate;
    int duration; // Duration in minutes

public:
    DentalAppointment(const Person &p, const Date &d, int dur);
    void display() const;

};
