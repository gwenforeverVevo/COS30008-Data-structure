#ifndef CUSTOM_MAP_H
#define CUSTOM_MAP_H

#include <map>
#include <string>

class CustomMap
{
private:
    std::map<std::string, int> data;  // Associative container

public:
    CustomMap();  // Constructor

    // Insert a key-value pair into the map
    void insert(const std::string &key, int value);

    // Return the value associated with a key
    int operator[](const std::string &key) const;

    // Delete a key from the map
    void remove(const std::string &key);

    // Check if a key exists
    bool contains(const std::string &key) const;

    // Get the size of the map
    int size() const;

    // A function that returns all keys sorted in alphabetical order
    std::vector<std::string> sortedKeys() const;
};

#endif // CUSTOM_MAP_H
