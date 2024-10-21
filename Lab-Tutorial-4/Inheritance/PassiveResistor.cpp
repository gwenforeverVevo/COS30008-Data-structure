#include "PassiveResistor.h"
#include "ComponentBase.h"

using namespace std;

PassiveResistor::PassiveResistor(double aBaseValue) noexcept : ComponentBase(aBaseValue, "Ohm", "OkM")
{
}

bool PassiveResistor::mustAdjust(double aValue) const noexcept override
{
    if (aValue >= 1000.0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

const double PassiveResistor::getScalar() const noexcept override
{
    return 1.0 / 1000.0;
}

double getReactance(double aFrequency = 0.0) const noexcept override
{
    return getBaseValue();
}