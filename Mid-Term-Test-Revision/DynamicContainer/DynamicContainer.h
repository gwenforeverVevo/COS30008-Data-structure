#ifndef DYNAMIC_CONTAINER_H
#define DYNAMIC_CONTAINER_H

#include <ostream>
#include <istream>

class DynamicContainer
{
private:
    int *fData;  // Dynamically allocated array of integers
    size_t fSize;  // Number of elements in the container

public:
    // Constructor to initialize the container with a given size
    DynamicContainer(size_t size);

    // Destructor to free the dynamically allocated memory
    ~DynamicContainer();

    // Accessor for size
    size_t getSize() const;

    // Index operator to access elements
    int &operator[](size_t index);

    // Overload the output stream operator to print container data
    friend std::ostream &operator<<(std::ostream &os, const DynamicContainer &container);

    // Overload the input stream operator to input container data
    friend std::istream &operator>>(std::istream &is, DynamicContainer &container);
};

#endif // DYNAMIC_CONTAINER_H
