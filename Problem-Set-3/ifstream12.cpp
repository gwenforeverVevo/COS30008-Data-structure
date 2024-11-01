#include "ifstream12.h"
#include <cassert>
#include <iostream> // For debug output

ifstream12::ifstream12(const char* aFileName, size_t aBufferSize) :
    fBuffer(new std::byte[aBufferSize]), fBufferSize(aBufferSize),
    fByteCount(0), fByteIndex(0), fBitIndex(-1)
{
    if (aFileName)
    {
        open(aFileName);
    }
}

ifstream12::~ifstream12()
{
    close();
    delete[] fBuffer;
}

void ifstream12::open(const char* aFileName)
{
    fIStream.open(aFileName, std::ifstream::binary);
    assert(fIStream.is_open());
    // std::cout << "Opened file: " << aFileName << std::endl; // Debug
}

void ifstream12::close()
{
    // std::cout << "Closing file." << std::endl; // Debug
    fIStream.close();
}

bool ifstream12::isOpen() const
{
    return fIStream.is_open();
}

bool ifstream12::good() const
{
    return fIStream.good();
}

bool ifstream12::eof() const
{
    // Check that the stream is exhausted: file EOF, no bytes left, and no remaining bits
    return fIStream.eof() && fByteIndex >= fByteCount && fBitIndex == 7; // Fully exhausted when all bits are read
}

void ifstream12::reset()
{
    fByteIndex = 0;
    fBitIndex = 7; // Start at the highest bit of the byte
}

void ifstream12::fetch_data()
{
    if (fByteCount == 0) // Fetch data only if no bytes are left
    {
        fIStream.read(reinterpret_cast<char*>(fBuffer), fBufferSize);
        fByteCount = fIStream.gcount(); // update byte count with number of bytes read
        reset();
        // std::cout << "Fetched " << fByteCount << " bytes of data into buffer." << std::endl; // Debug
    }
}

std::optional<size_t> ifstream12::readBit()
{
    if (fByteCount == 0) // Fetch data if necessary
    {
        fetch_data();
        if (fByteCount == 0)
        {
            return std::nullopt; // No more data to read
        }
    }

    // Convert the byte to an integer type before performing the bitwise operation
    size_t currentByte = std::to_integer<size_t>(fBuffer[fByteIndex]);
    size_t bitValue = (currentByte & (1 << fBitIndex)) ? 1 : 0;  // Perform the bitwise operation on integer

    fBitIndex--;
    if (fBitIndex < 0) // Move to the next byte when all bits of the current byte are read
    {
        fBitIndex = 7;
        fByteIndex++;
        fByteCount--;

        // std::cout << "Moved to next byte. Byte index: " << fByteIndex << ", bits remaining: " << fByteCount << std::endl; // Debug

        // Check if we need to fetch more data, but only if there are still remaining bytes
        if (fByteCount == 0 && !fIStream.eof())
        {
            fetch_data();
        }
    }

    return bitValue;
}

ifstream12& ifstream12::operator>>(size_t& aValue)
{
    aValue = 0;

    for (int i = 0; i < 12; i++) // Read 12 bits
    {
        auto bit = readBit();
        if (!bit.has_value()) 
        {
            // std::cout << "Reached EOF while reading bits." << std::endl;
            break; // Stop if EOF is reached
        }
        aValue |= (bit.value() << i); // Shift the bit into the correct position
    }

    // std::cout << "Read 12-bit value: " << aValue << std::endl; // Debug
    return *this;
}
