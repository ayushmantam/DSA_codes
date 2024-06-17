#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr{10, 1, 7, 8, 14, 9};
    int n = arr.size();

    // Insertion sort
    for (int round = 1; round < n; round++)
    {
        // Step a: fetch
        int val = arr[round];
        int j = round - 1;

        // Step b: compare and shift
        while (j >= 0 && arr[j] > val)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // Step c: insert the value
        arr[j + 1] = val;
    }

    // Printing the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
