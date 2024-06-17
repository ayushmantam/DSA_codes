#include <iostream>
#include <vector>
using namespace std;
//BHAI YE INCOMPLETE HAI PHIR SE CONNECT WAI  VIDEO DEKHNA HAI 
int findPivot(vector<int> arr)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if(s==e){   //single elment case 
            return s;
        }
        if (mid <= e && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        if (mid - 1 >= s && arr[mid - 1] > arr[mid])
        {
            return mid - 1;
        }
        if (arr[s] > arr[mid])
        {
            e = mid - 1;
        }

        else
        s = mid + 1;
        mid=s+(e-s)/2;

    }

    return -1;
}
int main()
{
    vector<int> arr{8,9, 19, 2, 4, 6};
    int ans = findPivot(arr);

    if (ans == -1)
    {
        cout << "kuch gadbad hai\n";
    }
    else
    {
        cout << "Ans is : " << ans << endl;
        cout << "Value of Ans is " << arr[ans] << endl;
    }

    return 0;
}