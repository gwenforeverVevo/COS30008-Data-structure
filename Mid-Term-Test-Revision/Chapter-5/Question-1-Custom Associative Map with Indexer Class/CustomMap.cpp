#include "CustomMap.h"

using namespace std;

CustomMap::CustomMap() : data(n, o)
{
}

void CustomMap::insert(const string &key, int value)
{

    if (isdigit(value) == false)
    {
        cout << "The value is not an interger";
        exit;
    }
    return data[key] = value;
}

int CustomMap::operator[](const string &key) const
{
    auto it = data.find(key);
    if (it != data.end())
    {
        return it->second;
    }
    else
    {
        throw out_of_range("Out of range");
    }
}

void CustomMap::remove(const string &key)
{
    auto it = data.find(key);
    if (it != data.end())
    {
        data.erase(it);
    }
    else
    {
        throw out_of_range("Out of range");
    }
}

bool CustomMap::contains(const string &key) const
{
    return data.find(key) != data.end();
}

int CustomMap::size()
{
    return data.size();
}