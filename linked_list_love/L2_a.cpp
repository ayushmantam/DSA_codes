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


//function to find position in InOrder
int findPosition(int arr[],int n,int element){
    for (int i = 0; i <=n; i++)
    {
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}
Node* buildTreeFromPreOrderInOrder(int inorder,int preorder[],int size,int preIndex, int inorderStart,int inorderEnd){
    //base case
    if(preIndex>=size||inorderStart>inorderEnd){
        return NULL;
    }

    //step A:
    int element =preorder[preIndex++];
    Node* root=new Node(element);

    int pos=findPosition( inorder ,size,element);

    //step B: root->left solve
    root->left=buildTreeFromPreOrderInOrder(inorder,preorder,size,preIndex,inorderStart,pos-1);

    //step C: root->right solve
    root->right=buildTreeFromPreOrderInOrder(inorder,preorder,size,pos+1,inorderEnd);

    return root;
}
int main(){


    return 0;
}