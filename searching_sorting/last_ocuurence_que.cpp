#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int lastOcc(vector<int> arr, int target)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (target == arr[mid])
        {
            ans = mid;
            s = mid + 1; // we want last occ so right most
        }
        else if (target < arr[mid])
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    vector<int> v{1, 2, 3, 3, 3, 3, 4, 4, 4, 4, 6, 7};
    int target = 4;
    int indexOfLastOcc = lastOcc(v, target);
    cout << "lastOcc index is: " << indexOfLastOcc << endl;
    // output
    // lastOcc index is: 9

    //upper bound is in built function  for last ouccurence
   
}
