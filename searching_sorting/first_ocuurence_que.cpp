#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int firstOccurence(vector<int> arr, int target)
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
            e = mid - 1; // beacause we want to find first occurence so try to get left most
        }
        else if (target > arr[mid])
        {
            s = mid + 1;
        }
        else if (target < arr[mid])
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    vector<int> v{1, 2, 3, 3, 3, 3, 4, 4, 4, 4, 6, 7};
    int target = 7;
    int indexOffirstOcc = firstOccurence(v, target);
    cout << "ans is " << indexOffirstOcc << endl;

    int target2 = 7;
    auto ans2 = lower_bound(v.begin(), v.end(), target2);
    cout << "answer2 is " << ans2 - v.begin() << endl;
    return 0;
}
// ans is 11
// answer2 is 11