#include <iostream>
#include "Temperature.h"

using namespace std;

int main()
{

    Temperature temp;
    temp.setTempKelvin(100);

    cout << temp.getTempKelvin() << " degrees kelvin" << endl;
    cout << temp.getTempFahrenheit() << " degrees fahrenheit" << endl;
    cout << temp.getTempCelsius() << " degrees celsius" << endl;

    cout << "---------------------------\n\n";

    temp.setTempFahrenheit(-279.67);

    cout << temp.getTempKelvin() << " degrees kelvin" << endl;
    cout << temp.getTempFahrenheit() << " degrees fahrenheit" << endl;
    cout << temp.getTempCelsius() << " degrees celsius" << endl;

    cout << "---------------------------\n\n";

    temp.setTempCelsius(-173.15);

    cout << temp.getTempKelvin() << " degrees kelvin" << endl;
    cout << temp.getTempFahrenheit() << " degrees fahrenheit" << endl;
    cout << temp.getTempCelsius() << " degrees celsius" << endl;

    return 0;
}