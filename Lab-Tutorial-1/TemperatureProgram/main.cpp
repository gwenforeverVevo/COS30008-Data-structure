#include <iostream>
#include "Temperature.h"

using namespace std;

int main() {
    Temperature temp;
    temp.setTempKelvin(300);

    cout << temp.getTempKelvin() << " degrees Kelvin" << endl;
    cout << temp.getTempFahrenheit() << " degrees Fahrenheit" << endl;
    cout << temp.getTempCelsius() << " degrees Celsius" << endl;

    cout << "---------------------------\n\n";

    temp.setTempFahrenheit(32);

    cout << temp.getTempKelvin() << " degrees Kelvin" << endl;
    cout << temp.getTempFahrenheit() << " degrees Fahrenheit" << endl;
    cout << temp.getTempCelsius() << " degrees Celsius" << endl;

    cout << "---------------------------\n\n";

    temp.setTempCelsius(0);

    cout << temp.getTempKelvin() << " degrees Kelvin" << endl;
    cout << temp.getTempFahrenheit() << " degrees Fahrenheit" << endl;
    cout << temp.getTempCelsius() << " degrees Celsius" << endl;

    return 0;
}
