#include <iostream>
#include "Temperature.h"

int main()
{
    Temperature temp;

    // Set temperature in Kelvin
    temp.setTempKelvin(300.0);
    std::cout << "Temperature in Kelvin: " << temp.getTempKelvin() << " K\n";
    std::cout << "Temperature in Fahrenheit: " << temp.getTempFahrenheit() << " °F\n";
    std::cout << "Temperature in Celsius: " << temp.getTempCelsius() << " °C\n\n";

    // Set temperature in Fahrenheit
    temp.setTempFahrenheit(98.6);
    std::cout << "Temperature in Kelvin: " << temp.getTempKelvin() << " K\n";
    std::cout << "Temperature in Fahrenheit: " << temp.getTempFahrenheit() << " °F\n";
    std::cout << "Temperature in Celsius: " << temp.getTempCelsius() << " °C\n\n";

    // Set temperature in Celsius
    temp.setTempCelsius(25.0);
    std::cout << "Temperature in Kelvin: " << temp.getTempKelvin() << " K\n";
    std::cout << "Temperature in Fahrenheit: " << temp.getTempFahrenheit() << " °F\n";
    std::cout << "Temperature in Celsius: " << temp.getTempCelsius() << " °C\n";

    return 0;
}
