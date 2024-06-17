#include <iostream>
#include<vector>
using namespace std;
int binarySearchRec(vector<int>& nums, int low, int high, int target) {

    if (low > high) return -1; //Base case.

    // Perform the steps:
    int mid = (low + high) / 2;
    if (nums[mid] == target) return mid;
    else if (target > nums[mid])
        return binarySearchRec(nums, mid + 1, high, target);
    return binarySearchRec(nums, low, mid - 1, target);
}
int binarySearch(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;
    // int mid = (start + end) / 2; // have a issue int limit exceeded
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        int element = arr[mid];
        if (element == target)//element found then return index
        {
            return mid; // mil gya to pahle hi mid return kar dega
        }
        else if (target < element)
        {
            // search in left
            end = mid - 1;
        }
        else
        {
            // search in right
            start = mid + 1;
        }
        // calculation of mid at each step(in loop)
        // mid = (start + end) / 2;

        mid = start + (end - start) / 2;
    }

    return -1; // agar ni mila to
}

int main()
{
    int arr[] = {2, 3, 4, 5, 6, 7, 8};
    int size = 7;
    int target = 8;

    int indexOftarget = binarySearch(arr, size, target);
    if (indexOftarget == -1)
    {
        cout << "target not found" << endl;
    }
    else
    {
        cout << "target is found at " << indexOftarget << endl;
    }
    return 0;
}

// target is found at 6

