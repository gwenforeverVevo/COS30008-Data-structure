#ifndef LAMBDA_INDEXER_H
#define LAMBDA_INDEXER_H

#include <map>
#include <string>
#include <functional>

class LambdaIndexer
{
private:
    std::map<size_t, int> indexMap;  // Map with size_t keys

public:
    LambdaIndexer();  // Constructor

    // Function to insert a value, using a lambda to convert the key
    void insert(const std::string &key, int value, std::function<size_t(const std::string &)> keyConverter);

    // Get value using string key, applying lambda conversion from string to size_t
    int get(const std::string &key, std::function<size_t(const std::string &)> keyConverter) const;

    // Function to remove a key using a lambda conversion from string to size_t
    void remove(const std::string &key, std::function<size_t(const std::string &)> keyConverter);
};

#endif // LAMBDA_INDEXER_H
