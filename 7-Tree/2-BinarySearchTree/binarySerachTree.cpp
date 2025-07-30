#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
           data=val;
           left=right=NULL;
    }
};

Node* insert(Node* root,int target){
    // Node* root →
// This is the current root node (or subtree root) where you are trying to insert the new value. It holds the location/address of the current node.

// int target →
// This is the value you want to insert into the Binary Search Tree (BST).

    if(!root){                      //check if there is no node yet 
        Node* temp=new Node(target);
        return temp;
    }
    if(target<root->data){
       root->left= insert(root->left,target);
    }
    else{
        root->right=insert(root->right,target);
    }
    return root;                  //returning address
}

void inorder(Node* root){           //get nodes(values) in assending order
    if(!root){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

bool search(Node* root,int target){
    if(!root){
        return 0;
    }
    if(root->data==target){
        return 1;
    }
    Node* temp=NULL;
    if(target<root->data){
    return search(root->left,target);
    }
    else{
        return search(root->right,target);
    }
}
 
int main(){
    int arr[]={3,7,4,1,6,9};
    Node* root=NULL;
    for(int i=0;i<6;i++){
       root=insert(root,arr[i]);    
    }
    inorder(root);

    cout<<endl;
    cout<<search(root,4);

}