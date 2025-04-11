#include "BitWriter.cpp"

int main() {

    int passed = 0;
    int totalTests = 5;

    BitWriter writer;
    std::vector<bool> bits = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0};
    for (bool b : bits) {
        writer.write(b);
    }

    std::vector<u_int8_t> outputs;
    writer.getData(outputs);

    // example test
    std::cout << "Data set: {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0}" << std::endl;
    // TEST CASE 1
    std::cout << "Testing hex outputs..." << std::endl;
    std::string actualHex = writer.toHexString(outputs, "-");
    std::string expectedHex = "AA-0A";
    if (actualHex == expectedHex) {
        std::cout << "Test passed." << std::endl;
        ++passed;
    }
    else {
        std::cout << "Test failed." << std::endl;
        std::cout << "Expected: " << expectedHex << std::endl;
        std::cout << "Actual: " << actualHex << std::endl;
    }

    std::cout << std::endl;

    // TEST CASE 2
    size_t size = writer.getData(outputs);
    std::cout << "Testing size... " << std::endl;
    if (size == 12) {
        passed++;
        std::cout << "Test passed." << std::endl;
    }
    else {
        std::cout << "Test failed." << std::endl;
        std::cout << "Expected: 12" << std::endl;
        std::cout << "Actual: " << size << std::endl;
    }

    std::cout << std::endl;

    // testing 4-bit entry
    std::cout << "Data set: {1, 0, 0, 1}" << std::endl;
    BitWriter writer2;
    std::vector<bool> bits2 = {1, 0, 0, 1};
    for (bool b : bits2) {
        writer2.write(b);
    }

    std::vector<u_int8_t> outputs2;
    writer2.getData(outputs2);

    // TEST CASE 3
    std::cout << "Testing hex outputs..." << std::endl;
    std::string actualHex2 = writer2.toHexString(outputs2, "-");
    std::string expectedHex2 = "09";
    if (actualHex2 == expectedHex2) {
        std::cout << "Test passed." << std::endl;
        ++passed;
    }
    else {
        std::cout << "Test failed." << std::endl;
        std::cout << "Expected: " << expectedHex2 << std::endl;
        std::cout << "Actual: " << actualHex2 << std::endl;
    }

    std::cout << std::endl;

    // TEST CASE 4
    size_t size2 = writer2.getData(outputs);
    std::cout << "Testing size... " << std::endl;
    if (size2 == 4) {
        ++passed;
        std::cout << "Test passed." << std::endl;
    }
    else {
        std::cout << "Test failed." << std::endl;
        std::cout << "Expected: 4" << std::endl;
        std::cout << "Actual: " << size2 << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Data set: {}" << std::endl;
    // TEST CASE 5 (empty list)
    BitWriter writer3;
    std::vector<bool> bits3;
    std::cout << "Testing empty list... " << std::endl;
    std::vector<u_int8_t> empty;
    writer3.getData(empty);
    std::string actualHex3 = writer3.toHexString(empty, "-");
    std::string expectedHex3 = "";
    if (actualHex3 == expectedHex3) {
        std::cout << "Test passed." << std::endl;
        ++passed;
    }
    else {
        std::cout << "Test failed." << std::endl;
        std::cout << "Expected: " << expectedHex3 << std::endl;
        std::cout << "Actual: " << actualHex3 << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Total tests passed: " << passed << std::endl;
    std::cout << "Total tests failed: " << (totalTests - passed) << std::endl;




    return 0;
}