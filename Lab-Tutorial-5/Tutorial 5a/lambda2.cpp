#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using functionType = std::function<int(void)>;
void displayResult(functionType, string);
const int SIZE = 10;

int main()
{
    // Question 1
    int array[SIZE] = {10,
                       8,
                       35,
                       12,
                       3,
                       57,
                       19,
                       22,
                       64,
                       9};

    // Question 2
    auto calAverage = [array] -> int
    {
        int sum = 0 for (i = 0; i < SIZE; i++)
        {
            sum += array[i]
        }
        int average = sum / SIZE;
        return average;
    }

                                 // QUestion 3
                                 auto getMaximum = [array] -> int
    {
        max = 0;
        for (i = 0; i < SIZE; i++)
        {
            if (max < array[i])
            {
                max = array[i];
            }
        }
        return max;
    }
                                                              // Question 4
                                                              auto checkValue = [array](int value) -> int
    {
        for (i = 0; i < SIZE; i++)
        {
            if (array[i] == value)
            {
                return i;
            }
        }
        return -1;
    }

    // Question 6

    DisplayerResult(getMaximum, "The Max is ");
    DisplayerResult(calAverage, "The Average is ");

    // Question 7
    int value;
    cout << "Enter value" << endl;
    cin >> value;

    int position = checkValue(value);
    if (position != -1)
        cout << "The position is " << position << endl;
    else
        cout << "Value not found!!!!!" << endl;

    return 0;

    //Question

    void displayResult(function myLambda, string message){
        cout << message << myLambda() << endl;
    }
}