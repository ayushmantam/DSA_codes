#include<iostream>
#include<climits>
using namespace std;

// IMP BAAT KISI ARRAY ME 
// AS PARAMETER USKI SIZE BHI DALNA IS GOOD PRACTICE

void print(int arr[],int n,int i){
    //base case
    if (i>=n)
    {
        return;
    }

    //1 case solve krdia;
    cout<<arr[i]<<" ";

    //baaki recursion sambhal lega
    print(arr,n,i+1);
    
}
//agar maxi pass by referece nhi krte hai to
//function ke khatam hote hi local variable maxi khatam ho jayega 

void findMax(int arr[],int n,int i,int &maxi){
    //base case
    if (i>=n)
    {
        //array agar khatam ho gya or porra traverse ho gya
        //toh wapis aajao
        return;
    }

    //1 case solve karna hai
    if (arr[i]>maxi)
    {
        maxi=arr[i];
    }
    
    findMax(arr,n,i+1,maxi);
}

int main(){
    // int arr[5]={10,20,30,40,50};
    // int n=5;
    // int i=0;
    // print(arr,n,i);


    int arr1[8]={10,20,30,40,50,60,70,80};
    int n=8;
    int maxi=INT_MIN;

    int i=0;
    findMax(arr1,n,i,maxi);

    cout<<"Maximum number is "<<maxi<<endl;
}


    