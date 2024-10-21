#include <iostream>
#include <vector>

// Recursive binary search function
int binarySearch(const std::vector<int>& vec, int low, int high, int target) {
    if (low > high)
        return -1; // Base case: target not found

    int mid = low + (high - low) / 2;

    if (vec[mid] == target)
        return mid;  // Base case: target found
    else if (vec[mid] > target)
        return binarySearch(vec, low, mid - 1, target);  // Recursive step: search left
    else
        return binarySearch(vec, mid + 1, high, target); // Recursive step: search right
}

int main() {
    std::vector<int> vec = {1, 3, 5, 7, 9, 11, 13, 15};

    int target = 7;
    int result = binarySearch(vec, 0, vec.size() - 1, target);

    if (result != -1)
        std::cout << "Target found at index: " << result << std::endl;
    else
        std::cout << "Target not found." << std::endl;

    return 0;
}
