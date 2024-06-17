// bool detectLoop(Node* head){

//     //Empty LL
//     if (head==NULL)
//     {
//         return false;
//     }
//     //for map we have to include map library
//     map<Node*,bool>visited;
//     Node* temp=head;

//     while (temp!=NULL)
//     {
//         //cycle is present
//         if(visited[temp]==true){
//             cout<<"LOOP Present on element "<<temp->data<<endl;
//             return true;
//         }
//         visited[temp]=true;
//         temp=temp->next;

//     }
//     return false;
//     //TC O(n)
//     //SC O(n)
// }