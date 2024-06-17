#include <iostream>
#include <ctime>    // For seeding the random number generator
#include <cstdlib>  // For generating random numbers
using namespace std;
// Function to create and return an array of random elements
int* generateRandomArray(int size, int min, int max) {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(nullptr)));
    
    // Allocate memory for the array
    int* arr = new int[size];
    
    // Generate random elements and assign them to the array
    for (int i = 0; i < size; ++i) {
        arr[i] = min + (rand() % (max - min + 1));
    }
    
    return arr;
}

int main() {
    int size = 10;
    int min = 1;
    int max = 100;
    
    int* randomArray = generateRandomArray(size, min, max);
    
    // Display the generated array
    for (int i = 0; i < size; ++i) {
        cout << randomArray[i] << " ";
    }
    
    // Don't forget to delete the allocated memory
    delete[] randomArray;
    
    return 0;
}
