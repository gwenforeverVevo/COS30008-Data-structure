#include "Temperature.h"

// Constructor
Temperature::Temperature() {
    kelvin = 0;
}

// Setters
void Temperature::setTempKelvin(double kelvin) {
    this->kelvin = kelvin;
}

void Temperature::setTempFahrenheit(double fahrenheit) {
    double celsius = (fahrenheit - 32) * 5.0 / 9.0;
    kelvin = celsius + 273.15;
}

void Temperature::setTempCelsius(double celsius) {
    kelvin = celsius + 273.15;
}

// Getters
double Temperature::getTempKelvin() const {
    return kelvin;
}

double Temperature::getTempFahrenheit() const {
    double celsius = kelvin - 273.15;
    return (celsius * 9.0 / 5.0) + 32;
}

double Temperature::getTempCelsius() const {
    return kelvin - 273.15;
}
