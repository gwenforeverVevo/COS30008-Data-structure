#include "ComponentBase.h"

using namespace std;

ComponentBase::ComponentBase(double aBaseValue,
                             const string &aMajorUnit,
                             const string &aMinorUnits) noexcept : fBaseValue(aBaseValue),
                                                                   fMajorUnit(aMajorUnit),
                                                                   fMinorUnits(aMinorUnits)
{
}

virtual ~ComponentBase() {}

double ComponentBase::getBaseValue() const noexcept
{
    return fBaseValue;
}
void ComponentBase::setBaseValue(double aBaseValue) noexcept
{
    fBaseValue = aBaseValue;
}

const string &ComponentBase::getMajorUnit() const noexcept
{
    return fMajorUnit;
}
const string &ComponentBase::getMinorUnits() const noexcept
{
    return fMinorUnits;
}

virtual bool ComponentBase::mustAdjust(double aValue) const noexcept = 0;
// returns component dependent scalar
virtual const double ComponentBase::getScalar() const noexcept = 0;

// returns (frequency-dependent) passive resistance value
virtual double ComponentBase::getReactance(double aFrequency = 0.0) const noexcept = 0;

// returns (frequency-dependent) voltage drop
double ComponentBase::getPotentialAt(double aCurrent,
                                     double aFrequency = 0.0) const noexcept
{
    return getReactance(aFrequency) * aCurrent;
}
// returns (frequency-dependent) current flowing through a resistor
double ComponentBase::getCurrentAt(double aVoltage,
                                   double aFrequency = 0.0) const noexcept
{
}

friend istream &operator>>(istream &aIStream, ComponentBase &aObject)
{
    double lValue;
    string lUnit;

    aIStream >> lValue >> lUnit;

    aObject.setBaseValue(lValue, lUnit);

    return aIStream;
}

friend ostream &operator<<(ostream &aOStream, const ComponentBase &aObject)
{
    double lValue;
    std::string lUnit;

    aObject.toUnitValue(lValue, lUnit);

    return aOStream << lValue << " " << lUnit;
}