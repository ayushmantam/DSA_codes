#include <iostream>
using namespace std;

bool isSorted(int arr[], int n, int i)
{
    if (i == n - 1)
    {
        return true;
    }

    if (arr[i] < arr[i + 1])
    {
        return isSorted(arr, n, i + 1);
    }
    else
    {
        return false;
    }
}


int main()
{

    int arr[] = {1, 2, 3, 6, 7, 8};
    int n = 6;
    int i = 0;
    int ans = isSorted(arr, n, i);
    cout << ans;
    return 0;
}