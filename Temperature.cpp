#include "Temperature.h"

// Constructor implementation
Temperature::Temperature()
{
    kelvin = 0;
}

// Set temperature in Kelvin
void Temperature::setTempKelvin(double kelvin)
{
    this->kelvin = kelvin;
}

// Set temperature in Fahrenheit and convert to Kelvin
void Temperature::setTempFahrenheit(double fahrenheit)
{
    double celsius = (5.0 / 9) * (fahrenheit - 32);
    kelvin = celsius + 273.15;
}

// Set temperature in Celsius and convert to Kelvin
void Temperature::setTempCelsius(double celsius)
{
    kelvin = celsius + 273.15;
}

// Get temperature in Kelvin
double Temperature::getTempKelvin() const
{
    return kelvin;
}

// Convert Kelvin to Fahrenheit and return
double Temperature::getTempFahrenheit() const
{
    return (kelvin - 273.15) * 9.0 / 5 + 32;
}

// Convert Kelvin to Celsius and return
double Temperature::getTempCelsius() const
{
    return kelvin - 273.15;
}
