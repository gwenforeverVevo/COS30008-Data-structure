#include "DentalAppointment.h"
#include <iostream>
using namespace std;
int main()
{
    // Creating a Person object
    Person patient("John", "Doe", 30);

    // Creating a Date object
    Date appointmentDate(15, 8, 2024);

    // Creating a DentalAppointment object
    DentalAppointment appointment(patient, appointmentDate, 60);

    // Displaying the appointment details
    appointment.display();

    return 0;
}
