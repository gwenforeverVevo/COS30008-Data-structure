#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <ostream>
#include <istream>

class DynamicArray
{
private:
    int *data;
    size_t size;

public:
    // Constructor and Destructor
    DynamicArray(size_t size);
    ~DynamicArray();

    // Accessor for size
    size_t getSize() const;

    // Index operator
    int &operator[](size_t index);

    // Stream operators
    friend std::ostream &operator<<(std::ostream &os, const DynamicArray &array);
    friend std::istream &operator>>(std::istream &is, DynamicArray &array);
};

#endif // DYNAMIC_ARRAY_H
