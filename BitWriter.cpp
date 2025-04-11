#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

class BitWriter {
    private:
    std::vector<uint8_t> bitSet;
    // keeps track of how many bits out of 8 have been written
    int position = 0;
    uint8_t byte = 0;
    size_t bitCount = 0;

    public:
    void write(bool bitValue) {
        // left shift by one place
        byte <<= 1;
        // if true, sets the value to 1
        // otherwise, nothing is needed
        if (bitValue) {
            byte |= 1;
        }
        ++bitCount;
        ++position;

        // pushes full byte to vector and resets position back to 0
        if (position == 8) {
            bitSet.push_back(byte);
            byte = 0;
            position = 0;
        }
    }

    size_t getData(std::vector<uint8_t> &out) {
        // copy over the data currently in bitSet
        out = bitSet;
        // completes byte by placing 0s if incomplete
        if (position > 0) {
            out.push_back(byte);
        }
        return bitCount;
    }

    // referenced https://stackoverflow.com/questions/69563813/convert-stdarray-of-bytes-to-hex-stdstring
    // and had to look up stringstreams bc i've never seen those before... or any of this
    // and iomanip https://cplusplus.com/reference/iomanip/
    std::string toHexString(std::vector<uint8_t> bytes, const std::string& delim = "") {
        std::stringstream output;
        for (size_t i = 0; i < bytes.size(); ++i) {
            output << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << (int)(bytes[i]);
            if (i != bytes.size() - 1) {
              output << delim;
            }
        }
        return output.str();
    }

};