#include <iostream>
#include <vector>
using namespace std;
//bubble sort me jo sabse bada hota hai usse pichhhe karte jaate hai
int main()
{
    vector<int> arr{10, 1, 7, 6, 14, 9};
    int n = arr.size();
    // bubble sort
    for (int round = 1; round < n; round++)
    {
        bool swapped = false;
        for (int j = 0; j < n - round; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            // sort ho chuka hai,no need to check in further rounds
            break;
        }
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // printing
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}