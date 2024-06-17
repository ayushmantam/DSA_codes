#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

void takeinput(Node* root){
    cin>>data;

    while (data!=-1)
    {
        root=insert(data); 
    }  
    
}
int main(){
    Node* root=NULL;
    cout<<"Enter the data for Node\n";
    takeinput();
}