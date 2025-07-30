#include <iostream>
#include<queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int value)
    {
        data = value;
        left=right=NULL;
    }
};

int main()
{
   int x;
   cout<<"Enter the root element:"<<endl;
   cin>>x;
   int first,second;
   queue<Node*>q;
   Node* root=new Node(x);    //new node created         
   q.push(root);                 //root contains the address 

//    Building the Binary Tree
while(!q.empty()){
Node* temp=q.front();
q.pop();
cout<<"Enter the left value of "<<temp->data<<" : ";
cin>>first;      //left child
if(first!=-1){
    temp->left=new Node(first); 
    q.push(temp->left);             //pushing address
}

cout<<"Enter the right value of "<<temp->data<<" : ";
cin>>second;            //Right side
if(second!=-1){
    temp->right=new Node(second);
    q.push(temp->right);
}
}
}