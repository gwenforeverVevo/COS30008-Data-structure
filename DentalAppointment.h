#ifndef DENTAL_APPOINTMENT_H
#define DENTAL_APPOINTMENT_H


#include "Person.h"
#include "Date.h"

class DentalAppointment {
private:
    Person patient;
    Date appointmentDate;
    int duration; // Duration in minutes

public:
    DentalAppointment(const Person &p, const Date &d, int dur);
    void display() const;
};

#endif
