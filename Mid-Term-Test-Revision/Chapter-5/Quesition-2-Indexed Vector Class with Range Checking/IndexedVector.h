#ifndef INDEXED_VECTOR_H
#define INDEXED_VECTOR_H

#include <vector>

class IndexedVector
{
private:
    std::vector<int> data;  // Underlying collection
    int size;

public:
    IndexedVector(int n);  // Constructor

    // Overload the [] operator with range checking
    const int &operator[](int index) const;

    // Get the size of the vector
    int getSize() const;

    // Set the value at a specific index
    void setValue(int index, int value);

    // Function to return the maximum element in the vector
    int maxElement() const;
};

#endif // INDEXED_VECTOR_H
