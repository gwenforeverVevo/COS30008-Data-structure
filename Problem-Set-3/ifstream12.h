#pragma once

#include <cstddef>  // for std::byte
#include <fstream>
#include <optional>

class ifstream12
{
private:
    std::ifstream fIStream;
    std::byte* fBuffer;  // Input buffer
    size_t fBufferSize;  // Input buffer size
    size_t fByteCount;   // Available input bytes
    size_t fByteIndex;   // Current byte index
    int fBitIndex;       // Current bit index (can be negative)

    void reset();       // Reset buffer
    void fetch_data();  // Read data
    std::optional<size_t> readBit();  // Read next bit

public:
    ifstream12(const char* aFileName = nullptr, size_t aBufferSize = 128);
    ~ifstream12();

    void open(const char* aFileName);
    void close();
    bool isOpen() const;
    bool good() const;
    bool eof() const;
    
    ifstream12& operator>>(size_t& aValue);

    // Declaration for isExhausted() method
    bool isExhausted() const;
};
