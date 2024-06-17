#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int s, int e, int target)
{

    int mid = s + (e - s) / 2;

    if (s > e)
    {
        return 0;
    }

    if (arr[mid] == target)
    {
        return 1;
    }
    else if (arr[mid] > target)
    {
        // left search
        return binarySearch(arr, s, mid - 1, target);
    }
    else // right search
    {
        return binarySearch(arr, mid + 1, e, target);
    }
}

int main()
{
    vector<int> v{10, 20, 30, 40, 50, 60};
    int target = 90;
    int n = v.size();

    int s = 0;
    int e = n - 1;
    int ans = binarySearch(v, s, e, target);
    cout << "Answer is :" << ans << endl;

    return 0;
}