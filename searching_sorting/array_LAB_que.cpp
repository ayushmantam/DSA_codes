#include <iostream>
using namespace std;
void insert(int arr[], int size, int position, int data)
{
    size++;
    for (int i = size - 1; i > position; i--)
    {

        arr[i] = arr[i - 1];
    }
    arr[position] = data;
    return;
}
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
void remove(int arr[], int size, int position)
{
    arr[position]=0;
    for (int i = position; i < size; i++)
    {
        
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 6, 7};
    print(arr, 6);
    cout << endl;
    cout << "give index of position\n";
    int index;
    cin >> index;
    insert(arr, 6, index, 99);
    print(arr, 7);
}