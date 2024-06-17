#include<queue>
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

Node* buildTree(){
    int data;
    cout<<"Enter the data\n";
    cin>>data;

    if(data==-1){
        return NULL;
    }

    //Step A
    Node* root=new Node(data);

    //Step B
    cout<<"Enter the data for left part of "<<data<<endl;
    root->left=buildTree();

    //Step C
    cout<<"Enter the data for right part of "<<data<<endl;
    root->right=buildTree();

    return root; //sabke papa
}

void levelOrderTraversal(Node* root){
    queue<Node*>q;//Node* type queue for storing Nodes

    //initially;
    q.push(root);

/* ek line me hai sarre
    while (!q.empty())
    {
        //A
        Node* temp=q.front();
        //B
        q.pop();
        
        //C
        cout<<temp->data<<" ";
        //D    (FOR CHILD NODES)
        //agar left part exits then
        if(temp->left){
            q.push(temp->left);
        }
         
        if(temp->right){
            q.push(temp->right);
        }

    
    }
*/

    q.push(nullptr);//kyonki root me ek node ke baad hi level khatam ho jata hai
    //isilye initially esa kiya

    while (!q.empty())
    {
        //A
        Node* temp=q.front();

        //B
        q.pop();

        if(temp==NULL) {
            cout<<endl;//ek level ke baad endl print

            if(!q.empty()){//agar q empty hai aur usme null push karenege to infinite loop chal jayega

                 q.push(NULL);//ye null child class ke just baad push hoga
            }
        }

        //B
        else{
        
        //C 
        cout<<temp->data<<" ";
        //D
        //agar left part exits then wo apni child childs de dega
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    } 
    }
}

void inorderTraversal(Node* root){
    if(root==NULL){
        return ;
    }

    //LNR
    inorderTraversal(root->left);
    cout<<root->data<<" ";  //print Current Node
    inorderTraversal(root->right);
}


void preorderTraversal(Node* root){
    //base case
    if (root==NULL)
    {
        return;
    }
    //NLR
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}



void postorderTraversal(Node* root){
    if(root==NULL){
        return;
    }

    //LRN
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
 
}

//leetcode max depth
int height(Node* root){
    if(root==NULL){
        return 0;
    }

    int leftheight=height(root->left);
    int rightHeight=height(root->right);
    int ans=max(leftheight,rightHeight)+1;

    return ans;
}

int diameterOfBinaryTree(Node* root){
     if(root==NULL){
        return 0;
     }      
     int op1=diameterOfBinaryTree(root->left);
     int op2=diameterOfBinaryTree(root->right);
     int op3=height(root->left)+1+height(root->right);
     int ans=max(op1,max(op2,op3));

     return ans;
}


 bool isBalanced(Node* root) {
        if(root==NULL){
          return true;
        }

        //1  solve
        int leftheight=height(root->left);
        int rightheight=height(root->right);
        int diff=abs(leftheight-rightheight);
        bool ans1=(diff<=1);

        //recursion
        bool leftAns=isBalanced(root->left);
        bool rightAns=isBalanced(root->right);

        if(ans1&&leftAns&&rightAns)
        return true;
        else
        return false;

}

int main(){
    Node* root=NULL;
    root=buildTree();

    levelOrderTraversal(root);
}