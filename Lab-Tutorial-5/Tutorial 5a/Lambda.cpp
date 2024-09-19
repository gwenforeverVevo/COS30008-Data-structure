#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using functionType = std::function<int(void)>;
void displayResult(functionType,string);
const int SIZE = 10;

int main()
{
    // Quesiton 1
    int number[10] = {10, 8, 35, 12, 3, 57, 19, 22, 64, 9};

    // Question 2
    auto average_lambda = [](const vector<int> &arr)
    {
        double sum = 0;
        for (int num : arr)
        {
            sum += num;
        }
        return sum / arr.size();
    };

    auto getAverage = [number]() -> int
    {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
        {
            sum += number[i];
        }
        return sum / SIZE;
    };

    // Qeusion 3
    auto getLargeValue = [number]() -> int
    {
        int Biggest = 0;
        for (int i = 0; i < SIZE; i++)
        {
            if (Biggest < number[i])
            {
                Biggest = number[i];
            }
        }
        return Biggest;
    };

    // Question 4
    auto getPosition = [number](int i) -> int
    {
        int Biggest = number[0];
        for (int j = 0; j < SIZE; j++)
        {
            if (number[i] == i)
            {
                return j;
            }
        }
        return -1;
    };
    // Question 5
    auto displayLambda = [](auto lambda_fcuntion) {

    };

    cout << "Average of numbers:" << endl;
    getAverage(average_lambda);

    cout << "Largest value in numbers:" << endl;
    getLargeValue(largest_lambda);

    // Question 7: Call position_lambda in main
    int num_to_find = 35;
    int position = getPosition(num_to_find);
    cout << "The position of " << num_to_find << " in the array is: " << position << endl;

    return 0;
}

void displayerResult(functionType myLambda, string message)
{
    cout << message << myLambda() << endl;
}
