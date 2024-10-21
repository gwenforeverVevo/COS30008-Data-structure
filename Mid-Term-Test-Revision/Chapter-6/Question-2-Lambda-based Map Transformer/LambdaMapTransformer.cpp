#ifndef LAMBDA_MAP_TRANSFORMER_H
#define LAMBDA_MAP_TRANSFORMER_H

#include <map>
#include <string>
#include <functional>

class LambdaMapTransformer
{
private:
    std::map<std::string, int> data;

public:
    LambdaMapTransformer();  // Constructor

    // Insert key-value pair into the map
    void insert(const std::string &key, int value);

    // Apply a transformation function to all values in the map
    void transformValues(std::function<int(int)> transformer);

    // Apply a transformation function to the map, creating a new map
    std::map<std::string, int> mapToNew(std::function<int(const std::string &, int)> transformer);
};

#endif // LAMBDA_MAP_TRANSFORMER_H
