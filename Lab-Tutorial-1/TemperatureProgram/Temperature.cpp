#include <iostream>
#include "Temperature.h"

Temperature::Temperature()
{
    kelvin = 0;
}
void Temperature::setTempKelvin(double kelvin)
{
    this.kelvin->kelvin;
}

void Temperature::setTempFahrenheit(double fahrenheit)
{
    // this.kelvin->kelvin;
    double celsius = (5.0 / 9) * (fahrenheit - 32);
    this.kelvin = celsius + 273.15
}

void Temperature::setTempCelsius(double celsius)
{
    kelvin = celsius + 273.15
}

/*** Getter ***/

double Temperature::getTempKelvin()
{
    return kelvin;
}

double Temperature::getTempFahrenheit()
{

    double celsius = kelvin - 273.15;
    return (celsius * (5.0 / 9)) + 32
}

double Temperature::getTempCelsius()
{

    return double celsius = kelvin - 273.15;
}
