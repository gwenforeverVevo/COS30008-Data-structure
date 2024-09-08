#pragma once

class Temperature {
private:
    double kelvin;

public:
    // Constructor
    Temperature();

    // Setters
    void setTempKelvin(double kelvin);
    void setTempFahrenheit(double fahrenheit);
    void setTempCelsius(double celsius);

    // Getters
    double getTempKelvin() const;
    double getTempFahrenheit() const;
    double getTempCelsius() const;
};
