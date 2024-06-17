#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int index = i;
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;
    int largest = index;

    if (leftIndex <= n && arr[largest] < arr[leftIndex])
    {
        largest = leftIndex;
    }
    if (rightIndex <= n && arr[largest] < arr[rightIndex])
    {
        largest = rightIndex;
    }
    if (index != largest)
    {
        // left ya right child me se koi > hogya currentNode se
        swap(arr[largest], arr[index]);
        index = largest;
        heapify(arr, n, index);
    }

    if(index==largest){ //optiona; 
        return;
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
}


void heapSort(int arr[],int n){
    while (n!=-1)
    {
        swap(arr[1],arr[n]);  //swap  first and last elemnt
        n--;
        heapify(arr,n,1);  //heapify reduced sizeds array
    }
}

int main(){
    int arr[]={-1,12,15,13,11,14};
    int n=5;
    buildHeap(arr,n);
    cout<<"Printing heap"<<endl;
    for (int i = 0; i <= n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}