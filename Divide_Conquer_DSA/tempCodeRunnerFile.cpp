#include<iostream>
using namespace std;

void merge(int *arr, int s, int e) {
    int mid = (s + e) / 2;

    // length of new two arrays
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int* left = new int[len1];
    int* right = new int[len2];

    // copy values
    int k = s;
    for (int i = 0; i < len1; i++) {
        left[i] = arr[k];
        k++;
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++) {
        right[i] = arr[k];
        k++;
    }

    // merge logic
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;

    while (leftIndex < len1 && rightIndex < len2) {
        if (left[leftIndex] < right[rightIndex]) {
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        } else {
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }

    // copy remaining elements from left array
    while (leftIndex < len1) {
        arr[mainArrayIndex] = left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }

    // copy remaining elements from right array
    while (rightIndex < len2) {
        arr[mainArrayIndex] = right[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }

    // Cleanup: delete the dynamically allocated memory
    delete[] left;
    delete[] right;

}


void mergeSort(int* arr,int s,int e){
    //base case;
    //s==e  ->single element
    //s>e  ->invaild array
    if(s>=e)
    return;

//breaking
    int mid=(s+e)/2;

    //left part sort kardo recursion bhaiya
    mergeSort(arr,s,mid);

    //right part sort kardo recursion bhaiya
    mergeSort(arr,mid+1,e);

    //now merge two sorted arrays
    merge(arr,s,e);
}
int main(){
    int arr[]={4,3,2,5,4};
    int n=5;
    int s=0;
    int e=n-1;
    mergeSort(arr,s,e);


    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;

    return 0;
}