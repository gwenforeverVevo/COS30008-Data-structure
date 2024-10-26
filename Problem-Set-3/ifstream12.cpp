#include "ifstream12.h"
#include <cassert>

using namespace std;

void ifstream12::reset()
{
    for (size_t i = 0; i < fBufferSize; i++)
        fBuffer[i] &= std::byte{0};
    fByteIndex = 0;
    fBitIndex = 7;
}

ifstream12::ifstream12(const char *aFileName, size_t aBufferSize) : fBuffer(new std::byte[aBufferSize]),
                                                                    fBufferSize(aBufferSize),
                                                                    fByteCount(0),
                                                                    fByteIndex(0),
                                                                    fBitIndex(7)
{
    reset();
    open(aFileName);
}

ifstream12::~ifstream12()
{
    close();
    delete[] fBuffer;
}

void ifstream12::open(const char *aFileName)
{
    assert(!isOpen());
    if (aFileName)
    {
        fIStream.open(aFileName, ifstream::binary);
        fetch_data();
    }
}

void ifstream12::close()
{
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
    // The stream must be at the end, and we must have processed all bytes and bits
    return fIStream.eof() && (fByteIndex >= fByteCount) && (fBitIndex == 7);
}

void ifstream12::fetch_data()
{
    if (fIStream.good())
    {
        fIStream.read(reinterpret_cast<char *>(fBuffer), fBufferSize);
        fByteCount = fIStream.gcount();
        fByteIndex = 0;
        fBitIndex = 7;
    }
}

std::optional<size_t> ifstream12::readBit()
{
    if (fByteIndex >= fByteCount)
    {
        fetch_data();
        if (fByteIndex >= fByteCount)
        {
            return std::nullopt;
        }
    }

    size_t bit = (static_cast<size_t>(fBuffer[fByteIndex]) >> fBitIndex) & 1;
    fBitIndex--;

    if (fBitIndex < 0)
    {
        fByteIndex++;
        fBitIndex = 7;
    }

    return bit;
}

ifstream12 &ifstream12::operator>>(size_t &aValue)
{
    aValue = 0;
    for (size_t i = 0; i < 12; i++)
    {
        auto bit = readBit();
        if (!bit.has_value())
        {
            break;
        }
        aValue |= (bit.value() << i);
    }
    return *this;
}