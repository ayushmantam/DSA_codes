#include <iostream>
#include <fstream>

int main() {
    // Create an ofstream object and open a file
    std::ofstream outFile("example.txt");

    // Check if the file is open
    if (!outFile.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        return 1;
    }

    // Write data to the file
    outFile << "Hello, File Handling in C++!" << std::endl;
    outFile << 42 << std::endl;

    // Close the file
    outFile.close();

    return 0;
}
