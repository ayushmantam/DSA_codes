#include <iostream>
using namespace std;
class Heap
{
public:
    int arr[100];
    int size;
    Heap()
    {
        size = 0;
    }

    void insert(int value)
    {
        // value insert karo end me
        size = size + 1;
        int index = size;
        arr[index] = value;

        // iss value ko place at right(sahi) position
        while (index > 1) // root element ka parent nhi hota
        {
            int parentIndex = index / 2;
            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    int Delete()  //Extracting maximum element
    {
        // If the heap is empty
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return -1; // Return a default value indicating an error
        }

        // Store the root value to be returned later
        int ans = arr[1];  //delete operation will give value of root node

        // Replace root value with the last node's data
        arr[1] = arr[size];
        size--;

        // Place the root node's data in its correct position
        int index = 1;
        while (index <= size)
        {
            int left = 2 * index;
            int right = 2 * index + 1;

            int largest = index;

            if (left <= size && arr[largest] < arr[left])
            {
                largest = left;
            }
            if (right <= size && arr[largest] < arr[right])
            {
                largest = right;
            }

            if (largest == index)
            {
                break; // No swap needed, break the loop, till now
            }
            else
            {
                swap(arr[index], arr[largest]);
                index = largest;
            }
        }
        return ans; // Return the original root value
    }
};

int main()
{
    /*
    //creation
    Heap h;
    h.arr[0] = -1;
    h.arr[1] = 100;
    h.arr[2] = 50;
    h.arr[3] = 60;
    h.arr[4] = 40;
    h.arr[5] = 45;
    h.size = 5;

    cout << "printing the heap" << endl;
    for (int i = 0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl;
    h.insert(110);
    h.size = 6;
    cout << "printing the heap" << endl;
    for (int i = 0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    cout<<endl;
    */
    // insertion se creation
    Heap h;
    h.insert(50);
    h.insert(30);
    h.insert(70);
    h.insert(40);
    h.insert(80);
    h.insert(100);
    cout << "printing the heap" << endl;
    for (int i = 0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl;
    cout << h.Delete() << endl;

    cout << "printing the heap" << endl;
    for (int i = 0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl;
}