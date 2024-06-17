#include <iostream>
using namespace std;

int main()
{
    int row = 5;
    int column = 4;
    int **arr = new int *[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[column];
    }
    // printing
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    //(Deallocation) Delete
    // 1st step
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    // 2nd step
    delete[] arr;
}