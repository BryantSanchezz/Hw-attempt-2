#include <iostream>
#include <bitset>
#include <string>
#include <cmath>

//  convert integer to binary
std::string intToBinary(int num) {
    return std::bitset<32>(num).to_string();  //  integer to 32-bit binary
}

//   convert character to binary
std::string charToBinary(char ch) {
    return std::bitset<8>(ch).to_string();  //  character to 8-bit binary
}

// convert float to binary
std::string floatToBinary(float num) {
    int intPart = static_cast<int>(num);  //   integer part
    float fracPart = num - intPart;  //   fractional part

    // integer part to binary
    std::string binaryIntPart = intToBinary(intPart);

    //  fractional part to binary
    std::string binaryFracPart = ".";
    while (fracPart > 0 && binaryFracPart.length() < 10) {  // 10 bits
        fracPart *= 2;
        int fracBit = static_cast<int>(fracPart);
        binaryFracPart += std::to_string(fracBit);
        fracPart -= fracBit;
    }

    return binaryIntPart + binaryFracPart;
}

// Main function
int main() {
    int intValue;
    char charValue;
    float floatValue;

    std::cout << "Enter an integer: ";
    std::cin >> intValue;
    std::cout << "Binary representation of integer: " << intToBinary(intValue) << std::endl;

    std::cout << "Enter a character: ";
    std::cin >> charValue;
    std::cout << "Binary representation of character: " << charToBinary(charValue) << std::endl;

    std::cout << "Enter a float: ";
    std::cin >> floatValue;
    std::cout << "Binary representation of float: " << floatToBinary(floatValue) << std::endl;

    return 0;
}
