#include "DentalAppointment.h"
#include <iostream>

#include "Person.h"
#include "Date.h"
using namespace std;

DentalAppointment::DentalAppointment(const Person &p, const Date &d, int dur)
    : patient(p), appointmentDate(d), duration(dur) {}

void DentalAppointment::display() const {
    cout << "Dental Appointment Details:" << endl;
    patient.display();
    appointmentDate.display();
    cout << "Duration: " << duration << " minutes" << endl;
}
