#include "LambdaSorter.h"
#include <iostream>
#include <algorithm> // For std::sort
#include <numeric>   // For std::accumulate

using namespace std;

LambdaSorter::LambdaSorter()
{
}

void LambdaSorter::sort(vector<int> &vec, function<bool(int, int)> comparator)
{
    sort(vec.begin(), vec.end(), comparator);
}

vector<int> LambdaSorter::filter(const std::vector<int> &vec, std::function<bool(int)> predicate)
{
}