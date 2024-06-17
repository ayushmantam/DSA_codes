#include<iostream>
using namespace std;
void print(int arr[],int &size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
}

void insertAtbegin(int arr[],int &size,int element){
    for (int i = size; i >0; i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=element;
    size++;
    print(arr,size);
    return;
}
void insertAtend(int arr[],int &size,int element){
    arr[size]=element;
    size++;
    print(arr,size);
    return;
}
void insertAtindex(int arr[],int &size,int element,int index){
    for (int i = size; i >index; i--)
    {
        arr[i]=arr[i-1];
    }
    arr[index]=element;
    size++;
    print(arr,size);
    return;
}

void deleteAtindex(int arr[],int &size,int index){
    for (int i = index; i <size-1 ; i++)
    {
        arr[i]=arr[i+1];
    }
    size--;
    print(arr,size);
    return;
}

int main(){
   int arr[8]={1,2,3,4,5,6,7,8};
   int size=8;
   print(arr,size);
   insertAtbegin(arr,size,100);
   insertAtend(arr,size,200);
   insertAtindex(arr,size,300,5);
   deleteAtindex(arr,size,4);

}