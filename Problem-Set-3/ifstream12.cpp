#include "ifstream12.h"
#include <cassert>
#include <iostream>

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
    // std::cout << "File opened: " << aFileName << std::endl;
}

void ifstream12::close()
{
    fIStream.close();
    // std::cout << "File closed." << std::endl;
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
    bool isExhausted = fIStream.eof() && (fByteCount == 0) && (fBitIndex == 7);
    // std::cout << "Checking EOF - fIStream.eof(): " << fIStream.eof() 
    //           << ", fByteCount: " << fByteCount 
    //           << ", fBitIndex: " << fBitIndex 
    //           << ", eof() result: " << isExhausted << std::endl;
    return isExhausted;
}

void ifstream12::reset()
{
    fByteIndex = 0;
    fBitIndex = 7;
}

void ifstream12::fetch_data()
{
    if (fByteCount == 0) 
    {
        fIStream.read(reinterpret_cast<char*>(fBuffer), fBufferSize);
        fByteCount = fIStream.gcount();

        // Force EOF detection if no bytes were read
        if (fByteCount == 0 && fIStream.peek() == EOF) 
        {
            fIStream.setstate(std::ios::eofbit); // Set EOF flag explicitly
        }

        reset();
        // std::cout << "Fetched " << fByteCount << " bytes into buffer." << std::endl;
    }
}

std::optional<size_t> ifstream12::readBit()
{
    if (fByteCount == 0) 
    {
        fetch_data();
        if (fByteCount == 0)
        {
            return std::nullopt;
        }
    }

    size_t currentByte = std::to_integer<size_t>(fBuffer[fByteIndex]);
    size_t bitValue = (currentByte & (1 << fBitIndex)) ? 1 : 0;

    fBitIndex--;
    if (fBitIndex < 0)
    {
        fBitIndex = 7;
        fByteIndex++;
        fByteCount--;

        if (fByteCount == 0 && !fIStream.eof())
        {
            fetch_data();
        }
    }

    // std::cout << "Read bit: " << bitValue 
    //           << ", fByteIndex: " << fByteIndex 
    //           << ", fBitIndex: " << fBitIndex 
    //           << ", fByteCount: " << fByteCount 
    //           << std::endl;

    return bitValue;
}

ifstream12& ifstream12::operator>>(size_t& aValue)
{
    aValue = 0;

    for (int i = 0; i < 12; i++)
    {
        auto bit = readBit();
        if (!bit.has_value()) 
        {
            // std::cout << "Reached EOF while reading 12 bits." << std::endl;
            break;
        }
        aValue |= (bit.value() << i);
    }

    // std::cout << "Read 12-bit value: " << aValue << std::endl;
    return *this;
}
