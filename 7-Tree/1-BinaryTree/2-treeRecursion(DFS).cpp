#include <iostream>
#include <malloc.h>
#include<queue>
using namespace std;

struct node
{
public:
    int data;
    struct node *left;
    struct node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* BinaryTree(){
    int x;
    cin>>x;
    if(x==-1){
        return NULL;
    }
    node* temp=new node(x);
    // left side create
    cout<<"Enter the left child of"<<x<<" :";
    temp->left=BinaryTree();
    // right side create
    cout<<"Enter the riht child of"<<x<<" :";
    temp->right=BinaryTree();
    return temp;
}

void preOrder(node* root){ 
    if(root==NULL){           //base case
        return;
    }             //nLR
    cout<<root->data;          //Node    
    preOrder(root->left);         //left
  preOrder(root->right);         //right
}
//---Time Complexity--- o(n)                   ----Space Complexity---o(h)   o(n):in worst case
// in recursion we always calculate SC by using stack as we have to do fun call

void InOrder(node* root){ 
    if(root==NULL){           //base case
        return;
    }             //nLR
    InOrder(root->left);         //left
    cout<<root->data;          //Node   
  InOrder(root->right);         //right
}

void PostOrder(node* root){ 
    if(root==NULL){           //base case
        return;
    }             //nLR
    PostOrder(root->left);         //left
  PostOrder(root->right);         //right
  cout<<root->data;          //Node   
}

// calculate the size of tree
void Total(node* root,int &count){
        if(root==NULL){
            return;
        }
        count++;
        Total(root->left,count);
        Total(root->right,count);
}
// 2nd method:
// int Total(node* root) {
//     if (root == NULL) return 0;
//     return 1 + Total(root->left) + Total(root->right);
// }

node* Search(node* root,int target){
    if(root==NULL){    //Base case
               return NULL;
    }
// it means:
// We reached the end of a path in the tree.
// There's no more node to check in this direction.
// Therefore, the value we're looking for is not here.
 

    if(root->data==target){
        return root;
    }
    node* leftSearch=Search(root->left,target);
        if(leftSearch!=NULL){
            return leftSearch;
        }
    

    return Search(root->right,target);
}

// node* Search(node* root, int target) {
//     if (root == NULL) {
//         return NULL;
//     }
//     else if (root->data == target) {
//         return root;
//     }
//     else {
//         node* leftSearch = Search(root->left, target);
//         if (leftSearch != NULL) {
//             return leftSearch;
//         }
//         else {
//             return Search(root->right, target);
//         }
//     }
// }

int main()
{
    // Tree craetion code
    cout<<"Enter the root Node";
    node* root;
    root=BinaryTree();

    // PreOrder Print:
    cout<<"Pre-ORder:";
    preOrder(root);
    cout<<endl;

      // InOrder Print:
      cout<<"In-ORder:";
      InOrder(root);
      cout<<endl;

        // PostOrder Print:
    cout<<"Post-ORder:";
    PostOrder(root);
    
        // Count total number of nodes
        int count = 0;
        Total(root, count);
        cout << "\nTotal number of nodes: " << count << endl;

        // To Search in TREE
// for(int i=0;i<3;i++){
        int target;
        cout<<"Enter the value to Search in Tree?"<<endl;
        cin>>target;
        node* found=Search(root,target);
        if(found!=NULL){
            cout<<"The Node found with value:"<<found->data<<endl;
        }
        else{
            cout<<"Node not Found"<<endl;
        }
    // }
    
}


// ---------------TIME COMPLEXITY---------------
// o(n)


// ---------------Space COMPLEXITY---------------
// o(h)    h:height of the tree 
// o(n):in worst case