#ifndef LAMBDA_SORTER_H
#define LAMBDA_SORTER_H

#include <vector>
#include <functional>

class LambdaSorter
{
public:
    LambdaSorter();  // Constructor

    // Function to sort a vector of integers using a lambda comparator
    void sort(std::vector<int> &vec, std::function<bool(int, int)> comparator);

    // Function to filter a vector of integers using a lambda predicate
    std::vector<int> filter(const std::vector<int> &vec, std::function<bool(int)> predicate);

    // A function to find the sum of even or odd numbers using a lambda expression
    int sumFiltered(const std::vector<int> &vec, std::function<bool(int)> predicate);
};

#endif // LAMBDA_SORTER_H
