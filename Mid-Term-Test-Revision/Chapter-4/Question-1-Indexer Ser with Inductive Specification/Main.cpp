#include <iostream>
#include <map>

using namespace std;

// Recursive function to generate multiples of 3
int generateMultiplesOfThree(int index) {
    // Base case: If index is 0, return 0
    if (index == 0)
        return 0;
    
    // Recursive step: Return the multiple of 3 for the current index
    return /* Complete this recursive call */;
}

// Function to create an indexed set and assign unique indices
void createIndexedSet(int size) {
    std::map<std::string, int> indexedSet;

    for (int i = 0; i < size; ++i) {
        std::string indexKey = "Num_" + std::to_string(i);

        // Insert the generated value with its unique index
        indexedSet[indexKey] = /* Use the recursive function here */;

        // Print the indexed value
        std::cout << indexKey << ": " << indexedSet[indexKey] << std::endl;
    }
}

int main() {
    int size;
    std::cout << "Enter the size of the indexed set: ";
    std::cin >> size;

    // Create the indexed set of multiples of 3
    createIndexedSet(size);

    return 0;
}
